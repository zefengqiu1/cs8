#ifndef DERIVED_GRAPH_H
#define DERIVED_GRAPH_H

#include "graph.h"
using namespace std;
template<class Item>
class Derive_Graph:public graph<Item>
{
public:
    Derive_Graph(size_t alloc);
    void add_edge(size_t source,size_t target,const Item& label);
    Item remove_edge(size_t source,size_t target);
    Item read_edge_label(size_t source,size_t target);
private:
    Item **edge_labels;
};

template<class Item>
Derive_Graph<Item>::Derive_Graph(size_t alloc):graph<Item>(alloc)
{
     //allocate space for edges label;
    edge_labels=new Item*[alloc];
    for(int i=0;i<alloc;i++)
    {
        edge_labels[i] = new Item[alloc];
    }

}


template<class Item>
void Derive_Graph<Item>::add_edge(size_t source,size_t target,const Item& label)
//add edge and label
{
   graph<Item>::add_edge(source,target);
   edge_labels[source][target]=label;

}

template<class Item>
Item Derive_Graph<Item>::remove_edge(std::size_t source, std::size_t target)
//get rid of that direction from source to target.
//also remove label
{
    graph<Item>::remove_edge(source,target);
    //Item* pointer=edge_labels[source][target];
    //delete pointer;
    Item _delete= edge_labels[source][target];
    edge_labels[source][target]=0;
    return _delete;
}

template<class Item>
Item Derive_Graph<Item>::read_edge_label(size_t source,size_t target)
{

   return edge_labels[source][target];
}







#endif // DERIVED_GRAPH_H
