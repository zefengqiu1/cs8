#ifndef RECORD_H
#define RECORD_H
#include <iostream>

using namespace std;

template<typename T>
struct record
{
    int key;
    T _value;



    record(int k=0, T v=0):key(k), _value(v)
    {

    }

    friend bool operator ==(const record<T>& left, const record<T>& right)
    {
        return left.key==right.key;
    }

    friend ostream& operator <<(ostream& outs, const record<T>& print_me)
    {


        outs<<print_me.key<<":"<<print_me._value;

        return outs;
    }

};

#endif // RECORD_H
