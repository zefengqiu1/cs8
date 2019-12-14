#ifndef B_TREE_FUNCTION_H
#define B_TREE_FUNCTION_H

#include <iostream>
#include <assert.h>
#include "../heap/vector.h"

using namespace std;

template <class T>
T maximal(const T& a, const T& b);                      //return the larger of the two items

template <class T>
void Swap(T& a, T& b);  //swap the two items

template <class T>
int index_of_maximal(T data[ ], int n);                 //return index of the largest item in data

template <class T>
void ordered_insert(T data[ ], int& n, T entry);        //insert entry into the sorted array
                                                        //data with length n

template <class T>
int first_ge(const T data[ ], int n, const T& entry);   //return the first element in data that is
                                                        //not less than entry

template <class T>
void attach_item(T data[ ], int& n, const T& entry);    //append entry to the right of data

template <class T>
void insert_item(T data[ ], int i, int& n, T entry);    //insert entry at index i in data

template <class T>
void detach_item(T data[ ], int& n, T& entry);          //remove the last element in data and place
                                                        //it in entry

template <class T>
void delete_item(T data[ ], int i, int& n, T& entry);   //delete item at index i and place it in entry

template <class T>
void merge(T data1[ ], int& n1, T data2[ ], int& n2);   //append data2 to the right of data1

template <class T>
void split(T data1[ ], int& n1, T data2[ ], int& n2);   //move n/2 elements from the right of data1
                                                        //and move to data2

template <class T>
void copy_array(T dest[], const T src[],int& dest_size, int src_size);              //copy src[] into dest[]

template <class T>
void print_array(const T data[], int n, int pos = -1);  //print array data

template <class T>
bool is_gt(const T data[], int n, const T& item);       //item > all data[i]

template <class T>
bool is_le(const T data[], int n, const T& item);       //item <= all data[i]




template <class T>
T maximal(const T& a, const T& b)  //return the larger of the two items
{
    return a>b?a:b;
}

template <class T>
void Swap(T& a, T& b)  //swap the two items
{
    T temp=a;
    a=b;
    b=temp;
}
template <class T>
int index_of_maximal(T data[ ], int n)                 //return index of the largest item in data
{
    int index=0;
    for(int i=1;i<n;i++)
    {
        if(data[index]<data[i])
        {
            index=i;
        }
    }

    return index;
}

template <class T>
void ordered_insert(T data[ ], int& n, T entry)        //insert entry into the sorted array
{

    int index=first_ge(data,n,entry);
    insert_item(data,index,n,entry);
}                                                //data with length n

template <class T>
int first_ge(const T data[ ], int n, const T& entry)   //return the first index in data that is
{
    for(int i=0;i<n;i++)
    {
        if(entry<=data[i]) return i;

    }
    return n;
}                                                       //not less than entry

template <class T>
void attach_item(T data[ ], int& n, const T& entry)    //append entry to the right of data
{
    data[n]=entry;
    n++;
}

template <class T>
void insert_item(T data[ ], int i, int& n, T entry)    //insert entry at index i in data
{
   // assert(i<n);

    for(int j=n;j>i;j--)//shfit right;
    {
        data[j]=data[j-1];
    }
    n++;
    data[i]=entry;



}

template <class T>
void detach_item(T data[ ], int& n, T& entry)          //remove the last element in data and place
{
   // assert(n!=0);
    entry=data[n-1];
    n--;
}                                  //it in entry

template <class T>
void delete_item(T data[ ], int i, int& n, T& entry)   //delete item at index i and place it in entry
{
       // assert(i<n);
        entry=data[i];          //shift left????
        for(int j=i;j<n-1;j++)
        {
            data[j]=data[j+1];
        }
        n--;
}
template <class T>
void merge(T data1[ ], int& n1, T data2[ ], int& n2)   //append data2 to the right of data1
{

//    for(int i=n1, j=0; j<n2; j++, i++){
//        data1[i] = data2[j];
//    }
//    n1 = n1+n2;
//    n2 = 0;

    for(int i=0;i<n2;i++)
    {
      data1[n1]=data2[i];
      n1++;
    }
    n2=0;

}


//move n/2 elements from the right of data1
//and move to data2
template <class T>
void split(T data1[ ], int& n1, T data2[ ], int& n2)
{
    //move n/2 elements from the right of data1
    //and move to data2
    int index=0;
    n2 = n1/2;
    for(int i = n1- n1/2; i<n1; i++){
        data2[index] = data1[i];
        index++;
    }
    n1 = n1-n2;

//    n2 = n1/2;
//    for(int left = n1- n1/2, right = 0; left<n1; left++, right++){
//        data2[right] = data1[left];
//    }
//    n1 = n1-n2;

}

template <class T>
void copy_array(T dest[], const T src[],int& dest_size, int src_size)                //copy src[] into dest[]
{
    dest_size=src_size;
    for(int i=0;i<src_size;i++)
    {
        dest[i]=src[i];
    }
}
template <class T>
void print_array(const T data[], int n, int pos)  //print array data
{
    for(int i = 0;i<n;i++)
    {
        cout<<data[i]<<"|";
    }
    cout<<endl;
}
template <class T>
bool is_gt(const T data[], int n, const T& item)       //item > all data[i]
{
    for(int i=0;i<n;i++)
    {
        if(item<=data[i]) return false;
    }
    return true;
}
template <class T>
bool is_le(const T data[], int n, const T& item)       //item <= all data[i]
{
    for(int i=0;i<n;i++)
    {
        if(item>data[i]) return false;
    }
    return true;
}


//-------------- Vector Extra operators: ---------------------

template <typename T>
ostream& operator <<(ostream& outs, const Vector<T>& list)
{
    list.print();
    return outs;
}//print vector list

template <typename T>
Vector<T>& operator +=(Vector<T>& list, const T& addme)
{
      list.push_back(list);
      return list;

}//list.push_back addme





#endif // B_TREE_FUNCTION_H
