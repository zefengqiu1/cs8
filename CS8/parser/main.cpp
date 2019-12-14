#include <iostream>
#include "parser.h"
#include "../binary_2d/table.h"
using namespace std;

int main()
{
    string a ="select last from woqu where last = zefeng qiu and country=columbia";
   // char a[]="select last from student where last = zefeng qiu and country = columbia";

   // char s[] = "select last from woqu";
    Parser p(a);
    MMap<string,string> ptree;
    ptree=p.parse_tree();

   // cout<<ptree["command"]<<endl;
    cout<<ptree["command"]<<endl;
    cout<<ptree["table"]<<endl;
    cout<<ptree["where"]<<endl;
    cout<<ptree["condition"]<<endl;
    cout<<ptree["field"]<<endl;

//    string table_name=p.parse_tree()["table"].front();


//     cout<<table_name<<endl;
//     Table t(table_name);
//     t.select_all();


//        string table_name=ptree["table"];
//        table t(table_name);
//        t.select()



   // cout<<p.parse_tree();//["command"];



    //cout<<ptree["command"];

  //  cout<<ptree["command"].isempty()<<endl;

    //=="select"





//        enum keys{ZERO,SELECT,FROM};

//        MMap<string,int> _map;
//       // _map.insert("zero",keys);
//        _map.insert("select",keys::SELECT);
//        //_map["select"]=keys::SELECT;
//        cout<<_map;

    cout << "Hello World!" << endl;
    return 0;
}
