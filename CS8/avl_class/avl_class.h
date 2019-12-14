#ifndef AVL_CLASS_H
#define AVL_CLASS_H

#include "avl_function.h"


template<typename T>
class avl{
public:
    avl();
    avl(const T* sorted_list, int size=-1);
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    avl(const avl<T>& copy_me);

    avl<T>& operator =(const avl<T>& rhs)
    {
        if (this == &rhs)
        {
            return *this;
        }
        _root = tree_copy(rhs.root);
        return *this;
    }

    ~avl();
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void insert(const T& insert_me);
    void erase(const T& target);
    bool search(const T& target, tree_node<T>* & found_ptr);
    void clear();

    friend ostream& operator <<(ostream& outs, const avl<T>& tree)
    {
        tree_print_debug(tree._root, 0,outs);
        return outs;
    }
    avl<T>& operator +=(const avl<T>& rhs);

private:
    tree_node<T>* _root;
};

template<typename T>
avl<T>::avl()
{
    _root=nullptr;
}

template  <typename T>
avl<T>::avl(const T* sorted_list, int size)
{
    _root = tree_from_sorted_list(sorted_list, size );
}

template<typename T>
avl<T>::avl(const avl<T>& copy_me)
{
    _root = tree_copy(copy_me.root);
}

template<typename T>
avl<T>::~avl()
{
    tree_clear(_root);
}

template<typename T>
void avl<T>::insert(const T& insert_me)
{
    tree_insert(_root, insert_me);
}

template <typename T>
void avl<T>::erase(const T& target)
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
bool avl<T>::search(const T& target, tree_node<T>*& found_ptr)
{
    return tree_search(_root, target, found_ptr);
}

template<typename T>
void avl<T>::clear()
{
    tree_clear(_root);
}

#endif // AVL_CLASS_H
