#include <iostream>
#include "record.h"
#include  "open_hash.h"
#include "../chained_hash/chained_hash.h"
using namespace std;


template<typename T>
void test_hash_table_interactive( open_hash<T>& item, string table);

template<typename T>
void test_hash_table_random(open_hash<T>& object, int howmanykey, string table);

template<typename T>
void test_hash_table_interactive(chained_hash<T>& object, string table);

template<typename T>
void test_hash_table_random(chained_hash<T>& object, int howmanykey, string table);


int main()
{
        cout<<endl<<endl<<endl<<"----------------------"<<endl<<endl<<endl;
        const bool RANDOM_CHAINED = false;
        const bool RANDOM_OPEN = false;
        const bool INTERACTIVE_OPEN = true;
        const bool INTERACTIVE_CHAINED = true;

        if (INTERACTIVE_OPEN){
            cout<<"-------  INTERACTIVE TESTS ---------------------------"<<endl;
            open_hash<record<double>> open;
            test_hash_table_interactive(open, "open_hash_table" );
        }

        if (INTERACTIVE_CHAINED){
            cout<<"-------  INTERACTIVE TESTS ---------------------------"<<endl;
            chained_hash<record<double>> chained;
            test_hash_table_interactive(chained, "chained_hash_table" );
        }

        if (RANDOM_CHAINED){
            cout<<"----------- RANDOM TEST ------------------------------"<<endl;
           cout<< ". . . . . .  Chained Hash Table . . . . . . . . . . ."<<endl;
            chained_hash<record<double>> c_table;//have to put double
            test_hash_table_random(c_table, 2500, "chained_hash_table<record>");
          //  cout<<c_table<<endl;
        }

        if (RANDOM_OPEN){
            cout<<"----------- RANDOM TEST ------------------------------"<<endl;
            cout<<". . . . . .  Simple Hash Table . . . . . . . . . . ."<<endl;
            open_hash<record<double>> h_table;
            test_hash_table_random(h_table, 500, "hash_table<record>");
            //cout<<h_table<<endl;
        }

        cout<<endl<<endl<<endl<<"---------------------------------"<<endl;
    return 0;
}

template<typename T>
void test_hash_table_random(open_hash<T>& object, int howmanykey, string table)
{

    cout<<table<<endl;
    cout<<"---- ["<<howmanykey<<"] keys inserted."<<endl;
    open_hash<T> needrandomkey;//used it to have random key
    srand(time(nullptr));
    int randomkey[howmanykey];//500
    int key;
    double number;
    int numberoffound=0;
    int numberofnotfound=0;
    int sizeofkey;

    while(needrandomkey.size()<howmanykey)
    {
        sizeofkey=needrandomkey.size();
        key=rand()%9999+1;
        number=rand()%999+1;
        needrandomkey.insert(record<double>(key,number));
        if(sizeofkey < needrandomkey.size())
        {
            randomkey[sizeofkey]=key;
        }
    }

    //pick half random key from randomkeyarray
    for(int i=0;i<howmanykey/2;i++)
    {
        object.insert(record<double>(randomkey[i],i+1));
    }
    cout<<object<<endl;
    cout<<"collision count: "<<object.countofcollision()<<endl;
    cout<<"size of key is "<<object.size()<<endl;

    for(int i=0;i<object.size();i++)
    {
        if(object.is_present(randomkey[i]))
        {
            numberoffound++;
        }
    }

    for(int i=object.size();i<howmanykey;i++)
    {
        if(!object.is_present(randomkey[i]))
        {
            numberofnotfound++;
        }
    }

    cout<<"- - - - - - - - - Search for existing keys ----------------"<<endl;
    cout<<"Search for existing keys:"<< howmanykey/2<<" keys to be tested:"<<endl;
    cout<<"EXISTING KEYS LOOKUP: VERIFID. EXISTING KEYS EXAMINED:"<< numberoffound<<endl;


    cout<<"- - - - - - - - - Search for non-existent keys ----------------"<<endl;
    cout<<"Search for nonexistent keys:"<< howmanykey/2<<" keys to be tested:"<<endl;
    cout<<" NONEXISTENT KEYS LOOKUP: VERIFID. NONEXISTENT KEYS EXAMINED::"<< numberofnotfound<<endl;

}



template<typename T>
void test_hash_table_random(chained_hash<T>& object, int howmanykey, string table)
{
        cout<<table<<endl;
        cout<<"---- ["<<howmanykey<<"] keys inserted."<<endl;
        chained_hash<T> needrandomkey;
        int randomkey[howmanykey];
        srand(time(nullptr));
        int key;
        double number;
        int numberoffound=0;
        int numberofnotfound=0;
        int sizeofkey;


        while(needrandomkey.size()<howmanykey)
        {
            sizeofkey=needrandomkey.size();
            key=rand()%9999+1;
            number=rand()%999+1;
            needrandomkey.insert(record<double>(key,number));
            if(sizeofkey < needrandomkey.size())
            {
                randomkey[sizeofkey]=key;
            }
        }

        //pick half random key from randomkeyarray
        for(int i=0;i<howmanykey/2;i++)
        {
            object.insert(record<double>(randomkey[i],i+1));
        }
        cout<<object<<endl;
        cout<<"size of key is "<<object.size()<<endl;

        for(int i=0;i<object.size();i++)
        {
            if(object.is_present(randomkey[i]))
            {
                numberoffound++;
            }
        }

        for(int i=object.size();i<howmanykey;i++)
        {
            if(!object.is_present(randomkey[i]))
            {
                numberofnotfound++;
            }
        }
    cout<<"- - - - - - - - - Search for existing keys ----------------"<<endl;
    cout<<"Search for existing keys:"<< howmanykey/2<<" keys to be tested:"<<endl;
    cout<<"EXISTING KEYS LOOKUP: VERIFID. EXISTING KEYS EXAMINED:"<< numberoffound<<endl;

    cout<<"- - - - - - - - - Search for non-existent keys ----------------"<<endl;
    cout<<"Search for nonexistent keys:"<< howmanykey/2<<" keys to be tested:"<<endl;
    cout<<" NONEXISTENT KEYS LOOKUP: VERIFID. NONEXISTENT KEYS EXAMINED::"<< numberofnotfound<<endl;


 }


template<typename T>
void test_hash_table_interactive(open_hash<T>& item, string table)
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
                cout<<"the size is "<<item.size()<<endl;
                cout<<item<<endl;
                break;
            case'I':
                cout<<"plase insert your key and number (key:number)."<<endl;
                cin>>key;
                cin>>comma;
                cin>>number;
                cout<<"["<<key<<":"<<number<<"]"<<"has been inserted"<<endl;
                item.insert(record<double>(key,number));// how to deal with this one
                cout<<item<<endl;
                break;
           case 'R':
                key=rand()%9999+1;
                number=rand()%999+1;
                cout<<"["<<key<<":"<<number<<"]"<<"has been inserted"<<endl;
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
                    cout<<"not found"<<endl;
                }
                cout<<item<<endl;
                 break;

        }
        // cout<<"-------------------------------------"<<endl;
         cout<<"please input your command"<<endl;
         cout<<"[S]ize() [I]nsert [R]andom [D]elete [F]ind value exists?   e[X]it  :"<<endl;
         cout<<":";cin>>ans;

    }

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
                    cout<<object<<endl;
                    break;
                case'I':
                    cout<<"plase insert your key and number (key:number)."<<endl;
                    cin>>key;
                    cin>>comma;
                    cin>>number;
                    cout<<"["<<key<<":"<<number<<"]"<<"has been inserted"<<endl;
                    object.insert(record<double>(key,number));// how to deal with this one
                    cout<<object<<endl;
                    break;
               case 'R':
                    key=rand()%9999+1;
                    number=rand()%999+1;
                    cout<<"["<<key<<":"<<number<<"]"<<"has been inserted"<<endl;
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
                    cout<<object<<endl;
                     break;

            }
            // cout<<"-------------------------------------"<<endl;
             cout<<"please input your command"<<endl;
             cout<<"[S]ize() [I]nsert [R]andom [D]elete [F]ind value exists?   e[X]it  :"<<endl;
             cout<<":";cin>>ans;
    }
}
