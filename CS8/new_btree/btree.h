#ifndef BTREE_H
#define BTREE_H
#include <iostream>
#include <iomanip>
#include "btree_array_functions.h"
//#include "constant.h"

using namespace std;

const bool DEBUG_CONST=true;

template <class T>
class BTree
{
public:

    //--------------------------------------------------
    BTree(bool dups = false);
    //big three:
    BTree(const BTree<T>& other);
    ~BTree();
    BTree<T>& operator =(const BTree<T>& RHS);

    void print_tree(int level = 0, ostream &outs=cout) const; //print a readable version of the tree


    void print_tree2(int level=0,ostream& outs=cout) const
    {
//        outs<<setw(4*level);
//        print_array(data,data_count);
//        for(int i=0;i<child_count;i++)
//        {
//            subset[i]->print_tree2(level+1,outs);
//        }

       if(!is_leaf())
       {
           subset[0]->print_tree2();
       }else
       {
           print_array(data,data_count);
           BTree<T>* walker=pointer;
           while(walker!=nullptr)
           {
              // print_tree(walker->data,walker->data_count);
               print_array(walker->data,walker->data_count);
               walker=walker->pointer;
           }
       }
    }

    friend ostream& operator<<(ostream& outs, const BTree<T>& print_me){
        print_me.print_tree(0, outs);
        return outs;
    }
    int size() const;                           //count the number of elements in the tree
    bool empty() const;                         //true if the tree is empty


    void clear_tree();                          //clear this object (delete all nodes etc.)
    void copy_tree(const BTree<T>& other,BTree<T>* pointer);      //copy other into this object




    bool is_valid();

    void insert(const T& entry);                //insert entry into the tree

    T& get(const T& entry);                     //return a reference to entry in the tree
    bool contains(const T& entry);              //true if entry can be found in the array
    bool contains(const T& entry) const;
    T* find(const T& entry);                    //return a pointer to this key. NULL if not there.
    T& get_ex(const T& entry);
    const T& get_ex(const T& entry)const;
    const T& get(const T& entry) const;

    void remove(const T& entry);                //remove entry from the tree

    //before this are finished
    //--------------------------------------------------

private:
    static const int MINIMUM = 1;
    static const int MAXIMUM = 2 * MINIMUM;

    //--------------------------------------------------

    bool dups_ok;                                   //true if duplicate keys may be inserted
    int data_count;                                 //number of data elements
    T data[MAXIMUM + 1];                            //holds the keys
    int child_count;                                //number of children

    BTree<T>*  pointer=nullptr;

    //one parent only has three(Max + 1) subset, but we set to max+2, leave one as a temp
    //incase we need to use it when we do delete or add.
    BTree* subset[MAXIMUM + 2];                     //subtrees

    bool is_leaf() const {return child_count==0;}   //true if this is a leaf node


    //insert element functions
    void loose_insert(const T& entry);              //allows MAXIMUM+1 data elements in the root
    void fix_excess(int i);                         //fix excess of data elements in child i

    void remove_biggest(T& entry);                  //remove the biggest child of this tree->entry

    void loose_remove(const T& entry);              //allows MINIMUM-1 data elements in the root
    //before this are finished
    //--------------------------------------------------

//private:
    //remove element functions:
    void fix_shortage(int i);                       //fix shortage of data elements in child i
    void rotate_left(int i);                        //transfer one element LEFT from child i
    void rotate_right(int i);                       //transfer one element RIGHT from child i
    void merge_with_next_subset(int i);             //merge subset i with subset i+1

};

template <class T>
BTree<T>::BTree(bool dups){
    //dups: duplicate keys
    dups_ok = dups;
    data_count = 0;
    for(int i=0; i< MAXIMUM + 2; i++){
        subset[i] = nullptr;
    }
    child_count = 0;
}

template <class T>
BTree<T>::BTree(const BTree<T>& other){
    copy_tree(other);
}

template <class T>
BTree<T>::~BTree<T>(){
    if(DEBUG_CONST)
        cout<<"deconstructor is being called"<<endl;
    clear_tree();
}

template <class T>
BTree<T>& BTree<T>::operator=(const BTree<T>& RHS){
    if(this!=&RHS){
        clear_tree();
        copy_tree(RHS);
    }
    return *this;
}

template <class T>
void BTree<T>::print_tree(int level, ostream &outs)const{
    const bool debug = false;
    if(debug){
        cout<<"print tree being called"<<endl;
    }
    if(is_leaf()){
        if(debug){
            cout<<"in if"<<endl;
            cout<<"data_count -1 ="<<data_count-1<<endl;
        }
        for(int i= data_count -1 ; i>=0; i--){
            if(debug){
                cout<<"i"<<i<<endl;
            }
            cout<<endl;
            outs<<setw(5*level)<<"[ "<<data[i]<<" ]";
            cout<<endl;
        }
        cout<<endl;
    }
    else{
        for(int i= data_count-1, j=child_count-1; j>=0; i--, j--){
            subset[j]->print_tree(level+1);
            if(i>=0)
                outs<<setw(5*level)<<"[ "<<data[i]<<" ]"<<endl;
        }
    }
}

template <class T>
int BTree<T>::size()const{
    return data_count+child_count;
}

template <class T>
bool BTree<T>::empty()const{
    return data_count==0;
}

template <class T>
void BTree<T>::clear_tree(){
    /*in clear_tree, different with constructor
     * in constructor, set MAX+2 subset point to nullptr
     * cuz leave the last one as a "temp subset" in case we will use it
     * but in clear_tree, we are only delete from 0 to child_count - 1
     * subset, don't take care the "temp subset"
     */
    data_count = 0;
    for(int i = child_count-1; i>0; i--){
        delete subset[i];
    }
    child_count=0;

}

template <class T>
void BTree<T>::copy_tree(const BTree<T>& other,BTree<T>* pointer){//==============
    clear_tree();
    dups_ok = other.dups_ok;
    child_count = other.child_count;
    copy_array(data, other.data, data_count, other.data_count);
    if(other.is_leaf())
    {

    }
    for(int i=0; i<child_count; i++){
        subset[i] = new BTree<T>;
        subset[i]->copy_tree(other.subset[i]);
    }



}

//---------------------------------------------------------------------
//            C O N T A I N S / F I N D / G E T / E T C .
//---------------------------------------------------------------------
template <class T>
bool BTree<T>::contains(const T& entry){

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

    return false;
}

template <class T>
bool BTree<T>::contains(const T& entry)const{

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
    return false;
}

template <class T>
T* BTree<T>::find(const T& entry){
    if(DEBUG_CONST)
        cout<<" find in btree is being called"<<endl;
    T* result;
    if(!contains(entry))
        return result = nullptr;
    return result = &get_ex(entry);
}
template <class T>
const T& BTree<T>::get_ex(const T& entry) const{
    if(DEBUG_CONST)
        cout<<" const get_ex in btree is being called"<<endl;
    int i = first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i]==entry);
    if (found)
    {
        if(is_leaf())
           return data[i];
        else
           subset[i+1]->get_ex(entry);

    }
    else{
        if(!is_leaf())
            return subset[i]->get_ex(entry);
        else
            assert(found);
    }
}
template <class T>
T& BTree<T>::get_ex(const T& entry){
    int i = first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i]==entry);
    if (found)
    {
        if(is_leaf())
           return data[i];
        else
           subset[i+1]->get_ex(entry);
    }
    else{
        if(!is_leaf())
            return subset[i]->get_ex(entry);
        else
            assert(found);
    }
}


template <class T>
T& BTree<T>::get(const T& entry){
    if(DEBUG_CONST)
        cout<<" get btree is being called"<<endl;
    if(!contains(entry)){
        insert(entry);
    }
    return get_ex(entry);
}

//const don't change the calling object itself
template <class T>
const T& BTree<T>::get(const T& entry) const{
    if(DEBUG_CONST)
        cout<<" const get btree is being called"<<endl;
    return get_ex(entry);
}


//------------------------------------------------
//          I N S E R T
//------------------------------------------------
template <typename T>
void BTree<T>::insert(const T& entry){

    loose_insert(entry);
    //when the root is need to be fix_excess
    if(data_count> MAXIMUM){
        BTree<T>* item = new BTree<T>;
        copy_array(item->data, data, item->data_count, data_count);
        copy_array(item->subset, subset, item->child_count, child_count);
        data_count = 0;
        child_count = 1;
        subset[0] = item;
        fix_excess(0);
    }
}

template <typename T>
void BTree<T>::loose_insert(const T& entry){


    int i = first_ge(data,data_count,entry);
    bool found=(i<data_count && data[i]==entry);

    if(found)
    {
        if(is_leaf())
        {
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
void BTree<T>::fix_excess(int i){
    //when it is leaf, insert copy one and links.

    insert_item(subset, i+1, child_count, new BTree<T>);
    split(subset[i]->data, subset[i]->data_count, subset[i+1]->data, subset[i+1]->data_count);
    split(subset[i]->subset, subset[i]->child_count, subset[i+1]->subset, subset[i+1]->child_count );
    T temp;
    detach_item(subset[i]->data, subset[i]->data_count, temp);
    ordered_insert(data, data_count, temp );
    //
    if(subset[i]->is_leaf())
        insert_item(subset[i+1]->data,0,subset[i+1]->data_count,temp);
        subset[i]->pointer=subset[i+1]; //links

}



template <typename T>
void BTree<T>::remove(const T& entry){

    loose_remove(entry);
    if(data_count < MINIMUM && child_count >0){
        BTree<T>* temp = subset[0];
        copy_array(data,subset[0]->data,data_count,subset[0]->data_count);
        copy_array(subset,subset[0]->subset,child_count,subset[0]->child_count);
        temp->child_count=0;
        delete temp;
        temp = NULL;
    }

}
template <typename T>
void BTree<T>::loose_remove(const T& entry){

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
            if(subset[i+1]->is_leaf() && subset[i+1]->data_count < MINIMUM)
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
            if(subset[i]->is_leaf() && subset[i]->data_count < MINIMUM)
                fix_shortage(i);
        }
    }

}

template <typename T>
void BTree<T>::fix_shortage(int i){


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
void BTree<T>::merge_with_next_subset(int i){

    T temp;
   // detach_item(data,data_count,temp);
    delete_item(data,i,data_count,temp);
    merge(subset[i]->data,subset[i]->data_count,subset[i+1]->data,subset[i+1]->data_count);

    BTree<T>* hold;
    delete_item(subset, i+1, child_count, hold);//then delete subset[i+1];
    delete hold;
    hold=nullptr;
}
template <typename T>
void BTree<T>::rotate_left(int i){

    T temp;
    delete_item(subset[i]->data,0,subset[i]->data_count,temp);
    ordered_insert(subset[i-1]->data, subset[i-1]->data_count, temp);
    data[i-1]=subset[i]->data[0];

}

template <typename T>
void BTree<T>::rotate_right(int i){
     //(i < child_count - 1) and (subset[i]->data_count > MINIMUM)
     //subset[i+ 1] has only MINIMUM - 1 entries.

    T temp;
    detach_item(subset[i]->data,subset[i]->data_count,temp);
    ordered_insert( subset[i+1]->data, subset[i+1]->data_count, temp );
    data[i]=temp;
 //   ordered_insert(data,data_count,temp);
 //   detach_item(data,data_count,temp);


}


#endif // BTREE_H
