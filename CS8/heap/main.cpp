#include <iostream>
#include <stdlib.h>
#include <random>
#include "vector.h"
#include "heap.h"
#include "pqueue.h"
#include "templatecompare.h"
#include "info.h"
using namespace std;


void vector_test();

void heap_test();

void test_bigger();

void priorityq_test();

int main()
{
  //  cout << "Hello World!" << endl;

   // test_bigger();
      vector_test();
  //  srand(time(nullptr));

  //  heap_test();


//  PQueue<string,Bigger<info<string> > > pq;
//   //  pq.insert("headache",3);//1
//  //   pq.insert("cold",1);//2
//     pq.insert("1",9);//1
//     pq.insert("2",9);//2
//     pq.insert("3",9);//3
//     pq.insert("4",9);//4
//     pq.insert("5",9);//5
//     pq.insert("6",9);//6
//     cout<<pq;

//    while(!pq.is_empty())
//    {
//      cout<<pq.Pop()<<endl;
//    }

  //  priorityq_test();

    return 0;
}


void heap_test()
{
    cout<<"heap test"<<endl;
    Heap<unsigned int,Smaller<int>> _h;
    char ans;
    unsigned int number;
    cout<<"please input your command"<<endl;
    cout<<"r for random number,i for insert, p for pop,x for exit"<<endl;
    cout<<":";cin>>ans;
    while((toupper(ans))!='X')
    {
        switch (toupper(ans)) {
            case 'R':
                number=rand()%999+1;
                _h.insert(number);
                cout<<number<<endl;
                cout<<_h<<endl;
                break;
            case'I':
                cout<<"plase insert your number"<<endl;
                cin>>number;
                _h.insert(number);
                cout<<_h<<endl;
                break;
           case 'P':
                cout<<_h.Pop();
                cout<<_h<<endl;
                break;

        }
        // cout<<"-------------------------------------"<<endl;
         cout<<"please input your command"<<endl;
         cout<<"r for random number,i for insert, p for pop,x for exit"<<endl;
         cout<<":";cin>>ans;

    }

}

void priorityq_test()
{
    cout<<"Priority Test"<<endl;
    PQueue<int,Bigger<info<int> > > pq;
    int i=0;
    char ans;
    unsigned int number;
    cout<<"please input your command"<<endl;
    cout<<"R for random number i for insert, p for pop,x for exit"<<endl;
    cout<<":";cin>>ans;
    while((toupper(ans))!='X')
    {
        switch (toupper(ans)) {
            case 'R':
                number=rand()%999+1;
                pq.insert(number,i);
                cout<<number<<endl;
                cout<<pq<<endl;
                break;
            case'I':
                cout<<"plase insert your number"<<endl;
                cin>>number;
                pq.insert(number,i);
                cout<<pq<<endl;
                break;
           case 'P':
                cout<<pq.Pop();
                cout<<pq<<endl;
                break;

        }
         cout<<"-------------------------------------"<<endl;
         cout<<"please input your command"<<endl;
         cout<<"R for random number, i for insert, p for pop, x for exit"<<endl;
         cout<<":";cin>>ans;

    }
}

void vector_test()
{
    Vector<int> v(100);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    cout<<v;
    v.clear();
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    cout<<v;
//    cout<<v.size()<<endl;
//    cout<<v.capacity()<<endl;
//    v.pop_back();
//      v.pop_back();
//        v.pop_back();
//     cout<<v.size()<<endl;
//     cout<<v.capacity()<<endl;
//     cout<<v;
//     cout<<v.front()<<endl;
//     cout<<v.back()<<endl;
//     cout<<v.isempty()<<endl;
//     cout<<v<<endl;
//     cout<<v.size()<<endl;
//     cout<<v.at(8)<<endl;


}

