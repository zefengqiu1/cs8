#include <iostream>
#include <stdlib.h>
#include "avl_function.h"
#include "avl_class.h"
using namespace std;


template<typename T>
int isavl(tree_node<T>* root);
//output will be the actual height of tree
//if output is negative number means is not avl tree otherwise is avl tree.


void isavl_test();
//check the function isavl();

void test_avl_class();


int main()
{

   // test_insert_and_print();
   // test_search();

   // test_remove_max();
   // test_erase();

   // test_tree_from_sorted_list();

   // test_height_update();

    test_avl_class();
  //  isavl_test();

    return 0;
}



void isavl_test()
{
    tree_node<int>* root_pointer=new tree_node<int>(50);
    tree_insert(root_pointer,25);
    tree_insert(root_pointer,75);
    tree_insert(root_pointer,15);
    tree_insert(root_pointer,65);
    tree_insert(root_pointer,80);
    tree_print_debug(root_pointer);


    int height=isavl(root_pointer);
    if(height<0)
    {
        cout<<"not avl tree"<<endl;
    }else
    {
        cout<<"the height is "<<height<<endl;
    }



    tree_node<int>* root2=new tree_node<int>(30);
    tree_insert(root2,40);
    tree_insert(root2,50);
    tree_insert(root2,60);
    tree_insert(root2,35);
    tree_insert(root2,25);
    tree_print_debug(root2);
    int height1=isavl(root2);
    if(height1<0)
    {
        cout<<"not avl tree"<<endl;
    }else
    {
        cout<<"the height is "<<height1<<endl;
    }


}




template<typename T>
int isavl(tree_node<T>* root)
{
    if(root==nullptr) return -1;
    int left=isavl(root->_left);
    int right=isavl(root->_right);
    if(abs(right-left)>=2)
    {
        return -10; //or throw exception
    }else
    {
         return max(left,right)+1;
    }
}


void test_avl_class()
{
       char command;
       int number=0;
       avl<int> _avl;
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
                            _avl.insert(number);
                            cout<<_avl;
                            break;
                        case'I':
                            cout<<"I:"; cin>>number;
                            _avl.insert(number);
                            cout<<_avl;
                            break;
                        case'C':
                            cout<<"C: clear"<<endl;
                            _avl.clear();
                            cout<<_avl;
                            break;

                        case'E':
                            cout<<"E:"; cin>>number;
                            _avl.erase(number);
                            cout<<_avl;
                            break;
                        case'S':
                            cout<<"S:"; cin>>number;
                            tree_node<int>* found=nullptr;
                            if(_avl.search(number,found))
                            {
                                cout<<"found!"<<found->_item<<endl;
                            }else
                            {
                                cout<<"not found!"<<endl;
                            }
                            cout<<_avl;
                            break;

                    }
                    cout<<"-------------------------------------"<<endl;
                    cout<<"[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it:  "<<endl;
                    cout<<":"; cin>>command;
               }

}







