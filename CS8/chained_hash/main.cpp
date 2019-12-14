#include <iostream>
#include "record.h"
#include  "chained_hash.h"
using namespace std;


//template<typename T>
//void test_hash_table_interactive( open_hash<T>& object, string table);

//template<typename T>
//void test_hash_table_random(open_hash<T>& object, int howmanykey, string table);

template<typename T>
void test_hash_table_interactive(chained_hash<T>& object, string table);

template<typename T>
void test_hash_table_random(chained_hash<T>& object, int sizeofkey, string table);


int main()
{
    chained_hash<record<double>> _table;
    //test_hash_table_random(_table,30,"hello");
    test_hash_table_interactive(_table,"chained_hash");




//    cout<<endl<<endl<<endl<<"----------------------"<<endl<<endl<<endl;
//    const bool RANDOM_CHAINED = false;
//    const bool RANDOM_OPEN = false;
//    const bool INTERACTIVE_OPEN = false;
//    const bool INTERACTIVE_CHAINED = true;

//    if (INTERACTIVE_OPEN){
//        cout<<"-------  INTERACTIVE TESTS ---------------------------"<<endl;
//        open_hash<record<double>> open;
//        test_hash_table_interactive(open, "open_hash_table" );
//    }

//    if (INTERACTIVE_CHAINED){
//        cout<<"-------  INTERACTIVE TESTS ---------------------------"<<endl;
//        chained_hash<record<double>> chained;
//        test_hash_table_interactive(chained, "chained_hash_table" );
//    }

//    if (RANDOM_CHAINED){
//        ----------- RANDOM TEST ------------------------------
//        . . . . . .  Chained Hash Table . . . . . . . . . . .;
//        chained_hash<record<double>> c_table;//have to put double
//        test_hash_table_random(c_table, 2500, "chained_hash_table<record>");
//        cout<<c_table<<endl;
//    }

//    if (RANDOM_OPEN){
//        cout<<"----------- RANDOM TEST ------------------------------"<<endl;
//        cout<<". . . . . .  Simple Hash Table . . . . . . . . . . ."<<endl;
//        open_hash<record<double>> h_table;
//        test_hash_table_random(h_table, 500, "hash_table<record>");
//        cout<<h_table<<endl;
//    }

//    cout<<endl<<endl<<endl<<"---------------------------------"<<endl;
    return 0;
}


template<typename T>
void test_hash_table_random(chained_hash<T>& object, int sizeofkey, string table)
{
        cout<<table<<endl;
       // srand(time(nullptr));
        int key;
        double number;

    while(object.size()< sizeofkey)
    {
        key=rand()%9999+1;
        number=rand()%999+1;
        object.insert(record<double>(key,number));
    }
    cout<<object<<endl;
    cout<<object.size()<<endl;
}




template<typename T>
void test_hash_table_interactive(chained_hash<T>& object, string table)
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
                    cout<<"size is "<<object.size()<<endl;
                    break;
                case'I':
                    cout<<"plase insert your key and number (key:number)."<<endl;
                    cin>>key;
                    cin>>comma;
                    cin>>number;
                    cout<<key<<":"<<number<<"has been inserted"<<endl;
                    object.insert(record<double>(key,number));// how to deal with this one
                    cout<<object<<endl;
                    break;
               case 'R':
                    key=rand()%9999+1;
                    number=rand()%999+1;
                    cout<<key<<":"<<number<<"has been inserted"<<endl;
                    object.insert(record<double>(key,number)); // how to deal with this one
                    cout<<object<<endl;
                    break;
               case 'D':
                    cout<<"plase insert your key"<<endl;
                    cin>>key;
                    cout<<key<<"has been removed"<<endl;
                    object.remove(key);
                    cout<<object<<endl;
                    break;
               case 'F':
                    cout<<"plase insert your key"<<endl;
                    cin>>key;
                    record<double> result;
                    if(object.find(key,result))
                    {
                        cout<<"["<<result<<"]"<<"found!"<<endl;
                    }else
                    {
                        cout<<"sorry!not found!"<<endl;
                    }
                     break;

            }
            // cout<<"-------------------------------------"<<endl;
             cout<<"please input your command"<<endl;
             cout<<"[S]ize() [I]nsert [R]andom [D]elete [F]ind value exists?   e[X]it  :"<<endl;
             cout<<":";cin>>ans;
    }
}




