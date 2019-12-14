#include <iostream>
#include "btree.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    BTree<int> b;
    b.insert(10);
    b.insert(20);
    b.insert(30);
    b.insert(40);
    b.insert(50);
    b.insert(60);
    b.insert(70);
    b.insert(80);

    cout<<b<<endl;
    cout<<"after clear"<<endl;
    b.clear_tree();
   // b.clear_tree();
   // cout<<b;

//    BTree<int> c;
//    c.copy_tree(b);
//    cout<<c<<endl;
//    cout<<"123"<<endl;

    return 0;
}
