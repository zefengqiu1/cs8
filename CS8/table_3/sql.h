#ifndef SQL_H
#define SQL_H
#include "table.h"
#include "../parser_1/parser.h"
#include "fstream"
class SQL{
public:

    SQL();

    bool validation(string command);

    void run(string command)
    {
        if(!validation(command))
        {
            cout<<"invalid input,please enter again!!!"<<endl;
            return;
        }


        Parser p(command);

        if(!p.fail())
        {
            ptree=p.parse_tree();
        }else
        {
            cout<<"invalid input,please enter again!!!"<<endl;
            return;
        }
        //cout<<ptree<<endl;
        if(ptree["command"].front()=="create"||ptree["command"].front()=="make")
        {
            string table_name=ptree["table"].front();
            Vector<string> v=ptree["fields"];
            Table t(table_name,v);
            cout<<"SQL::create table ("<<table_name<<","<<v<<")"<<endl;
            cout<<table_name<<" table created "<<"col: "<<v<<endl;


           // t.print();

        }else if(ptree["command"].front()=="insert")
        {
            Table t(ptree["table"].front());
            t.insert(ptree["values"]);
            cout<<"SQL::inserted"<<endl;

        }else
        {
            Table t(ptree["table"].front());
            if(ptree["fields"].front()=="*" && ptree["where"].isempty())
            {
                  Table _t=t.select_all();
                  cout<<"table_name: "<<_t.get_table_name()<<" records: "<<_t.record_number()<<endl;
                  cout<<_t<<endl;

              //  cout<< t.select_all()<<endl;
            }else //if (ptree["fields"].front()!="*" && ptree["where"].isempty())
            {
               // cout<<t.select(ptree["fields"],ptree["condition"])<<endl;

                Table _t=t.select(ptree["fields"],ptree["condition"]);
                cout<<"table_name: "<<_t.get_table_name()<<" records: "<<_t.record_number()<<endl;
                cout<<_t<<endl;

                //cout<<t.select(ptree["fields"],ptree["condition"]);
            }
        }
      }
private:
    MMap<string,string> ptree;
};

SQL::SQL()
{


}

bool SQL::validation(string command)
{   int index=0;
    for(int i=0;i<command.size();i++)
    {
       if(command[i]=='"')   index++;

    }

    return index%2==0;
}

#endif // SQL_H
