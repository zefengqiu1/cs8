#include <iostream>
#include <iomanip>

#include "stringtoken.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    char s[] = "it was the night of october = 17th.\", pi was still 3.14.";
    char b[] ="insert into employee values \"Van     Gogh\",	\"Jim Bob\", 		\"Phys Ed\"";
    STokenizer stk(b);
    Token t;
    while(!stk.done()){
        stk>>t;
        cout<<setw(10)<<t.type_string()<<setw(10)<<t<<endl;
      //  cout<<t<<endl;
        t = Token();
    }

   // cout<<"\"";
    return 0;
}
