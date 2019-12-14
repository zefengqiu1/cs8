#ifndef CHAINED_HASH_H
#define CHAINED_HASH_H
#include <iostream>
#include <cstdlib>
#include <cassert>
#include "list_2.h"

using namespace std;

template <class RecordType>
class chained_hash
{
public:
    // MEMBER CONSTANT -- See Appendix E if this fails to compile.
    static const size_t CAPACITY = 20;

    // CONSTRUCTOR
    chained_hash( );


    // MODIFICATION MEMBER FUNCTIONS
    void insert(const RecordType& entry);

    void remove(int key);

    // CONSTANT MEMBER FUNCTIONS
    bool is_present(int key) const;

    bool find(int key, RecordType& result) const; //check find or not.

    size_t size( ) const { return used; }

    friend ostream& operator <<(ostream& outs, const chained_hash<RecordType>& p){
            for(size_t i=0;i<p.CAPACITY;i++)
            {
                outs<<" ["<<i<<"] ";
                outs<<p.data[i];
                outs<<endl;
            }
            return outs;
     }

private:

    // MEMBER VARIABLES
    List<RecordType> data[CAPACITY];
    size_t used;

    // HELPER FUNCTIONS
    size_t hash(int key) const;

    typename List<RecordType>::Iterator find_node(int key) const //iterator to check whether exist and return it
    {
        int index=hash(key);
        typename List<RecordType>::Iterator i;
        for (i = data[index].Begin(); i != data[index].End(); i++) {
           if ((*i).key == key)
             return i;
         }

        return nullptr;
    }//find this key in the table

};

template <class RecordType>
chained_hash<RecordType>::chained_hash()
{
    used=0;
}

template <class RecordType>
void chained_hash<RecordType>::insert(const RecordType& entry)
{
    if(is_present(entry.key))//check present? if yes,update, no add
    {
        remove(entry.key);
        insert(entry);
    }else
    {
        size_t index=hash(entry.key);
        data[index].InsertHead(entry);
        used++;
    }

}

template <class RecordType>
void chained_hash<RecordType>::remove(int key)
{
    int index=hash(key);
    if(find_node(key))
    {
        data[index].Delete(find_node(key));
        used--;
    }

}

template <class RecordType>
bool chained_hash<RecordType>::is_present(int key) const
{

    bool found=false;
    assert(key >= 0);
    if(find_node(key))
    {
        found=true;
        return found;
    }
    return found;

}

template <class RecordType>
bool chained_hash<RecordType>::find(int key, RecordType& result) const
{

    bool found=false;
    assert(key >= 0);

    if(find_node(key) && key ==(*find_node(key)).key)
    {
        result=*find_node(key);
        found=true;
        return found;
    }
     return found;
}

template <class RecordType>
inline std::size_t chained_hash<RecordType>::hash(int key) const
// Postcondition: The return value is the hash value for the given key.
{
    return key % CAPACITY;
}



#endif // CHAINED_HASH_H
