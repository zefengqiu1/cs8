#ifndef TABLE_H
#define TABLE_H
#include <string>
#include "record.h"
#include "../B+_tree/map.h"
#include "../B+_tree/mmap.h"
#include "../linklist/queue.h"
#include <set>





class Table{
public:
    Table(string table_name,vectorstr v);
    Table(string table_name);
    void insert(vectorstr field_name);
    void split_condition_and_logic(vectorstr v)
    {
        vectorstr condition;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!="or"||v[i]!="and")
            {
               condition.push_back(v[i]);
            }else
            {
                conditions.push(condition);
                condition.clear();
                logic.push(v[i]);
            }
        }
    }
    /*
    vector<MMap<string,int>> indices;
    Map<string,int> field_map;
    vectorstr field_name;
    */
    void get_indice(vectorstr condition)
    {
        Map<string,int> a;
        //set<int> _set;
        a["="]=1;
        a[">"]=2;
        a["<"]=3;
        a[">="]=4;
        a["<="]=5;
        string field=condition[0];
        string logic=condition[1];
        string value=condition[2];
        int index;
            switch (a[logic]) {
                case 1://==
                {
                MMap<string,int>::Iterator it;
                set<int> _set;
               it=indices[index].find(value);
               Vector<int> recd=(*it).value_list;
               while(!recd.isempty())
               {
                   _set.insert(recd.pop_back());
               }
               sets.push(_set);

                }

                    break;
                  case 2://>
                  {
                    index=field_map[field];
                    set<int> _set;
                    MMap<string,int>::Iterator it;
                    for(it=indices[index].lower_bound(value)++;it!=indices[index].end();it++)
                    {
                         Vector<int> recd=(*it).value_list;
                        while(!recd.isempty())
                        {
                           _set.insert(recd.pop_back());
                        }
                    }
                        sets.push(_set);


                  }
                    break;
            case 3://<
            {
                index=field_map[field];
                set<int> _set;
                MMap<string,int>::Iterator it;
                for(it=indices[index].begin();it!=indices[index].upper_bound(value);it++)
                {
                     Vector<int> recd=(*it).value_list;
                    while(!recd.isempty())
                    {
                       _set.insert(recd.pop_back());
                    }
                }
                    sets.push(_set);
            }

                break;

            case 4: //>=
            {
                index=field_map[field];
                set<int> _set;
                MMap<string,int>::Iterator it;
                for(it=indices[index].lower_bound(value);it!=indices[index].end();it++)
                {
                     Vector<int> recd=(*it).value_list;
                    while(!recd.isempty())
                    {
                       _set.insert(recd.pop_back());
                    }
                }
                    sets.push(_set);

            }
                break;

            case 5:  //<=
            {
                index=field_map[field];
                set<int> _set;
                MMap<string,int>::Iterator it;
                for(it=indices[index].begin();it!=indices[index].upper_bound(value)++;it++)
                {
                     Vector<int> recd=(*it).value_list;
                    while(!recd.isempty())
                    {
                       _set.insert(recd.pop_back());
                    }
                }
                    sets.push(_set);
            }
                break;

            }
    }

    void intersection()
    {
        while(!logic.empty())
        {
            if(logic.pop()=="and")
            {
                set<int> a=sets.pop();
                set<int> b=sets.pop();
                set<int> result;
                set_intersection(a.begin(), a.end(),               // 3.
                                b.begin(), b.end(),               // 4.
                               inserter(result, result.end())); // 5.
                sets.push(result);
            }else
            {
                set<int> a=sets.pop();
                set<int> b=sets.pop();
                set<int> result;
                set_union(a.begin(), a.end(),               // 3.
                                b.begin(), b.end(),               // 4.
                               inserter(result, result.end())); // 5.
                sets.push(result);
            }
        }

    }

    Table select_all()
    {
        string table_name="hello";

        table_name+=std::to_string(serial++);
        cout<<table_name<<endl;
        //get_field_name()
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

    Table select(vectorstr condition);

    void set_all_field(vectorstr fieldname)
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
    }
    vectorstr get_field_value_based_on_condition(vectorstr _field_name,vectorstr field_value)
    {
        vectorstr data;
        int index=0;
        for(int i=0;i<_field_name.size();i++)
        {
            if(field_map.contains(_field_name[i]))
                index=field_map[_field_name[i]];
                data.push_back(field_value[index]);
        }
        return data;
    }
    void write_info();
    vectorstr get_fields();

    void print() const;
    void print1();


    friend ostream& operator<<(ostream& outs,const Table& r)
    {
        r.print();
       // r.select_all();
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
    Queue<string> logic;//
    Queue<vectorstr> conditions;
    Queue<set<int>> sets;

};
/*
bool file_exists(const char filename[]);

void open_fileRW(fstream& f, const char filename[]) throw(char*);
void open_fileW(fstream& f, const char filename[]);

*/
int Table::serial=0;

void Table::write_info() { //write to field name.txt
    // write the field name into txt file
    ofstream _ff = ofstream(field_tbl_name);
    for(int i = 0 ; i < field_name.size(); i ++) {
        _ff << field_name[i] << " ";
    }
    _ff.close();
}

vectorstr Table::get_fields() {
    vectorstr v;
     ifstream _ff = ifstream(field_tbl_name);
     while(!_ff.eof()) {
         string s;
         _ff >> s;
         v.push_back(s);
        // cout << "get_fields: " << s <<endl;
     }
     _ff.close();
     return v;
}



Table::Table(string table_name)
{
    data_tbl_name=table_name+binary_postfix;
    field_tbl_name=table_name+txt_postfix;
    cout<<data_tbl_name<<endl;
    cout<<field_tbl_name<<endl;
    last_record_number=0;
    empty=true;
    set_all_field(get_fields());
    fstream f;
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
       last_record_number++;
       index++;
       pos=r.read(f,index);
    }
    f.close();
}




Table Table::select(vectorstr condition)
{
   // field == value;
    string field=condition[0];
    vectorstr _field_name;
    _field_name.push_back(condition[0]); //field_name need to be insert into table;
   // vector<int> indexoffield;
  //  indexoffield.push_back(field_name[])
   string value=condition[2];

   Vector<int> result= indices[field_map[field]].get(value);
  // cout<<result<<endl;//recond NO.
   fstream f;
   open_fileRW(f,data_tbl_name.c_str());
   Table t("student1",_field_name);
   while(!result.isempty())
   {
       int recordNo=result.pop_back();
       Record r;
       r.read(f,recordNo);
       vectorstr data=get_field_value_based_on_condition(_field_name,r.get_fields_value());
       t.insert(data);
   }
   f.close();
   return t;


//   Table t("result9",field_name);
//    for(int i=0;i<result.size();i++)
//    {
//      r.read(f,result[i]);
//      vectorstr data=r.get_fields(f);
//      t.Insert(data);
//    }
    //return t;
}


Table::Table(string table_name,vectorstr v)
{
    //table_name+=postfix;
    data_tbl_name=table_name+binary_postfix;
    field_tbl_name=table_name+txt_postfix;
    last_record_number=0;
    empty=true;
    set_all_field(v);
     write_info();
    //write field name to field table;
    fstream f;
    open_fileW(f,data_tbl_name.c_str());
    f.close();

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
       // data_table[i].insert(data[i],recno);
    }
    f.close();
    last_record_number++;
    empty=false;
}





void Table::print() const
{
    fstream f;
    cout << setw << field_name<<endl;
    Record r;//(field_name);
    //cout<<r<<endl;
    open_fileRW(f,data_tbl_name.c_str());
    int index=0;
    int pos= r.read(f,index)/5000;
    while (pos>0) {
     // vectorstr values=r.get_fields_value();
     //cout<<setw(10)<<values<<endl;
     cout<<r<<endl;
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
