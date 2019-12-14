#ifndef VECTOR_H
#define VECTOR_H
#include "add_entry_lib.h"

template<typename T>
class Vector
{
public:
    Vector();
    Vector(initializer_list<T> it);
    Vector(int capacity);
    ~Vector();
    Vector(const Vector& other);
    Vector& operator =(const Vector& other)
    {
           if(this==&other)
           {
               return *this;
           }else
           {
               delete [] _v;
               _v=NULL;
               _size=other._size;
               _capacity=other._capacity;
               _v=allocate<T>(_capacity);
               copy_list(_v,other._v,_size);
               return *this;
           }
    }

    Vector& operator +=(const T&b)
    {
        push_back(b);
        return *this;
    }

    void erase(int erase_index);
    int index_of(const T& item); //search for item

    void clear();
    void print() const;
    void push_back(const T& item);
    T pop_back();
    bool isempty() const;


    const T operator[](const unsigned int index) const;
    T& operator[] (const unsigned int index);
    T& at(int index);
    const T at(int index) const;


    T& front() const;
    T& back() const;

    //setter and getter
    void set_size(int size);
    void set_capacity(int capacity);
    int size() const;
    int capacity()const;

    friend ostream& operator <<(ostream& outs, const Vector& p){
            p.print();
            return outs;
     }

private:
    T* _v;
    int _size;
    int _capacity;

};

template<typename T>
Vector<T>::Vector()
{
    _size=0;
    _capacity=8;
    _v=allocate<T>(_capacity);
}

template<typename T>
Vector<T>::Vector(initializer_list<T> it)
{
    _size=0;
    _capacity=8;
    _v=allocate<T>(_capacity);
    for(const T* i=it.begin();i!=it.end();i++)
    {
        push_back(*i);
    }
}

template<typename T>
Vector<T>::Vector(int capacity)
{
    _size=0;
    _capacity=capacity;
    _v=allocate<T>(_capacity);
}

template<typename T>
Vector<T>::~Vector()
{
    delete [] _v;
}

template<typename T> //copy constructor
Vector<T>::Vector(const Vector& other)
{
    _size=other._size;
    _capacity=other._capacity;
    _v=allocate<T>(_capacity);
    copy_list(_v,other._v,_size);
}


template<typename T>
void Vector<T>::erase(int erase_index)
{
   T delete_me=_v[erase_index];
   remove_entry(_v,delete_me,_size,_capacity);
}


template<typename T>
int Vector<T>::index_of(const T& item)
{
    for(int i=0;i<_size;i++)
    {
        if(_v[i]==item) return i;
    }

    return -1;
}

template<typename T>
void Vector<T>::clear()
{
    delete [] _v;
    _size=0;
    _v=allocate<T>(_capacity);
}

template<typename T>
void Vector<T>::print() const
{
    print_list(_v,_size);
}

template<typename T>
void Vector<T>::push_back(const T& item)
{
    _v=add_entry(_v,item,_size,_capacity);
}

template<typename T>
T Vector<T>::pop_back()
{
    assert(!isempty());
    T* walker=_v;
    walker+=_size-1;
    T delete_me=*walker;
    _v=remove(_v,walker,_size,_capacity);
    return delete_me;
}

template<typename T>
bool Vector<T>::isempty() const
{
    return _size==0?true:false;
}

template<typename T>
T& Vector<T>::at(int index) //return reference so able to make change.
{
    assert(!(index>=_size));
    return _v[index];
}

template<typename T>
const T Vector<T>::at(int index) const
{
    assert(!(index>=_size));
    return _v[index];
}

template<typename T>
T& Vector<T>::operator[](unsigned int index) //return reference so able to make change.
{
    assert(index<_size);
    return _v[index];
}

template<typename T>
const T Vector<T>::operator[](unsigned int index) const //return copy value
{
    assert(index<_size);
    return _v[index];
}

template<typename T>
T& Vector<T>::front() const
{
    return _v[0];
}

template<typename T>
T& Vector<T>::back() const
{
    return _v[_size-1];
}


template<typename T>
void Vector<T>::set_size(int size)
{
    _size=size;
}

template<typename T>
void Vector<T>::set_capacity(int capacity)
{
    _capacity=capacity;
}

template<typename T>
int Vector<T>::size() const
{
    return _size;
}
template<typename T>
int Vector<T>::capacity() const
{
    return _capacity;
}



#endif // VECTOR_H
