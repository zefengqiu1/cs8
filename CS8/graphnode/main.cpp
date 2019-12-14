#include <iostream>
#include <set>
#include <limits.h>
#include "../heap/heap.h"
#include "graph.h"
using namespace std;


void test_depth_first();

void test_bread_first();

int main()
{

    test_depth_first();
    test_bread_first();

    graph<int> _g;
    _g.add_vertex(0);
    _g.add_vertex(1);
    _g.add_vertex(2);
    _g.add_vertex(3);
    _g.add_vertex(4);
    _g.add_vertex(5);
    _g.add_edge(0,1,2);
    _g.add_edge(0,5,9);
    _g.add_edge(1,2,8);
    _g.add_edge(1,3,15);
    _g.add_edge(1,5,6);
    _g.add_edge(2,3,1);
    _g.add_edge(4,2,7);
    _g.add_edge(4,3,3);
    _g.add_edge(5,4,3);


  //  int* a;
    shortest_path(_g,0);
//    for(int i=0;i<_g.size();i++)
//    {
//        cout<<a[i]<<"|";
//    }
    return 0;
}

void test_depth_first()
{
    cout<<"dfs"<<endl;
    graph<int> _g;
    _g.add_vertex(0);
    _g.add_vertex(1);
    _g.add_vertex(2);
    _g.add_vertex(3);
    _g.add_edge(0,3,1);
    _g.add_edge(0,1,2);
    _g.add_edge(1,2,3);
    _g.add_edge(3,2,4);
    _g.add_edge(3,1,5);

    depth_first(print_int_line, _g, 0);


}

void test_bread_first()
{
    cout<<"bfs"<<endl;
    graph<int> _g;
    _g.add_vertex(0);
    _g.add_vertex(1);
    _g.add_vertex(2);
    _g.add_vertex(3);
    _g.add_edge(0,3,1);
    _g.add_edge(0,1,2);
    _g.add_edge(1,2,3);
    _g.add_edge(3,2,4);
    _g.add_edge(3,1,5);

    breadth_first(print_int_line, _g, 0);
}



