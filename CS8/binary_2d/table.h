#ifndef TABLE_H
#define TABLE_H
#include<iostream>
#include <fstream>
#include<vector>
#include "../B_tree/mmap.h"
#include "../B_tree/map.h"
#include "../heap/vector.h"
#include "record.h"
#include "iomanip"
using namespace std;


class Table{
public:
    static int serials;

    Table(string table_name,vectorstr fields);

    Table(string table_name);// already have the table

    void Insert(vectorstr data);//data inside of vector

    Table select(vectorstr condition);//condition inside of vector

    Table select_all();


    void set_fields(vectorstr field)//set field's name
    {
        field_name=field;
        for(int i=0;i<field_name.size();i++)
        {

           //data_table[i]=MMap<string,int>();
           data_table.push_back(MMap<string,int>());
        }
    }

    void print1();
    void print() const;

    bool is_empty()
    {
        return empty;
    }
    vectorstr get_fields(fstream& ins) //get fields'name
    {
        vectorstr field_name;

        Record r;
        r.read(ins,0);
        field_name=r.get_fields(ins);
        return field_name;
    }

    friend ostream& operator<<(ostream& outs,const Table& r)
    {
        r.print();
       // r.select_all();
        return outs;
    }

private:

    vector<MMap<string,int>> data_table;

   // Map<string,MMap<string,int>> field;
   // Map<string,int> field;//can be vector
    vectorstr field_name;
    string name_of_table;
    int last_record_number=0;
    bool empty=true;
    string postfix=".bin";

};

int Table::serials=0;

/*
bool file_exists(const char filename[]);

void open_fileRW(fstream& f, const char filename[]) throw(char*);
void open_fileW(fstream& f, const char filename[]);

*/



Table Table::select(vectorstr condition)
{
    //field == value
    string field=condition[0];
    string value=condition[2];
    int index=0;
   // cout<<condition<<endl;
   // field_name=condition;
   // cout<<field_name<<endl;
   // cout<<field_name.size()<<endl;
   for(int i=0;i<field_name.size();i++)
   {
       if(field_name[i]==field)
       {
           index=i;
       }
   }
   Vector<int> result= data_table[index].get(value);

   Record r;
   fstream f;
   //open_fileRW(f,name_of_table.c_str());
   //r.read(f,0);
   //vectorstr fieldname=r.get_fields(f);

   Table t("result9",field_name);
    for(int i=0;i<result.size();i++)
    {
      r.read(f,result[i]);
      vectorstr data=r.get_fields(f);
      t.Insert(data);
    }
    return t;
}



Table Table::select_all()
{
    //    vectorstr values=r.get_fields(f);
    //    string filename="result";
    //    serials+=1;
    //    filename+=std::to_string(serials);
//    fstream f;
//    open_fileRW(f,name_of_table.c_str());
//    Record r;
//    Table t("abcd",field_name);
//    long pos=r.read(f,1);
//    while (pos>0) {
//        vectorstr values=r.get_fields(f);
//        t.Insert(values);
//        pos=r.read(f,pos);
//    }
//    f.close();
//    return t;
    return *this;
}

Table::Table(string table_name,vectorstr fields)
{
    fstream f;
    table_name+=postfix;
    name_of_table=table_name;
    open_fileW(f,table_name.c_str());
    set_fields(fields);
    Record r(field_name);
    r.write(f);  //write the field name to the textfile
    f.close();
    last_record_number++;

}

//only allow one data each time
void Table::Insert(vectorstr data)
{
    fstream f;
    open_fileRW(f,name_of_table.c_str());
    Record r(data);
    long recno;
    recno=r.write(f);
    for(int i=0;i<data.size();i++)
    {
        data_table[i][data[i]]+=recno;
       // data_table[i].insert(data[i],recno);
    }
    f.close();
    last_record_number++;
    empty=false;
}

Table::Table(string table_name)
{
    fstream f;
    table_name+=postfix;
    name_of_table=table_name;
    open_fileRW(f,name_of_table.c_str());
    set_fields(get_fields(f));
    //cout<<field_name<<endl;
    Record r;
    int pos=r.read(f,1);                         //map 四个都加上recond number;
    while (pos>0) {
        vectorstr values=r.get_fields(f);
        for(int i=0;i<values.size();i++)
        {
          // data_table[i][values[i]]+=recno;
           data_table[i][values[i]]+=pos;
        }
        last_record_number++;
        pos=r.read(f,pos);
    }
    f.close();

}


void Table::print() const
{
    fstream f;
    open_fileRW(f,name_of_table.c_str());
    Record r;
    int pos= r.read(f,0);
    while (pos>0) {
      vectorstr values=r.get_fields(f);
     cout<<setw(10)<<values<<endl;
     pos=r.read(f,pos);
    // cout<<pos<<endl;
    }

    f.close();

}

void Table::print1()
{
    for(int i=0;i<data_table.size();i++)
    {
       cout<<data_table[i];
    }
}



#endif // TABLE_H
