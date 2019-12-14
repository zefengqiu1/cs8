#ifndef AVL_FUNCTION_H
#define AVL_FUNCTION_H
#include "tree_node.h"
#include <iomanip>

template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me);


template <typename T>
bool tree_search(tree_node<T>* root, const T& target,tree_node<T>* &found_ptr);

template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target);



template<typename T>
void tree_print(tree_node<T>* root, int level=0, ostream& outs=cout);



template<typename T>       //prints detailes info about each node
void tree_print_debug(tree_node<T>* root, int level=0, ostream& outs=cout);



template <typename T>       //clear the tree
void tree_clear(tree_node<T>* &root);


template <typename T>       //erase target from the tree
bool tree_erase(tree_node<T>*& root, const T& target);


template <typename T>       //erase rightmost node from the tree  // store the item in max_value
void tree_remove_max(tree_node<T>* &root, T& max_value);

template <typename T>       //Add tree src to dest
void tree_add(tree_node<T>* & dest, const tree_node<T>* src);


template <typename T>       //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root);


template <typename T>       // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int start,int end);




// ---------------- ROTATIONS --------------------------
template <typename T>
tree_node<T>* rotate_right(tree_node<T>* &root);

template <typename T>
tree_node<T>* rotate_right(tree_node<T>* &root) //left_node is not null.
{
     tree_node<T>* temp=root->_left;
     root->_left=temp->_right;
     temp->_right=root;
     root->update_height();
     temp->update_height();
     root=temp;
     return root;
}



template <typename T>
tree_node<T>* rotate_left(tree_node<T>* &root);


template <typename T>
tree_node<T>* rotate_left(tree_node<T>* &root)//ok
{

    tree_node<T>* temp=root->_right;
    root->_right=temp->_left;
    temp->_left=root;
    root->update_height();
    temp->update_height();
    root=temp;
    return root;
}


template <typename T>
tree_node<T>* rotate(tree_node<T>* & root); //decide which rotate is needed based on balance factor

template <typename T>
tree_node<T>* rotate(tree_node<T>* & root)
{
    tree_node<T>* temp=root;
    if(temp->balance_factor()==2)
    {
            temp=temp->_right;
            if(temp->balance_factor()>0)//right heavy
            {
                //right-right
              root=rotate_left(root);
            }else
            {
                //right-left heavy

                root->_right=rotate_right(temp);
                root= rotate_left(root);

            }
        }else if(temp->balance_factor()==-2)
        {

            temp=temp->_left;
            if(temp->balance_factor()<0)//left heavy
            {
                //right-right
              root=rotate_right(root);
            }else
            {
                //left-right heavy

                root->_left=rotate_left(temp);
                root= rotate_right(root);
            }
        }

    return root;
}



template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me)
{
    if(root==nullptr)
    {
        tree_node<T>* treenode=new tree_node<T>(insert_me);
        root=treenode;
    }else if(root->_item<=insert_me)
    {
        tree_insert(root->_right,insert_me);
        rotate(root);

    }else
    {
        tree_insert(root->_left,insert_me);
        rotate(root);
    }

      root->update_height();

}




template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target)
{
    if(root==nullptr) return nullptr;
    if(root->_item==target) return root;
    if(target<root->_item)
    {
       return tree_search(root->_left,target);
    }else{
       return tree_search(root->_right,target);
    }
}



template <typename T>
bool tree_search(tree_node<T>* root, const T& target,tree_node<T>* &found_ptr)
{
    if(root==nullptr) return false;
    if(root->_item==target)
    {
       found_ptr=root;
       return true;
    }
    if(target<root->_item)
    {
       return tree_search(root->_left,target,found_ptr);
    }else{
       return tree_search(root->_right,target,found_ptr);
    }
}


template<typename T>
void tree_print(tree_node<T>* root, int level, ostream& outs)
{
    if(root!=nullptr)
    {
        tree_print(root->_right,level+1,outs);
        outs<<setw(4*level)<<""<<"["<<root->_item<<"]"<<endl;
        tree_print(root->_left,level+1,outs);
    }

}



template<typename T>       //prints detailes info about each node
void tree_print_debug(tree_node<T>* root, int level, ostream& outs)
{
    if(root!=nullptr)
    {
        tree_print_debug(root->_right,level+1,outs);
        outs<<setw(10*level)<<""<<"["<<root->_item<<"]"<<"{"<<root->_height<<"}"<<root->balance_factor()<<endl;//<<"{"<<root->_height<<"}"
        tree_print_debug(root->_left,level+1,outs);
    }

}



template <typename T>       //clear the tree
void tree_clear(tree_node<T>* &root)
{
    if(root)
    {
        tree_clear(root->_left);
        tree_clear(root->_right);
        delete root;
        root=nullptr;
    }
}


template <typename T>       //erase target from the tree
bool tree_erase(tree_node<T>*& root, const T& target)
{

    bool flag=false;
   if(root!=nullptr)
   {
       if(root->_item==target) //find the target check whether any left node below the target
       {
           if(root->_left==nullptr)  // if no left node, then directly delete target and root point to the right.
           {
               tree_node<T>* pointer=root;
               root=root->_right;
               delete pointer;
               pointer=nullptr;
               return true;

           }else if(root->_left!=nullptr)  // if have left node,find the max and move the max to the top.then rotate.
           {
               T max;
               tree_remove_max(root->_left,max);
               tree_node<T>* newone= new tree_node<T>(max) ;
               newone->_left=root->_left;
               newone->_right=root->_right;
               delete root;
               root=newone;
               root->update_height();
               rotate(root);    //call rotate after finishing reconnect the node.
               return true;

           }
       }
       else if(target<=root->_item)
       {
          flag= tree_erase(root->_left,target);

       }else
       {
          flag= tree_erase(root->_right,target);
       }
   }
   root->update_height(); //when trackback call the rotate and update heigh again
   rotate(root);
   return flag;
}




template <typename T>       //erase rightmost node from the tree  // store the item in max_value
void tree_remove_max(tree_node<T>* &root, T& max_value)
{

        if(root!=nullptr)
        {
           max_value=root->_item;
           if(root->_right!=nullptr) //going to right side
           {
                tree_remove_max(root->_right,max_value);
                root->update_height();
                rotate(root);
           }else  //else root is the max.
           {
                if(root->_left!=nullptr)   //check any node in the left hand size if have then root =root_left
                {
                    tree_node<T>* temp=root;
                    root=root->_left;
                    delete temp;
                    temp=nullptr;

                }else    // if no, directly delete the target.
                {
                    delete root;
                    root=nullptr;

                }

           }
        }
}


template <typename T>       //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root)
{
    if(root!=nullptr)
    {
        return new tree_node<T>(root->_item,tree_copy(root->_left),tree_copy(root->_right));
    } else
    {
        return nullptr;
    }

}



template <typename T>       //Add tree src to dest
void tree_add(tree_node<T>* & dest, const tree_node<T>* src)
{

    if(src!=nullptr)
    {

        tree_add(dest,src->_left);
        tree_add(dest,src->_right);
        tree_insert(dest,src->_item);

    }

}



template <typename T>       // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int start,int end)
{
    if(start>end) return nullptr;
    int mid=(end+start)/2;
    tree_node<T>* root=new tree_node<T>(a[mid]);
    root->_left=tree_from_sorted_list(a,start,mid-1);
    root->_right=tree_from_sorted_list(a,mid+1,end);
    root->update_height();
    return root;
}


template <typename T>       // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int size)
{

   return tree_from_sorted_list(a,0,size-1);
}

#endif // AVL_FUNCTION_H
