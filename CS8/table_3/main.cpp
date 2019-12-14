#include <iostream>
#include "table.h"
#include "sql.h"
#include <sstream>
#include "../filetokenizer/filetokenizer.h"

using namespace std;

void test_1();

void test_2();

void read_file();

void test_map();

MMap<string, long> get_word_indices(char* file_name);

int main(int argc, char *argv[])
{


    test_map();

//    MMap<string, long> a;
//    a=get_word_indices("solitude.txt");
//    cout<<"headache"<<endl;
//    cout<<a<<endl;


//    char ans;
//    int index=0;
//    SQL a;
//    while(toupper(ans)!='X')
//    {
//        cout<<"please enter the command"<<endl;
//        string filename;
//        getline(cin,filename);
//        fstream f;
//        f.open(filename.c_str());
//        if(f.fail())
//        {
//           // cout<<"open fail"<<endl;
//           // exit(1);
//            cout<<filename<<endl;
//            a.run(filename);
//        }else
//        {
//            while(!f.eof())
//            {
//                string command;
//                getline(f,command);
//                if(command.find("//")==string::npos && command!=" " && !command.empty())//没找到
//                {
//                    cout<<"commmand["<<index<<"]:"<<command<<endl;
//                    a.run(command);
//                    cout<<endl;
//                    cout<<endl;
//                    index++;
//                }else
//                {
//                      cout<<command<<endl;
//                }

//            }
//            f.close();
//        }
//        cout<<"input"<<endl;
//        cin>>ans;
//        cin.ignore();
//    }


    return 0;
}


void test_map()
{
      MMap<string, long> word_indices;
      word_indices = get_word_indices("solitude.txt");
      cout<<endl<<endl<<endl;

      //list all nodes of the index mmap:
      for (MMap<string, long>::Iterator it = word_indices.begin();
           it != word_indices.end(); it++){
          cout<<*it<<endl;
      }


      cout<<endl<<endl<<endl;
      cout<<"---------------------------------------------------"<<endl;
      string this_word = "ice";
      cout<<"---------------------------------------------------"<<endl;
      cout<<"Indices of \""<<this_word<<"\""<<endl;
      //list indices of this_word:
      if (word_indices.contains(this_word)){
          cout<<this_word<<": "<<word_indices[this_word]<<endl;
      }
      cout<<endl<<endl<<endl;

      cout<<"---------------------------------------------------"<<endl;
      string from = "ask";
      string to = "asker";
      //list from .. to:
      cout<<"listing indices from \""<<from<<"\" to \""<<to<<"\""<<endl;
      cout<<"---------------------------------------------------"<<endl;
      for (MMap<string, long>::Iterator it =
                  word_indices.lower_bound(from);
           it != word_indices.upper_bound(to) &&
           it != word_indices.end(); it++){
          cout<<*it<<endl;
      }

      cout <<endl<<endl<<endl<< "========== E N D  ====================" << endl;


}

MMap<string, long> get_word_indices(char* file_name){
    const bool debug = false;
    MMap<string, long> word_indices;
    FTokenizer ftk(file_name);
    Token t;
    long count = 0;

    ftk >> t;
    while (ftk.more()){
        //only the "words"
        if (t.type_string() == "ALPHA"){
            string s;
            s = t.token_str();
            word_indices[s] += count;
            count++;
            if (debug)
                cout<<"|"<<t.token_str()<<"|"<<endl;
        }
        ftk >> t;
    }
    return word_indices;
}


//void test_1()
//{
//    vectorstr v={"recNo","first","last","department"};
//    Table t("heihei",v);
//    vectorstr list[] = {
//        vectorstr{"0","Joe","Blow","CS"},
//        vectorstr{"1","Dave","Smith","CS"},
//        vectorstr{"2","Jane","Doe","Math"},
//        vectorstr{"3","Mary","Stevenson","CS"},
//        vectorstr{"4","Jane","Torres","CS"},
//        vectorstr{"5","Sid","Albertson","CS"},
//        vectorstr{"6","Samuel","Johnson","CS"},
//    };

//    for (int i = 0; i<7; i++){

//        t.insert(list[i]);
//        //cout<<list[i]
//    }
//   // t.print();
//}

//void read_file()
//{
//   string filename;
//   string postfix=".txt";
//   cout<<"plase enter the file name without .txt"<<endl;
//   cin>>filename;
//   filename+=postfix;
//   fstream f;
//   f.open(filename.c_str());
//   if(f.fail())
//   {
//       cout<<"open fail"<<endl;
//       exit(1);
//   }
//   while(!f.eof())
//   {
//       string _command;
//       getline(f,_command);
//       if(!_command.empty())
//        cout<<_command<<endl;
//   }


//}



//void test_2()
//{

//    Table t("heihei");
//    t.print1();
//}


