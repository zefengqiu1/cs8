#include <iostream>
#include <timer.h>
using namespace std;


template <class T>
void insert_sort(T a[], unsigned int size);

template <class T>
void bubble_sort(T a[], unsigned int size);

template <class T>
int partition (T arr[], int low, int high);

template <class T>
void quick_sort(T a[], int left,int right);

template <class T>
void quick_sort(T a[], unsigned int size);


template <class T>
void merge_sort(T a[], unsigned int size);

template <class T>
void merge_sort(T a[], int start,int end,T temp[]);

template<class T>
void merge(T a[],int left,int mid,int right,T temp[]);


template <class T>
void heap_sort(T a[], unsigned int size);

template <class T>
void heapify(T arr[], int n, int i);

template <class T>
void swap(T a[], int i,int j);



void shuffle(int a[], unsigned int  size);
//shuffle elements of a[]


template <class T>
void copy_array(T dest[], const T src[], unsigned int size);

//return true if a[] is in ascending order
template <class T>
bool verify(const T a[], unsigned int  size);

//return a string "SORTED" or "NOT SORTED" depending if a[] is sorted
template <class T>
string verifystr(const T a[], unsigned int  size);

//print the array if status_only is true along with info on sortedness of a[]
template <class T>
void print_array(const T a[], int size, bool status_only = false);

//print a[] from start to end
template <class T>
void print_array_segment(T a[], unsigned int start, unsigned int end);


float time_sort_routine(int a[], unsigned int  size, void (*f)(int *, unsigned int));


template<class T>
void average_time(T a[],unsigned int size);


int main()
{
     const int size=50000;
    int a[size];
            //int b[size],c[size],d[size],e[size];
   // int b[5]={3,2,4,7,5};
   // insert_sort(b,5);
   // print_array_segment(b,0,4);
    srand(time(nullptr));

   for(int i=0;i<size;i++)  //fill array
   {
       int number=(rand()%(size-1))+1;
       a[i]=number;
   }

    average_time(a,size);


    return 0;
}






template <class T>
void insert_sort(T a[], unsigned int size)
{
    for(int i=1;i<size;i++)
    {
        int key,j;
        key = a[i]; //now
        j = i - 1;//prev


       while (j >= 0 && a[j] > key)//shift right
       {
           a[j + 1] = a[j];
           j--;
       }
       a[j + 1] = key;
    }
}


template <class T>
void quick_sort(T a[], unsigned int size)//partition
{
    int low=0;
    int high=size-1;
    quick_sort(a,low,high);
}

template <class T>
void quick_sort(T a[], int left,int right)
{

    if (left < right)
    {
        int  mid = partition(a, left, right);
        quick_sort(a, left, mid-1);  // Before pi
        quick_sort(a, mid+1, right); // After pi
    }

}



template <class T>
int partition (T arr[], int low, int high)
{
    int pivot = arr[low];//pick first elment as pivot
    int location = low;//location point to the last element that less than pivot
    for(int i = low+1; i <= high; i++)//i has to be low+1 since recursion so cant be fixed for loop the each elment
    {
        if(arr[i] < pivot)//check and swap
        {
            location++;
            swap(arr,i,location);
        }

    }
    swap(arr[low], arr[location]);//swap the pivot with current location.
    return location;
}

template <class T>
void merge_sort(T a[], unsigned int size)//divide and merge
{
    T temp[size];
    merge_sort(a,0,size,temp);
}

template <class T>
void merge_sort(T a[], int start,int end,T temp[])
{

    if(start<end)
    {
        int mid=start+(end-start)/2;
        merge_sort(a,start,mid,temp);
        merge_sort(a,mid+1,end,temp);
        merge(a,start,mid,end,temp);
    }

}


template<class T>
void merge(T a[],int left,int mid,int right,T temp[])
{
           int i = left;     //left pointer
           int j = mid+1;   //right pointer
           int t = 0;       //reset pointer
           while (i<=mid && j<=right){
               if(a[i]<=a[j]){
                   temp[t++] = a[i++];
               }else {
                   temp[t++] = a[j++];
               }
           }
           while(i<=mid){//put the left side into array
               temp[t++] = a[i++];
           }
           while(j<=right){//put the right side into array
               temp[t++] = a[j++];
           }
           t = 0;
           //any left put into the temp array
           while(left <= right){
               a[left++] = temp[t++];
           }

}


template <class T>
void heap_sort(T a[], unsigned int size)
{
    //int i=0;
    for(int i=size/2-1;i>=0;i--)
    {
        heapify(a,size,i);
    }//rearrange heap

    for(int i=size-1;i>=0;i--)
    {
        swap(a,0,i);//swap first and last
        heapify(a,i,0);//heapfy again.
    }
}

template <class T>
void heapify(T arr[], int n, int i) // n array size , i start position
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr, i,largest);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}


template <class T>
void bubble_sort(T a[], unsigned int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i-1;j++)//move the max to the right each time
        {
            if(a[j]>a[j+1])
            {
                swap(a,j,j+1);
            }
        }
    }
}


template <class T>
void swap(T a[], int i,int j)
{
    T temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void shuffle(int a[], unsigned int  size)
{

    int i=(rand()%(size-1))+1;
    int j=(rand()%(size-1))+1;
    swap(a,i,j);


}


template <class T>
void copy_array(T dest[], const T src[], unsigned int size)
{
    for(int i=0;i<size;i++)
    {
        dest[i]=src[i];

    }
}

template <class T>
bool verify(const T a[], unsigned int  size)
{
    for(int i=0;i<size-1;i++)
    {
        if(a[i]>a[i+1]) return false;
    }

    return true;
}


template <class T>
string verifystr(const T a[], unsigned int  size)
{
    if(verify(a,size))
    {
        return"sorted";
    }else
    {
        return"not sorted";
    }

}


//print the array if status_only is true along with info on sortedness of a[]
template <class T>
void print_array(const T a[], int size, bool status_only)
{

    if(status_only)
    {
        print_array_segment(a,0,size-1);
    }
}


template <class T>
void print_array_segment(T a[], unsigned int start, unsigned int end)
{
    for(int i=start;i<=end;i++)
    {
        cout<<a[i]<<'|';
    }
    cout<<endl;
}

float time_sort_routine(int a[], unsigned int  size, void (*f)(int *, unsigned int)){
    timer t;
    t.start();
    f(a, size);
    t.stop();
    return t.duration();
}

template<class T>
void average_time(T a[],unsigned int size)
{
    for(int i=0;i<size;i++)
    {
        shuffle(a,size);
    }
    T b[size],c[size],d[size],e[size];

    copy_array(b,a,size);
    copy_array(c,a,size);
    copy_array(d,a,size);
    copy_array(e,a,size);


    cout<<"average duration - bubbleSort(50000):"<<time_sort_routine(a,size,bubble_sort)<<endl;

    cout<<"average duration - mergeSort(50000):"<<time_sort_routine(c,size,merge_sort)<<endl;
    cout<<"average duration - quickSort(50000):"<<time_sort_routine(d,size,quick_sort)<<endl;
    cout<<"average duration - heapSort(50000):"<<time_sort_routine(e,size,heap_sort)<<endl;

 cout<<"average duration - insertSort(50000):"<<time_sort_routine(b,size,insert_sort)<<endl;

 cout<<verifystr(a,size)<<endl;
  cout<<verifystr(b,size)<<endl;
   cout<<verifystr(d,size)<<endl;
    cout<<verifystr(e,size)<<endl;
     cout<<verifystr(c,size)<<endl;
}




