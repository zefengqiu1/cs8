#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include "../heap/vector.h"
#include <string>
#include "../B_tree/mmap.h"

using namespace std;

class Table{
public:
    Table(string table_name,Vector<string> fields);

    Table(string table_name);// 已经有table,直接打开就好

    void Insert(Vector<string> data);//data inside of vector

    Table selcet(vector<string> condition);//condition inside of vector

    Table select_all();

    Table transfer(vector<Record> data);


private:



};
#endif // TABLE_H
