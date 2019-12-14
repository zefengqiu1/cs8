#ifndef TOKEN_H
#define TOKEN_H

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


Token::Token()
{
    _type=0;
    _token="";
}

Token::Token(string str,int type)
{
    _token=str;
    _type=type;
}

int Token::type()
{
    return _type;
}

string Token::type_string()
{
    switch (_type) {
    case 1:
        return "PUNC!~";
    case 2:
        return "NUMBER!~";
    case 3:
        return"SPACE!~";
    case 4:
        return"ALPHA";
    case 7:
        return "NUMBER!~";
    default:
        return "UNKNOWN!~";

    }
}

string Token::token_str()
{
    return _token;
}

#endif // TOKEN_H
