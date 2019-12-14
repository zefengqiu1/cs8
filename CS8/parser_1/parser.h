#ifndef PARSER_H
#define PARSER_H
//#include "../B_tree/mmap.h"
//#include "../B_tree/map.h"
#include "../B+_tree/map.h"
#include "../B+_tree/mmap.h"
#include "../linklist/queue.h"
#include "../string_1/stringtoken.h"

using namespace std;



class Parser{
public:

        //Parser(char* s);

        Parser(string command);

        void set_string();
        int get_column(Token t);

        bool get_parse_tree();
        void build_keyword_list();
        void initial_table();
        MMap<string,string>& parse_tree()
        {
            return ptree;
        }
        bool fail()
        {
            if(flag)
            {
                return false;
            }else
            {
                return true;
            }
        }

private:

    MMap<string,string> ptree;
    Map<string,int> keywords;

    int adjacent_table[MAX_COLUMNS][MAX_COLUMNS];
    bool flag;
    Queue<Token> input;
    enum keys{ZERO,CREATE,MAKE,TABLE,FIELDS,INSERT,INTO,
             VALUES,
             SELECT,
             STAR,
             FROM,
             WHERE,//11
             RELATIONAL,//12
             LOGICAL};  //13

    char _buffer[MAX_BUFFER];       //input string

};


Parser::Parser(string command)
{

  strcpy(_buffer,command.c_str());
  initial_table();
  build_keyword_list();
  set_string();
}

void Parser::set_string()
{
    STokenizer stk(_buffer);
    Token t;
    string b="\"";
    string a="";
    while(!stk.done()){
        stk>>t;


        if(t.token_str()=="\"")
        {
            t=Token();
            stk>>t;
            while(t.token_str()!=b )
            {
                a+=t.token_str();
                t=Token();
                stk>>t;
                if(t.token_str()==b)
                {
                    input.push(Token(a,4));
                    a.clear();
                    break;
                }
            }

        }
        else if(t.type()==4||t.type()==2||t.token_str()==">"||t.token_str()=="<"||
                t.token_str()=="="||t.token_str()=="*"||t.token_str()==">="
                ||t.token_str()=="<=")
        {
            input.push(t);
        }

        t = Token();
    }
 //   cout<<"queue size is "<<input.size()<<endl;

    flag=get_parse_tree();

  // cout<<ptree<<endl;
   // flag=fail();
}

int Parser::get_column(Token t)
{
    if(keywords.contains(t.token_str()))
    {
         return keywords[t.token_str()];
    }else
    {
        return 14;
    }

}

bool Parser::get_parse_tree()
{

    int state=0;

    while(!input.empty() && state!=-1)
    {
        Token t=input.pop();
        // cout<<t<<endl;
       // cout<<get_column(t)<<endl;//
        state=adjacent_table[state][get_column(t)];
      //  cout<<state<<endl;
        switch (state) {
            case 1:
            case 6:
            case 11:
                ptree["command"]+=t.token_str();
                break;
            case 3:
            case 8:
            case 16:
                ptree["table"]+=t.token_str();
                break;
            case 5:
            case 12:
            case 14:
                ptree["fields"]+=t.token_str();
                break;
            case 15: //from
                break;
            case 10:
                ptree["values"]+=t.token_str();
                break;
            case 17:
                ptree["where"]+="yes";
                break;
            case 18:
            case 19:
            case 20:
            case 21:
                ptree["condition"]+=t.token_str();
                break;
        }

    }
    // cout<<state<<endl;
    //cout<<ptree<<endl;
    if(adjacent_table[state][0]!=1)
    {
        ptree.clear();
//        if(DEBUG)
//        {
//            cout<<"invalid input,please enter again!!!"<<endl;
//        }
        return false;
    }else
        return true;
}

void Parser::build_keyword_list()
{

    keywords.insert("create",CREATE);
    keywords.insert("make",MAKE);
    keywords.insert("table",TABLE);
    keywords.insert("fields",FIELDS);
    keywords.insert("insert",INSERT);
    keywords.insert("into",INTO);
    keywords.insert("values",VALUES);
    keywords.insert("select",SELECT);
    keywords.insert("*",STAR);
    keywords.insert("from",FROM);
    keywords.insert("where",WHERE);
    keywords.insert(">",RELATIONAL);
    keywords.insert("=",RELATIONAL);
    keywords.insert(">=",RELATIONAL);
    keywords.insert("<",RELATIONAL);
    keywords.insert("<=",RELATIONAL);
    keywords.insert("and",LOGICAL);
    keywords.insert("or",LOGICAL);
}


void Parser::initial_table()
{

    init_table(adjacent_table);

    mark_success(adjacent_table,5);

     mark_success(adjacent_table,10);
     mark_success(adjacent_table,16);
   //  mark_success(adjacent_table,19);
     mark_success(adjacent_table,20);
    //first colunmn finished

       mark_cell(0,adjacent_table,1,1);
       mark_cell(0,adjacent_table,2,1);

       mark_cell(0,adjacent_table,5,6);
       mark_cell(0,adjacent_table,8,11);

       mark_cell(1,adjacent_table,3,2);
       mark_cell(2,adjacent_table,14,3);

       mark_cell(3,adjacent_table,4,4);


       mark_cell(4,adjacent_table,14,5);
       mark_cell(5,adjacent_table,14,5);

       mark_cell(6,adjacent_table,6,7);

       mark_cell(7,adjacent_table,14,8);

       mark_cell(8,adjacent_table,7,9);

       mark_cell(9,adjacent_table,14,10);

       mark_cell(10,adjacent_table,14,10);

       mark_cell(11,adjacent_table,9,12);
       mark_cell(11,adjacent_table,14,14);

       mark_cell(12,adjacent_table,10,13);

       mark_cell(13,adjacent_table,14,16);

       mark_cell(14,adjacent_table,10,15);
       mark_cell(14,adjacent_table,14,14);

       mark_cell(15,adjacent_table,14,16);

       mark_cell(16,adjacent_table,11,17);
       mark_cell(17,adjacent_table,14,18);
       mark_cell(18,adjacent_table,12,19);

       mark_cell(19,adjacent_table,14,20);

       mark_cell(20,adjacent_table,13,21);

       mark_cell(21,adjacent_table,14,18);

//    for(int i=0;i<22;i++)
//    {
//        cout<<i<<"   ";
//        for(int j=0;j<15;j++)
//        {
//            cout<<adjacent_table[i][j]<<"|";
//        }
//        cout<<endl;
//    }


}


#endif // PARSER_H
