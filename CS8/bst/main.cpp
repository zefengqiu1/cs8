#include <iostream>
#include <stdlib.h>
#include "bst_function.h"
#include "bst_class.h"
using namespace std;


void test_insert_and_print();

void test_remove_max();

void test_search();

void test_erase();

void test_tree_from_sorted_list();

void test_height_update();

void test_tree_copy();

void test_bst_class();

int main()
{

   // test_insert_and_print();
   // test_search();

   // test_remove_max();
   // test_erase();

   // test_tree_from_sorted_list();

    //test_height_update();

      test_bst_class();
    return 0;
}

void test_bst_class()
{
       char command;
       int number=0;
       BST<int> _bst;
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
                            _bst.insert(number);
                            cout<<_bst;
                            break;
                        case'I':
                            cout<<"I:"; cin>>number;
                            _bst.insert(number);
                            cout<<_bst;
                            break;
                        case'C':
                            cout<<"C: clear"<<endl;
                            _bst.clear();
                            cout<<_bst;
                            break;

                        case'E':
                            cout<<"E:"; cin>>number;
                            _bst.erase(number);
                            cout<<_bst;
                            break;
                        case'S':
                            cout<<"S:"; cin>>number;
                            tree_node<int>* found=nullptr;
                            if(_bst.search(number,found))
                            {
                                cout<<"found!"<<found->_item<<endl;
                            }else
                            {
                                cout<<"not found!"<<endl;
                            }
                            cout<<_bst;
                            break;

                    }
                    cout<<"-------------------------------------"<<endl;
                    cout<<"[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:  "<<endl;
                    cout<<":"; cin>>command;
               }

}




void test_height_update()
{
    tree_node<int>* root_pointer=new tree_node<int>(50);
    tree_insert(root_pointer,25);
    tree_insert(root_pointer,75);
    tree_insert(root_pointer,15);
    tree_insert(root_pointer,65);
    tree_insert(root_pointer,80);
    tree_print_debug(root_pointer,0,cout);
    int max=0;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"after remove max"<<endl;
    tree_remove_max(root_pointer,max);
    tree_print_debug(root_pointer,0,cout);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"after erase 75"<<endl;
    tree_erase(root_pointer,75);
    tree_print_debug(root_pointer,0,cout);

    tree_insert(root_pointer,80);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"after insert"<<endl;
    tree_print_debug(root_pointer,0,cout);

}




void test_insert_and_print()
{
    tree_node<int>* root_pointer=new tree_node<int>(50);
    tree_insert(root_pointer,25);
    tree_insert(root_pointer,75);
    tree_insert(root_pointer,15);
    tree_insert(root_pointer,65);
    tree_insert(root_pointer,80);
    tree_print(root_pointer,0,cout);
}


void test_search()
{
    tree_node<int>* root_pointer=new tree_node<int>(50);

    tree_insert(root_pointer,25);
    tree_insert(root_pointer,75);
    tree_insert(root_pointer,15);
    tree_insert(root_pointer,65);
    tree_insert(root_pointer,80);
    tree_print(root_pointer,0,cout);
    cout<<"the number program searched is 25"<<endl;
    cout<<"the output is "<<tree_search(root_pointer,25)->_item<<endl;
}

void test_remove_max()
{

    tree_node<int>* root_pointer=new tree_node<int>(50);

    tree_insert(root_pointer,25);
    tree_insert(root_pointer,75);
    tree_insert(root_pointer,15);
    tree_insert(root_pointer,65);
    tree_insert(root_pointer,80);

    tree_print(root_pointer,0,cout);

    int max=0;
    tree_remove_max(root_pointer,max);
    cout<<"max number is "<<max<<endl;
    cout<<"after remove_max()"<<endl;
    tree_print(root_pointer,0,cout);

}

void test_erase()
{
    tree_node<int>* root_pointer=new tree_node<int>(50);

    tree_insert(root_pointer,25);
    tree_insert(root_pointer,75);
    tree_insert(root_pointer,15);
    tree_insert(root_pointer,65);
    tree_insert(root_pointer,80);
   tree_print(root_pointer,0,cout);
   tree_erase(root_pointer,25);
   cout<<"the number program erase is 25"<<endl;
   cout<<endl;
   cout<<"after erase()"<<endl;

    tree_print(root_pointer,0,cout);
}



void test_tree_from_sorted_list()
{
    int a[]={3,4,5,6,7,8,9};
    tree_node<int>*root1 = nullptr;
    root1= tree_from_sorted_list(a,7);
    tree_print(root1,0,cout);
}


void test_tree_copy()
{
    tree_node<int>* root_pointer=new tree_node<int>(50);
    tree_insert(root_pointer,25);
    tree_insert(root_pointer,75);
    tree_insert(root_pointer,15);
    tree_insert(root_pointer,65);
    tree_insert(root_pointer,80);
    tree_print(root_pointer,0,cout);

    tree_node<int>* secondtree=nullptr;
    secondtree=tree_copy(root_pointer);
    cout<<"after copy"<<endl;
    tree_print(secondtree,0,cout);
}


