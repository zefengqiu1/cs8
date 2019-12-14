#ifndef SQL_H
#define SQL_H
#include "table.h"
#include "../parser/parser.h"

class SQL{
public:

    SQL();

    Table run(string command)
    {
        //char a[]=command.c_str();
        Parser p(command);
        ptree=p.parse_tree();
        if(ptree["command"].front()=="create")
        {
            string table_name=ptree["table"].front();
            Vector<string> v=ptree["fields"];
            //vector 转换
            Table t(table_name,v);

        }else if(ptree["command"].front()=="insert")
        {

            Table t(ptree["table"].front());
            t.insert(ptree["value"]);
            _t=t;

        }else//select
        {
             Table t(ptree["table"].front());
             Vector<string> condition=ptree["condition"];
            for(int i=0;i<condition.size();i++)
            {

                Map<string,int> field_map=t.get_field_map();

            }
            while(!condition.isempty())
            {
               _t=t.select();
            }

            return t;
        }

        Vector<string> condition=ptree["condition"];
        vectorstr data;

    }
    //adjacent table
    //lower bound and upper
    //sql
    //select;
    //

private:
    Table _t;
    MMap<string,string> ptree;


};
#endif // SQL_H
