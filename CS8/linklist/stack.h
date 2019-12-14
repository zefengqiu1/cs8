#ifndef STACK_H
#define STACK_H
#include "list.h"

template<class T>
class Stack{

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


    Stack();
    ~Stack();
    Stack(const Stack<T>& other);

    Stack<T>& operator =(const Stack<T>& rhs);


    T pop();
    bool empty();
    T Top();
    void push(const T item);

   template <class U>
   friend ostream& operator <<(ostream& outs, const Stack<U>& s)
   {
       _printlist(s._top);
       return outs;
   }

private:
    Node<T>* _top;
};

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T> &rhs)
{
    if(this==&rhs)
    {
        return *this;
    }else
    {
        copy_list(rhs._top,_top);
        return *this;
    }
}

template<class T>
Stack<T>::Stack()
{
    _top=nullptr;
}

template<class T>
Stack<T>::~Stack<T>()
{
    if(_top!=nullptr)
    {
        delete_all(_top);
    }
    _top=nullptr;

}

template<class T>
Stack<T>::Stack(const Stack<T>& other)
{
    _top=nullptr;
    copy_list(other._top,_top);
}


template<class T>
void Stack<T>::push(const T item)
{
    _top=_insert_head(_top,item);

}


template<class T>
bool Stack<T>::empty()
{
    if(_top==nullptr)
    {
        return true;
    }else
    {
        return false;
    }
}

template<class T>
T Stack<T>::pop()
{
    assert(_top!=nullptr);
    return delete_head(_top);
}

template<class T>
T Stack<T>::Top()
{
    assert(_top!=nullptr);
    T item=_top->_item;
    return item;
}

#endif // STACK_H
