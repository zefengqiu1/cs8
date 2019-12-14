#include <iostream>
#include <fstream>
#include <record.h>
using namespace std;
const int MAX = 1000;
#include <vector>



//读文件存在可以打开
//写文件不存在自动创建。


int main()
{
    cout << "Hello World!" << endl;
//    char a[10][10];
//    a[0][1]='c';
//    cout<<sizeof (a)<<endl;


    //hello!
//        cout<<endl<<endl<<endl<<endl;
//        ifstream f;
//        ofstream w;
//        char buffer[MAX];
//        f.open("solitude.txt");
//        //hello!
//        f.seekg(2,ios::beg);//at the begining of stream or file when ios:beg and 2 is offset.
//        cout<<f.tellg()<<endl;//always on the next to be ready to read.
//        f.read(buffer,4);
//        for(int i=0;i<f.gcount();i++)
//        {
//            cout<<buffer[i]<<endl;
//        }


//        cout<<endl<<endl<<endl<<endl;
//        //ifstream f;
//        ofstream w;
//        char buffer[MAX];
//        char buff[]={'1','2','3','4'};
//        w.open("solitude.txt");
//        //hello!
//        w.seekp(0,ios::end);//at the begining of stream or file when ios:beg and 2 is offset.
//        cout<<w.tellp()<<endl;//always on the next to be ready to read.
//        w.write(buff,4);
//        w.close();
//        for(int i=0;i<w.gcount();i++)
//        {
//            cout<<buffer[i]<<endl;
//        }


       // f.read(buffer, MAX -1);

//        while (f.gcount()>0){
//            //how many chars were read?
//            cout<<"number of chars read: "<<f.gcount()<<endl;

//            //place null char:
//            buffer[f.gcount()] = NULL;

//            //cout<<"Here is the block: "<<endl<<endl<<endl;

//            //cout<<buffer<<endl;
//            f.read(buffer, MAX -1);
//        }


//        cout <<endl<<endl<< "==============" << endl;

//    cout <<endl<<endl<<endl<< "================================" << endl;
//       Record list[10] = {"zero",
//                          "one",
//                          "two",
//                          "three",
//                          "four",
//                          "five",
//                          "six",
//                          "seven",
//                          "eight",
//                          "nine"};
//       for (int i = 0; i< 10; i++){
//           cout<<list[i]<<endl;
//       }
//       save_list(list, 10);

        vector<string> v1;
        v1.push_back("one");
        v1.push_back("zefeng");
        v1.push_back("cs");

        vector<string> v2;
        v2.push_back("two");
        v2.push_back("fangze");
        v2.push_back("cs");
        vector<string> v3;
        v3.push_back("three");
        v3.push_back("qiuzefeng");

        v3.push_back("cs");


        cout <<endl<<endl<<endl<< "================================" << endl;
//           Record list[3][3] = { {"one","zefeng","cs"},
//                                 {"two","fengze","cs"},
//                                 {"three","qiuzefeng","cs"}

//                             };

        Record list[3][3] = { {v1},{v2},{v3}

                          };
           for (int i = 0; i< 3; i++){
               cout<<list[i]<<endl;
           }
           save_list(list,3);

       Record r;
       fstream f;
       open_fileRW(f, "record_list.bin" );
       r.read(f, 0);
       cout<<"record 0: "<<r<<endl;
       r.read(f, 1);
       cout<<"record 1: "<<r<<endl;

    return 0;
}

/*
void save_list(Record list[][3], int count){
    fstream f;
    open_fileW(f, "record_list.bin");
    for (int i= 0; i<count; i++){
        list[i].write(f);
    }
    f.close();

}


*/
