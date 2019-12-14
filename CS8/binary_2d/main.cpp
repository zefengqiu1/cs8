
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "table.h"

using namespace std;

void test_1();

void test_2();

int main(int argc, char *argv[])
{

   //test_1();
    test_2();



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

            t.Insert(list[i]);
        }
       cout<<t<<endl;

//              cout<<t.select_all();
//       char ans;
//       cout<<"input"<<endl;
//       cin>>ans;
//        while(ans!='x')
//        {
//            cout<<t.select_all();
//             cout<<"input"<<endl;
//             cin>>ans;

//        }
        //cout<<t<<endl;
        t.print();
        t.print1();
}

void test_2()
{
    Table t("woqu");
    vectorstr v;
    v.push_back("last");
    v.push_back("=");
    v.push_back("Doe");
    cout<<t.select(v);
   // cout<<t.select(v);

//    t.print1();



//    Table t("woqu");
//   cout<<t.select_all();
//   cout<<t.select_all();
//   cout<<t.select_all();
//   cout<<t.select_all();

//   cout<<"123"<<endl;
//   cout<<t.select_all();
//   cout<<t.select_all();


//    cout<<t<<endl;
//    t.print1();


}

