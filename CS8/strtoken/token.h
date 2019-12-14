#ifndef TOKE_H
#define TOKE_H

#include <iostream>
#include <string>
using namespace std;

class Token
{
public:
    Token();
    Token(string str, int type);
    friend ostream& operator <<(ostream& outs, const Token& t)
    {
        cout<<t._token;
        return outs;
    }
    int type();
    string type_string();//look at type return stirng
    string token_str();//

private:
    string _token;
    int _type;
};

#endif // TOKE_H
