#include <iostream>
#include "b_tree_function.h"
#include "btree.h"
#include "mmap.h"
#include "map.h"
using namespace std;


void test_insert();

void test_detele();

void test_merge();

void test_gt_le();

void test_split();

void test_btree();

void test_map();

void test_mmap();


void test_bplustree_auto(int tree_size=5000, int how_many=500, bool report=false);
bool test_bplustree_auto(int how_many, bool report=true);

void test_btree_1();

int Random(int lo, int hi);


int main()
{
  //  test_insert();
  //     test_merge();
  //  test_gt_le();
  // test_split();
  //  test_mmap();
  // test_map();

//    MMap<int,string> _mmap;
//   cout<<"test insert"<<endl;
//   _mmap.insert(1,"apple");
//   _mmap.insert(2,"orange");
//   _mmap.insert(3,"banana");
//   MMap<int,string> mmap;
//   cout<<"123"<<endl;
//   mmap=_mmap;
//    cout<<_mmap<<endl;
//   cout<<mmap<<endl;

    test_btree_1();
//    BTree<int> _bt;
//    _bt.insert(10);
//    _bt.insert(20);
//    _bt.insert(30);
//    _bt.insert(40);
//    _bt.insert(50);
//    _bt.insert(60);
//    cout<<_bt;
//    cout<<"after copy"<<endl;
//    BTree<int> b;
//    b=_bt;

//    cout<<b<<endl;

   // test_btree();
    // srand(time(0));

    // test_bplustree_auto(1000,100,false);
    // test_bplustree_auto(200,true);
    return 0;
}


void test_btree_1()
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
      cout<<_map.is_valid()<<endl;



}


void test_mmap()
{
       MMap<int,string> _mmap;
      cout<<"test insert"<<endl;
      _mmap.insert(1,"apple");
      _mmap.insert(2,"orange");
      _mmap.insert(3,"banana");
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
      //cout<<_mmap;
      cout<<"size: "<<_mmap.size()<<endl;
      _mmap.erase(7);
      cout<<"after remove size: "<<_mmap.size()<<endl;
      cout<<"contain 23 ? :"<<_mmap.contains(23)<<endl;
      cout<<"find key 19: "<<_mmap[19]<<endl;
      cout<<"get key 3: "<<_mmap.get(3)<<endl;
      cout<<"get unexsit key 75"<<endl;
      _mmap.get(75);
      cout<<"get vetor size: "<<_mmap.count(23)<<endl;
      cout<<_mmap<<endl;

      cout<<_mmap.is_valid()<<endl;
}





void test_bplustree_auto(int tree_size, int how_many, bool report){
    bool verified = true;
    for (int i = 0; i< how_many; i++){
        if (report){
            cout<<"*********************************************************"<<endl;
            cout<<" T E S T:    "<<i<<endl;
            cout<<"*********************************************************"<<endl;
        }
        if (!test_bplustree_auto(tree_size, report)){
            cout<<"T E S T :   ["<<i<<"]    F A I L E D ! ! !"<<endl;
            verified = false;
            return;
        }

    }
    cout<<"**************************************************************************"<<endl;
    cout<<"**************************************************************************"<<endl;
    cout<<"             E N D     T E S T: "<<how_many<<" tests of "<<tree_size<<" items: ";
    cout<<(verified?"VERIFIED": "VERIFICATION FAILED")<<endl;
    cout<<"**************************************************************************"<<endl;
    cout<<"**************************************************************************"<<endl;

}


int Random(int lo, int hi)
{
    int r = rand()%(hi-lo+1)+lo;

    return r;
}

bool test_bplustree_auto(int how_many, bool report){
    const int MAX = 10000;
    assert(how_many < MAX);
    BTree<int> bpt;
    int a[MAX];
    int original[MAX];
    int deleted_list[MAX];

    int original_size;
    int size;
    int deleted_size = 0;

    //fill a[ ]
    for (int i= 0; i< how_many; i++){
        a[i] = i;
    }
    //shuffle a[ ]: Put this in a function!
    for (int i = 0; i< how_many; i++){
        int from = Random(0, how_many-1);
        int to = Random(0, how_many -1);
        int temp = a[to];
        a[to] = a[from];
        a [from] = temp;
    }
    //copy  a[ ] -> original[ ]:
    copy_array(original, a, original_size,how_many);
    size = how_many;
    original_size = how_many;
    for (int i=0; i<size; i++){
        bpt.insert(a[i]);

    }
    if (report){
        cout<<"========================================================"<<endl;
        cout<<"  "<<endl;
        cout<<"========================================================"<<endl;
        cout<<bpt<<endl<<endl;
    }
    for (int i= 0; i<how_many; i++){
        int r = Random(0, how_many - i - 1);
        if (report){
            cout<<"========================================================"<<endl;
            cout<<bpt<<endl;
            cout<<". . . . . . . . . . . . . . . . . . . . . . . . . . . . "<<endl;
            cout<<"deleted: "; print_array(deleted_list, deleted_size);
            cout<<"   from: "; print_array(original, original_size);
            cout<<endl;
            cout<<"  REMOVING ["<<a[r]<<"]"<<endl;
            cout<<"========================================================"<<endl;
        }
        bpt.remove(a[r]);


        delete_item(a, r, size, deleted_list[deleted_size++]);
        if (!bpt.is_valid()){
            cout<<setw(6)<<i<<" I N V A L I D   T R E E"<<endl;
            cout<<"Original Array: "; print_array(original, original_size);
            cout<<"Deleted Items : "; print_array(deleted_list, deleted_size);
            cout<<endl<<endl<<bpt<<endl<<endl;
            return false;
        }

    }
    if (report) cout<<" V A L I D    T R E E"<<endl;

    return true;
}




void test_btree()
{
    BTree<int> _bt;
    _bt.insert(10);
    _bt.insert(20);
    _bt.insert(30);
    _bt.insert(40);
    _bt.insert(50);
    _bt.insert(60);
    _bt.insert(70);
    cout<<_bt;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    _bt.remove(50);
    cout<<_bt<<endl;
    cout<<_bt.is_valid();

 //  cout<<*_bt.find(30)<<endl;

  // cout<<_bt.contains(70)<<endl;
   //cout<<_bt.contains(40)<<endl;
  // cout<<_bt.get(30)<<endl;
 //  cout<<_bt.get(40)<<endl;
  //  cout<<_bt;
}


void test_split()
{
    int a[6]={10,20,30,40,50};
        int size=5;
    int b[3];
    int size2;
    split(a,size,b,size2);
    print_array(a,size,0);
    print_array(b,size2,0);
}

void test_gt_le()
{
    int a[6]={10,20,30,40,50,60};

    int size=6;
   // ordered_insert(a,size,35);
    print_array(a,size,0);
    cout<<is_le(a,6,10)<<endl;
    cout<<is_gt(a,6,60)<<endl;

}
void test_merge()
{
    int a[6]={10,20,30,40,50,60};

    int size1=6;

    int b[2]={70,80};
        int size2=2;
     merge(a,size1,b,size2);
   //  print_array(a,size1,0);

     int c[6];
     int size3;
     copy_array(c,a,size3,size1);//test copy
     print_array(c,size3,0);
}

void test_insert()
{
    int a[6]={10,20,30,40,50,60};

    int size=6;

    print_array(a,size,0);
    ordered_insert(a,size,35);

    //attach_item(a,size,65);
    cout<<size<<endl;
    print_array(a,size,0);
}
void test_detele()
{
    int a[6]={10,20,30,40,50,60};
    int size=6;

    print_array(a,size,0);
    int item;
   // detach_item(a,size,item);
    delete_item(a,2,size,item);
    cout<<item<<endl;
    cout<<size<<endl;
    print_array(a,size,0);
}

/*
    cout << "Hello World!" << endl;


    int a[6]={10,20,30,40,50,60};
    //cout<<index_of_maximal(a,6)<<endl;

   // cout<<maximal(3,4);
    //cout<<first_ge(a,6,70);
    int size=6;
   // ordered_insert(a,size,35);
    print_array(a,size,0);
    //cout<<size<<endl;

    //attach_item(a,size,65);
    int item;
   // detach_item(a,size,item);
    delete_item(a,2,size,item);
    cout<<item<<endl;
    cout<<size<<endl;
    print_array(a,size,0);
    //cout<<is_le(a,6,10);

*/


//    _map.insert(1,"qiuzefeng");
//    _map.insert(2,"zefengqiu");
//    _map.insert(3,"qiuzefeng");
//    _map.insert(4,"zefengqiu");
//    _map.insert(5,"qiuzefeng");
//    _map.insert(6,"zefengqiu");
//    _map.insert(7,"qiuzefeng");
//    _map.insert(8,"zefengqiu");
//    _map.insert(9,"qiuzefeng");
//    _map.insert(10,"zefengqiu");
