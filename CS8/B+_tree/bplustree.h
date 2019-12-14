#ifndef BTREE_H
#define BTREE_H
#include "b+_tree_function.h"
#include "../linklist/stack.h"
#include <iostream>
#include <iomanip>
using namespace std;


template <class T>
class BplusTree
{
public:
    class Iterator{
       public:
           friend class BPlusTree;
           Iterator(BplusTree<T>* _it=NULL, int _key_ptr = 0):it(_it), key_ptr(_key_ptr){}

           T operator *(){
               assert(key_ptr < it->data_count); //return data count
               return it->data[key_ptr];
           }

           Iterator operator++(int un_used){ //it++
               if(key_ptr<it->data_count-1)
               {
                    key_ptr++;
               }else
               {
                   it=it->pointer;
                   key_ptr=0;
               }
               return Iterator(it,key_ptr);
           }

           Iterator operator++(){ //++it
               if(key_ptr<it->data_count-1)
               {
                    key_ptr++;
               }else
               {
                   it=it->pointer; //pointer to next one
                   key_ptr=0;
               }
               return Iterator(it,key_ptr);
           }
           friend bool operator ==(const Iterator& lhs, const Iterator& rhs){
                 return (lhs.it==rhs.it && lhs.key_ptr==rhs.key_ptr);

           }

           friend bool operator !=(const Iterator& lhs, const Iterator& rhs){
               return (lhs.it!=rhs.it || lhs.key_ptr!=rhs.key_ptr);

           }
           void print_Iterator(){
                cout<<*it;
           }
           bool is_null(){return !it;}
       private:
           BplusTree<T>* it;
           int key_ptr;
       };


    Iterator _find(const T& entry);


    Iterator lower_bound(const T& entry);

                                             // key entry or next if does not
                                             // exist >= entry
    Iterator upper_bound(const T& entry);

    Iterator begin();
    Iterator end();
    //return first that goes AFTER key
    //exist or not, the next entry  >entry

    //---------------------------------------------------------------------
    //            B E G I N ( )   &   E N D ( )
    //---------------------------------------------------------------------




    BplusTree(bool dups = false);
    //big three:
    BplusTree(const BplusTree<T>& other);
    ~BplusTree();
    BplusTree<T>& operator =(const BplusTree<T>& RHS);

    void insert(const T& entry);                //insert entry into the tree
    void remove(const T& entry);                //remove entry from the tree

    void clear_tree();                          //clear this object (delete all nodes etc.)
    //void copy_tree(const BplusTree<T>& other);      //copy other into this object
    void copy_tree(const BplusTree<T>& other);  //copy other into this object
    void copy_tree(const BplusTree<T>& other, Stack<BplusTree<T>*>& s);
    bool contains(const T& entry);              //true if entry can be found in the array
    T& get_ex(const T& entry);
    const T& get_ex(const T& entry) const;

    const T& get(const T& entry) const;
    T& get(const T& entry);                     //return a reference to entry in the tree
    T* find(const T& entry);                    //return a pointer to this key. NULL if not there.

    int size() const;                           //count the number of elements in the tree
    bool empty() const;                         //true if the tree is empty

    void print_tree(int level = 0, ostream &outs=cout) const; //print a readable version of the tree


    void print_tree2(int level=0,ostream& outs=cout) const
    {

       if(!is_leaf())
       {
           subset[0]->print_tree2();
       }else
       {
           print_array(data,data_count);
           BplusTree<T>* walker=pointer;
           while(walker!=nullptr)
           {
               print_array(walker->data,walker->data_count);
               walker=walker->pointer;
           }
       }
    }

    void print_tree3(int level=0, ostream& outs=cout) const;

    void get_smallest(T& entry)  //entry := leftmost leaf
    {
        if(!is_leaf())
        {
            subset[0]->get_smallest(entry);
        }else
        {
            entry=data[0];
        }

    }

     void get_biggest(T& entry)    //entry := rightmost leaf
     {
        if(!is_leaf())
        {
            subset[child_count-1]->get_biggest(entry);

        }else
        {
            entry=data[data_count-1];
        }
     }


    bool is_valid(); //check is btree_valid;

    friend ostream& operator<<(ostream& outs, const BplusTree<T>& print_me){
        print_me.print_tree(0, outs);
        return outs;
    }
private:
    static const int MINIMUM = 1;
    static const int MAXIMUM = 2 * MINIMUM;

    bool dups_ok;                                   //true if duplicate keys may be inserted
    int data_count;                                 //number of data elements
    T data[MAXIMUM + 1];                            //holds the keys
    int child_count;                                //number of children
    BplusTree* subset[MAXIMUM + 2];                     //subtrees
    BplusTree* pointer=NULL;
    bool is_leaf() const {return child_count==0;}   //true if this is a leaf node

    //insert element functions
    void loose_insert(const T& entry);              //allows MAXIMUM+1 data elements in the root
    void fix_excess(int i);                         //fix excess of data elements in child i
     void fix_excess2(int i);
    //remove element functions:
    void loose_remove(const T& entry);              //allows MINIMUM-1 data elements in the root
    void fix_shortage(int i);                       //fix shortage of data elements in child i

    void remove_biggest(T& entry);                  //remove the biggest child of this tree->entry
    void rotate_left(int i);                        //transfer one element LEFT from child i
    void rotate_right(int i);                       //transfer one element RIGHT from child i
    void merge_with_next_subset(int i);             //merge subset i with subset i+1
    BplusTree* get_smallest_node();

};

template <class T>
typename  BplusTree<T>::Iterator BplusTree<T>::_find(const T& entry)
{
    int i= first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i] == entry);
    if(found){

        if(is_leaf())
        {
            return Iterator(this,i);
        }else
        {
             return subset[i+1]->_find(entry);
        }
    }
    else{
        if(is_leaf()){
            return Iterator(NULL);
        }
        else{
            return subset[i]->_find(entry);
        }
    }


} //return an iterator to this key. NULL if not there.


template <class T>
typename BplusTree<T>::Iterator BplusTree<T>::lower_bound(const T& entry)
{

    int i= first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i] == entry);
    if(found){

        if(is_leaf())
        {
            return Iterator(this,i);
        }else
        {
             return subset[i+1]->lower_bound(entry);
        }
    }
    else{
        if(is_leaf()){
            return Iterator(this,i-1)++;
        }
        else{
            return subset[i]->lower_bound(entry);
        }
    }
}

template <class T>
typename BplusTree<T>::Iterator BplusTree<T>::upper_bound(const T& entry)
{

    int i= first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i] == entry);
    if(found){

        if(is_leaf())
        {
            return Iterator(this,i)++;
        }else
        {
             return subset[i+1]->upper_bound(entry);
        }
    }
    else{
        if(is_leaf()){
            return Iterator(this,i-1)++;
        }
        else{
            return subset[i]->upper_bound(entry);
        }
    }

}



template <class T>
typename BplusTree<T>::Iterator BplusTree<T>::begin(){
    return Iterator(get_smallest_node());
}

template <class T>
typename BplusTree<T>::Iterator BplusTree<T>::end(){
    return Iterator(NULL);
}

template<class T>
BplusTree<T>* BplusTree<T>::get_smallest_node()
{
    if(!is_leaf())
    {
        return subset[0]->get_smallest_node();

    }else
    {
        BplusTree<T>* smallest=this;
        return smallest;
    }
}

template<class T>
BplusTree<T>::BplusTree(bool dups )
{
    dups_ok=dups;
    for(int i=0;i<MAXIMUM + 2;i++)
    {
        subset[i]=nullptr;

    }

    pointer=nullptr;
    data_count=0;
    child_count=0;
}

template<class T>
BplusTree<T>::BplusTree(const BplusTree<T>& other)
{
    copy_tree(other);
}


template <class T>
BplusTree<T>::~BplusTree<T>(){

    clear_tree();
    pointer=NULL;
}


template <class T>
int BplusTree<T>::size()const{
    return data_count;
}

template <class T>
bool BplusTree<T>::empty()const{
    return data_count==0;
}

template <class T>
void BplusTree<T>::clear_tree(){

    //set data_count to 0
    data_count = 0;
    for(int i=0;i<child_count;i++)
    {
        subset[i]->clear_tree();
        delete subset[i];
    }
    child_count=0;  //set the child count= 0 at the end

}

template<class T>
void BplusTree<T>::copy_tree(const BplusTree<T>& other)
{
   // assumes this btree is empty. [memory leaks otherwise]
    clear_tree();
    dups_ok = other.dups_ok;
    child_count = other.child_count;
    Stack<BplusTree<T>*> s;
    copy_array(data,other.data,data_count,other.data_count);
    for(int i = 0 ; i < child_count ; i ++ ) {
        subset[i] = new BplusTree<T>(dups_ok);
        subset[i]->copy_tree(*other.subset[i],s);
    }
}

 template<class T>
void BplusTree<T>:: copy_tree(const BplusTree<T>& other, Stack<BplusTree<T>*>& s)
{
    // assert(empty());
     dups_ok = other.dups_ok;
     child_count = other.child_count;
     copy_array(data,other.data,data_count,other.data_count);
    if(is_leaf()) {
        if(!s.empty()) {
            BplusTree<T>* _prev = s.pop();
            _prev->pointer = this;
            s.push(this);
        } else {
            s.push(this);
        }
    }
    for(int i = 0 ; i < child_count ; i ++ ) {
        subset[i] = new BplusTree<T>(dups_ok);
        subset[i]->copy_tree(*other.subset[i],s);
    }
}



template<class T>
BplusTree<T>& BplusTree<T>::operator=(const BplusTree<T>& RHS)
{
    if(this==&RHS)
    {
        return *this;
    }else
    {
        copy_tree(RHS);
        return *this;
    }
}

//========================insert===================
template <typename T>
void BplusTree<T>::insert(const T& entry){

    loose_insert(entry);
    //when the root is need to be fix_excess
    if(data_count> MAXIMUM){
        BplusTree<T>* item = new BplusTree<T>;
        copy_array(item->data, data, item->data_count, data_count);
        copy_array(item->subset, subset, item->child_count, child_count);
        data_count = 0;
        child_count = 1;
        subset[0] = item;
        fix_excess(0);
    }
}

template <typename T>
void BplusTree<T>::loose_insert(const T& entry){


    int i = first_ge(data,data_count,entry);
    bool found=(i<data_count && data[i]==entry);

    if(found)
    {
        if(is_leaf())
        {
            data[i]=entry;
            return;
        }else
        {
            subset[i+1]->loose_insert(entry);
            if(subset[i+1]->data_count>MAXIMUM )
            {
                fix_excess(i+1);
            }

        }
    }else//not found subset[i]
    {
        if(is_leaf())
        {
            insert_item(data,i,data_count,entry);
            return;
        }else
        {
             subset[i]->loose_insert(entry);
             if(subset[i]->data_count>MAXIMUM )
             {
                 fix_excess(i);
             }
        }
    }

}

template <typename T>
void BplusTree<T>::fix_excess(int i){
    //when it is leaf, insert copy one and links.

    insert_item(subset, i+1, child_count, new BplusTree<T>);
    split(subset[i]->data, subset[i]->data_count, subset[i+1]->data, subset[i+1]->data_count);
    split(subset[i]->subset, subset[i]->child_count, subset[i+1]->subset, subset[i+1]->child_count );
    T temp;
    detach_item(subset[i]->data, subset[i]->data_count, temp);
    ordered_insert(data, data_count, temp );
    //
    if(subset[i]->is_leaf())
        insert_item(subset[i+1]->data,0,subset[i+1]->data_count,temp);
        BplusTree<T>* temp1;
        //links
        subset[i+1]->pointer=subset[i]->pointer;
        subset[i]->pointer=subset[i+1];

}



template <typename T>
void BplusTree<T>::remove(const T& entry){

    loose_remove(entry);
    if(data_count < MINIMUM && child_count >0){
        BplusTree<T>* temp = subset[0];
        copy_array(data,subset[0]->data,data_count,subset[0]->data_count);
        copy_array(subset,subset[0]->subset,child_count,subset[0]->child_count);
        temp->child_count=0;
        delete temp;
        temp = NULL;
    }

}
template <typename T>
void BplusTree<T>::loose_remove(const T& entry){

    int i=first_ge( data, data_count, entry );
    bool found=( i<data_count && data[i]==entry );
    if(found)
    {
        if(is_leaf())
        {
            T temp;
            delete_item(data,i,data_count,temp);
        }else
        {
            subset[i+1]->loose_remove(entry);
            if(is_leaf() && subset[i+1]->data_count < MINIMUM)
                fix_shortage(i+1);
        }
    }else
    {
        if(is_leaf())
        {
            return;
        }else
        {
            subset[i]->loose_remove(entry);
            if(is_leaf() && subset[i]->data_count < MINIMUM)
                fix_shortage(i);
        }
    }

}

template <typename T>
void BplusTree<T>::fix_shortage(int i){


    if(i<child_count-1 && subset[i+1]->data_count> MINIMUM){

        rotate_left(i+1);
    }

    //when rotate righe, i has to have left subset, so can't be 0 and less then child_count
    else if(i>0 && i<child_count && subset[i-1]->data_count> MINIMUM ){
        rotate_right(i-1);
    }
    else if(i>0){

        merge_with_next_subset(i-1);
    }
    else{
        merge_with_next_subset(i);
    }
}


template <typename T>
void BplusTree<T>::merge_with_next_subset(int i){

        T temp;
        delete_item(data,i,data_count,temp);
        merge(subset[i]->data,subset[i]->data_count,subset[i+1]->data,subset[i+1]->data_count);
        BplusTree<T>* hold;
        delete_item(subset, i+1, child_count, hold);//then delete subset[i+1];
        if(hold!=nullptr)
        {
            delete hold;
            hold=nullptr;
        }

}
template <typename T>
void BplusTree<T>::rotate_left(int i){

           T temp;
           delete_item(subset[i]->data,0,subset[i]->data_count,temp);
           ordered_insert(subset[i-1]->data, subset[i-1]->data_count, temp);
           data[i-1]=subset[i]->data[0];


}

template <typename T>
void BplusTree<T>::rotate_right(int i){
     //(i < child_count - 1) and (subset[i]->data_count > MINIMUM)
     //subset[i+ 1] has only MINIMUM - 1 entries.
        T temp;
        detach_item(subset[i]->data,subset[i]->data_count,temp);
        ordered_insert( subset[i+1]->data, subset[i+1]->data_count, temp );
        data[i]=temp;

}


//---------------------------------------------------------------------
//            C O N T A I N S / F I N D / G E T / E T C .
//---------------------------------------------------------------------
template <class T>
bool BplusTree<T>::contains(const T& entry){

    int i= first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i] == entry);
    if(found){

        if(is_leaf())
        {
            return true;
        }else
        {
             return subset[i+1]->contains(entry);
        }
    }
    else{
        if(is_leaf()){
            return false;
        }
        else{
            return subset[i]->contains(entry);
        }
    }
}

template <class T>
T* BplusTree<T>::find(const T& entry){

    T* result;
    if(!contains(entry))
        return result = nullptr;
    return result = &get_ex(entry);
}
template <class T>
const T& BplusTree<T>::get_ex(const T& entry) const{

    int i = first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i]==entry);
    if (found)
    {
        if(is_leaf())
           return data[i];
        else
           return subset[i+1]->get_ex(entry);
    }else{

        if(!is_leaf())
            return subset[i]->get_ex(entry);
        else
            assert(found);
    }
}
template <class T>
T& BplusTree<T>::get_ex(const T& entry){
    int i = first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i]==entry);
    if (found)
    {
        if(is_leaf())
           return data[i];
        else
           return subset[i+1]->get_ex(entry);
    }
    else{
        if(!is_leaf())
            return subset[i]->get_ex(entry);
        else
            assert(found);
    }
}


template <class T>
T& BplusTree<T>::get(const T& entry){

    if(!contains(entry)){
        insert(entry);
    }
    return get_ex(entry);
}

//const don't change the calling object itself
template <class T>
const T& BplusTree<T>::get(const T& entry) const{

    return get_ex(entry);
}

template <typename T>
void BplusTree<T>::print_tree(int level, ostream& outs) const{
    // do the recursion print
    // print the leaf first

    if(is_leaf()){
        for(int i= data_count -1 ; i>=0; i--){

            cout<<endl;
            outs<<setw(5*level)<<"[ "<<data[i]<<" ]";
            cout<<endl;
        }
        cout<<endl;
    }
    else{

        for(int j=child_count-1;j>=0;j--)
        {
            subset[j]->print_tree(level+1);
           if(j>=1)
            outs<<setw(5*level)<<"[ "<<data[j-1]<<" ]"<<endl;
        }
    }

}


template <typename T>
bool BplusTree<T>::is_valid(){
    for(int i=0;i<data_count-1;i++)
    {
        if(data[i]>data[i+1]) return false;
    }

    if (is_leaf()) return true;
    if(!is_le(subset[child_count-1]->data,subset[child_count-1]->data_count,data[data_count-1])) return false;

    for(int i = 0 ;  i< data_count; i ++) {
        if(!is_gt(subset[i]->data,subset[i]->data_count,data[i]))
        {
           cout << "data: "<<data[i]<<" is not greater than every subset[i]->data[ ]" << endl;
            return false;
        }
    }

    for(int i = 0 ;  i< data_count; i ++) {
        T smallest;
        subset[i+1] -> get_smallest(smallest);
        if(!(data[i] == smallest)) {
            cout << "data: "<<data[i]<<" is not equal to subset[i+1]->smallest" << endl;
            return false;
        }
    }
            //Recursively validate every subset[i]
    for(int i = 0 ; i < child_count; i ++ ){
        if(!subset[i]->is_valid()) {
            cout << "subset: "<<i<<" is not validate" << endl;
            return false;
        }
    }
    return true;
}


template <typename T>void BplusTree<T>::print_tree3(int level, ostream& outs) const
{
    if(!is_leaf())
    {        subset[0]->print_tree3(level, outs);
    } else {
        outs << "[" ;        print_array(data, data_count);
        outs << "] "<<data_count<<"|" << child_count << " -> ";
        BplusTree<T>* temp = pointer;

        while(temp) {
            outs << "[" ;            print_array(temp->data, temp->data_count);
            outs << "] "<<temp->data_count<<"|" << temp->child_count << " -> ";
            temp = temp->pointer;        }
    }
}



#endif // BTREE_H
