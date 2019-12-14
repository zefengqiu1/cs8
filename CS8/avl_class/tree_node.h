#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <iostream>

using namespace std;


template <typename T>
struct tree_node{
    T _item;
    tree_node<T>* _left;
    tree_node<T>* _right;
    int _height;

    int balance_factor(){
        //balance factor = height of the right subtree
        //                        - the height of the left subtree
        //a NULL child has a height of -1
        //a leaf has a height of 0
        if(_right!=nullptr && _left!=nullptr)
        {
            return _right->_height-_left->_height;
        }else if( _right==nullptr &&_left!=nullptr)
        {
            return -1-(_left->_height);
        }else if (_right!=nullptr && _left==nullptr) {
            return _right->_height-(-1);
        }
        else
        {
            return 0;
        }

    }


    int height(){
        // Height of a node is 1 + height of the "taller" child
        //A leaf node has a height of zero: 1 + max(-1,-1)
        if(_left==nullptr && _right==nullptr)
        {
            return 1+max(-1,-1);
        }else if(_left==nullptr && _right!=nullptr)
        {
            return 1+max(-1,_right->_height);
        }else if(_right==nullptr && _left!=nullptr)
        {
            return 1+max(_left->_height,-1);
        }else
        {
            return 1+max(_left->_height,_right->_height);
        }
    }

    int update_height(){
        //set the _height member variable (call height();)
       return _height=height();
    }

    tree_node(T item=T(), tree_node* left=NULL,
                          tree_node* right=NULL):
                    _item(item), _left(left), _right(right)
    {

        _height=0;
        //don't forget to set the _height.
    }
    friend ostream& operator <<(ostream& outs,
                                const tree_node<T>& t_node){
        outs<<"|"<<t_node._item<<"|";
    }
};
#endif // TREE_NODE_H
