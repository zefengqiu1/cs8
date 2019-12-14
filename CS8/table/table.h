#ifndef TABLE_H
#define TABLE_H
#include <string>
#include "record.h"
#include "../B+_tree/map.h"
#include "../B+_tree/mmap.h"

class Table{
public:
    Table(string table_name,vectorstr v);
    Table(string table_name);
    void insert(vectorstr field_name);

    Table select_all()
    {
        string table_name="hello";

        table_name+=std::to_string(serial++);
        cout<<table_name<<endl;
        Table t(table_name,get_field_name());
        fstream f;
        open_fileRW(f,_tbl_name.c_str());
        Record r;
        int pos= r.read(f,1);
        while (pos>0) {
          t.insert(r.get_fields_value());
         pos=r.read(f,pos);
        }
        f.close();
        return t;
    }

    Table select(vectorstr condition);

    void set_all_field(vectorstr fieldname)
    {
        //field_name=fieldname;
        for(int i=0;i<fieldname.size();i++)
        {
            field_map.insert(fieldname[i],i);
        }

        for(int i=0;i<fieldname.size();i++)
        {
            indices.push_back(MMap<string,int>());
        }
    }
    vectorstr get_field_name()
    {
        fstream f;
        vectorstr fieldname;
        open_fileRW(f,_tbl_name.c_str());
        Record r;
        r.read(f,0);
        fieldname=r.get_fields_value();
        f.close();
        return fieldname;
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

    Map<string,int> get_field_map()
    {
        return field_map;
    }

    void print() const;
    void print1();


    friend ostream& operator<<(ostream& outs,const Table& r)
    {
        r.print();
       // r.select_all();
        return outs;
    }

private:
    string postfix=".bin";
   // string field_name_table="field_tbl";
    string _tbl_name;
    vector<MMap<string,int>> indices;
    Map<string,int> field_map;
    vectorstr field_name;

    int last_record_number;
    bool empty;
    int static serial;

};
/*
bool file_exists(const char filename[]);

void open_fileRW(fstream& f, const char filename[]) throw(char*);
void open_fileW(fstream& f, const char filename[]);

*/
int Table::serial=0;


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
   open_fileRW(f,_tbl_name.c_str());
   Table t("student1",_field_name);
   while(!result.isempty())
   {
       int recordNo=result.pop_back();
       Record r;
       r.read(f,recordNo);
       vectorstr data=get_field_value_based_on_condition(_field_name,r.get_fields_value());
      // cout<<data<<endl;
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
    table_name+=postfix;
    _tbl_name=table_name;
    last_record_number=0;
    empty=true;
    field_name=v;
    set_all_field(v);
    fstream f;
    open_fileW(f,_tbl_name.c_str());
    Record r(v);
    r.write(f);
    f.close();

}

void Table::insert(vectorstr data)
{
    fstream f;
    open_fileRW(f,_tbl_name.c_str());
    Record r(data);
    long recno;
    recno=r.write(f);
    for(int i=0;i<data.size();i++)
    {
        indices[i][data[i]]+=recno;
       // data_table[i].insert(data[i],recno);
    }
    f.close();
    last_record_number++;
    empty=false;
}



Table::Table(string table_name)
{
    table_name+=postfix;
    _tbl_name=table_name;
    last_record_number=0;
    empty=true;
   // set_all_field(v);
    field_name=get_field_name();
    set_all_field(get_field_name());
    fstream f;
    open_fileRW(f,_tbl_name.c_str());
    Record r;
    int pos;
    pos=r.read(f,1);
    while (pos>0) {
       vectorstr value=r.get_fields_value();
       for(int i=0;i<value.size();i++)
       {
           indices[i][value[i]]+=pos-1;//pos always next record
       }
       last_record_number++;
       pos=r.read(f,pos);
    }
    f.close();
}


void Table::print() const
{
    fstream f;
    open_fileRW(f,_tbl_name.c_str());
    Record r;
    int pos= r.read(f,0);
    while (pos>0) {
      vectorstr values=r.get_fields_value();
     cout<<setw(10)<<values<<endl;
     pos=r.read(f,pos);
    // cout<<pos<<endl;
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
