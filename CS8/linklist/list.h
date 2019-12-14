#ifndef LIST_H
#define LIST_H
#include "linkedlistfunction.h"

template<class T>
class List{

public:
    class Iterator{
    public:
        friend class List;
        Iterator()
        {
            _ptr=nullptr;
        }
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
    List();
    ~List();
    List(const List<T> &other);

   Iterator InsertHead(T i);                                          //insert at the head of list

   Iterator InsertAfter(T i, Iterator iMarker);                                            //insert after marker

   Iterator InsertBefore(T i, Iterator iMarker);                                        //insert before marker

   T Delete(List<T>::Iterator iMarker);                                        //delete node pointed to by marker

   void Print() const;

   T& operator[](int index);
                                                        //return item at position index
   Iterator Begin() const;                                       //Iterator to the head node

   Iterator End() const;                                       //Iterator to NULL

   Iterator LastNode() const;                                                   //Iterator to the last node


    friend ostream& operator <<(ostream& outs,const List& print_me)
    {
        _printlist(print_me._head);
        return outs;
    }

private:

     Node<T>* _head;

};


template<class T>
List<T>::List()
{
    _head=NULL;
}

template<class T>
List<T>::~List<T>()
{
    if(_head!=nullptr)
    delete_all(_head);
}

template<class T>
List<T>::List(const List<T>& other)
{
    _head=nullptr;
    copy_list(other._head._head);
}

template <class T>
typename List<T>::Iterator List<T>::InsertHead(T i)
{
    return  _insert_head(_head,i);
}

template <class T>
typename List<T>::Iterator List<T>::InsertAfter(T i, Iterator iMarker)
{
    return _insert_after(_head,iMarker._ptr,i);
}

template <class T>
typename List<T>::Iterator List<T>::InsertBefore(T i, Iterator iMarker)
{

    Node<T>* p=iMarker._ptr;

    return  _insert_after(_head,p->_pre,i);
}

template <class T>
T List<T>::Delete(List<T>::Iterator iMarker)
{
    Node<T>* deletethis=iMarker._ptr;
    if(deletethis->_pre!=nullptr)
    {
        _head=deletethis->_next;
        T item=deletethis->_item;
        delete deletethis;
        return item;
    }
    deletethis->_pre=deletethis->_next;
    T item=deletethis->_item;
    delete deletethis;
    return item;
}

template <class T>
void List<T>::Print() const
{
     _printlist(_head);
}

template <class T>
T& List<T>::operator[](int index)
{
    return At(_head,index);
}

template <class T>
typename :: List<T>::Iterator List<T>::Begin() const //Iterator to the head node;
{
    return _head;
}

template <class T>
typename::List<T>::Iterator List<T>::End()  const
{
    return nullptr;
}

template <class T>
typename :: List<T>::Iterator List<T>::LastNode() const
{
    return lastnode(_head);
}

#endif // LIST_H
