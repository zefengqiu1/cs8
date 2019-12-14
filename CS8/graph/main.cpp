#include <iostream>
#include "graph.h"
using namespace std;


//weight and short_path;

void test_depth_first();

void test_bread_first();

int main()
{

   // cout << "Hello World!" << endl;
    test_depth_first();
    test_bread_first();


    return 0;
}

void test_depth_first()
{
    graph<int> _g;
    _g.add_vertex(0);
    _g.add_vertex(1);
    _g.add_vertex(2);
    _g.add_vertex(3);
    _g.add_edge(0,3);
    _g.add_edge(0,1);
    _g.add_edge(1,2);
    _g.add_edge(3,2);
    _g.add_edge(3,1);

    depth_first(print_int_line, _g, 0);


}

void test_bread_first()
{
    graph<int> _g;
    _g.add_vertex(0);
    _g.add_vertex(1);
    _g.add_vertex(2);
    _g.add_vertex(3);
    _g.add_edge(0,3);
    _g.add_edge(0,1);
    _g.add_edge(1,2);
    _g.add_edge(3,2);
    _g.add_edge(3,1);

    breadth_first(print_int_line, _g, 0);
}

//void shortest_path(size_t vertex,int sizeofdistance_array,int edges[][6])
//{
//    int predecessor[sizeofdistance_array];
//    int* distance =new int[sizeofdistance_array];
//     distance[0]=0;
//    for(int i=1;i<sizeofdistance_array;i++)
//    {
//        distance[i]=INT_MAX;
//    }
//    distance[0]=0;
//    set<size_t> allowed_vertex;
//    //initial distance array.
//    set<size_t>::iterator it;
//    int next=0;
//    Heap<int,Smaller<int>> _h;

//   // allowed_vertex.insert(vertex);
//    for(int allowed_size=1;allowed_size<sizeofdistance_array;allowed_size++)
//    {
//        for(int i=0;i<sizeofdistance_array;i++)//find the smallest value in not allowed vertex;
//        {
//            it=allowed_vertex.find(i);
//            if(it!=allowed_vertex.end())//存在跳过
//            {
//                continue;
//            }else
//            {
//                _h.insert(distance[i]);
//            }
//        }
//        int min=_h.Pop();
//        for(int i=0;i<sizeofdistance_array;i++)
//        {
//            if(distance[i]==min)//get min number of index or vertex
//            {
//                next=i;
//            }
//        }
//        //next=_h.Pop();
//        while(!_h.is_empty()) //clear queue;
//        {
//            _h.Pop();
//        }

//        allowed_vertex.insert(next);

//        for (int v = 0; v < sizeofdistance_array; ++v)
//        {
//            it=allowed_vertex.find(v);
//            if ( it==allowed_vertex.end() && edges[next][v]>0)
//              //((v is not an allowed vertex) and (there is an edge from next to v))
//            {
//                int sum = distance[next] +edges[next][v]; //(weight of the edge from next to v);
//                if (sum < distance[v])
//                    distance[v] = sum;
//                    predecessor[v]=next;
//            }
//        }
//    }


//    for(int i=0;i<sizeofdistance_array;i++)
//    {
//        cout<<distance[i]<<"|";
//    }

//    cout<<endl;

//    for(int i=0;i<sizeofdistance_array;i++)
//    {
//        cout<<predecessor[i]<<"|";
//    }

//}

