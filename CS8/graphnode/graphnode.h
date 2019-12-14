#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include <vector>
using namespace std;

template<class Item>
struct GraphNode{

    Item _data;
    bool is_visited;
    int Weight;
    GraphNode();
    GraphNode(Item data,int weight=0);
    vector<GraphNode> _neighbour;//neighbour with weight


};

template<class Item>
GraphNode<Item>::GraphNode(Item data,int weight)
{
    _data=data;
    is_visited=false;
}



#endif // GRAPHNODE_H
