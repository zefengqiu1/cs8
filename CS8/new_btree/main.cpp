#include <iostream>

using namespace std;
#include "btree.h"

void test_bplustree();

int main()
{
    cout << "Hello World!" << endl;
    test_bplustree();

//    BTree<int> _bt;
//    _bt.insert(10);
//    _bt.insert(20);
//    _bt.insert(30);

//    _bt.insert(25);
//    _bt.insert(21);

//    BTree<int> b;
//    b=_bt;
//     cout<<b;

//    _bt.insert(40);
//    _bt.insert(50);
//    _bt.insert(60);


   // _bt.remove(30);

   // _bt.print_tree2();
//    _bt.remove(25);
//     _bt.remove(21);
  //   cout<<_bt.get(70);

   // _bt.remove(20);
   // _bt.remove(10);

//    cout<<endl;
//    cout<<endl;
//    cout<<endl;
//    _bt.remove(50);
//    cout<<_bt<<endl;
//    cout<<_bt.is_valid();
    return 0;
}


void test_bplustree()
{

    char command;
    int number=0;
    BTree<int> _BTree;
    cout<<"Welcome to Binary Search tree !"<<endl;
    srand(time(NULL));

    cout<<"[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it: "<<endl;
           cout<<":"; cin>>command;
            while((toupper(command))!='X')
            {
                 switch (toupper(command)) {
                     case'R':
                         number=rand()%100+1;
                         cout<<"R:"; cout<<number;
                         _BTree.insert(number);
                         cout<<_BTree;
                         break;
                     case'I':
                         cout<<"I:"; cin>>number;
                         _BTree.insert(number);
                         cout<<_BTree;
                         break;
                     case'C':
                         cout<<"C: clear"<<endl;
                         _BTree.clear_tree();
                         cout<<_BTree;
                         break;

                     case'E':
                         cout<<"E:"; cin>>number;
                         _BTree.remove(number);
                         cout<<_BTree;
                         break;
                     case'S':
                         cout<<"S:"; cin>>number;
                         int* pointer=_BTree.find(number);
                        // tree_node<int>* found=nullptr;
                         if(pointer!=nullptr)
                         {
                             cout<<"found!"<<*pointer<<endl;
                         }else
                         {
                             cout<<"not found!"<<endl;
                         }
                         cout<<_BTree;
                         break;

                 }
                 cout<<"-------------------------------------"<<endl;
                 cout<<"[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:  "<<endl;
                 cout<<":"; cin>>command;
            }
}
