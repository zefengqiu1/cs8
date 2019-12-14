#ifndef TABLE_H
#define TABLE_H
#include <string>
#include "record.h"
#include "../B+_tree/map.h"
#include "../B+_tree/mmap.h"
#include "../linklist/queue.h"
#include <set>

const bool DEBUG=false;

class Table{
public:
    Table(string table_name,vectorstr v);
    Table(string table_name);
    Table(const Table& other)
    {
        copy_table(other);
    }

    void copy_table(const Table& RHS);


    Table& operator =(const Table& RHS)
    {
        if(this==&RHS) return *this;
        else
        {
            copy_table(RHS);
            return *this;
        }
    }

    void insert(vectorstr field_name);

    void infix_of_condition(vectorstr& v); //when get the condition vector from the ptree,
                                           //transfer it to the infix queue.

    Queue<vectorstr> shunting_yard(); // change infix queue to postfix


    set<int> RPN();  // based on "and" "or", get the result set.

    int record_number()
    {
        return last_record_number;
    }

    string get_table_name()
    {
        int index=data_tbl_name.find_first_of('.');
        string table_name=data_tbl_name.substr(0,index);
        return table_name;
    }

    set<int> get_indice(vectorstr condition); // get the set of record number which is matching to the condition.


    set<int> _set_intersection(set<int>& set1,set<int>& set2);  //intersection of two sets.



    set<int> _set_union(set<int>& set1,set<int>& set2); //union of two sets


    void write_to_table(Table& t,set<int>& result,fstream& f); //write the matching data to new table



    Table select_all(); //check all data

    Table select(vectorstr fields,vectorstr condition); //check certain data when matching the condition;

    void set_all_field(vectorstr fieldname); //set up all indice mmap, field_name vector, index map,operator map;

    void write_info();
    vectorstr get_fields();

    void print() const;
    void print1();

    friend ostream& operator<<(ostream& outs,const Table& r)
    {
        r.print();
        return outs;
    }

private:
    string binary_postfix=".bin";
    string field_tbl_name;
    string data_tbl_name;
    string txt_postfix=".txt";
    Vector<MMap<string,int>> indices;
    Map<string,int> field_map;
    vectorstr field_name;
    int last_record_number;
    bool empty;
    int static serial;
    Queue<vectorstr> infix;
    Map<string,int> operator_map;

};

int Table::serial=0;


Table::Table(string table_name)
{
    data_tbl_name=table_name+binary_postfix;
    field_tbl_name=table_name+txt_postfix;
    if(DEBUG)
       // cout<<data_tbl_name<<endl;
       // cout<<field_tbl_name<<endl;
    last_record_number=0;
    empty=true;
    set_all_field(get_fields());
    fstream f;
    //data_tbl_name.c_str()
    open_fileRW(f,data_tbl_name.c_str());
    Record r;
    int pos;
    int index=0;
    pos=r.read(f,index);
    while (pos>0) {
       vectorstr value=r.get_fields_value();
       for(int i=0;i<value.size();i++)
       {
           indices[i][value[i]]+=index;//pos always next record
       }
       index++;
       pos=r.read(f,index);
       last_record_number++;
    }

    f.close();
}

Table::Table(string table_name,vectorstr v)
{

    data_tbl_name=table_name+binary_postfix;
    field_tbl_name=table_name+txt_postfix;
    if(DEBUG)
       // cout<<data_tbl_name<<endl;
       // cout<<field_tbl_name<<endl;

    empty=true;
    set_all_field(v);
     write_info();
    //write field name to field table;
    fstream f;
    open_fileW(f,data_tbl_name.c_str());
    f.close();
    last_record_number=0;

}



void Table::copy_table(const Table& RHS)
{
    binary_postfix=RHS.binary_postfix;
    field_tbl_name=RHS.field_tbl_name;
    data_tbl_name=RHS.data_tbl_name;
    txt_postfix=RHS.txt_postfix;
    indices=RHS.indices;
    field_map=RHS.field_map;
    field_name=RHS.field_name;
    last_record_number=RHS.last_record_number;
    empty=RHS.empty;
}


void Table::write_info() { //write to field name.txt
    // write the field name into txt file
    ofstream f;
    f.open(field_tbl_name.c_str());
    if(!f.fail())
    {
        for(int i = 0 ; i < field_name.size(); i ++) {

            f <<" "<<field_name[i];
            if(DEBUG)
               cout<<"write"<<field_name[i]<<endl;
        }
        f.close();
    }else
    {
        cout<<"open file failed"<<endl;
        exit(1);
    }
}

vectorstr Table::get_fields() {
       vectorstr v;
       ifstream f;
       f.open(field_tbl_name.c_str());
       if(!f.fail())
       {
           while(!f.eof()) {
            string s;
            f >> s;
            v.push_back(s);
            if(DEBUG)
               cout << "read from file " << s <<endl;
           }
            f.close();
            return  v;
       }else
       {
           cout<<"open file failed"<<endl;
           exit(1);
       }

}





void Table::insert(vectorstr data)
{
    fstream f;
    open_fileRW(f,data_tbl_name.c_str());
    Record r(data);
    long recno;
    recno=r.write(f);
    for(int i=0;i<data.size();i++)
    {
        indices[i][data[i]]+=recno/5000;
    }
    f.close();
    last_record_number++;
    empty=false;
}

Table Table::select_all()
{
    string table_name="select_all";
    table_name+=std::to_string(serial++);
    if(DEBUG)
        cout<<"table name: "<<table_name<<endl;
    Table t(table_name,field_name);
    fstream f;
    open_fileRW(f,data_tbl_name.c_str());
    Record r;
    int index=0;
    int pos= r.read(f,index);
    while (pos>0) {
      t.insert(r.get_fields_value());
      index++;
     pos=r.read(f,index);
    }
    f.close();
    return t;
}


Table Table::select(vectorstr fields,vectorstr condition)
{
    infix_of_condition(condition);
    set<int> result;
    result=RPN();
    fstream f;
    open_fileRW(f,data_tbl_name.c_str());
    string table_name="result";

    if(fields.front()=="*")
    {
        if(DEBUG)
            cout<<"field_name "<<field_name<<"field_name_size "<<field_name.size()<<endl;

        table_name+=std::to_string(serial++);
         Table t(table_name,field_name);
         write_to_table(t,result,f);
          f.close();
          return t;
    }else
    {
        table_name+=std::to_string(serial++);
        //cout<<table_name<<endl;
         Table t(table_name,fields);
         write_to_table(t,result,f);
          f.close();
          return t;
    }

}




void Table::infix_of_condition(vectorstr& v)
{
    vectorstr condition;
    //string condi_or_logic;
    if(DEBUG)
        cout<<v.size()<<endl;
    if(!v.isempty())
    {
        for(int i=0;i<v.size();i++)
        {
            if(DEBUG)
                cout<<v[i]<<endl;

            if(v[i]!="or" && v[i]!="and")
            {
               condition.push_back(v[i]);
            }else
            {
                if(DEBUG)
                    cout<<condition<<endl;

                infix.push(condition);
                vectorstr v1;
                v1.push_back(v[i]);
                infix.push(v1);
                condition.clear();
            }
        }
        if(DEBUG)
            cout<<condition<<endl;
        infix.push(condition);
    }

}


Queue<vectorstr> Table::shunting_yard()
{
    Queue<vectorstr> postfix;
    Stack<vectorstr> s;
    while(!infix.empty())
    {
        vectorstr v=infix.pop();
        if(v.front()=="and"||v.front()=="or")
        {
            if(s.empty())
            {
                s.push(v);
            }else
            {
                if(s.Top().front()=="and" && v.front()=="or")
                {
                    postfix.push(s.pop());
                }
                s.push(v);
            }
        }else
        {
            postfix.push(v);
        }

    }
    while(!s.empty())
    {
        postfix.push(s.pop());
    }
    return postfix;
}

set<int> Table::RPN()
{
    Queue<vectorstr> postfix=shunting_yard();
    Stack<set<int>> s;
    while (!postfix.empty()) {
        vectorstr v=postfix.pop();
        if(v.front()!="and" && v.front()!="or")
        {
            s.push(get_indice(v));
        }else
        {
            if(v.front()=="and")
            {
               set<int> set1=s.pop();//set1
               set<int> set2=s.pop();//set2
               set<int> result=_set_intersection(set1,set2);
               s.push(result);

            }else
            {
                set<int> set1=s.pop();//set1
                set<int> set2=s.pop();//set2
                set<int> result=_set_union(set1,set2);
                s.push(result);
            }
        }
    }
    return s.pop();
}


set<int> Table::get_indice(vectorstr condition)
{
    string field=condition[0];
    string logic=condition[1];
    string value=condition[2];
    set<int> _set;
    int index;
        switch (operator_map[logic]) {
            case 1://==
            {
             index=field_map[field];
            MMap<string,int>::Iterator it;

            if(!indices[index].contains(value))
            {

                break;
            }
            it=indices[index].find(value);

           Vector<int> recd=(*it).value_list;
           if(DEBUG)
                cout<<recd<<endl;
           while(!recd.isempty())
           {


               _set.insert(recd.pop_back());
           }


            }
                break;
              case 2://>
              {
                index=field_map[field];
               // set<int> _set;
                MMap<string,int>::Iterator it;
                    for( it=indices[index].upper_bound(value);it!=indices[index].end();it++)
                    {
                        Vector<int> recd=(*it).value_list;
                        if(DEBUG)
                            cout<<recd<<endl;
                        while(!recd.isempty())
                        {

                           _set.insert(recd.pop_back());
                        }
                    }


              }
                break;
        case 3://<
        {
            index=field_map[field];

            MMap<string,int>::Iterator it;
            for(it=indices[index].begin();it!=indices[index].lower_bound(value);it++)
            {
                 Vector<int> recd=(*it).value_list;
                 if(DEBUG)
                    cout<<recd<<endl;
                while(!recd.isempty())
                {

                   _set.insert(recd.pop_back());
                }
            }
        }

            break;

        case 4: //>=
        {
            index=field_map[field];

            MMap<string,int>::Iterator it;
            for(it=indices[index].lower_bound(value);it!=indices[index].end();it++)
            {
                 Vector<int> recd=(*it).value_list;
                 if(DEBUG)
                    cout<<recd<<endl;
                while(!recd.isempty())
                {
                   _set.insert(recd.pop_back());
                }
            }
        }
            break;

        case 5:  //<=
        {
            index=field_map[field];

            MMap<string,int>::Iterator it;
            for(it=indices[index].begin();it!=indices[index].upper_bound(value);it++)
            {
                Vector<int> recd=(*it).value_list;
                if(DEBUG)
                    cout<<recd<<endl;
                while(!recd.isempty())
                {
                   _set.insert(recd.pop_back());
                }
            }
        }
            break;

        }

        return _set;
}


set<int> Table::_set_intersection(set<int>& set1,set<int>& set2)
{
    set<int> result;
    set_intersection(set1.begin(), set1.end(),
                    set2.begin(), set2.end(),
                   inserter(result, result.end()));
    return result;
}

set<int> Table::_set_union(set<int>& set1,set<int>& set2)
{
    set<int> result;
    set_union(set1.begin(), set1.end(),
                    set2.begin(), set2.end(),
                   inserter(result, result.end()));
    return result;
}


void Table::write_to_table(Table& t,set<int>& result,fstream& f)
{
    if(!result.empty())
    {
        for (std::set<int>::iterator it=result.begin(); it!=result.end(); ++it)
        {
            vectorstr value;
            int recordNo=*it;
            Record r;
            r.read(f,recordNo);
            vectorstr data=r.get_fields_value();
            if(DEBUG)
                cout<<data<<endl;
            vectorstr field_name=t.field_name;
            int size=field_name.size();
            if(DEBUG)
                cout<<"field name size from file"<<size<<endl;
            for(int i=0;i<size;i++)  //check for data you need.
            {
               value.push_back(data[field_map[field_name[i]]]);
            }

            t.insert(value);
        }
    }
}


void Table::set_all_field(vectorstr fieldname)
{
    for(int i=0;i<fieldname.size();i++)
    {
        field_map.insert(fieldname[i],i);
    }

    for(int i=0;i<fieldname.size();i++)
    {
        indices.push_back(MMap<string,int>());
    }
    field_name=fieldname;
    operator_map["="]=1;
    operator_map[">"]=2;
    operator_map["<"]=3;
    operator_map[">="]=4;
    operator_map["<="]=5;
}

void Table::print() const
{
    fstream f;
   // cout<<field_name<<endl;
     cout<<setw(20)<<setiosflags(ios::right)<<"Record";
   for(int i=0;i<field_name.size();i++)
   {
      cout<<setw(20)<<setiosflags(ios::right)<<field_name[i];
   }
   cout<<endl;
    Record r;//(field_name);
    open_fileRW(f,data_tbl_name.c_str());
    int index=0;
    int pos= r.read(f,index)/5000;
    while (pos>0) {
     //cout<<setw(10)<<index<<setw(10)<<r<<endl;
     cout<<setw(20)<<setiosflags(ios::right) <<index<<r<<endl;
     index++;
     pos=r.read(f,index);
    }

    f.close();
}

void Table::print1()
{
    for(int i=0;i<indices.size();i++)
    {
       cout<<indices[i];
    }
}


#endif // TABLE_H
