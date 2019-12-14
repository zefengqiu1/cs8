#include <iostream>
#include "stringtokenizer.h"
#include <iomanip>
using namespace std;

int main()
{
    char s[] = "it was the night of october, = 17th. pi was still 3.14.";
    STokenizer stk(s);
    Token t;
    while(!stk.done()){
        stk>>t;
        cout<<setw(10)<<t.type_string()<<setw(10)<<t<<endl;
        t = Token();
    }
    return 0;
}
