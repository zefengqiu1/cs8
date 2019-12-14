#ifndef LIST_2_H
#define LIST_2_H
#include"node_1.h"

#include <iostream>
#include <iomanip>

using namespace std;

template <class ITEM_TYPE>
class List
{
public:
    class Iterator{
    public:
        friend class List;                              //give access to list to access _ptr
        Iterator()
        {
            _ptr=NULL;
        }                                                 //default ctor
        Iterator(node<ITEM_TYPE>* p)
        {
            _ptr=p;

        }                                                //Point Iterator to where p is pointing to

        operator bool()
        {
            if(_ptr!=NULL)
            {
                return true;
            }else
                return false;
        }

                                                   //casting operator: true if _ptr not NULL
                                                        //      this turned out to be a pain!
        ITEM_TYPE& operator *()
        {
            assert(_ptr!=NULL);
            return _ptr->_item;
        }                                               //dereference operator
        ITEM_TYPE* operator ->()
        {
            assert(_ptr!=NULL);
            ITEM_TYPE* p=&_ptr->_item ;
            return p;
        }                                               //member access operator

        bool is_null()
        {
            if(_ptr==NULL)
            {
                return true;
            }else
                return false;
        }                                                           //true if _ptr is NULL

        friend bool operator !=(const Iterator& left,const Iterator& right)
        {
            return left._ptr!=right._ptr;
        }                                               //true if left != right

        friend bool operator ==(const Iterator& left,const Iterator& right)
        {
            return left._ptr==right._ptr;
        }                                                               //true if left == right

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
        }                                                           //friend operator: it++

    private:
        node<ITEM_TYPE>* _ptr;                          //pointer being encapsulated
    };

    List()                                      //CTOR
    {
        _head_ptr=NULL;
        _size=0;
        _last_node=lastnode(_head_ptr);

    }
                                                                //BIG 3:
    ~List()
    {
        ClearList(_head_ptr);
    }
    List(const List<ITEM_TYPE> &copyThis)
    {
        _head_ptr=CopyList(copyThis._head_ptr);
    }
    List& operator =(const List& RHS)
    {
        if(this==&RHS)
        {
            return *this;
        }
        ClearList(_head_ptr);
        _head_ptr=CopyList(RHS._head_ptr);
        return *this;
    }

    Iterator InsertHead(ITEM_TYPE i) ;                            //insert at the head of list
    Iterator InsertAfter(ITEM_TYPE i, Iterator iMarker);            //insert after marker
    Iterator InsertBefore(ITEM_TYPE i, Iterator iMarker);       //insert before marker
    Iterator InsertSorted(ITEM_TYPE i);                         //insert in a sorted list

    ITEM_TYPE Delete(List<ITEM_TYPE>::Iterator iMarker);        //delete node pointed to by marker
    void Print() const;
    Iterator Search(const ITEM_TYPE &key);                      //return Iterator to node [key]
    Iterator Prev(Iterator iMarker);                            //previous node to marker

    ITEM_TYPE& operator[](int index);                           //return item at position index
    Iterator Begin() const;                                     //Iterator to the head node
    Iterator End() const;                                       //Iterator to NULL
    Iterator LastNode() const;                                  //Iterator to the last node
    template <class U>                                          //Note the template arg U
    friend ostream& operator <<(ostream& outs, const List<U>& l)
    {
        //print_list(l.head);
         l.Print();
         return outs;
    }
private:
    node<ITEM_TYPE>* _head_ptr;
    int _size;
    node<ITEM_TYPE>* _last_node;
};


template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::InsertHead(ITEM_TYPE i)
{
    _size++;
    return insert_head(_head_ptr,i);

}

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::InsertAfter(ITEM_TYPE i, Iterator iMarker)
{

    _size++;
    return insert_after(_head_ptr,iMarker._ptr,i);

}

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::InsertBefore(ITEM_TYPE i, Iterator iMarker)
{
    _size++;
    return insert_before(_head_ptr,iMarker._ptr,i);
}

template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::InsertSorted(ITEM_TYPE i)
{
     _size++;
    return insertsorted(_head_ptr,i);
}
template <class ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::Prev(Iterator iMarker)
{
    return prev_node(_head_ptr,iMarker._ptr);
}

template <class ITEM_TYPE>
void List<ITEM_TYPE>::Print() const
{
     print_list(_head_ptr);
}

template <class ITEM_TYPE>
ITEM_TYPE& List<ITEM_TYPE>::operator[](int index)
{
    return At(_head_ptr,index);
}

template <class ITEM_TYPE>
ITEM_TYPE List<ITEM_TYPE>::Delete(List<ITEM_TYPE>::Iterator iMarker)
{

    node<ITEM_TYPE>*current=iMarker._ptr;
    _size--;
    return DeleteNode(_head_ptr,current);

}

template <class ITEM_TYPE>
typename :: List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::Search(const ITEM_TYPE &key)
{
    return  find(_head_ptr,key);

}

template <class ITEM_TYPE>
typename :: List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::Begin() const //Iterator to the head node;
{
    return _head_ptr;
}

template <class ITEM_TYPE>
typename::List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::End()  const
{

    node<ITEM_TYPE>* walker=_head_ptr;
    while(walker!=NULL)
    {
        walker=walker->_next;
    }
    return walker;
}

template <class ITEM_TYPE>
typename :: List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::LastNode() const
{
    return lastnode(_head_ptr);
}
#endif // LIST_2_H
