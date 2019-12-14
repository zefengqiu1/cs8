#ifndef NODE_1_H
#define NODE_1_H
#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
struct node
{
public:
    node();
    node(T item=T(), node<T>* next = NULL):_item(item), _next(next){

       }

    friend ostream& operator <<(ostream& outs,const node<T> &printMe)
    {
        outs<<"["<<printMe._item<<"]->";
        return outs;
    }

    T _item;
    node<T>* _next;
};

template<class T>
node<T>* insert_head(node<T>* &head_ptr, const T& item);

template<class T>
node<T>* insert_after(node<T>* &head_ptr, node<T>* after_this, const T& item);

template <class T>
node<T>* insert_before(node<T>*& head,node<T>* beforeThis,T insertThis);

template<class T>
node<T>* prev_node(node<T>* head_ptr, node<T>* prev_to_this);

template<class T>
void print_list(node<T>* head_ptr, ostream& outs = cout);

template<class T>
node<T>* find(node<T>* head_ptr, const T& key);

template <typename T>
void PrintList_backwards(node<T> *head);

template <typename T>
T DeleteNode(node<T>*&head,node<T>* deleteThis);

template <typename T>
node<T>* CopyList(node<T>* head);

template <class T>
void ClearList(node<T>*& head);

template <class T>
T& At(node<T>* head, int pos);

template <class T>
node<T>* insertsorted(node<T>* &head,const T& item,bool ascending=true);

template <class T>
node<T>* WhereThisGoes(node<T>* head,  T item,bool ascending=true);

template <class T>
node<T>* lastnode(node<T>* head);


//---------------------------------------------------

template <typename T>
T& At(node<T>* head, int pos)
{
    node<T>*walker=head;
     while(pos>0)
     {
         walker=walker->_next;
         pos--;
     }
     return walker->_item;
}

template <typename T>
void ClearList(node<T>*& head)
{
    node<T>*walker=head;
    node<T>* temp;
    while(walker!=NULL)
    {
        temp=walker->_next;
        delete walker;
        walker=temp;
    }
    head=nullptr;
}


template <typename T>
node<T>* CopyList(node<T>* head)
{
    node<T>* newlist=NULL;
    node<T>* temp;
    node<T>* walker=head;
    while(walker!=NULL)
    {
        if(newlist==NULL)
        {
           temp=insert_head(newlist,walker->_item);

        }else
        {
            temp=insert_after(newlist,temp,walker->_item);
        }
        walker=walker->_next;
    }

    return newlist;
}

template <typename T>
T DeleteNode(node<T>*&head,node<T>* deleteThis)
{
    node<T>*previous=prev_node(head,deleteThis);
    if(previous==NULL)
    {
        head=deleteThis->_next;
        T item=deleteThis->_item;
        delete deleteThis;
        return item;
    }
    previous->_next=deleteThis->_next;
    T item=deleteThis->_item;
    delete deleteThis;
    return item;
}



template <typename T>
void PrintList_backwards(node<T> *head)
{
    int count=0;
    node<T>*walker=head;
    while(walker!=NULL)
    {
        count++;
        walker=walker->_next;
    }
    while(count>0)
    {
        cout<<*prev_node(head,walker);
        walker=prev_node(head,walker);
        count--;
    }
    cout<<"H"<<endl;

}


template<class T>
node<T>* insert_head(node<T>* &head_ptr, const T& item){
    //1:
    node<T>* temp = new node<T>(item);
    //2:
    temp->_next = head_ptr;
    //3.
    head_ptr = temp;
    return temp;
}

template<class T>
node<T>* insert_after(node<T>* &head_ptr, node<T>* after_this, const T& item)
{
    assert(after_this!=NULL);
    node<T>* temp= new node<T>(item);
    temp->_next=after_this->_next;
    after_this->_next=temp;
    return temp;
}

template <class T>
node<T>* insert_before(node<T>*& head,node<T>* beforeThis,T insertThis)
{

    if(prev_node(head,beforeThis)==nullptr)
    {
        insert_head(head,insertThis);
        return head;
    }

    node<T>* previous=prev_node(head,beforeThis);
    return insert_after(head,previous,insertThis);


}

template<class T>
node<T>* find(node<T>* head_ptr, const T& key)
{
    node<T>* walker=head_ptr;
    while(walker!=NULL)
    {
        if(walker->_item==key)
        {
            //cout<<walker->_item<<endl;
            return walker;
        }else
            walker=walker->_next;
    }
    return walker;
}

template<class T>
node<T>* prev_node(node<T>* head_ptr, node<T>* prev_to_this)
{
    assert(head_ptr!=NULL);
    node<T>* walker=head_ptr;
    if(prev_to_this==head_ptr)
    {
        return NULL;
    }
    while(walker!=NULL && walker->_next!=prev_to_this)
    {
            walker=walker->_next;
    }
    assert(walker!=NULL);

    return walker;
}

template<class T>
void print_list(node<T>* head_ptr, ostream& outs){
    node<T>* walker = head_ptr;
    outs<<"H->";
    while (walker!=NULL){
        outs<<*walker;
        walker = walker->_next;
    }
    outs<<"|||"<<endl;
}


template <class T>
node<T>* insertsorted(node<T>* &head,const T& item,bool ascending)
{

    if(WhereThisGoes(head,item,ascending)==NULL)
    {
        return insert_head(head,item);
    }else
    {
        node<T>* temp;
        temp=WhereThisGoes(head,item,ascending);
        return insert_after(head,temp,item);
    }

}

template <class T>
node<T>* InsertSorted_and_add(node<T>* &head,T item,bool ascending=true)
{
        node<T>* temp;
        if(find(head,item)==NULL)
        {
            return insertsorted(head,item,ascending);
        }else
        {
            temp=find(head,item);
            temp->_item=temp->_item+item;

        }
        return temp;

}

template <class T>
node<T>* WhereThisGoes(node<T>* head,T item,bool ascending)
{
    if(!ascending)
    {
        node<T>* temp;
        node<T>* walker=head;
        if(head==nullptr||item>head->_item)
        {
            return NULL;
        }
        while(walker!=NULL &&walker->_next!=NULL)
        {
            temp=walker->_next;
            if(walker->_item>item && !(temp->_item > item))
            {
                return walker;
            }
            walker=walker->_next;
        }

        return walker;
    }else
    {
        node<T>* temp;
        node<T>* walker=head;
        if(head == nullptr||item < head->_item)
        {
            return NULL;
        }
        while(walker!=NULL &&walker->_next!=NULL)
        {
            temp=walker->_next;
            if(walker->_item<item && !(temp->_item < item))
            {
                return walker;
            }
            walker=walker->_next;
        }
        return walker;
    }

}


template <class T>
node<T>* lastnode(node<T>* head)
{
    node<T>* walker=head;
    while(walker!=NULL && walker->_next!=NULL)
    {
        walker=walker->_next;
    }
    return walker;
}
#endif // NODE_1_H
