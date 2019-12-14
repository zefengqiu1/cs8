#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <iomanip>
#include "btree_function.h"
//#include "constant.h"


using namespace std;
const bool DEBUG_CONST=true;

template <class T>
class BTree
{
public:

    //--------------------------------------------------

    BTree(bool dups=false);
    //big three:
    BTree(const BTree<T>& other);
    ~BTree();
    BTree<T>& operator =(const BTree<T>& RHS);

    void print_tree(int level = 0, ostream &outs=cout) const; //print a readable version of the tree

    friend ostream& operator<<(ostream& outs, const BTree<T>& print_me){
        print_me.print_tree(0, outs);
        return outs;
    }
    int size() const;                           //count the number of elements in the tree
    bool empty() const;                         //true if the tree is empty


    void clear_tree();                          //clear this object (delete all nodes etc.)
    void copy_tree(const BTree<T>& other);      //copy other into this object

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
        subset[i] = NULL;
    }
    child_count = 0;
}

template <class T>
BTree<T>::BTree(const BTree<T>& other){

    copy_tree(other);
}

template <class T>
BTree<T>::~BTree<T>(){
   if(is_leaf())
   {
    clear_tree();
   }else
   {
       data_count=0;
   }

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
    for(int i = 0; i < child_count; i++)
    {
        subset[i]->clear_tree();
       // delete subset[i];
       // subset[i] = NULL;
    }
    child_count=0;


}

template <class T>
void BTree<T>::copy_tree(const BTree<T>& other){


    clear_tree();   //clear the tree
    dups_ok = other.dups_ok;
    child_count = other.child_count;
    copy_array(data, other.data, data_count, other.data_count);
    for(int i=0; i<child_count; i++){
        subset[i] = new BTree<T>;
        subset[i]->copy_tree(*other.subset[i]);
    }
}

//---------------------------------------------------------------------
//            C O N T A I N S / F I N D / G E T / E T C .
//---------------------------------------------------------------------
template <class T>
bool BTree<T>::contains(const T& entry){
    const bool debug = false;
    if(debug){
        cout<<"contains:"<<endl;
    }
    int i= first_ge(data, data_count, entry);
    if(debug){
        cout<<"i:"<<i<<endl;
        cout<<"data_count:"<<data_count<<endl;
    }
    bool found = (i<data_count && data[i] == entry);
    if(found){
        if(debug)
            cout<<"in"<<endl;
        return true;
    }
    else{
        if(debug)
            cout<<"in else"<<endl;
        if(is_leaf()){
            if(debug)
                cout<<"is leaf";
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
    const bool debug = false;
    if(debug){
        cout<<"contains:"<<endl;
    }
    int i= first_ge(data, data_count, entry);
    if(debug){
        cout<<"i:"<<i<<endl;
        cout<<"data_count:"<<data_count<<endl;
    }
    bool found = (i<data_count && data[i] == entry);
    if(found){
        if(debug)
            cout<<"in"<<endl;
        return true;
    }
    else{
        if(debug)
            cout<<"in else"<<endl;
        if(is_leaf()){
            if(debug)
                cout<<"is leaf";
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
        return data[i];
    else{
        if(!is_leaf())
            return subset[i]->get_ex(entry);
        else
            assert(found);
    }
}
template <class T>
T& BTree<T>::get_ex(const T& entry){
    if(DEBUG_CONST)
        cout<<" get_ex in btree is being called"<<endl;
    int i = first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i]==entry);
    if (found){
        return data[i];
    }
    else{
        if(!is_leaf()){
            return subset[i]->get_ex(entry);
        }
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
    //in order for this class to be able to keep track of the number of the keys, this function (and the functions
    //  it calls ) must return a success code.
    //If we are to keep track of the number the keys (as opposed to key/values) then the success
    //  code must distinguish between inserting a new key, or adding a new key to the existing key.
    //  (for "dupes_ok")
    //
    //loose_insert this entry into this root.
    //loose_insert(entry) will insert entry into this tree. Once it returns, all the subtrees are valid
    //  btree subtrees EXCEPT this root may have one extra data item:
    //    in this case (we have excess in the root)
    //      create a new node, copy all the contents of this root into it,
    //      clear this root node,
    //      make the new node this root's only child (subset[0])
    //
    //Then, call fix_excess on this only subset (subset[0])

    loose_insert(entry);
    //when the root is need to be fix_excess
    if(data_count> MAXIMUM){
        BTree<T>* item = new BTree<T>;
        copy_array(item->data, data, item->data_count, data_count);
        copy_array(item->subset, subset, item->child_count, child_count);
       // print_array(data,data_count);
//        cout<<*item<<endl;
//        cout<<item->data_count;
        data_count = 0;
        child_count = 1;
        subset[0] = item;
        //cout<<*subset[0];
       // cout<<subset[0]->data_count<<endl;
        fix_excess(0);
    }
}

template <typename T>
void BTree<T>::loose_insert(const T& entry){
    /*
       int i = first_ge(data, data_count, entry);
       bool found = (i<data_count && data[i] == entry);

       three cases:
         a. found: deal with duplicates
         ! found:
         b. leaf : insert entry in data at position i
         c. !leaf: subset[i]->loose_insert(entry)
                   fix_excess(i) if there is a need
            |   found     |   !found        |
      ------|-------------|-----------------|-------
      leaf  |  a. Deal    | b: insert entry |
            |     with    |    at data[i]   |
      ------|  duplicates |-----------------|-------
            |             | d: subset[i]->  |
      !leaf |             |    loose_insert |
            |             |    fix_excess(i)|
      ------|-------------|-----------------|-------
    */

    int index = first_ge(data, data_count, entry);
    bool found = (index < data_count && data[index]== entry);
    if(found){
        /*
        if found, for map: need to rewrite the entry
        so comment this for "map".
        cout<<"Already have this item!"<<endl;
        */
        //when test btree in main, need to use = only.
        data[index] = entry;
//        return;
        //when test map or mmap in main, can use any of these two
//        data[index] = data[index] + entry;
//        data[index] += entry;
    }

    // not found
    else{
        if(is_leaf()){
            insert_item(data, index, data_count, entry);
        }
        else{
            subset[index]->loose_insert(entry);
            //only this position need to be fixed
            if(subset[index]->data_count > MAXIMUM)
                fix_excess(index);
        }
    }
}

template <typename T>
void BTree<T>::fix_excess(int i){

    //this node's child i has one too many items: 3 steps:
    //1. add a new subset at location i+1 of this node
    insert_item(subset, i+1, child_count, new BTree<T>);

    //2. split subset[i] (both the subset array and the data array) and move half into
    // subset[i+1] (this is the subset we created in step 1.)
    split(subset[i]->data, subset[i]->data_count, subset[i+1]->data, subset[i+1]->data_count);
    if(!subset[i]->is_leaf())
        split(subset[i]->subset, subset[i]->child_count, subset[i+1]->subset, subset[i+1]->child_count );


    //3. detach the last data item of subset[i] and bring it and insert it into this node's data[]
    // //Note that this last step may cause this node to have too many items. This is OK. This will be
    // dealt with at the higher recursive level. (my parent will fix it!)
    T temp;
    detach_item(subset[i]->data, subset[i]->data_count, temp);
    ordered_insert(data, data_count, temp );
}

template <typename T>
void BTree<T>::remove(const T& entry){
    //Loose_remove the entry from this tree.
    //once you return from loose_remove, the root (this object) may have no data and only a single subset
    //now, the tree must shrink:
    //  point a temporary pointer (shrink_ptr) and point it to this root's only subset
    //  copy all the data and subsets of this subset into the root (through shrink_ptr)
    //  now, the root contains all the data and poiners of it's old child.
    //  now, simply delete shrink_ptr (blank out child), and the tree has shrunk by one level.
    //  Note, the root node of the tree will always be the same, it's the child node we delete
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
    const bool debug = false;
    if(debug)
        cout<<"loose remove is being called"<<endl;
    //four cases:
    int i=first_ge( data, data_count, entry );
    bool found=( i<data_count && data[i]==entry );


    //a. leaf && not found target: there is nothing to do
    if(is_leaf() && (!found))
        cout<<"do nothing"<<endl;


    //b. leaf && found target: just remove the target
    else if(is_leaf() && found){
        if(debug)
            cout<<" is leaf and found"<<endl;
        T temp=entry;
        delete_item( data, i, data_count, temp);
    }


    //c. not leaf and not found target: recursive call to loose_remove
    else if((!is_leaf()) && (!found)){
        if(debug)
            cout<<"!is leaf && !found"<<endl;
        subset[i]->loose_remove(entry);
    }


    //d. not leaf and found: replace target with largest child of subset[i]
    else if((!is_leaf()) && found){
        if(debug)
            cout<<"!is_leaf && found"<<endl;
        T temp;
        subset[i]->remove_biggest(temp);
        swap(data[i], temp);
    }

    //at last, fix_shortage
    if((!is_leaf()) && subset[i]->data_count < MINIMUM)
        fix_shortage(i);

    /*
             |   !found    |   found       |
       ------|-------------|---------------|-------
       leaf  |  a: nothing | b: delete     |
             |     to do   |    target     |
       ------|-------------|---------------|-------
       !leaf | c: loose_   | d: replace    |
             |    remove   |               |
             |fix_shortage |  w/ biggest   |
       ------|-------------|---------------|-------
    */
}

template <typename T>
void BTree<T>::fix_shortage(int i){
    const bool debug = false;
    if(debug)
        cout<<"fix is being called"<<endl;
    /* fix shortage in subtree i:
         * if child i+1 has more than MINIMUM, rotate left
         * elif child i-1 has more than MINIMUM, rotate right
         * elif there is a right child, merge child i with next child
         * else merge child i with left child
         */

    //when rotate left, i has to have right subset, so i<child_count-1
    if(i<child_count-1 && subset[i+1]->data_count> MINIMUM){
        if(debug){
            cout<<"in first if"<<endl;
            cout<<"child_count:"<<child_count<<endl;
        }
        rotate_left(i+1);
    }

    //when rotate righe, i has to have left subset, so can't be 0 and less then child_count
    else if(i>0 && i<child_count && subset[i-1]->data_count> MINIMUM ){
        if(debug){
            cout<<"in second if"<<endl;
            cout<<"child_count:"<<child_count<<endl;
        }

        rotate_right(i-1);
    }

    //when merge with subset[i-1], means there has to be a subset[i-1], so i>0
    else if(i>0){
        if(debug){
            cout<<"in last if"<<endl;
            cout<<"child_count:"<<child_count<<endl;
        }
        merge_with_next_subset(i-1);
    }

    else{
        if(debug){
            cout<<"in third if"<<endl;
            cout<<"child_count:"<<child_count<<endl;
        }
        merge_with_next_subset(i);
    }
}

template <typename T>
void BTree<T>::remove_biggest(T& entry){
    const bool debug = false;
    if(debug)
        cout<<"remove_biggest is being called"<<endl;
    // Keep looking in the last subtree (recursive)
    //  until you get to a leaf.
    // Then, detach the last (biggest) data item
    //
    // after the recursive call, fix shortage.
    if(!is_leaf()){
        if(debug){
            cout<<"in !is_leaf"<<endl;
        }
        subset[child_count-1]->remove_biggest(entry);
    }
    else{
        if(debug){
            cout<<"in else"<<endl;
        }
        detach_item(data, data_count, entry);
    }
    if(!is_leaf() && subset[child_count-1]->data_count<MINIMUM){
        fix_shortage(child_count-1);
    }
}
template <typename T>
void BTree<T>::merge_with_next_subset(int i){
    const bool debug = false;
    if(debug)
        cout<<"merge next is being called"<<endl;
    //Merge subset[i] with subset [i+1] with data[i] in the middle


    //1. remove data[i] from this object
    T temp;
    delete_item(data, i, data_count, temp);
    if(debug)
        cout<<"delete item"<<endl<<*this<<endl;


    //2. append it to child[i]->data
    ordered_insert(subset[i]->data, subset[i]->data_count, temp);
    if(debug)
        cout<<"order insert item"<<endl<<*this<<endl;


    //3. Move all data items from subset[i+1]->data to subset[i]->data
    merge(subset[i]->data, subset[i]->data_count, subset[i+1]->data, subset[i+1]->data_count);
    if(debug)
        cout<<"merge item"<<endl<<*this<<endl;


    //4. Move all subset pointers from subset[i+1]->subset to subset[i]->subset
    if(!(subset[i+1]->is_leaf())){
        if(debug)
            cout<<"in if"<<endl;
        merge(subset[i]->subset,subset[i]->child_count,subset[i+1]->subset,subset[i+1]->child_count);
    }
    if(debug)
        cout<<"after if:"<<endl<<*this<<endl;


    //5. delete subset[i+1] (store in a temp ptr)
    subset[i+1]->data_count=0;
    subset[i+1]->child_count=0;
    delete subset[i+1];
    if(debug)
        cout<<"after delete:"<<endl<<*this<<endl;


    //6. delete temp ptr
    BTree<T>* hold;
    delete_item(subset, i+1, child_count, hold);
    if(debug)
        cout<<"last:"<<endl<<*this<<endl;
}
template <typename T>
void BTree<T>::rotate_left(int i){
    /*
     * (0 < i < child_count) and (subset[i]->data_count > MINIMUM)
     * subset[i-1] has only MINIMUM - 1 entries.
     *
     * item transfers from child[i] to child [i-1]
     *
     * FIRST item of subset[i]->data moves up to data to replace data[i-1],
     * data[i-1] moves down to the RIGHT of subset[i-1]->data
     *
     *  i = 1:
     *              [50 100]
     *  [  ]        [65 75]       ....
     *            [a]  [b]  [c]
     *
     *  65 move up to replace 50 (data[i])
     *  65's child (its child 0) moves over to be the child of 50
     *  50 moves down to the right of subset[i]->data
     *
     *              [65 100]
     *  [50]         [ 75 ]       ....
     *     [a]      [b]  [c]
     * last item of subset[i-1]->data moves up to data,
     * data[i] moves down to the RIGHT of subset[i]->data
     */
    T temp;

    delete_item( data, i-1, data_count, temp );
    ordered_insert(subset[i-1]->data, subset[i-1]->data_count, temp);

    delete_item(subset[i]->data, 0, subset[i]->data_count, temp);
    ordered_insert(data, data_count, temp );

    // If necessary, shift first subset of subset[i] to end of subset[i-1]
    if (!subset[i]->is_leaf()){
        BTree<T>* child_temp;
        delete_item( subset[i]->subset, 0,subset[i]->child_count, child_temp );
        attach_item( subset[i-1]->subset, subset[i-1]->child_count, child_temp );
    }

}

template <typename T>
void BTree<T>::rotate_right(int i){
    /* (i < child_count - 1) and (subset[i]->data_count > MINIMUM)
     * subset[i+ 1] has only MINIMUM - 1 entries.
     *
     * item transfers from child[i] to child [i+1]
     *
     * LAST item of subset[i]->data moves up to data to replace data[i],
     * data[i] moves down to the LEFT of subset[i+1]->data
     *
     * i = 1
     *                     [50 100]
     *      [20 30]        [65 75]          [ ]
     *  [..] [..] [..]   [a] [b] [c]        [..]
     *
     *  75 moves up to replace 100 (data[i])
     *  75's child (its last child) moves over to be the (child 0) child of 100
     *  100 moves down to subset[i]->data
     *
     *                     [50 75]
     *      [20 30]          [65]          [100]
     *  [..] [..] [..]     [a] [b]        [c] [..]
     * last item of subset[i-1]->data moves up to data,
     * data[i] moves down to the RIGHT of subset[i]->data
     */
    T temp;

    delete_item(data, i, data_count, temp );
    ordered_insert( subset[i+1]->data, subset[i+1]->data_count, temp );

    detach_item(subset[i]->data, subset[i]->data_count, temp );
    ordered_insert(data, data_count, temp );

    // If necessary, shift last subset of subset[i] to front of subset[i+1]
    if (!subset[i]->is_leaf()){
        BTree<T>* child_temp;
        detach_item( subset[i]->subset, subset[i]->child_count, child_temp );
        insert_item( subset[i+1]->subset, 0, subset[i+1]->child_count, child_temp );
    }
}

template <typename T>
bool BTree<T>::is_valid(){
    const bool debug = false;
    if(debug)
        cout<<"is valid being called"<<endl;

    /*
     * need to separate is_leaf and !is_leaf situation
     * all situation as below are return false, at the end, return true
     *
     * if(!is_leaf)
     *     a. check child_count and data_count is valid or not?
     *     b. check if data is in order ( data[1] > data[0])
     *     c. check subset bigger or smaller than parent
     *
     *                         A          B
     *                       [25    |    75]
     *               [5 |10]    [30 | 50]   [80 | 90]
     *               C   D       E    F      G    H
     *      like this btree.
     *      Cuz we already check if data is in order, so only need
     *       check two situation as below.
     *       1) last data of left subset need to be less than data[i]
     *          D < A,  F < B
     *       2) first data of right subset need to be grater than data[data_count -1]
     *          E> A,  G > B
     *
     *      3) Also, the biggest item of last subset of D need to be smaller than A.
     *
     *      d. recursion calling
     *
     * else
     *      a. check count
     *      b. check order
     *
     *
     * */

    if(!is_leaf()){
        if(debug)
            cout<<"! leaf"<<endl;

        //check count is valid
        if(child_count < data_count+1){
            if(debug)
                cout<<" not enough child_count"<<endl;
            return false;
        }
        if(child_count > MAXIMUM + 1){
            if(debug)
                cout<<" too many child"<<endl;
            return false;
        }
        if(data_count > MAXIMUM){
            if(debug)
                cout<<"too many data_count"<<endl;
            return false;
        }
        if(data_count < MINIMUM){
            if(debug)
                cout<<" too few data"<<endl;
        }
        //check order
        if(data_count == 2){
            if(debug)
                cout<<"has two data"<<endl;
            if(data[0] > data[1]){
                if(debug)
                    cout<<"not in right order"<<endl;
                return false;
            }
        }
        //check subset bigger or smaller than parent
        for(int i=0; i<=data_count; i++){
            if(debug)
                cout<<"in for loop to compare subset and data"<<endl;

            //if is checking 1)
            if(i!= data_count){
                if(debug){
                    cout<<"i:"<<i<<endl;
                    cout<<"data_count:"<<data_count<<endl;
                    cout<<"data[i]:"<<data[i]<<endl;
                    cout<<"subset[i]->data[data_count-1]:"<<subset[i]->data[(subset[i]->data_count)-1]<<endl;
                }
                if(data[i] <= subset[i]->data[(subset[i]->data_count)-1]){
                    if(debug){
                        cout<<"data[i]:"<<data[i]<<endl;
                        cout<<"subset[i]->data[data_count-1]:"<<subset[i]->data[data_count-1]<<endl;
                    }
                    return false;
                }
            }

            //else is checking 2)
            else{
                if(debug){
                    cout<<"in else:"<<endl;
                    cout<<"i:"<<i<<endl;
                    cout<<"data_count:"<<data_count<<endl;
                    cout<<"Data[i-1]:"<<data[i-1]<<endl;
                    cout<<"subset[i]->data[subset[i]->data_count-1]:"<<subset[i]->data[subset[i]->data_count-1]<<endl;
                }
                if(data[i-1] >= subset[i]->data[subset[i]->data_count-1]){
                    return false;
                }
            }
        }

        //recursion calling
        for(int i=0; i<child_count; i++){
            if(!subset[i]->is_valid()){
                return false;
            }
        }
    }

    //this part is checking btree has only 1 level
    else{
        if(data_count> MAXIMUM)
            return false;
        else if(data_count == 2){
            if(data[1] <= data[0])
                return false;
        }
    }
    return true;
}


#endif // BTREE_H
