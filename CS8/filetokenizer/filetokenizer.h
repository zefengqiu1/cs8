#ifndef FILETOKENIZER_H
#define FILETOKENIZER_H

#include <fstream>
#include "../string_1/stringtoken.h"


#define MAX_BUFFER 200

class FTokenizer
{
public:

    const int MAX_BLOCK = MAX_BUFFER;

    FTokenizer(char* fname);

    Token next_token(); // return the token when get the token from the file.

    bool more();
    int pos();
    int block_pos();

    friend FTokenizer& operator >> (FTokenizer& f, Token& t)
    {
        if(f.more()){
            t=f.next_token();
        }
        return f;
    }

private:
    bool get_new_block(); //gets the new block from the file
    std::ifstream _f;     //file being tokenized
    STokenizer _stk;     //The STokenizer object to tokenize current block
    int _pos;           //Current position in the file
    int _blockPos;      //Current position in the current block
    bool _more;         //false if last token of the last block
                        //  has been processed and now we are at
                        //  the end of the last block.
};


FTokenizer::FTokenizer(char* fname)
{
   _f.open(fname);
   if(_f.fail())
   {
       cout<<"open file failed"<<endl;
       exit(1);
   }
    _pos=0;
    _blockPos=0;
    get_new_block();
}

Token FTokenizer::next_token()
{
    {
        Token t;
        if(!_stk.done())
        {
           _stk>>t;

        }else if(get_new_block())
        {
             return next_token();
        }

        return t;

    }

}

bool FTokenizer::more()
{
    return _more;
}

int FTokenizer::pos()
{
    return  _pos;
}

int FTokenizer::block_pos()
{
    return _blockPos;
}

bool FTokenizer::get_new_block()
{
    {
        char arr[MAX_BLOCK];
        _f.read(arr,MAX_BLOCK-1);
        arr[MAX_BLOCK-1]=NULL;
        if(_f.gcount()>0)
        {
            _more=true;
             _stk.set_string(arr);
        }else
        {
            _f.close();
            _more=false;
        }

        return _more;
    }
}


#endif // FILETOKENIZER_H
