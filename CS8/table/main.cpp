#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>

#include "table.h"
#include "sql.h"
#include <cstring>

using namespace std;


void test_1();

void test_2();

int main(int argc, char *argv[])
{

    string a;

   // test_1();
   //   test_2();
//    string abc="select last from student";
//    char buffer[100];

//     strcpy(buffer,abc.c_str());

//     for(int i=0;i<100;i++)
//     {
//         cout<<buffer[i]<<" ";
//     }

    return 0;
}

void test_1()
{
    vectorstr v={"recNo","first","last","department"};
    Table t("woqu",v);
    vectorstr list[] = {
        vectorstr{"1","Joe","Blow","CS"},
        vectorstr{"2","Dave","Smith","CS"},
        vectorstr{"3","Jane","Doe","Math"},
        vectorstr{"4","Mary","Stevenson","CS"},
        vectorstr{"5","Jane","Torres","CS"},
        vectorstr{"6","Sid","Albertson","CS"},
        vectorstr{"7","Samuel","Johnson","CS"},
    };
    for (int i = 0; i<7; i++){

        t.insert(list[i]);
    }
    t.print();
}

void test_2()
{

    Table t("woqu");
    cout<<t.select_all();
     cout<<t.select_all();
      cout<<t.select_all();
       cout<<t.select_all();
//       cout<<t.select_all();
//        cout<<t.select_all();
//         cout<<t.select_all();
//          cout<<t.select_all();
   // t.print1();

//    vectorstr v;
//    v.push_back("last");
//    v.push_back("=");
//    v.push_back("Doe");
//    cout<<t.select(v);
//       cout<<t.select(v);
//          cout<<t.select(v);
//             cout<<t.select(v);
//                cout<<t.select(v);

//    char ans;
//    cout<<"input"<<endl;
//    cin>>ans;
//    while(ans!='x')
//    {
//        cout<<t.select_all();
//         cout<<"input"<<endl;
//         cin>>ans;

//    }

//    cout<<t.select_all();
//    cout<<t.select_all();
//    cout<<t.select_all();







//        Table t("woqu");
//        cout<<t.select_all();
//         cout<<t.select_all();
//          cout<<t.select_all();
//           cout<<t.select_all();
//            cout<<t.select_all();
//             cout<<t.select_all();
//              cout<<t.select_all();

     //  t.print();
     //  t.print1();

}

/*
    cout <<endl<<endl<<endl<< "================================" << endl;
    fstream f;
    open_fileW(f, "record_list_two_d.bin");
    vectorstr list[] = {
        vectorstr{"0","Joe","Blow","CS"},
        vectorstr{"1","Dave","Smith","CS"},
        vectorstr{"2","Jane","Doe","Math"},
        vectorstr{"3","Mary","Stevenson","CS"},
        vectorstr{"4","Jane","Torres","CS"},
        vectorstr{"5","Sid","Albertson","CS"},
        vectorstr{"6","Samuel","Johnson","CS"},
    };
    Record r;
    for (int i = 0; i<7; i++){
        vectorstr v=list[i];

        r = Record(v);
        cout<<"here is r: "<<endl<<r<<endl;
        cout<<"--------------------"<<endl;
        r.write(f);
    }
    f.close();
    open_fileRW(f, "record_list_two_d.bin" );
    r.read(f, 2);
    cout<<"record 2: "<<endl<<r<<endl;
    r.read(f, 3);
    cout<<"record 3: "<<endl<<r<<endl;

    cout <<endl<<endl<<endl<< "================================" << endl;


*/
