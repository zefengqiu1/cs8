#ifndef HEAP_H
#define HEAP_H
#include"vector.h"
#include "templatecompare.h"
#include <algorithm>
#include <iomanip>
template<typename T, typename Compare=Bigger<T> >
class Heap{

public:
       Heap();
       void insert(const T& insert_me);
       T Pop();
       bool is_empty() const;
       int size() const;
       int capacity() const;
       friend ostream& operator << (ostream& outs, const Heap<T,Compare>& print_me)
       {
           print_me.print_tree(0,0,outs);
           return outs;
       }

private:
        void print_tree(ostream& outs = cout) const;
        void print_tree(unsigned int root, int level = 0, ostream& outs = cout) const;
         bool is_leaf(unsigned int i) const;
         unsigned int parent_index(unsigned int i) const;
         unsigned int left_child_index(unsigned int i)const;
         unsigned int right_child_index(unsigned int i) const;
         unsigned int big_child_index(unsigned int i) const;
         void swap_with_parent(unsigned int i);
         Vector<T> _v;
         Compare cmp;
};


template<typename T, typename Compare>
void Heap<T,Compare>::print_tree(ostream& outs) const
{
    outs<<_v;
}


template<typename T, typename Compare>
void Heap<T,Compare>::print_tree(unsigned int root, int level, ostream& outs) const
{
           if(root<_v.size())
           {
               print_tree(right_child_index(root),level+1,outs);
               outs<<setw(4*level)<<"["<<_v[root]<<"]";
               print_tree(left_child_index(root),level+1,outs);
           }

           outs<<endl;
}


template<typename T, typename Compare >
Heap<T,Compare>::Heap()
{

}

template<typename T, typename Compare >
void Heap<T,Compare>::insert(const T& insert_me)
//every time has new insert, use while loop to check the parent_node,if bigger then swap
{
    _v.push_back(insert_me);
    int i=_v.size()-1;

    while(cmp(_v[parent_index(i)],_v[i]))  //parent node greater or smaller than child swap when insert.
          //_v[parent_index(i)]<_v[i])
    {
        swap_with_parent(i);
        i=parent_index(i);
    }
}


template<typename T, typename Compare >
T Heap<T,Compare>::Pop()  // put the last to the top and delete the last, then check and ready to swap
{
    assert(!_v.isempty());
    T max=_v[0];
    T last=_v.back();
    _v[0]=last;
    _v.pop_back();
    if(_v.isempty())
    {
        return max;
    }else
    {
        int i=0;
        while(big_child_index(i)>=0 && _v.size()>big_child_index(i) && cmp(_v[i] ,_v[big_child_index(i)] ) )
        {
           int index=big_child_index(i);
           swap_with_parent(index);
           i=index;
        }
     }
        return max;

}

template<typename T, typename Compare >
bool Heap<T,Compare>::is_empty() const
{
    return _v.isempty();
}

template<typename T, typename Compare >
int Heap<T,Compare>::size() const
{
    return _v.size();
}

template<typename T, typename Compare >
int Heap<T,Compare>::capacity() const
{
   return _v.capacity();
}



template<typename T, typename Compare >
bool Heap<T,Compare>::is_leaf(unsigned int i) const
{
    if(left_child_index(i)!=-1&&right_child_index(i)!=-1) //check whether a leaf
    {
        return false;
    }else
    {
        return true;
    }

}

template<typename T, typename Compare >
unsigned int Heap<T,Compare>::parent_index(unsigned int i) const
{   //get parent node index,edge case when only one parent exsit.
    assert(!(_v.size()<=i) && !(i<0));
    if(i==0) return 0;
    return (i-1)/2;
}

template<typename T, typename Compare >
unsigned int Heap<T,Compare>::left_child_index(unsigned int i) const
{   //edge case left_child index cannot over the array size, pass out -1 means outofbound no left node.
    assert(!(_v.size()<=i) && !(i<0));
    return 2*i+1<_v.size()?2*i+1:-1;

}

template<typename T, typename Compare >
unsigned int Heap<T,Compare>::right_child_index(unsigned int i) const
{
    //edge case right_child index cannot over the array size, pass out -1 means outofbound no right node.
    assert(!(_v.size()<=i) &&!(i<0));
    return 2*i+2<_v.size()?2*i+2:-1;
}

template<typename T, typename Compare >
unsigned int Heap<T,Compare>::big_child_index(unsigned int i) const
{
    //compare both left node and right node return the index with greater/less one.
    unsigned int left=left_child_index(i);
    unsigned int right=right_child_index(i);
    if(!is_leaf(i))
    {
        return cmp(_v[left],_v[right])?right:left;
    }else if(left==-1)
    {
        return right;
    }else if(right==-1)
    {
        return left;
    }else
        return -1;

}

template<typename T, typename Compare >
void Heap<T,Compare>::swap_with_parent(unsigned int i)
{
     //swap with parent
     T temp=_v[parent_index(i)];
    _v[parent_index(i)]=_v[i];
    _v[i]=temp;
}

#endif // HEAP_H
