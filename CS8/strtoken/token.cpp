#include "token.h"

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
