#include <iostream>
#include "list.h"
#include "linkedlistfunction.h"
#include "stack.h"
#include "queue.h"
using namespace std;


void test_insert_head();
void test_list_insert_head();
void test_insert_after();
void test_delete_head();
void test_delete_all();
void test_copy_list();
void test_stack();
void test_queue();
void test_list_iterator();
void test_1();
void test_2();

int main()
{

    Queue<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    cout<<a.size()<<endl;
    while(!a.empty())
    {
        cout<<
               a.pop()<<endl;

    }
     //test_insert_head();
    // test_list_insert_head();
     //test_stack_push();
     // test_delete_head();
     // test_delete_all();
     //test_copy_list();
    //  test_stack();
    //  cout<<endl;
    //  cout<<endl;
    //  test_queue();
   // test_1();
    //test_2();
    return 0;
}


void test_insert_head()
{
    cout<<"test insert head"<<endl;
    Node<int>* head=nullptr;

    for(int i=0;i<10;i++)
    {

        _insert_head(head,i);
    }

    _printlist(head);
    cout<<endl;
}

void test_list_insert_head()
{
    cout<<"test list insert head"<<endl;
    List<int> l;
    for(int i=0;i<10;i++)
    {
       // l._insert_head(i);
        l.InsertHead(i);
    }
    cout<<l<<endl;


}

void test_insert_after()
{
    cout<<"test insert after"<<endl;
    Node<int>* head=nullptr;

    for(int i=0;i<10;i++)
    {

        _insert_head(head,i);
    }

    _printlist(head);
    cout<<endl;

    Node<int>* walker=head;
    walker=walker->_next;
    _insert_after(head,walker,100);

    _printlist(head);
    cout<<endl;
}


void test_delete_head()
{
    cout<<"test delete head"<<endl;
    Node<int>* head=nullptr;

    for(int i=0;i<10;i++)
    {

        _insert_head(head,i);
    }

    _printlist(head);
    cout<<endl;
    cout<<delete_head(head)<<endl;
    _printlist(head);
    cout<<endl;

}

void test_delete_all()
{
    cout<<"test delete all"<<endl;
    Node<int>* head=nullptr;

    for(int i=0;i<10;i++)
    {

        _insert_head(head,i);
    }

    _printlist(head);
    cout<<endl;

    cout<<"after delete all"<<endl;
    delete_all(head);
    _printlist(head);
    cout<<endl;
}


void test_copy_list()
{
    cout<<"test copy list"<<endl;
    Node<int>* head=nullptr;

    for(int i=0;i<10;i++)
    {

        _insert_head(head,i);
    }

    _printlist(head);
    cout<<endl;

    Node<int>* head1=nullptr;
    cout<<"after copy list"<<endl;
    cout<<copy_list(head,head1)->_item<<endl;
     _printlist(head1);
     cout<<endl;


}

void test_stack()
{
    cout<<"Test Stack"<<endl;
    Stack<int> s;
    for(int i=0;i<=9;i++)
    {
        s.push(i);
    }
    Stack<int> s2(s);
    cout<<"s ";cout<<s<<endl;
    cout<<"s2";cout<<s2<<endl;

    cout<<" after s pop "<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"assign s back to s2"<<endl;
    s=s2;

    cout<<"s ";cout<<s<<endl;
    cout<<"s2";cout<<s2<<endl;




}


void test_queue()
{

    cout<<"Queue Test"<<endl;
    Queue<int> q;
    for(int i=0;i<=9;i++)
    {
        q.push(i);
    }

    Queue<int> q2(q);
    cout<<"q ";cout<<q<<endl;
    cout<<"q2";cout<<q2<<endl;

    cout<<" after q pop "<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;

    cout<<"assign q back to q2"<<endl;
    q=q2;

    cout<<"q ";cout<<q<<endl;
    cout<<"q2";cout<<q2<<endl;

}

void test_list_iterator()
{
      List<int> a;               //instantiate a List object
      List<int>::Iterator it;
      for(int i=0;i<9;i++)
      {
          a.InsertHead(i);

      }
      for (it=a.Begin();it!=a.End();it++){                         //postfix ++
                                              //looping through all the elements of List using the Iterator
              cout<<*it<<"|";
          }
      a.Print();
}

void test_1()
{
    cout<<"Queue Test"<<endl;
    Queue<int> q;
    for(int i=0;i<=9;i++)
    {
        q.push(i);
    }

    Queue<int> q2(q);
    cout<<"q ";cout<<q<<endl;
    cout<<"q2";cout<<q2<<endl;

    cout<<" after q pop "<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
    cout<<"{"<<q.pop()<<"}";cout<<q<<endl;
   // cout<<"{"<<q.pop()<<"}";cout<<q<<endl;


    cout<<q<<endl;
    q.push(1);
    q.push(2);
    cout<<q<<endl;
}

void test_2()
{
    cout<<"Test Stack"<<endl;
    Stack<int> s;
    for(int i=0;i<=9;i++)
    {
        s.push(i);
    }
    Stack<int> s2(s);
    cout<<"s ";cout<<s<<endl;
    cout<<"s2";cout<<s2<<endl;

    cout<<" after s pop "<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
      cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
        cout<<"{"<<s.pop()<<"}";cout<<s<<endl;
    cout<<s<<endl;
    s.push(1);
    s.push(2);
    cout<<s<<endl;
}






