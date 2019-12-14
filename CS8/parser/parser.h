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
            return false;
        }

private:

    MMap<string,string> ptree;
    Map<string,int> keywords;

    int adjacent_table[MAX_COLUMNS][MAX_COLUMNS];
    bool flag=false;
    //input_queue hold input
    Queue<Token> input;
    enum keys{ZERO,SELECT,FROM,WHERE,STAR};  //0,1,2

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
   // char s[] = "it was the night of october 17th. pi was still 3.14.";
    STokenizer stk(_buffer);
    Token t;
    while(!stk.done()){
        stk>>t;
        //if(t.type_string())
      //  cout<<t<<endl;
        if(t.type()==4)//means it is string
            input.push(t);
       // cout<<setw(10)<<t.type_string()<<setw(10)<<t<<endl;
        t = Token();
    }
 //   cout<<"queue size is "<<input.size()<<endl;
    get_parse_tree();

    cout<<ptree<<endl;
   // flag=fail();
}

int Parser::get_column(Token t)
{
    if(keywords.contains(t.token_str()))
    {
         return  keywords[t.token_str()];
    }else
    {
        return 6;
    }

}

bool Parser::get_parse_tree()
{
    int state=0;
    while(!input.empty() && state!=-1)
    {
        Token t=input.pop();
         cout<<t<<endl;
       // cout<<get_column(t)<<endl;//1,5,2,5
        state=adjacent_table[state][get_column(t)];
        switch (state) {
            case 1:
                ptree["command"]+=t.token_str();
                break;
            case 2: // field
                ptree["field"]+=t.token_str();
                break;
            case 3:  //star
                ptree["field"]+=t.token_str();
                break;
            case 4://  from
               // ptree["table"]+=t.token_str();
                break;
            case 5:
                ptree["table"]+=t.token_str();
                break;
            case 6:
                ptree["where"]+="yes";
                break;
            case 7:
            case 8:
            case 9:
                ptree["condition"]+=t.token_str();
                break;
            default:
                ptree=MMap<string,string>();
                return false;
        }

    }
    return true;
}

void Parser::build_keyword_list()
{
    //key["select"]=SELECT;
    keywords.insert("select",SELECT);
    keywords.insert("from",keys::FROM);
    keywords.insert("where",WHERE);
    keywords.insert("*",STAR);
    keywords.insert("=",5);

   // keywords.insert("from",AND);

  //  cout<<keys::FROM<<endl;
  //  cout<<keywords<<endl;
}


void Parser::initial_table()
{

    init_table(adjacent_table);
    mark_fail(adjacent_table,0);
    mark_fail(adjacent_table,1);
    mark_fail(adjacent_table,2);
    mark_fail(adjacent_table,3);
    mark_fail(adjacent_table,4);
    mark_fail(adjacent_table,5);
    mark_fail(adjacent_table,6);
    mark_fail(adjacent_table,7);
    mark_fail(adjacent_table,8);
    mark_success(adjacent_table,9);
    //first colunmn finished


       mark_cell(0,adjacent_table,1,1);
      // mark_cell(1,adjacent_table,2,2);

       mark_cell(1,adjacent_table,4,3);
       mark_cell(1,adjacent_table,6,2);

       //
       mark_cell(2,adjacent_table,2,4);
       mark_cell(2,adjacent_table,6,2);
       mark_cell(3,adjacent_table,2,4);

       //
       mark_cell(4,adjacent_table,6,5);
       //
       mark_cell(5,adjacent_table,3,6);
       //
       mark_cell(6,adjacent_table,6,7);
       //
       mark_cell(7,adjacent_table,5,8);
       //
       mark_cell(8,adjacent_table,6,9);
       //
       mark_cell(9,adjacent_table,6,9);
       mark_cell(9,adjacent_table,5,9);

//      mark_cell(2,adjacent_table,6,3);
//     mark_cell(3,adjacent_table,3,4);
//      mark_cell(4,adjacent_table,6,5);
//        mark_cell(5,adjacent_table,5,6);
//        mark_cell(6,adjacent_table,6,7);

//    mark_cell(1,adjacent_table,1,-1);
//    mark_cell(2,adjacent_table,1,-1);
//    mark_cell(3,adjacent_table,1,-1);


//    mark_cell(0,adjacent_table,2,-1);
//    mark_cell(1,adjacent_table,2,-1);
//    mark_cell(2,adjacent_table,2,3);
//    mark_cell(3,adjacent_table,2,-1);

//    mark_cell(0,adjacent_table,5,-1);
//    mark_cell(1,adjacent_table,5,2);
//    mark_cell(2,adjacent_table,5,-1);
//    mark_cell(3,adjacent_table,5,4);

    //mark_cell(0,adjacent_table,1,1);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<7;j++)
        {
            cout<<adjacent_table[i][j]<<"|";
        }
        cout<<endl;
    }


}


#endif // PARSER_H
