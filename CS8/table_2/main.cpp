#include <iostream>
#include "table.h"
#include "sql.h"

using namespace std;

void test_1();

void test_2();






void read_file();

int main(int argc, char *argv[])
{

//    char ans;
//    int index=0;
//    SQL a;
//        cout<<"please enter the command"<<endl;
//        string filename;
//        getline(cin,filename);

//        fstream f;
//        f.open(filename.c_str());
//        if(f.fail())
//        {
//           // cout<<"open fail"<<endl;
//           // exit(1);
////            cout<<command<<endl;
////           a.run(command);
//        }else
//        {
//            while(!f.eof())
//            {
//                string command;
//                getline(f,command);
//                if(command=="\n\r") continue;

//                cout<<"commmand"<<index<<":"<<command<<endl;
//                if(!command.empty()||command!="\r"||command!="\n\r")

//                    a.run(command);
//                index++;
//            }
//            f.close();
//        }
     test_2();
    return 0;
}

void test_1()
{
    vectorstr v={"recNo","first","last","department"};
    Table t("heihei",v);
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

        t.insert(list[i]);
        //cout<<list[i]
    }
   // t.print();
}

void read_file()
{
   string filename;
   string postfix=".txt";
   cout<<"plase enter the file name without .txt"<<endl;
   cin>>filename;
   filename+=postfix;
   fstream f;
   f.open(filename.c_str());
   if(f.fail())
   {
       cout<<"open fail"<<endl;
       exit(1);
   }
   while(!f.eof())
   {
       string _command;
       getline(f,_command);
       if(!_command.empty())
        cout<<_command<<endl;
   }


}



void test_2()
{

    Table t("heihei");
    t.print1();

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
