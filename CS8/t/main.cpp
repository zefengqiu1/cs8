#include <iostream>
#include "bptable.h"

using namespace std;


void test_1();

void test_2();

int main()
{
    cout << "Hello World!" << endl;
   // test_1();
    test_2();
    return 0;
}


void test_1()
{
    vectorstr v={"recNo","first","last","department"};
    BPTable t("nihaoya",v);

    vectorstr list[] = {
        vectorstr{"0","Joe","Blow","CS"},
        vectorstr{"1","Dave","Smith","CS"},
        vectorstr{"2","Jane","Doe","Math"},
        vectorstr{"3","Mary","Stevenson","CS"},
        vectorstr{"4","Jane","Torres","CS"},
        vectorstr{"5","Sid","Albertson","CS"},
        vectorstr{"6","Samuel","Johnson","CS"},
    };
    for (int i = 0; i<7; i++){

        t.insert_into(list[i]);
    }

  //  t.print_inices();
}


void test_2()
{
    BPTable t("nihaoya");

   cout<<t.select_all();
   cout<<t.select_all();
   cout<<t.select_all();
   cout<<t.select_all();
   cout<<t.select_all();
   cout<<t.select_all();
   cout<<t.select_all();
   // t.print_inices();
   // cout<<t;
   // vectorstr v;
//    v.push_back("last");
//    v.push_back("=");
//    v.push_back("Doe");
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



   // cout<<t.select(v);




}
