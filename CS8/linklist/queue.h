#ifndef QUEUE_H
#define QUEUE_H
#include "linkedlistfunction.h"

template<class T>
class Queue{

public:
    class Iterator
    {
    public:
        Iterator();
        Iterator(Node<T>* p)
        {
            _ptr=p;
        }

        T& operator *()
        {
            assert(_ptr!=NULL);
            return _ptr->_item;
        }

        T* operator->()
        {
            assert(_ptr!=NULL);
            T* p=&_ptr->_item;
            return p;
        }

        bool is_null()
        {
            if(_ptr==nullptr)
                return true;
            else
                return false;
        }

       friend bool operator !=(const Iterator& left,const Iterator& right)
       {
           return left._ptr!=right._ptr;
       }                                               //true if left != right

       friend bool operator ==(const Iterator& left,const Iterator& right)
       {
           return left._ptr==right._ptr;
       }


         Iterator& operator++()
         {
             _ptr=_ptr->_next;
             return *this;
         }                                                   //member operator: ++it; or ++it = new_value

         friend Iterator operator++(Iterator& it,int unused)
         {
             Iterator hold;
             hold=it;
             ++it;
             return hold;
         }

    private:
       Node<T>* _ptr;
    };



        Queue();
        ~Queue();
        Queue(const Queue<T>& other);

        Queue<T> &operator =(const Queue& rhs);

        void push(T item);
        T pop();
        bool empty();
        T front();

        int size()
        {
            return _size;
        }

        friend ostream& operator <<(ostream& outs, const Queue& q){
             _printlist(q._head);
             return outs;
        }

private:
    Node<T>* _head;
    Node<T>* _tail;
    int _size;

};


template<class T>
Queue<T>& Queue<T>::operator=(const Queue& rhs)
{
    if(this==&rhs)
    {
        return *this;
    }else
    {
        _tail=copy_list(rhs._head,_head);
        return *this;
    }
}

template<class T>
Queue<T>::Queue()
{
    _head=nullptr;
    _tail=nullptr;
    _size=0;

}


template<class T>
Queue<T>::Queue(const Queue<T>& other)
{
   _head=nullptr;
   _tail=nullptr;
   _tail=copy_list(other._head,_head);
}


template<class T>
Queue<T>::~Queue<T>()
{
    if(_head!=nullptr)
    {
         delete_all(_head);
    }
    _head=nullptr;
    _tail=nullptr;

}



template<class T>
void Queue<T>::push(T item)
{

   _tail=_insert_after(_head,_tail,item);
   _size++;
}


template<class T>
T Queue<T>::pop() //if empty, need to reset _tail and_head to nullptr;
{
    assert(_head!=nullptr);
    T item=delete_head(_head);
    if(empty()) _tail=_head=nullptr;
   return item;
}

template<class T>
bool Queue<T>::empty()
{
    if(_head==nullptr)
    {
        return true;
    }else
    {
        return false;
    }
}

template<class T>
T Queue<T>::front()
{
    assert(_head!=nullptr);
    return _head->_item;
}

#endif // QUEUE_H
