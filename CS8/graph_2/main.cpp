#include <iostream>
#include <set>

#include "derived_graph.h"
using namespace std;


void Graph();

void inheritance_graph();

int main()
{


    Graph();
    inheritance_graph();

    return 0;
}

void inheritance_graph()
{

    Derive_Graph<int> _g(20);

    _g.add_vertex(0);
    _g.add_vertex(1);
    _g.add_vertex(2);
    _g.add_vertex(3);

    _g.add_edge(0,3,100);
    _g.add_edge(0,1,101);
    _g.add_edge(1,2,102);
    _g.add_edge(3,2,103);
    _g.add_edge(3,1,104);

    cout<<"dfs"<<endl;
     depth_first(print_int_line, _g, 0);
     cout<<endl;
     cout<<"bfs"<<endl;
     breadth_first(print_int_line, _g, 0);
     cout<<"checkpath:";

     if(checkpath(_g,0,2))
     {
         cout<<"reachable"<<endl;
     }else
     {
         cout<<"non-reachable"<<endl;
     }
     cout<<"read_edge_label"<<endl;
     cout<<_g.read_edge_label(0,3)<<endl;
     cout<<_g.read_edge_label(0,1)<<endl;
     cout<<_g.read_edge_label(1,2)<<endl;
     cout<<_g.read_edge_label(3,2)<<endl;
     cout<<"delete";
     cout<<_g.remove_edge(0,3)<<endl;

}

void Graph()
{
    graph<int> _g(20);

    _g.add_vertex(0);
    _g.add_vertex(1);
    _g.add_vertex(2);
    _g.add_vertex(3);

    _g.add_edge(0,3);
    _g.add_edge(0,1);
    _g.add_edge(1,2);
    _g.add_edge(3,2);
    _g.add_edge(3,1);

    cout<<"dfs"<<endl;
     depth_first(print_int_line, _g, 0);
     cout<<endl;
     cout<<"bfs"<<endl;
     breadth_first(print_int_line, _g, 0);
     cout<<"checkpath:";

     if(checkpath(_g,1,0))
     {
         cout<<"reachable"<<endl;
     }else
     {
         cout<<"non-reachable"<<endl;
     }

}


