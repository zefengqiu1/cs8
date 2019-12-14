#ifndef MMAP_H
#define MMAP_H
#include <iostream>
#include "../heap/vector.h"
#include "btree.h"
//#include <vector>
using namespace std;

template <typename K, typename V>
struct MPair{
    K key;
    Vector<V> value_list;

    //--------------------------------------------------------------------------------
    /*      MPair CTORs:
     *  must have these CTORs:
     *  - default CTOR / CTOR with a key and no value: this will create an empty vector
     *  - CTOR with a key AND a value: pushes the value into the value_list
     *  _ CTOR with a key and a vector of values (to replace value_list)
     */
    //--------------------------------------------------------------------------------
    MPair(const K& k=K())
    {
        key=k;
       // value_list.clear();
        value_list;
    }

    MPair(const K& k, const V& v)
    {
        key=k;
        value_list.push_back(v);
    }
    MPair(const K& k, const Vector<V>& vlist)
    {
        key=k;
        value_list=vlist;
    }
    //--------------------------------------------------------------------------------

    //You'll need to overlod << for your Vector:
    friend ostream& operator <<(ostream& outs, const MPair<K, V>& print_me)
    {
            outs<<print_me.key<<"|";
            outs<<print_me.value_list;
            return outs;
    }

    friend bool operator ==(const MPair<K, V>& lhs, const MPair<K, V>& rhs)
    {
        return lhs.key==rhs.key;
    }
    friend bool operator < (const MPair<K, V>& lhs, const MPair<K, V>& rhs)
    {
        return lhs.key<rhs.key;
    }
    friend bool operator <= (const MPair<K, V>& lhs, const MPair<K, V>& rhs)
    {
        return lhs.key<=rhs.key;
    }
    friend bool operator > (const MPair<K, V>& lhs, const MPair<K, V>& rhs)
    {
        return  lhs.key>rhs.key;
    }

    friend MPair<K, V> operator + (const MPair<K, V>& lhs, const MPair<K, V>& rhs)
    {
        if(lhs==rhs)
        {
            return lhs.value_list+rhs.value_list;
        }
    }

};


template <typename K, typename V>
class MMap
{
public:

    MMap();
    ~MMap()
    {
        mmap.clear_tree();
    }
   // Stack<T>& operator =(const Stack<T>& rhs);
    MMap<K,V>& operator=(const MMap<K,V>& rhs)
    {
        if(this==&rhs)
        {
            return*this;
        }else
        {
            key_count=rhs.key_count;
            mmap=rhs.mmap;
            return *this;
        }

    }
    /*
    Queue<T>& Queue<T>::operator=(const Queue& rhs)
    {
        if(this==&rhs)
        {
            return *this;
        }else
        {
            _tail=copy_list(rhs._head,_head);
            return *this;
        }
    }*/

    /*
    if(this==&rhs)
    {
        return *this;
    }else
    {
        copy_list(rhs._top,_top);
        return *this;
    }

*/
//  Capacity
    int size() const;
    bool empty() const;

//  Element Access
    const Vector<V>& operator[](const K& key) const;
    Vector<V>& operator[](const K& key);

//  Modifiers
    void insert(const K& k, const V& v);
    void erase(const K& key);
    void clear();

//  Operations:
    bool contains(const K& key);
    Vector<V> &get(const K& key);


    int count(const K& key);
    // I have not writtent hese yet, but we will need them:
    //    int count(const K& key);
    //    lower_bound
    //    upper_bound
    //    equal_range:

    bool is_valid(){return mmap.is_valid();}

    friend ostream& operator<<(ostream& outs, const MMap<K, V>& print_me){
        outs<<print_me.mmap;
        return outs;
    }

private:
    BTree<MPair<K, V> > mmap;
    int key_count;
};
template <typename K, typename V>
MMap<K,V>::MMap()
{
    key_count=0;
}

template <typename K, typename V>
int MMap<K,V>::size() const
{
    return key_count;
}

template <typename K, typename V>
bool MMap<K,V>::empty() const
{
    return key_count==0;
}


//  Element Access

template <typename K, typename V>
const Vector<V>& MMap<K,V>:: operator[](const K& key) const
{
       //if not contain would crash the program.
      // return get(key);
    return mmap.get(key).value_list;
}

template <typename K, typename V>
Vector<V>& MMap<K,V>::operator[](const K& key)
{
    //if not contain would add new node
    if(!contains(key))
    {
        key_count++;
    }
     return mmap.get(key).value_list;
}


//  Modifiers
template <typename K, typename V>
void MMap<K,V>::insert(const K& k, const V& v)
{

    if(contains(k))
    {
        //vector add;
          get(k).push_back(v);
        //  get(k)+=v;
    }else
    {
        //if not contain add new entry.
        mmap.insert(MPair<K,V>(k,v));
    }
    key_count++;
}


template <typename K, typename V>
void MMap<K,V>::erase(const K& key)
{
    assert(contains(key));
    mmap.remove(MPair<K,V>(key));
    key_count--;
}

template <typename K, typename V>
void MMap<K,V>::clear()
{
    mmap.clear_tree();
    key_count=0;
}


//  Operations:
template <typename K, typename V>
bool MMap<K,V>::contains(const K &key)
{
   return mmap.contains(MPair<K,V>(key));
}

template <typename K, typename V>
Vector<V>& MMap<K,V>::get(const K& key)
{
    //assert(contains(key));
    //if not contain would add new node
   // return mmap.get(key).value_list;

    if(!contains(key))
    {
        key_count++;
    }
     return mmap.get(key).value_list;

}

template <typename K, typename V>
int MMap<K,V>::count(const K& key)//return size of vector;
{
    return get(key).size();
}



#endif // MMAP_H
