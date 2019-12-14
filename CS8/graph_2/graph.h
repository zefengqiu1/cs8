#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <set>
#include "../linklist/queue.h"

using namespace std;

template<class Item>
class graph{

public:
    graph(size_t alloc);
    bool** reallocate();
    void copy(bool** des,bool** source,int size);
    void clear(bool**,int size);
    void add_vertex(const Item& item);

    Item& operator [](size_t vertex);
    size_t size() const;
    bool is_edge(size_t source,size_t target) const;
    set<size_t> neighbors(size_t vertex) const;
    Item operator [](size_t vertex) const;

     void add_edge(size_t source,size_t target);
     void remove_edge(size_t source,size_t target);


private:

    size_t many_vertices;
    bool **edges;
    Item *labels;
    size_t allocated;
};


template<class Item>
graph<Item>::graph(size_t alloc)
{
    many_vertices=0;
    labels=new Item[alloc];
    allocated=alloc;
    edges = new bool*[allocated];
    for (int i = 0; i < allocated; ++i)
    {
         edges[i] = new bool[allocated];
    }


    for (int i = 0; i < allocated; ++i)
    {
        for (int j = 0; j < allocated; ++j)
        {
            edges[i][j] = false;
        }

    }
   // cout<<"ah"<<endl;

}

template<class Item>
bool** graph<Item>::reallocate()
{

    int size=allocated*2;
    bool** new_array;
    new_array = new bool*[size];
    for (int i = 0; i < size; ++i)
        new_array[i] = new bool[size];

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            new_array[i][j] = false;

    return new_array;
}

template<class Item>
void graph<Item>::copy(bool** des,bool** source,int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            des[i][j] = source[i][j];
        }

    }


}

template<class Item>
void graph<Item>::clear(bool** edge,int size)
{
    for(int i=0;i<size;i++)
    {
        delete [] edge[i];
    }

    delete [] edge;

    edge=nullptr;

}

template<class Item>
void graph<Item>::add_vertex(const Item& label)
//when adding the vertex, we have col and row length to represent the number of vertex.
//so add one more col and row. set false;
//label is to store the item
{
        size_t new_vertex_number;
        size_t other_number;

        if(size()==allocated)  //reallocated ;
        {

            bool** realloc=reallocate();
            copy(realloc,edges,allocated);
            clear(edges,allocated);
            edges=realloc;
            allocated*=2;
        }
        new_vertex_number = many_vertices;
        ++many_vertices;
        for (other_number = 0; other_number < many_vertices; ++other_number)
        {
        edges[other_number][new_vertex_number] = false;
        edges[new_vertex_number][other_number] = false;
        }
        labels[new_vertex_number] = label;



}


template<class Item>
void graph<Item>::add_edge(size_t source,size_t target)
//this edge give us the direction when adding the edge
//but no weight of edge.
{
    assert(source < size( ));
    assert(target < size( ));
    edges[source][target] = true;
}

template <class Item>
bool graph<Item>::is_edge(std::size_t source, std::size_t target) const
// check whether from source to target.
{
    assert(source < size( ));
    assert(target < size( ));
    return edges[source][target];
}

template <class Item>
Item& graph<Item>::operator [ ] (std::size_t vertex)
{
    assert(vertex < size( ));
    return labels[vertex]; // Returns a reference to the label
}

template <class Item>
Item graph<Item>::operator [ ] (std::size_t vertex) const
{
    assert(vertex < size( ));
    return labels[vertex]; // Returns only a copy of the label
}

template <class Item>
std::set<std::size_t> graph<Item>::neighbors(std::size_t vertex) const
//vertex represent graph node and sit in the row with number.
//for loop that row and see any 1's, 1 means it is my neibour and take that col or node.
{
    std::set<std::size_t> answer;
    std::size_t i;
    assert(vertex < size( ));
    for (i = 0; i < size( ); ++i)
    {
    if (edges[vertex][i])
    answer.insert(i);
    }
    return answer;
}

template <class Item>
void graph<Item>::remove_edge(std::size_t source, std::size_t target)
//get rid of that direction from source to target.
{
    assert(source < size( ));
    assert(target < size( ));
    edges[source][target] = false;
}

template <class Item>
size_t graph<Item>::size() const
//return number of vertices.
{
    return many_vertices;
}

template <class Process, class Item, class SizeType>
void rec_dfs(Process f, graph<Item>& g, SizeType v, bool marked[ ]);

template <class Process, class Item, class SizeType>
void rec_dfs(Process f, graph<Item>& g, SizeType v, bool marked[ ])
{
    std::set<std::size_t> connections = g.neighbors(v);
    std::set<std::size_t>::iterator it;
    marked[v] = true; // Mark vertex v.
    f(g[v]); // Process the label of vertex v with the function f.
    // Traverse all the neighbors, looking for unmarked vertices:
    for (it = connections.begin( ); it != connections.end( ); ++it)
    {
     if (!marked[*it])
     rec_dfs(f, g, *it, marked);
    }
}

template <class Process, class Item, class SizeType>
void depth_first(Process f, graph<Item>& g, SizeType start);
//f is function to print
//g is graph
//v is vertex
template <class Process, class Item, class SizeType>
void depth_first(Process f, graph<Item>& g, SizeType start)
{
    bool marked[g.size()];
    assert(start < g.size( ));
    fill_n(marked, g.size( ), false);//mark array false;
    rec_dfs(f, g, start, marked);
}

template <class Process, class Item, class SizeType>
void breadth_first(Process f, graph<Item>& g, SizeType start);

template <class Process, class Item, class SizeType>
void breadth_first(Process f, graph<Item>& g, SizeType start)
{
    bool marked[g.size()];
    set<std::size_t> connections;
    set<std::size_t>::iterator it;
   // std::queue<std::size_t> vertex_queue;
    Queue<size_t> vertex_queue;
    assert(start < g.size( ));
    fill_n(marked, g.size( ), false);
    marked[start] = true;
    f(g[start]);
    vertex_queue.push(start);
    do{
        connections = g.neighbors(vertex_queue.front( ));
        vertex_queue.pop( );
       // Mark and process the unmarked neighbors, and place them in the queue.
        for (it = connections.begin( ); it != connections.end( ); ++it)
        {
            if (!marked[*it])
            {
                 marked[*it] = true;
                 f(g[*it]);
                 vertex_queue.push(*it);
            }
         }
    }
    while (!vertex_queue.empty( ));
}

void print_int_line(int value);

void print_int_line(int value)
{
    cout << value << endl;
}




template <class Item>
bool checkpath (graph<Item> g,int start,int end);

template <class Item>
bool checkpath(graph<Item> g,int start,int end)
{
    bool marked[g.size()];
    set<std::size_t> connections;
    set<std::size_t>::iterator it;
   // std::queue<std::size_t> vertex_queue;
    Queue<size_t> vertex_queue;
    assert(start < g.size( ));
    fill_n(marked, g.size( ), false);
    marked[start] = true;
  // f(g[start]);
    vertex_queue.push(start);
    do{
        connections = g.neighbors(vertex_queue.front( ));
        vertex_queue.pop( );
       // Mark and process the unmarked neighbors, and place them in the queue.
        for (it = connections.begin( ); it != connections.end( ); ++it)
        {
            if (!marked[*it])
            {
                 marked[*it] = true;
                // f(g[*it]);
                 if(g[*it]==end)
                     return true;
                 vertex_queue.push(*it);
            }
         }
    }
    while (!vertex_queue.empty( ));
    return false;
}





#endif // GRAPH_H
