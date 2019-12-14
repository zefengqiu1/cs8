#ifndef MMAP_H
#define MMAP_H
#include <iostream>
#include "../heap/vector.h"
#include "bplustree.h"
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
        MPair<K,V> tmp;
        if(lhs==rhs)
        {
            tmp.value_list=lhs.value_list+rhs.value_list;
        }
        return tmp;
    }

};


template <typename K, typename V>
class MMap
{
public:
       typedef BplusTree<MPair<K, V> > map_base;
       class Iterator{
       public:
           friend class MMap;
           Iterator(typename BplusTree<MPair<K,V>>::Iterator it=nullptr):_it(it){}


           Iterator operator ++(int unused)
           {
              // cout<<*_it<<endl;
               _it++;
              // cout<<*_it<<endl;
               return Iterator(_it);
           }

           Iterator operator ++()
           {
               _it++;
              return Iterator(_it);
           }

           MPair<K, V> operator *()
           {
               return *_it;
           }

           friend bool operator ==(const Iterator& lhs, const Iterator& rhs)
           {
               return lhs._it==rhs._it;
           }
           friend bool operator !=(const Iterator& lhs, const Iterator& rhs)
           {
               return lhs._it!=rhs._it;
           }

       private:
           typename map_base::Iterator _it;

       };


    MMap();

    Iterator lower_bound(const K& key)
    {
        return Iterator(mmap.lower_bound(key));
    }                                        //
                                             // key entry or next if does not
                                             // exist >= entry
    Iterator upper_bound(const K& key)
    {
        return Iterator(mmap.upper_bound(key));
    }

    Iterator begin()
    {
        return Iterator(mmap.begin());
    }
    Iterator end()
    {
        return Iterator(mmap.end());
    }
    Iterator find(const K& key) //==
    {
        return Iterator(mmap._find(key));
    }


    MMap<K,V>& operator =(const MMap<K,V>& RHS)
    {
        if(this==&RHS)
        {
            return *this;
        }else
        {
            mmap=RHS.mmap;
            return *this;
        }
    }

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
    BplusTree<MPair<K, V> > mmap;
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
    assert(contains(key));
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
         // get(k).push_back(v);
          get(k)+=v;
    }else
    {
        //if not contain add new entry.
        mmap.insert(MPair<K,V>(k,v));
        key_count++;
    }
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
