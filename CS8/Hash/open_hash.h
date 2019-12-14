#ifndef OPEN_HASH_H
#define OPEN_HASH_H
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <iomanip>

using namespace std;

template <class RecordType>
class open_hash
{
public:
    // MEMBER CONSTANT -- See Appendix E if this fails to compile.
    static const size_t CAPACITY = 811;

    // CONSTRUCTOR
    open_hash( );

    // MODIFICATION MEMBER FUNCTIONS
    void insert(const RecordType& entry);

    void remove(int key);

    // CONSTANT MEMBER FUNCTIONS
    bool is_present(int key) const;

    void find(int key, bool& found, RecordType& result) const;

    size_t countofcollision();
    size_t size( ) const { return used; }

    void print(ostream& outs) const;

    friend ostream& operator <<(ostream& outs, const open_hash<RecordType>& p){
            p.print(outs);
            return outs;
     }


private:

    // MEMBER CONSTANTS -- These are used in the key field of special records.
    static const int NEVER_USED = -1;
    static const int PREVIOUSLY_USED = -2;

    // MEMBER VARIABLES
    RecordType data[CAPACITY];
    size_t used;
    int collision_count;
    int collision[CAPACITY]; //check whether collision or not and use for print function.
    // HELPER FUNCTIONS
    size_t hash(int key) const;
    size_t next_index(size_t index) const;
    void find_index(int key, bool& found, size_t& index) const;
    bool never_used(size_t index) const;
    bool is_vacant(size_t index) const;

};

template <class RecordType>
size_t open_hash<RecordType>::countofcollision()
{
    return collision_count;
}


template <class RecordType>
void open_hash<RecordType>::print(ostream& outs) const
{
    for(size_t i=0;i<CAPACITY;i++)
    {
        outs<<" ["<<setw(3)<<setfill('0')<<i<<"] ";
      if(data[i].key>0)
      {
          if(collision[i]>=0)
          {
              outs<<"["<<data[i]<<"]"<<"*"<<"("<<collision[i]<<")";
          }else
          {
              outs<<"["<<data[i]<<"]";
          }
      }else if(data[i].key==-2)
      {
        outs<<"-------------";
      }

        outs<<endl;
    }
}


template <class RecordType>
open_hash<RecordType>::open_hash()
{
    std::size_t i;
    used = 0;
    collision_count=0;
    for (i = 0; i < CAPACITY; i++)
    {
        data[i].key = NEVER_USED; // Indicates a spot that’s never been used.
        collision[i] = NEVER_USED;
    }

}



template <class RecordType>
void open_hash<RecordType>::insert(const RecordType& entry)
{
    bool already_present; // True if entry.key is already in the table
    std::size_t index; // data[index] is location for the new entry
    assert(entry.key >= 0);
    // Set index so that data[index] is the spot to place the new entry.
    find_index(entry.key, already_present, index);
    // If the key wasn’t already there, then find the location for the new entry.
    if (!already_present)
    {
        assert(size( ) < CAPACITY);
        index = hash(entry.key);

        int collision_index=0;
        if(is_vacant(index))
        {
           data[index] = entry;
           ++used;
        }else   //COLLISION
        {
            collision_index=index;

            while (!is_vacant(index))
            {
                 index = next_index(index);
            }
            ++used;
            collision_count++;
            data[index] = entry;
            collision[index]=collision_index;

        }

    }else
    {
        data[index] = entry;
    }


}

template <class RecordType>
void open_hash<RecordType>::remove(int key)
{
    bool found; // True if key occurs somewhere in the table
    std::size_t index; // Spot where data[index].key == key
    assert(key >= 0);
    find_index(key, found, index);
    if (found)
    { // The key was found, so remove this record and reduce used by 1.
    data[index].key = PREVIOUSLY_USED; // Indicates a spot that’s no longer in use.
    collision[index]= NEVER_USED;
    --used;
    }

}

template <class RecordType>
bool open_hash<RecordType>::is_present(int key) const
{
    //See the solution to Self-Test Exercise `12 on page 625.
    bool found;
    size_t index;
    assert(key >= 0);
    find_index(key, found, index);
    return found;

}

template <class RecordType>
void open_hash<RecordType>::find(int key, bool& found, RecordType& result) const
{
    //See the solution to Self-Test Exercise 13 on page 626.
    size_t index;
    assert(key >= 0);
    find_index(key, found, index);
    if (found)
        result = data[index];

}

template <class RecordType>
inline std::size_t open_hash<RecordType>::hash(int key) const
// Postcondition: The return value is the hash value for the given key.
{

    return key % CAPACITY;
}


template <class RecordType>
inline std::size_t open_hash<RecordType>::next_index(std::size_t index) const
// Precondition: index < CAPACITY.
// Postcondition: The return value is either index+1 (if this is less than CAPACITY) or zero
// (if index+1 equals CAPACITY).
{
    return (index+1) % CAPACITY;
}

template <class RecordType>
void open_hash<RecordType>::find_index(int key, bool& found, std::size_t& i) const
// Precondition: key >= 0.
// Postcondition: If a record is in the table with the specified key, then found is true and index
// is set so that data[index].key is the specified key. Otherwise found is false, and i is garbage.
{
    std::size_t count; // Number of entries that have been examined
    count = 0;
    i = hash(key);
    while((count < CAPACITY) && (!never_used(i)) && (data[i].key != key))
    {
    ++count;
    i = next_index(i);
    }
    found = (data[i].key == key);
}

template <class RecordType>
inline bool open_hash<RecordType>::never_used(size_t index) const
// Library facilities used: stdlib.h
// Precondition: index < CAPACITY.
// Postcondition: If data[index] has never
// been used, then the return value is true.
// Otherwise the return value is false.
{
return (data[index].key == NEVER_USED);
}


template <class RecordType>
inline bool open_hash<RecordType>::is_vacant(size_t index) const
// Library facilities used: stdlib.h
// Precondition: index < CAPACITY.
// Postcondition: If data[index] is not now
// being used, then the return value is true.
// Otherwise the return value is false.
{
    return (data[index].key < 0);
}



#endif // OPEN_HASH_H
