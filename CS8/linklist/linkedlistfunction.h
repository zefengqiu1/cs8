#ifndef LINKEDLISTFUNCTION_H
#define LINKEDLISTFUNCTION_H
#include <iostream>

using namespace std;

template<class T>
struct Node
{
public:
    Node();
    Node(T item)
    {
        _item=item;
        _next=nullptr;
        _pre=nullptr;
    }

    T _item;
    Node<T>* _next;
    Node<T>* _pre;

    friend ostream& operator <<(ostream& outs,const Node<T> &printMe)
       {
           outs<<"["<<printMe._item<<"]->";
           return outs;
       }
};

//declaration
template <class T>
Node<T>* init_head(Node<T>* &head_ptr);


//deletes all the nodes in the list
template<class T>
void delete_all(Node<T>*&head);


//true if head is NULL, false otherwise.
template <class T>
bool empty(const Node<T>* head);




template<class T>
Node<T>* _insert_head(Node<T>* &head_ptr, T item);




//insert_after: if after is NULL, inserts at head
template <class T>
Node<T>* _insert_after(Node<T>* &head_ptr, Node<T>* after, const T& item);



//makes a copy of the list, returns a pointer to the last node:
template <class T>
Node<T>* copy_list(const Node<T>* head, Node<T>* & cpy);



//delete the node at the head of the list, reuturn the item:
template <class T>
T delete_head(Node<T>* &head_ptr);




template<class T>
void _printlist(Node<T>* head_ptr);


template <class T>
Node<T>* lastnode(Node<T>* head);


template <typename T>
T& At(Node<T>* head, int pos);


//definition

template <class T>
Node<T>* init_head(Node<T>* &head_ptr)
{
    head_ptr=nullptr;
    return head_ptr;
}



//deletes all the nodes in the list
template<class T>
void delete_all(Node<T>*&head)
{
    assert(head!=nullptr);
    Node<T>* deletethis=head;
    Node<T>* deletesoon;
    while(deletethis!=nullptr)
    {
        deletesoon=deletethis->_next;
        delete deletethis;
        deletethis=deletesoon;
    }
    head=nullptr;
}


//true if head is NULL, false otherwise.
template <class T>
bool empty(const Node<T>* head)
{
    if(head==nullptr)
    {
        return true;
    }else
        return false;
}




template<class T>
Node<T>* _insert_head(Node<T>* &head_ptr,T item)
{
    Node<T>*temp=new Node<T>(item);

    if(head_ptr)
    {
        head_ptr->_pre=temp;
    }
    temp->_next=head_ptr;
    head_ptr=temp;

    return temp;
}




//insert_after: if after is NULL, inserts at head
template <class T>
Node<T>* _insert_after(Node<T>* &head_ptr, Node<T>* after, const T& item)
{

    if(after==nullptr)
    {
        return _insert_head(head_ptr,item);
    }else if(after->_next!=nullptr)
    {
        Node<T>* newnode=new Node<T>(item);
        newnode->_next=after->_next;
        Node<T>* temp=after->_next;
        temp->_pre=newnode;
        newnode->_pre=after;
        after->_next=newnode;
        return newnode;
    }else
    {
        Node<T>* newnode=new Node<T>(item);
        after->_next=newnode;
        newnode->_pre=after;
        return newnode;
    }


}



//makes a copy of the list, returns a pointer to the last node:
template <class T>
Node<T>* copy_list(const Node<T>* head, Node<T>* & cpy)
{
    const Node<T>* walker=head;
    Node<T>* pos=cpy;
    while(walker!=nullptr)
    {
        T item=walker->_item;
        pos=_insert_after(cpy,pos,item);
        walker=walker->_next;
    }
    return pos;
}




template <class T>
T delete_head(Node<T>* &head_ptr)
{
        assert(head_ptr!=nullptr);  //if nullptr so cant delete
        if(head_ptr!=nullptr && head_ptr->_next!=nullptr)
        {
            Node<T>* deletethis=head_ptr;
            T item=deletethis->_item;
            //delete deletethis;
            Node<T>* temp=deletethis->_next;
            delete deletethis;
            head_ptr=temp;
            temp->_pre=nullptr;
            return item;
        }else
        {
            Node<T>* deleltethis=head_ptr;
            T item=deleltethis->_item;
            delete deleltethis;
            head_ptr=nullptr;
            return item;
        }

}

template<class T>
void _printlist(Node<T>* head_ptr)
{
    cout<<"H->";
    Node<T>* walker=head_ptr;
  while(walker!=nullptr)
  {
      cout<<*walker<<" ";
      walker=walker->_next;
  }
  cout<<"|||";
}


template <class T>
Node<T>* lastnode(Node<T>* head)
{
    Node<T>* walker=head;
    while(walker!=NULL && walker->_next!=NULL)
    {
        walker=walker->_next;
    }
    return walker;
}


template <typename T>
T& At(Node<T>* head, int pos)
{
    Node<T>*walker=head;
     while(pos>0)
     {
         walker=walker->_next;
         pos--;
     }
     return walker->_item;
}


#endif // LINKEDLISTFUNCTION_H
