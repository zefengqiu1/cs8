#ifndef PQUEUE_H
#define PQUEUE_H
#include <iostream>
#include "info.h"
#include "heap.h"

using namespace std;

template <typename T,typename Compare=Bigger<T> >
class PQueue
{
public:
    PQueue();

    bool insert(const T& value, int p);
    T Pop();

    bool is_empty() const;
    int size() const;
    void print_tree() const;
    friend ostream& operator <<(ostream& outs, const PQueue<T,Compare>& print_me)
    {
        print_me.print_tree();
        return outs;
    }

private:
    Heap<info<T>,Compare > heap;


};


template <typename T,typename Compare >
PQueue<T,Compare>::PQueue()
{

}


template <typename T,typename Compare >
bool PQueue<T,Compare>::insert(const T& value, int p)
{

    heap.insert(info<T>(value,p));
}

template <typename T,typename Compare >
T PQueue<T,Compare>::Pop()
{

    return  static_cast<info<T>>(heap.Pop()).item;

}

template <typename T,typename Compare >
bool PQueue<T,Compare>::is_empty() const
{
    return heap.is_empty();
}

template <typename T,typename Compare >
int PQueue<T,Compare>::size() const
{
    return heap.size();
}

template <typename T,typename Compare >
void PQueue<T,Compare>::print_tree() const
{
    cout<<heap;
}

#endif // PQUEUE_H
