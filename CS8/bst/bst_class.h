#ifndef BST_CLASS_H
#define BST_CLASS_H

#include "bst_function.h"


template<typename T>
class BST{
public:
    BST();
    BST(const T* sorted_list, int size=-1);
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    BST(const BST<T>& copy_me);

    BST<T>& operator =(const BST<T>& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        _root = tree_copy(rhs.root);
        return *this;
    }

    ~BST();
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void insert(const T& insert_me);
    void erase(const T& target);
    bool search(const T& target, tree_node<T>* & found_ptr);
    void clear();

    friend ostream& operator <<(ostream& outs, const BST<T>& tree)
    {
        tree_print_debug(tree._root, 0,outs);
        return outs;
    }
    BST<T>& operator +=(const BST<T>& rhs);

private:
    tree_node<T>* _root;
};

template<typename T>
BST<T>::BST()
{
    _root=nullptr;
}

template  <typename T>
BST<T>::BST(const T* sorted_list, int size)
{
    _root = tree_from_sorted_list(sorted_list, size );
}

template<typename T>
BST<T>::BST(const BST<T>& copy_me)
{
    _root = tree_copy(copy_me.root);
}

template<typename T>
BST<T>::~BST()
{
    tree_clear(_root);
}

template<typename T>
void BST<T>::insert(const T& insert_me)
{
    tree_insert(_root, insert_me);
}

template <typename T>
void BST<T>::erase(const T& target)
{
    if(tree_erase(_root, target))
    {
        cout << "Erase " << target << " successfully." << endl;
    }
    else {
        cout << "fail "<<target<<" not found" <<endl;
    }
}

template<typename T>
bool BST<T>::search(const T& target, tree_node<T>*& found_ptr)
{
    return tree_search(_root, target, found_ptr);
}

template<typename T>
void BST<T>::clear()
{
    tree_clear(_root);
}

#endif // BST_CLASS_H
