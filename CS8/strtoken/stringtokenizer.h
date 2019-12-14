#ifndef STokenizer_H
#define STokenizer_H
#include "token.h"
#include "table_function.h"
#include <string>
#define MAX_COLUMNS 256
#define MAX_BUFFER 200
#define MAX_ROWS 30

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
    static int _table[MAX_ROWS][MAX_COLUMNS];
};

#endif // STokenizer_H
