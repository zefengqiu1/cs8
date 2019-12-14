#ifndef SQL_H
#define SQL_H
#include "table.h"
#include "../parser_1/parser.h"
#include "fstream"
class SQL{
public:

    SQL();
    void run(string command)
    {

        Parser p(command);
        ptree=p.parse_tree();
       // cout<<ptree<<endl;
        if(ptree["command"].front()=="create"||ptree["command"].front()=="make")
        {
            string table_name=ptree["table"].front();
            Vector<string> v=ptree["fields"];
            Table t(table_name,v);
           // t.print();

        }else if(ptree["command"].front()=="insert")
        {
            Table t(ptree["table"].front());
            t.insert(ptree["values"]);
            cout<<t;
        }else
        {
            Table t(ptree["table"].front());
            if(ptree["fields"].front()=="*" && ptree["where"].isempty())
            {
                cout<<t.select_all();
            }else if (ptree["fields"].front()!="*" && ptree["where"].isempty())
            {

            }else if(ptree["where"].front()=="yes")
            {
                t.select(ptree["condition"]);

            }
        }



      }


    //lower bound and upper
    //sql
    //select;
    //

private:
    MMap<string,string> ptree;
};

SQL::SQL()
{

}

#endif // SQL_H
