#include <iostream>
#include "b+_tree_function.h"
#include "bplustree.h"
#include "mmap.h"
#include "map.h"
#include "../linklist/queue.h"
using namespace std;




void test_BplusTree();

void test_map();
void test_mmap();

void test_bplustree_1();

void test_iterator();


void remove_test();

int main()
{


  // test_bplustree_1();


  //  test_map();

 //test_mmap();

  // test_BplusTree();

   // test_iterator();
   remove_test();

    return 0;
}




int Random(int lo, int hi)
{
    int r = rand()%(hi-lo+1)+lo;

    return r;
}

void remove_test()
{
    BplusTree<int> bpt;
    Vector<int> v1;
    for(int i=0;i<100;i++)
    {
        int number=Random(0,500);
        v1.push_back(number);
        bpt.insert(number);
    }
    cout<<bpt<<endl;

    cout<<"number going to delete"<<endl;
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<"|";
    }
    cout<<endl;

    for(int i=0;i<v1.size();i++)
    {
        bpt.remove(v1[i]);
    }
    cout<<bpt<<endl;
}

void test_iterator(){
    const bool debug = false;
    BplusTree<int> bpt;
    for (int i= 0; i<125; i++)
        bpt.insert(Random(0,100));
    cout<<bpt<<endl;


    cout<<"------------------------------------------------------------"<<endl;
    for(BplusTree<int>::Iterator it = bpt.begin();
                                    it!= bpt.end(); ++it){
        if (debug) it.print_Iterator();
        cout<<"["<<*it<<"] ";
        if (debug) cout<<endl;
    }
    cout<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"test ++ operator: "<<endl;
    BplusTree<int>::Iterator it = bpt.begin();
    cout<<"{"<<*(it++)<<"}"<<endl;
    cout<<"{"<<*(it++)<<"}"<<endl;
    for (int i = 60; i<75; i++){
        it = bpt._find(i);
        if (!it.is_null())
            cout<<*it<<" was found."<<endl;
        else
            cout<<i<<" was not found"<<endl;
        }
    cout<<"===================================================================="<<endl;
}


void test_mmap()
{
       MMap<int,string> _mmap;
      cout<<"test insert"<<endl;
      _mmap.insert(1,"apple");
      _mmap.insert(2,"orange");
      _mmap.insert(2,"banana");
      _mmap.insert(4,"apple");
      _mmap.insert(5,"orange");
      _mmap.insert(6,"banana");
      _mmap.insert(7,"apple");
      _mmap.insert(8,"orange");
      _mmap.insert(9,"banana");
      _mmap.insert(23,"apple");
      _mmap.insert(30,"orange");
      _mmap.insert(45,"banana");
      cout<<_mmap<<endl;
      MMap<int,string>::Iterator it;
      it=_mmap.begin();
      cout<<"<10"<<endl;
      for(it=_mmap.begin();it!=_mmap.lower_bound(10);it++)
      {
          cout<<*it<<endl;
      }

      if(_mmap.is_valid())
      {
          cout<<"is valid mmap"<<endl;
      }else
      {
          cout<<"it is  not valid mmap"<<endl;
      }

}



void test_bplustree_1()
{

    char command;
    int number=0;
    BplusTree<int> _BTree;
    cout<<"Welcome to Binary Search tree !"<<endl;
    srand(time(NULL));
    cout<<"[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase      e[X]it: "<<endl;
           cout<<":"; cin>>command;
            while((toupper(command))!='X')
            {
                 switch (toupper(command)) {
                     case'R':
                         number=rand()%1000+1;
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



void test_BplusTree()
{
    BplusTree<int> _bt;
    _bt.insert(10);
    _bt.insert(20);
    _bt.insert(30);
    _bt.insert(40);
    _bt.insert(3);
    _bt.insert(7);
    _bt.insert(2);
    _bt.insert(1);
    cout<<_bt<<endl;
    if(_bt.is_valid())
    {
        cout<<"it is b+ tree"<<endl;
    }else
    {
        cout<<"not b+ tree"<<endl;
    }


    BplusTree<int>::Iterator it;
    cout<<">9"<<endl;
    for(it=_bt.upper_bound(9);it!=_bt.end();it++)
    {
        cout<<*it<<"|"; //>9

    }
    cout<<endl;
    cout<<">=9"<<endl;
    for(it=_bt.lower_bound(9);it!=_bt.end();it++)
    {
        cout<<*it<<"|"; //>=9

    }
    cout<<endl;

    cout<<">10"<<endl;
    for(it=_bt.upper_bound(10);it!=_bt.end();it++)
    {
        cout<<*it<<"|"; //>10

    }

    cout<<endl;
    cout<<">=10"<<endl;
    for(it=_bt.lower_bound(10);it!=_bt.end();it++)
    {
        cout<<*it<<"|"; //>=10

    }

     cout<<endl;

     cout<<"<29"<<endl;
    for(it=_bt.begin();it!=_bt.lower_bound(29);it++)
    {
        cout<<*it<<"|"; //<29

    }
     cout<<endl;
     cout<<"<=29"<<endl;
    for(it=_bt.begin();it!=_bt.upper_bound(29);it++)
    {
        cout<<*it<<"|"; //<=29

    }
    cout<<endl;
    cout<<"<30"<<endl;
        for(it=_bt.begin();it!=_bt.lower_bound(30);it++)
        {
            cout<<*it<<"|"; //<30

        }
         cout<<endl;
        cout<<"<=30"<<endl;
        for(it=_bt.begin();it!=_bt.upper_bound(30);it++)
        {
            cout<<*it<<"|"; //<=30

        }
         cout<<endl;

     _bt.print_tree2();

}


void test_map()
{
    Map<int,string> _map;
      _map.insert(1,"a");
      _map.insert(2,"b");
      _map.insert(4,"c");
      _map.insert(8,"d");
      _map.insert(11,"e");
      _map.insert(19,"f");
      _map.insert(21,"g");
      _map.insert(35,"h");
      _map.insert(50,"i");
      _map.insert(100,"j");
      cout<<_map;
      cout<<"size: "<<_map.size()<<endl;
      _map.erase(21);
      cout<<"after erase 21 size: "<<_map.size()<<endl;
      cout<<"is contain key 35? :"<<_map.contains(Pair<int,string>(35,"h"))<<endl;
      cout<<"output key 19 with [] operator:"<<_map[19]<<endl;
      cout<<"output key 11 with at function: "<<_map.at(11)<<endl;
      cout<<"output key 8 with get function:"<<_map.get(8)<<endl;
      cout<<"get unexsit key"<<endl;
      _map.get(75);
      cout<<_map<<endl;

}






