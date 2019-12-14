#ifndef ADD_ENTRY_LIB_H
#define ADD_ENTRY_LIB_H
#include <iostream>
using namespace std;

template<typename T>
T* allocate(int capacity);

template<typename T>
void copy_list(T* dest,T* src, int many_to_copy);

template<typename T>
T* search_entry(T* list, const T& find_me, int size);

template<typename T>
T* remove_entry(T* list, const T& delete_me,int& size, int& capacity);

template <typename T>
void append(T* dest,const T& item,int& d_size);

template<typename T>
T* add_entry(T* list, const T& new_entry,int& size, int& capacity);

template <typename T>
void shift_left(T* list,T* position,int& size);

template<typename T>
void print_list(T* list, int size);

template<typename T>
T* remove(T* list, const T& delete_me,int& size, int& capacity);

void show_size_capacity(int& size,int& capacity);


template<typename T>
bool find(T* list, const T& find_me, int size);

void test_string();
template<typename T>
bool find(T* list, const T& find_me, int size)
{
    T* walker=list;
    while(walker-list<size)
    {
        if(*walker==find_me)
        {
            return true;
        }else
        {
            walker++;
        }
    }
    return false;
}

template<typename T>
T* allocate(int capacity)
{
    const bool debug = false;
      if (debug) cout<<"allocate: capacity: "<<capacity<<endl;
      return new T[capacity];
}

template<typename T>
void copy_list(T*dest,T* src, int many_to_copy)
{
    for(int i=0;i<many_to_copy;i++)
    {
        *dest++ = *src++;
    }

}

template<typename T>
T* search_entry(T* list, const T& find_me, int size)
{
    for(int i=0;i<size;i++)
    {
        if(*list==find_me)
        {
            return list;
        }
        list++;
    }
    return nullptr;
}

template<typename T>
T* remove(T* list, T* position,int& size, int& capacity)
{
    T* list_1;
    shift_left(list,position,size);
    if((size<capacity/4)&& capacity/4>=8)
    {   capacity/=2;
        list_1=allocate<T>(capacity);
        copy_list(list_1,list,size);
        delete [] list;
        return list_1;
    }else
    {
     return list;
    }
}

template<typename T>
T* remove_entry(T* list, const T& delete_me,int& size, int& capacity)
{
    T* list_1;
    T* position=search_entry(list,delete_me,size);
    shift_left(list,position,size);
    if((size<capacity/4) && capacity/4>8)
    {   capacity/=2;
        list_1=allocate<T>(capacity);
        copy_list(list_1,list,size);
        delete [] list;
        return list_1;
    }else
    {
     return list;
    }
}

template <typename T>
void append(T* dest,const T& item,int& d_size)
{
    dest+=d_size;
    *dest=item;
    d_size++;

}



template <typename T>
T* add_entry(T* list, const T& new_entry,int& size, int& capacity)
{

    if(size==capacity)
    {
        capacity*=2;
        T* list_1=allocate<T>(capacity);
        copy_list(list_1,list,size);
        append(list_1,new_entry,size);
        delete [] list;
        return list_1;
    }else
    {
     append(list,new_entry,size);
     return list;
    }

}

template <typename T>
void shift_left(T* list,T* position,int& size)
{
    T* position_walker=position;
    while(position_walker-list<size)
    {
        *position_walker=*(position_walker+1);
        position_walker++;
    }
    size--;
}

template<typename T>
void print_list(T* list, int size)
{
    cout<<"[";
    for(int i=0;i<size;i++)
    {

        cout<<*list<<" ";
        //cout<<*list<<" ";
        list++;
    }
    cout<<"]";
}


void show_size_capacity(int& size,int& capacity)
{
    cout<<"the size of array is "<<size<<endl;
    cout<<"The capacity of array is "<<capacity<<endl;
}

void test_string()
{
    int capacity = 3;
       int size = 0;
       string key;
       string* list = allocate<string>(capacity);
       list=add_entry(list,key="Erika", size, capacity);
       print_list(list, size);

       list = add_entry(list, key="Red", size, capacity);
       print_list(list, size);

       list = add_entry(list, key="Bo", size, capacity);
       print_list(list, size);

       list = add_entry(list, key="Pierson", size, capacity);
       print_list(list, size);

       list = add_entry(list, key="Maher", size, capacity);
       print_list(list, size);

       list = add_entry(list, key="Mac", size, capacity);
       print_list(list, size);

       list = add_entry(list, key="Paula", size, capacity);
       print_list(list, size);


       cout<<"Deleting Erika"<<endl;

       list = remove_entry(list, key="Erika", size, capacity);
       print_list(list, size);


       cout<<"Deleting Bo"<<endl;

       list = remove_entry(list, key="Bo", size, capacity);
       print_list(list, size);

       cout<<"Deleting Maher"<<endl;

       list = remove_entry(list, key="Maher", size, capacity);
       print_list(list, size);

       cout<<"Deleting Pierson"<<endl;

       list = remove_entry(list, key="Pierson", size, capacity);
       print_list(list, size);

       cout<<"Deleting Red"<<endl;

       list = remove_entry(list, key="Red", size, capacity);
       print_list(list, size);
}



#endif // ADD_ENTRY_LIB_H
