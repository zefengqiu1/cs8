#ifndef BTREE_H
#define BTREE_H
#include "b_tree_function.h"
#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class BTree
{
public:
    BTree(bool dups = false);
    //big three:
    BTree(const BTree<T>& other);
    ~BTree();
    BTree<T>& operator =(const BTree<T>& RHS);

    void insert(const T& entry);                //insert entry into the tree
    void remove(const T& entry);                //remove entry from the tree

    void clear_tree();                          //clear this object (delete all nodes etc.)
    void copy_tree(const BTree<T>& other);      //copy other into this object

    bool contains(const T& entry);              //true if entry can be found in the array
    T& get_ex(const T& entry);
    const T& get_ex(const T& entry) const;

    const T& get(const T& entry) const;
    T& get(const T& entry);                     //return a reference to entry in the tree
    T* find(const T& entry);                    //return a pointer to this key. NULL if not there.

    int size() const;                           //count the number of elements in the tree
    bool empty() const;                         //true if the tree is empty

    void print_tree(int level = 0, ostream &outs=cout) const; //print a readable version of the tree



    bool is_valid(); //check is btree_valid;

    friend ostream& operator<<(ostream& outs, const BTree<T>& print_me){
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
    BTree* subset[MAXIMUM + 2];                     //subtrees

    bool is_leaf() const {return child_count==0;}   //true if this is a leaf node

    //insert element functions
    void loose_insert(const T& entry);              //allows MAXIMUM+1 data elements in the root
    void fix_excess(int i);                         //fix excess of data elements in child i

    //remove element functions:
    void loose_remove(const T& entry);              //allows MINIMUM-1 data elements in the root
    void fix_shortage(int i);                       //fix shortage of data elements in child i

    void remove_biggest(T& entry);                  //remove the biggest child of this tree->entry
    void rotate_left(int i);                        //transfer one element LEFT from child i
    void rotate_right(int i);                       //transfer one element RIGHT from child i
    void merge_with_next_subset(int i);             //merge subset i with subset i+1

};




template<class T>
BTree<T>::BTree(bool dups )
{
    dups_ok=dups;
    for(int i=0;i<MAXIMUM + 2;i++)
    {
        subset[i]=nullptr;
    }
    data_count=0;
    child_count=0;
}

template<class T>
BTree<T>::BTree(const BTree<T>& other)
{
    copy_tree(other);
}


template <class T>
BTree<T>::~BTree<T>(){

    clear_tree();
   // cout<<"1"<<endl;
}


template <class T>
int BTree<T>::size()const{
    return data_count;
}

template <class T>
bool BTree<T>::empty()const{
    return data_count==0;
}

template <class T>
void BTree<T>::clear_tree(){

    //set data_count to 0

    data_count = 0;
    for(int i=0;i<child_count;i++)
    {
        subset[i]->clear_tree();
       // BTree<T>* pointer =subset[i];
        delete subset[i];
        subset[i]=nullptr;
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


template <class T>
BTree<T>& BTree<T>::operator=(const BTree<T>& RHS){
    if(this!=&RHS){
        clear_tree();
        copy_tree(RHS);
    }
    return *this;
}

template<class T>
void BTree<T>::insert(const T& entry)
{
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
      //warp the original whole things to be only child of new root.
      //then do the fix_excess.
       if(data_count> MAXIMUM){
           BTree<T>* copy_Btree = new BTree<T>;
           copy_array(copy_Btree->data, data, copy_Btree->data_count, data_count);
           copy_array(copy_Btree->subset, subset, copy_Btree->child_count, child_count);
           data_count = 0;
           child_count = 1;
           subset[0] = copy_Btree;
           fix_excess(0);
       }


}

template<class T>
void BTree<T>::loose_insert(const T& entry)
{

//          int i = first_ge(data, data_count, entry);
//          bool found = (i<data_count && data[i] == entry);

//          three cases:
//            a. found: deal with duplicates
//            ! found:
//            b. leaf : insert entry in data at position i
//            c. !leaf: subset[i]->loose_insert(entry)
//                      fix_excess(i) if there is a need
//               |   found     |   !found        |
//         ------|-------------|-----------------|-------
//         leaf  |  a. Deal    | b: insert entry |
//               |     with    |    at data[i]   |
//         ------|  duplicates |-----------------|-------
//               |             | d: subset[i]->  |
//         !leaf |             |    loose_insert |
//               |             |    fix_excess(i)|
//         ------|-------------|-----------------|-------

    int i = first_ge(data,data_count,entry);
    bool found=(i<data_count && data[i]==entry);
    if(found)
    {
        data[i]=entry;//updata the entry;
    }else
    {
        if(is_leaf()) //not found and is leaf;
        {
            insert_item(data,i,data_count,entry);
        }else
        {
            subset[i]->loose_insert(entry);
            //if needs;
            if(subset[i]->data_count>MAXIMUM)
            {
                fix_excess(i);
            }

        }
    }
}

template<class T>
void BTree<T>::fix_excess(int i)
{
    //this node's child i has one too many items: 3 steps:
      //1. add a new subset at location i+1 of this node
      //2. split subset[i] (both the subset array and the data array) and move half into
      // subset[i+1] (this is the subset we created in step 1.)
      //3. detach the last data item of subset[i] and bring it and insert it into this node's data[]
      // //Note that this last step may cause this node to have too many items. This is OK. This will be
      // dealt with at the higher recursive level. (my parent will fix it!)

    insert_item(subset,i+1,child_count,new BTree<T>);//add new subset at i+1

    //move the child node(subset[i]) subset and data to the parent node(subset[i+1])
    split(subset[i]->data, subset[i]->data_count, subset[i+1]->data, subset[i+1]->data_count);
    split(subset[i]->subset, subset[i]->child_count, subset[i+1]->subset, subset[i+1]->child_count );

    T temp;
    detach_item(subset[i]->data, subset[i]->data_count, temp);//delete data from child node
    ordered_insert(data, data_count, temp);//insert to the parent data

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

        if(data_count<MINIMUM && child_count>0)//when root has no data then bring subset[0] to the root and delete
        {
             BTree<T>* temp=subset[0];
             copy_array(data,subset[0]->data,data_count,subset[0]->data_count);
             copy_array(subset,subset[0]->subset,child_count,subset[0]->child_count);
             temp->child_count=0;
             delete temp;
             temp=nullptr;
        }
}

template <typename T>
void BTree<T>::fix_shortage(int i){

//         fix shortage in subtree i:
//         * if child i+1 has more than MINIMUM, rotate left
//         * elif child i-1 has more than MINIMUM, rotate right
//         * elif there is a right child, merge child i with next child
//         * else merge child i with left child


   // if child i+1 has more than MINIMUM, rotate left
   // ask right child for help,then i has to be 0 or 1 since max child is 2 and no right child at 2.
    if(i<child_count-1 && subset[i+1]->data_count> MINIMUM){

        rotate_left(i+1);
    }

    //elif child i-1 has more than MINIMUM, rotate right
   //ask left child for help,then i has to be 1 or 2 since no left child at 0.
    else if(i>0 && i<child_count && subset[i-1]->data_count> MINIMUM ){
        rotate_right(i-1);
    }else if(i>0 ){   //when merge with subset[i-1], means there has to be a subset[i-1], so i>0
                        //when euqal i==1 can be merge right or merge left.
        merge_with_next_subset(i-1);
    }
    else{

        //merge with right
        merge_with_next_subset(i);
    }




}

template <typename T>
void BTree<T>::loose_remove(const T& entry){

    //four cases:
    int i=first_ge( data, data_count, entry );
    bool found=( i<data_count && data[i]==entry );

   if(is_leaf()&& !found)
   {
                                //reach the leaf and not found
   }else if(is_leaf() && found)
   {
     T item=entry;              // is leaf and found ,then delete
     delete_item(data,i,data_count,item);
   }else if((!is_leaf()) && !found)    //not reach the leaf and still not found then call loose_remove again
   {
        subset[i]->loose_remove(entry);
   }else if((!is_leaf()) && found)  //remove in the middle of tree
   {
        T item;
        subset[i]->remove_biggest(item);
        Swap(data[i],item);
   }

     //when delete at the place which is not leaf, take care of shortage situation
    //when recursion back, it will check the subset[i]
    if(!is_leaf() && subset[i]->data_count < MINIMUM)
        fix_shortage(i);


//             |   !found    |   found       |
//       ------|-------------|---------------|-------
//       leaf  |  a: nothing | b: delete     |
//             |     to do   |    target     |
//       ------|-------------|---------------|-------
//       !leaf | c: loose_   | d: replace    |
//             |    remove   |               |
//             |fix_shortage |  w/ biggest   |
//       ------|-------------|---------------|-------


}



template <typename T>
void BTree<T>::merge_with_next_subset(int i){
//
//     *  Merge subset[i] with subset [i+1] with data[i] in the middle
//     *
//     *   1. remove data[i] from this object
//     *   2. append it to child[i]->data
//     *   3. Move all data items from subset[i+1]->data to subset[i]->data
//     *   4. Move all subset pointers from subset[i+1]->subset to subset[i]->subset
//     *   5. delete subset[i+1] (store in a temp ptr)
//     *
//

    T temp;
    delete_item(data, i, data_count, temp);  //1
    ordered_insert(subset[i]->data,subset[i]->data_count,temp);//2
    merge(subset[i]->data,subset[i]->data_count,subset[i+1]->data,subset[i+1]->data_count);//3

    if(!(subset[i+1]->is_leaf())){  //4

       merge(subset[i]->subset,subset[i]->child_count,subset[i+1]->subset,subset[i+1]->child_count);

    }

    //5
       BTree<T>* hold;
       delete_item(subset, i+1, child_count, hold);//then delete subset[i+1];
       delete hold;
       hold=nullptr;
}


template <typename T>
void BTree<T>::rotate_left(int i)
{
    //( 0 < i < child_count) and (subset[i]->data_count > MINIMUM) ??
    //subset[i-1] has only MINIMUM - 1 entries.
    //i=1;

//     *
//     *              [50 100]
//     *  [  ]        [65 75]       ....
//     *            [a]  [b]  [c]
//     *
//     *  65 move up to replace 50 (data[i])
//     *  65's child (its child 0) moves over to be the child of 50
//     *  50 moves down to the right of subset[i]->data
//     *
//     *              [65 100]
//     *  [50]         [ 75 ]       ....
//     *     [a]      [b]  [c]


    //move the 50 to left_child,
    //then move up 65,last,
    //give the left child of 65 to be right child of 50

    T temp;
    delete_item(data,i-1,data_count,temp);
    ordered_insert(subset[i-1]->data,subset[i-1]->data_count,temp);//move 50 to left

    delete_item(subset[i]->data,0,subset[i]->data_count,temp); // move 65 up
    ordered_insert(data, data_count, temp);

    //take care of subset[i] is not leaf
    if(!subset[i]->is_leaf())
    {
        BTree<T>* transfer_child;
        delete_item( subset[i]->subset, 0,subset[i]->child_count, transfer_child );
        attach_item( subset[i-1]->subset, subset[i-1]->child_count, transfer_child );
    }
}


template <typename T>
void BTree<T>::rotate_right(int i){

//     * (i < child_count - 1) and (subset[i]->data_count > MINIMUM)
//     * subset[i+ 1] has only MINIMUM - 1 entries.
//    * i = 1
//        *                     [50 100]
//        *      [20 30]        [65 75]          [ ]
//        *  [..] [..] [..]   [a] [b] [c]        [..]
//        *
//        *  75 moves up to replace 100 (data[i])
//        *  75's child (its last child) moves over to be the (child 0) child of 100
//        *  100 moves down to subset[i]->data
//        *
//        *                     [50 75]
//        *      [20 30]          [65]          [100]
//        *  [..] [..] [..]     [a] [b]        [c] [..]



        //move the data[i] to the right child
        //move subset[i] child's data up level
        // last take care of subsut[i] is leaf or not
       T temp;
       delete_item(data, i, data_count, temp );
       ordered_insert( subset[i+1]->data, subset[i+1]->data_count, temp );

       detach_item(subset[i]->data, subset[i]->data_count, temp);
       ordered_insert(data, data_count, temp );

        //take care of subset[i] is not leaf
       if (!subset[i]->is_leaf()){
           BTree<T>* child_transfer;
           detach_item( subset[i]->subset, subset[i]->child_count, child_transfer );
           insert_item( subset[i+1]->subset, 0, subset[i+1]->child_count, child_transfer );
       }

}

template <typename T>
void BTree<T>::remove_biggest(T& entry){

    if(!is_leaf())   //go to the leaf to find the biggest one
    {
        subset[child_count-1]->remove_biggest(entry);
    }
    else{

        detach_item(data, data_count, entry);
    }

    // if it is lower than minimim after remove, then fix_shortage
    if(!is_leaf() && subset[child_count-1]->data_count<MINIMUM){
        fix_shortage(child_count-1);
    }

}


//---------------------------------------------------------------------
//            C O N T A I N S / F I N D / G E T / E T C .
//---------------------------------------------------------------------
template <typename T>
bool BTree<T>::contains(const T& entry){

    int i= first_ge(data, data_count, entry);
    bool found = (i<data_count && data[i] == entry);
    if(found)
    {
        return true;
    }else
    {
        if(is_leaf()) return false;
        else
        {
           return subset[i]->contains(entry); //not leaf keep calling contains to check
        }
    }
    //return false;
}
template <typename T>
T* BTree<T>::find(const T& entry){
    T* result =nullptr;
    if(contains(entry))
    {
        result=&get_ex(entry);
    }
    return result;
}

template <class T>
T& BTree<T>::get_ex(const T& entry){  //return entry reference
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
const T& BTree<T>::get_ex(const T& entry) const{ //return const and not able to make a change
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

template <typename T>
const T& BTree<T>::get(const T& entry)const{
    //const version of get and not able to add new node and crash the program
       return get_ex(entry);
}


template <typename T>
T& BTree<T>::get(const T& entry){
    //If entry is not in the tree, insert it
    //and call get_ex to  find it and return entry reference.
    if(!contains(entry)){
         insert(entry);
       }
       return get_ex(entry);
}

template <typename T>
void BTree<T>::print_tree(int level, ostream& outs) const{
    // do the recursion print
    // print the leaf first
/*
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
    */

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


template <typename T>
bool BTree<T>::is_valid(){
    const bool debug = false;
    if(debug)
        cout<<"is valid being called"<<endl;

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
                if(!(data[i-1] < subset[i]->data[subset[i]->data_count-1])){
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



//template <typename T>
//bool BTree<T>::is_valid(){

//    if(!is_leaf()) //
//    {
//         if(data_count>2) return false;
//         if(child_count>3) return false;
//         if(data_count==2)
//         {
//            if(!(data[0]<data[1])) return false;
//         }//check ascending for data


//         //check for subset[] and parent;

//         for(int i=0;i<=data_count;i++)
//         {
//             if(i==0)
//             {
//                 if(!(data[i]>subset[i]->data[subset[i]->data_count-1])) return false;
//             }
//             if(i==1)
//             {
//                // if(!is_gt(subset[i]->data,subset[i]->data_count,data[i])) return false;
//                    if(!(data[i]>subset[i]->data[subset[i]->data_count-1])) return false;
//             }

//             if(i==2)
//             {
//                if(data[i-1]>subset[i]->data[0]) return false;
//             }
//         }


//         for(int i=0;i<child_count;i++)
//         {
//             if(!subset[i]->is_valid())
//             {
//                 return false;
//             }
//         }

//    }else//check root
//    {
//        if(data_count>2) return false;
//        if(child_count>3) return false;

//        if(data_count==2)
//        {
//            if(!(data[0]<data[1])) return false;
//        }
//    }

//    return true;

//}

#endif // BTREE_H
