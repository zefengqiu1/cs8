#ifndef STRINGTOKEN_H
#define STRINGTOKEN_H
#include "token.h"
#include "table_function.h"
#include <iostream>
#include <string>

//const int MAX_COLUMNS=256;
const int  MAX_BUFFER=200;
const int MAX_ROWS=30;

const int MAX_COLUMN=256;

//#define MAX_ROWS 30

class STokenizer
{
public:
    STokenizer();
    STokenizer(char str[]);
    bool done();            //true: there are no more tokens

    //---------------
    //extract one token (very similar to the way cin >> works)
    friend STokenizer& operator >> (STokenizer& s, Token& t)
    {
            string str;
        switch (s.get_token(0,str)) {
            case 1:
                t=Token(str,1);
                break;
            case 2:
             t=Token(str,2);
                break;
            case 3:
                 t=Token(str,3);
                break;
            case 4:
                 t=Token(str,4);
                 break;
            case 7:
                 t=Token(str,7);
                break;
            default:
                 t=Token();
                 s._pos+=1;
                break;

        }
        return s;
    }

    //set a new string as the input string
    void set_string(char str[]);

private:
    //create table for all the tokens we will recognize
    //                      (e.g. doubles, words, etc.)
    void make_table(int _table[][MAX_COLUMNS]);

    //extract the longest string that match
    //     one of the acceptable token types
    int get_token(int start_state, string& token);
    //---------------------------------
    char _buffer[MAX_BUFFER];       //input string
    int _pos;                       //current position in the string
    static int _table[MAX_ROWS][MAX_COLUMN];
};

int STokenizer::_table[MAX_ROWS][MAX_COLUMN];

STokenizer::STokenizer()
{
    make_table(_table);
    _pos=0;
}


STokenizer::STokenizer(char str[])
{
    _pos=0;
    strcpy(_buffer,str);
    make_table(_table);
}

bool STokenizer::done()
{

    if(_pos==strlen(_buffer))
    {
        return true;
    }else
    {
         return false;
    }


}

void STokenizer::set_string(char str[])
{
    _pos=0;
    strcpy(_buffer,str);
}

void STokenizer::make_table(int _table[][MAX_COLUMNS])
{
          init_table(_table);
          const char Punc[]={'.','!',',',':','~','@','#','$','%','(',')','`','-','\"','\"','>','<','=','*'};
          const char Number[]="1234567890";
          const char Word[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
          const char Space[]={' '};
          const char Unknown[]="";

        mark_fail(_table,0);
        mark_success(_table,1);//pun
        mark_success(_table,2);//number
        mark_success(_table,3);//space
        mark_success(_table,4);//alpha
        mark_success(_table,5);//unknown
        mark_fail(_table,6);
        mark_success(_table,7);//number

          mark_cells(0,_table,Punc,1);
          mark_cells(0,_table,Number,2);
          mark_cell(0,_table,' ',3);
          mark_cells(0,_table,Word,4);
          //mark_cells(0,_table,Unknown,5);//unknown

         // mark_cells(1,_table,Punc,1);
           mark_cell(1,_table,'>',1);
           mark_cell(1,_table,'<',1);
           mark_cell(1,_table,'=',1);



          mark_cell(2,_table,'.',6);
          mark_cells(2,_table,Number,2);
          mark_cell(3,_table,' ',3);
          mark_cells(4,_table,Word,4);
          //mark_cells(5,_table,Unknown,5);//unkownn
          //5
          mark_cells(6,_table,Number,7);
          mark_cells(7,_table,Number,7);


          //
//          mark_cell(0,_table,'"',8);
//          mark_cells(8,_table,Word,9);
//          mark_cell(9,_table,' ',10);
//          mark_cells(9,_table,Word,9);

//          mark_cells(10,_table,Word,11);


//         mark_cells(11,_table,Word,11);
//         mark_cell(11,_table,'"',12);

         // mark_cell(11,_table,'"',11);

//          mark_success(_table,8);
//          mark_success(_table,9);
//          mark_success(_table,10);
    //      mark_success(_table,12);


//          for(int i=0;i<9;i++)
//          {
//              for(int j=0;j<256;j++)
//              {
//                  cout<<_table[i][j]<<"|";
//              }
//              cout<<endl;
//          }

}

int STokenizer::get_token(int start_state, string& token)
{
    int index=_pos;
    int start=_pos;
    bool success=false;
    int current_state=0;
    while(start_state!=-1 && index <strlen(_buffer))
    {
        if(_buffer[index]<0||_buffer[index]>128)
        {
            index++;
            break;
        }
        start_state=_table[start_state][_buffer[index]];
        if(start_state==-1)
        {
            break;
        }
        if(_table[start_state][0]==1)
        {
            success=true;
            current_state=start_state;
            index++;
            _pos=index;
        }else
        {
            index++;
        }

    }


    if(success)
    {
        for(int i=start;i<_pos;i++)
        {
            token+=_buffer[i];
        }

    }
    return current_state;

}




#endif // STRINGTOKEN_H
