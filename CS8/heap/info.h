#ifndef INFO_H
#define INFO_H
#include <iostream>
using namespace std;

template <typename T >
struct info{
    T item;
    int priority;
    static int serials; //all new object mutually share this varibale.
    int _serials;

    info();
    info(T i, int p);

    friend ostream& operator <<(ostream& outs, const info<T>& print_me)
    {
        outs<<print_me.item;
        return outs;
    }

    friend bool operator <(const info<T>& lhs, const info<T>& rhs)
    {

        if(lhs.priority==rhs.priority)
        {
            return lhs._serials>rhs._serials?true:false;
        }else
        {
            return rhs.priority>lhs.priority?true:false;
        }

    }


    friend bool operator >(const info<T>& lhs, const info<T>& rhs)
    {
        if(lhs.priority==rhs.priority)
        {
            return lhs._serials>rhs._serials?true:false;
        }else
        {
            return rhs.priority>lhs.priority?true:false;
        }
    }


};
template <typename T >
int info<T>::serials=0;

template <typename T >
info<T>::info()
{

}

template <typename T >
info<T>::info(T i, int p)
{
    item=i;
    priority=p;
    serials++;
    _serials=serials;

}


#endif // INFO_H
