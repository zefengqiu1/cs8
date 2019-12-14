#ifndef BTREE_ARRAY_FUNCTIONS_H
#define BTREE_ARRAY_FUNCTIONS_H
#include <iostream>
using namespace std;
template <class T>
T maximal(const T& a, const T& b);
template <class T>
void Swap(T& a, T& b);
template <class T>
int index_of_maximal(T data[ ], int n);
template <class T>
void ordered_insert(T data[ ], int& n, const T& entry);
template <class T>
int first_ge(const T data[ ], int n, const T& entry);
template <class T>
void insert_item(T data[ ], int i, int& n, T entry);
template <class T>
void attach_item(T data[ ], int& n, const T& entry);
template <class T>
void detach_item(T data[ ], int& n, T& entry);
template <class T>
void delete_item(T data[ ], int i, int& n, T& entry);
template <class T>
void merge(T data1[ ], int& n1, T data2[ ], int& n2);
template <class T>
void split(T data1[ ], int& n1, T data2[ ], int& n2);
template <class T>
void copy_array(T dest[], const T src[]);
template <class T>
void print_array(const T data[], int n, int pos = -1);
template <class T>
bool is_gt(const T data[], int n, const T& item);
template <class T>
bool is_le(const T data[], int n, const T& item);



template <class T>
T maximal(const T& a, const T& b){
    //return the larger of the two items
    if(a>=b)
        return a;
    else
        return b;
}

template <class T>
void Swap(T& a, T& b){
    //swap the two items
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <class T>
int index_of_maximal(T data[ ], int n){
    //return index of the largest item in data
    T largest=data[0];
    int largest_index=0;
    for(int i=1; i<n; ++i){
        if( data[i] > largest){
            largest=data[i];
            largest_index=i;
        }
    }
    return largest_index;
}

template <class T>
void ordered_insert(T data[ ], int& n, const T& entry){
    //insert entry into the sorted array
    //data with length n
    int temp;
    temp = first_ge(data, n, entry);
    insert_item(data, temp, n, entry);
}

template <class T>
int first_ge(const T data[ ], int n, const T& entry){
    //return the first element in data that is
    //not less than entry
    for(int i=0; i<n; i++){
        if(data[i] >= entry)
            return i;
    }
    return n;
}

template <class T>
void attach_item(T data[ ], int& n, const T& entry){
    //append entry to the right of data
    data[n]=entry;
    n++;
}

template <class T>
void insert_item(T data[ ], int i, int& n, T entry){
    //insert entry at index i in data
    for(int j=n; j>i; j--){
        data[j] = data[j-1];
    }
    n++;
    data[i] = entry;
}


template <class T>
void detach_item(T data[ ], int& n, T& entry){
    //remove the last element in data and place
    //it in entry
    entry = data[n-1];
    n--;
}

template <class T>
void delete_item(T data[ ], int i, int& n, T& entry){
    //delete item at index i and place it in entry
    entry = data[i];
    for(int j=i; j<n; j++){
        data[j] = data[j+1];
    }
    n--;
}
template <class T>
void merge(T data1[ ], int& n1, T data2[ ], int& n2){
//append data2 to the right of data1
    for(int i=n1, j=0; j<n2; j++, i++){
        data1[i] = data2[j];
    }
    n1 = n1+n2;
    n2 = 0;
}

template <class T>
void split(T data1[ ], int& n1, T data2[ ], int& n2){
    //move n/2 elements from the right of data1
    //and move to data2
    n2 = n1/2;
    for(int left = n1- n1/2, right = 0; left<n1; left++, right++){
        data2[right] = data1[left];
    }
    n1 = n1-n2;

}

template <class T>
void copy_array(T dest[], const T src[], int& dest_size, int src_size){
//copy src[] into dest[]
    for(int i=0; i<src_size; i++){
        dest[i] = src[i];
    }
    dest_size = src_size;
}

template <class T>
void print_array(const T data[], int n, int pos){
//print array data
    for(int i=0; i<n; i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

template <class T>
bool is_gt(const T data[], int n, const T& item){
//item > all data[i]
    int i=0;
    while(item > data[i]){
        i++;
    }
    if(i == n-1)
        return true;
    else
        return false;
}

template <class T>
bool is_le(const T data[], int n, const T& item){
//item <= all data[i]
    int i=0;
    while(item <= data[i]){
        i++;
    }
    if(i == n-1)
        return true;
    else
        return false;

}

//-------------- Vector Extra operators: ---------------------

template <typename T>
ostream& operator <<(ostream& outs, const vector<T>& list){
    //print vector list
    for (int i=0; i<list.size(); ++i ){
        if(i == list.size() -1)
            outs<<list.at(i);
        else
            outs<<list.at(i)<<"->";
    }
    return outs;
}

template <typename T>
vector<T>& operator +=(vector<T>& list, const T& addme){
    //list.push_back addme
    list.push_back(addme);
    return list;
}





#endif // BTREE_ARRAY_FUNCTIONS_H
