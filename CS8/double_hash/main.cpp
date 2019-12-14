#include <iostream>
#include "record.h"
#include  "double_hash.h"
#include <time.h>
using namespace std;


template<typename T>
void test_hash_table_interactive( double_hash<T>& item, string table);

template<typename T>
void test_hash_table_random(double_hash<T>& object, int howmanykey, string table);


int main()
{

//     clock_t start,finish;
//     double totaltime;
//     start=clock();

//     double_hash<record<double>> _double_hash;
//     test_hash_table_random(_double_hash, 700, "double_hash table");                     //把你的程序代码插入到这里面


//     finish=clock();
//     totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
//     cout<<"\n此程序的运行时间为"<<totaltime<<"秒！"<<endl;
//    double_hash<record<double>> _double_hash;
//    int a=22;
//    for(int i=0;i<19;i++)
//    {
//        _double_hash.insert(record<double>(a,i+1));
//        a+=19;
//    }
//    cout<<_double_hash;
   // test_hash_table_interactive(_double_hash,"double_hash table");
    return 0;
}

template<typename T>
void test_hash_table_random(double_hash<T>& object, int howmanykey, string table)
{
    cout<<table<<endl;
    srand(time(nullptr));
    int key;
    double number;

    while(object.size()<howmanykey)
    {
        key=rand()%9999+1;
        number=rand()%999+1;
        object.insert(record<double>(key,number));
    }
    cout<<"---- ["<<howmanykey<<"] keys inserted."<<endl;
    cout<<object;
    cout<<"collision count: "<<object.countofcollision()<<endl;


}



template<typename T>
void test_hash_table_interactive(double_hash<T>& item, string table)
{
    cout<<table<<endl;
    //open_hash<record<T>> open;
    srand(time(nullptr));
    char ans;
    char comma;
    int key;
    double number;
    cout<<"please input your command"<<endl;
    cout<<"[S]ize() [I]nsert [R]andom [D]elete [F]ind value exists?   e[X]it  :"<<endl;
    cout<<":";cin>>ans;
    while((toupper(ans))!='X')
    {
        switch (toupper(ans)) {
            case 'S':
                cout<<item.size()<<endl;
                //cout<<_h<<endl;
                break;
            case'I':
                cout<<"plase insert your key and number (key:number)."<<endl;
                cin>>key;
                cin>>comma;
                cin>>number;
                cout<<key<<":"<<number<<"has been inserted"<<endl;
                item.insert(record<double>(key,number));// how to deal with this one
                cout<<item<<endl;
                break;
           case 'R':
                key=rand()%9999+1;
                number=rand()%999+1;
                cout<<key<<":"<<number<<"has been inserted"<<endl;
                item.insert(record<double>(key,number)); // how to deal with this one
                cout<<item<<endl;
                break;
           case 'D':
                cout<<"plase insert your key"<<endl;
                cin>>key;
                cout<<key<<"has been removed"<<endl;
                item.remove(key);
                cout<<item<<endl;
                break;
           case'?':
                cout<<"plase insert your key"<<endl;
                cin>>key;
                if(item.is_present(key))
                {
                    cout<<"yes,it exist !"<<endl;
                }else
                {
                    cout<<"sorry, not exist! "<<endl;
                }
                break;
           case 'F':
                cout<<"plase insert your key"<<endl;
                cin>>key;
                bool found=false;
                record<double> result;
                item.find(key,found,result);
                if(found)
                {
                    cout<<"["<<result<<"]"<<"found!"<<endl;
                }else
                {
                    cout<<"not found!"<<endl;
                }
                 break;

        }
        // cout<<"-------------------------------------"<<endl;
         cout<<"please input your command"<<endl;
         cout<<"[S]ize() [I]nsert [R]andom [D]elete [F]ind value exists?   e[X]it  :"<<endl;
         cout<<":";cin>>ans;

    }

}




