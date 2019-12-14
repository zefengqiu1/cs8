#ifndef MAP_H
#define MAP_H
#include "bplustree.h"
#include <iostream>

using namespace std;

template <typename K, typename V>
struct Pair{
    K key;
    V value;

    Pair(const K& k=K(), const V& v=V()):key(k),value(v)
    {

    }
    friend ostream& operator <<(ostream& outs, const Pair<K, V>& print_me)
    {
        outs<<print_me.key<<"|"<<print_me.value;
        return outs;
    }
    friend bool operator ==(const Pair<K, V>& lhs, const Pair<K, V>& rhs)
    {
        return lhs.key==rhs.key;
    }
    friend bool operator < (const Pair<K, V>& lhs, const Pair<K, V>& rhs)
    {
        return lhs.key<rhs.key;
    }
    friend bool operator > (const Pair<K, V>& lhs, const Pair<K, V>& rhs)
    {
        return lhs.key>rhs.key;
    }
    friend bool operator <= (const Pair<K, V>& lhs, const Pair<K, V>& rhs)
    {
        return lhs.key<=rhs.key;
    }

    friend Pair<K, V> operator + (const Pair<K, V>& lhs, const Pair<K, V>& rhs)
    {
        if(lhs==rhs)
        {
           return lhs.value+rhs.value;
        }

    }
};



template <typename K, typename V>
class Map
{
public:

    Map();
//  Iterators
    Map<K,V>& operator =(const Map<K,V>& RHS)
    {
        if(this==&RHS)
        {
            return *this;
        }else
        {
            map=RHS.map;
            return *this;
        }
    }

//  Capacity
    int size() const;
    bool empty() const;

//  Element Access
    V& operator[](const K& key);
    V& at(const K& key);
    const V& at(const K& key) const;


//  Modifiers
    void insert(const K& k, const V& v);
    void erase(const K& key);
    void clear();
    V get(const K& key);

//  Operations:
   // Iterator find(const K& key);
    bool contains(const Pair<K, V>& target);

    // I have not writtent hese yet, but we will need them:
    //    int count(const K& key);
    //    lower_bound
    //    upper_bound
    //    equal_range:

    bool is_valid(){return map.is_valid();}

    friend ostream& operator<<(ostream& outs, const Map<K, V>& print_me){
        outs<<print_me.map<<endl;
        return outs;
    }
private:
    int key_count;
    BplusTree<Pair<K, V> > map;
};

template <typename K, typename V>
Map<K,V>::Map()
{
    key_count=0;

}

template <typename K, typename V>
int Map<K,V>::size() const
{
    return key_count;
}

template <typename K, typename V>
bool Map<K,V>::empty() const
{
    return key_count==0;
}


//  Element Access
template <typename K, typename V>
V& Map<K,V>::operator[](const K& key) //read or update can add new node
{
    //calling the get function which can add new node and not crash the program
    if(contains(key))
    {
        return map.get(Pair<K,V>(key)).value;
    }else
    {
        key_count++;
        return map.get(Pair<K,V>(key)).value;
    }


//    return map.get(Pair<K,V>(key)).value;
//    key_count=map.size();

}
template <typename K, typename V>
V& Map<K,V>::at(const K& key)    //read or update  can add new node
{
     //calling the get function which can add new node and not crash the program

    if(contains(key))
    {
        return map.get(Pair<K,V>(key)).value;
    }else
    {
        key_count++;
        return map.get(Pair<K,V>(key)).value;
    }

}


template <typename K, typename V>
const V& Map<K,V>::at(const K& key) const //read and no change on value and not add new node
{
     assert(contains(key));
    //calling the get function which cannot add new node and crash the program
     return map.get(Pair<K,V>(key)).value;
}



//  Modifiers

template <typename K, typename V>
void Map<K,V>::insert(const K& k, const V& v)
{
    if(contains(k))
    {
        map.insert(Pair<K,V>(k,v));
    }else
    {

        key_count++;
        map.insert(Pair<K,V>(k,v));
    }
}

template <typename K, typename V>
void Map<K,V>::erase(const K& k)
{
    assert(contains(k));
    map.remove(Pair<K,V>(k));
    key_count--;

}

template <typename K, typename V>
void Map<K,V>::clear()
{
    map.clear_tree();
    key_count=0;
}

template <typename K, typename V>
V Map<K,V>::get(const K& key) //only read and add new note but not able to change the value
{
    //assert(contains(Pair<K,V>(key)));
    //calling the get function which can add new node but no value and not crash the program

    if(contains(key))
    {
        return map.get(Pair<K,V>(key)).value;
    }else
    {
        key_count++;
        return map.get(Pair<K,V>(key)).value;
    }

}

template <typename K, typename V>
bool Map<K,V>::contains(const Pair<K, V>& target)
{
    return map.contains(target);
}

#endif // MAP_H
