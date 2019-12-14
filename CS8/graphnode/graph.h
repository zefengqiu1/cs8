#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <set>
#include <limits.h>
#include "../heap/heap.h"
#include "../linklist/queue.h"

using namespace std;

template<class Item>
class graph{
public:
    static const size_t MAXIMUM;
    graph();
    void add_vertex(const Item& item);
    void add_edge(size_t source,size_t target,int weight);
    void remove_edge(size_t source,size_t target);
    Item& operator [](size_t vertex);
    size_t size() const;
    bool is_edge(size_t source,size_t target) const;
    set<size_t> neighbors(size_t vertex) const;
    Item operator [](size_t vertex) const;
    void shortest_path(size_t vertex,int sizeofdistance_array);
    int read_weight(size_t source,size_t target) const;

private:
   // bool edges[MAXIMUM][MAXIMUM];

    int edges[MAXIMUM][MAXIMUM];
    Item labels[MAXIMUM];
    size_t many_vertices;

};

template <class Item>
const size_t graph<Item>::MAXIMUM=20;

template<class Item>
graph<Item>::graph()
{
    many_vertices=0;
    for(int i=0;i<MAXIMUM;i++)
        for(int j=0;j<MAXIMUM;j++)
            edges[i][j]=INT_MAX; //SET infinited
}


template<class Item>
void graph<Item>::add_vertex(const Item& label)
//when adding the vertex, we have col and row length to represent the number of vertex.
//so add one more col and row. set false;
//label is to store the item
{
    std::size_t new_vertex_number;
    std::size_t other_number;
    assert(size( ) < MAXIMUM);
    new_vertex_number = many_vertices;
    ++many_vertices;
    for (other_number = 0; other_number < many_vertices; ++other_number)
    {
    edges[other_number][new_vertex_number] = INT_MAX;
    edges[new_vertex_number][other_number] = INT_MAX;
    }
    labels[new_vertex_number] = label;
}


template<class Item>
void graph<Item>::add_edge(size_t source,size_t target,int weight )
//this edge give us the direction when adding the edge
//but no weight of edge.
{
    assert(source < size( ));
    assert(target < size( ));
    edges[source][target] = weight;

}

template <class Item>
bool graph<Item>::is_edge(std::size_t source, std::size_t target) const
// check whether from source to target.
{
    assert(source < size( ));
    assert(target < size( ));
    return edges[source][target]!=INT_MAX;
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
    edges[source][target] = INT_MAX;
}

template <class Item>
size_t graph<Item>::size() const
//return number of vertices.
{
    return many_vertices;
}


template<class Item>
int graph<Item>::read_weight(size_t source,size_t target) const
{
    return edges[source][target];
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
    f(g[start]); //can get node number and print
    vertex_queue.push(start);
    do{
        connections = g.neighbors(vertex_queue.front( ));
        vertex_queue.pop( );
       // Mark and process the unmarked neighbors, and place them in the queue.
        for (it = connections.begin( ); it != connections.end( ); ++it)//collection 里面是数字
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






/*
Input. A directed graph with positive integer edge weights and n vertices. One of the vertices,
called start, is specified as the start vertex.
Output. A list of the shortest distances from the start vertex to every other vertex in the graph.
The algorithm uses an array of n integers (called distance) and a set of vertices (called
allowed_vertices). The variables v, allowed_size, and sum are local integer variables. There
is some special value (∞) that we can place in the distance array to indicate an infinite distance
(which means there is no path).
Step 1. Initialize the distance array to contain all ∞, except distance[start], which is set to 0.
Step 2. Initialize the set of allowed vertices to be the empty set.
Step 3. Compute the complete distance array:

*/

template<class Item>
int* shortest_path(const graph<Item>& g,int vertex);

template<class Item>
int* shortest_path(const graph<Item>& g,int vertex)
{
        int size=g.size();
        int predecessor[size];
        int* distance =new int[size];
         distance[0]=0;
        for(int i=1;i<size;i++)
        {
            distance[i]=INT_MAX;
        }
        distance[0]=0;
        set<size_t> allowed_vertex;
        //initial distance array.
        set<size_t>::iterator it;
        int next=0;
        Heap<int,Smaller<int>> _h;

       // allowed_vertex.insert(vertex);
        for(int allowed_size=1;allowed_size<size;allowed_size++)
        {
            for(int i=0;i<size;i++)//find the smallest value in not allowed vertex;
            {
                it=allowed_vertex.find(i);
                if(it!=allowed_vertex.end())//存在跳过
                {
                    continue;
                }else
                {
                    _h.insert(distance[i]);
                }
            }
            int min=_h.Pop();
            for(int i=0;i<size;i++)
            {
                if(distance[i]==min)//get min number of index or vertex
                {
                    next=i;
                }
            }
            //next=_h.Pop();
            while(!_h.is_empty()) //clear queue heap;
            {
                _h.Pop();
            }

            allowed_vertex.insert(next);

            for (int v = 0; v < size; ++v)
            {
                it=allowed_vertex.find(v);
                if ( it==allowed_vertex.end() && g.read_weight(next,v)!=INT_MAX)
                  //((v is not an allowed vertex) and (there is an edge from next to v))
                {
                    int sum = distance[next] +g.read_weight(next,v); //(weight of the edge from next to v);
                    if (sum < distance[v])
                        distance[v] = sum;
                        predecessor[v]=next;
                }

            }
        }

        cout<<"distance array: ";
        for(int i=0;i<size;i++)
        {
            cout<<distance[i]<<"|";
        }

        cout<<endl;
        cout<<"predecesor: ";
        for(int i=1;i<size;i++)
        {
            cout<<predecessor[i]<<"|";
        }
        cout<<endl;
       // cout<<"shortest path"<<endl;
        int vertex_on_path = 5; // The last vertex on the path
        cout << "shortest path to vertex "<<vertex_on_path << endl; // Print the final vertex.
        while (vertex_on_path != vertex)
        {
        vertex_on_path = predecessor[vertex_on_path];
        cout << vertex_on_path << endl;
        }
}



#endif // GRAPH_H
