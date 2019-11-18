#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include "node.hpp"

template <class T>
class BST
{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);

private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;
};

template <class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template <class T>
BST<T>::~BST()
{
    root = NULL;
    while (root != NULL)
    {
        remove(root->get_data());
    }
}

template <class T>
std::vector<T> *BST<T>::inorder()
{
    std::vector<T> *vec = new std::vector<T>;

    /*if (root == NULL)
    {
        return;
    }
     
    inorder(root.get_left());
    inorder(root.get_right());*/
    

    if (root != NULL)
    {
        root->get_left();
        root->get_right();
    }
    

    /*if (begin > end)
    {
        return NULL;
    }

    i = max (inorder, begin, end);
    Node *root = new(inorder[i]);

    if (begin == end)
    {
        return root;
    }

    root->get_left() = BST (inorder, begin, i - 1);  
    root->get_right() = BST (inorder, i + 1, end); */ 

    return vec;
}

template <class T>
std::vector<T> *BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;
    return vec;
}

template <class T>
std::vector<T> *BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;

    return vec;
}

template <class T>
void BST<T>::insert(T new_data)
{
    /*Node<T> *createNode;
    int *i;

    i = 0;

    if (new_data == NULL)
    {
        return;
    }
    else if (new_data < root->i)
    {
        root->get_left(), i;
    }
    else
    {
        root->get_right(), i;
    }
    return;*/
    //Node<T>* BST<T>::search(T) [width T = int];
}

template <class T>
Node<T> *BST<T>::search(T val)
{
    /*int left = 0;
    int right = 0;
   if (root == NULL)
   {
       return NULL;
   }
   else if (root->get_data() == val)
    {
        return root;
    }
    else
    {
        Node<T> *left = search(root->get_left(), val);
        Node<T> *right = search(root->get_right(), val);

        if (left == 0 && right == 0)
        {
            return 0;
        }
        else
        {
            return left+right+1;
        }
    }*/

    /*int left = 0;
    int right = 0;
   if (root == NULL)
   {
       return 1;
   }
   else if (root->get_data() == val)
    {
        return 1;
    }
    else if (root->get_data() > val)
    {
        return search(root->get_left(), val);
    }
    else
    {
        return search(root->get_right(), val);
    }*/
    Node<T> *cur_Node;

    while (root != NULL)
    {
        if (root->get_data() == val)
        {
            break;
        }
        else if (root->get_data() != val)
        {
            root->get_left();
        }
        else
        {
            root->get_right();
        }
    return root;
    }

}

template <class T>
void BST<T>::remove(T val)
{
    Node<T> *temp_Node = NULL;
    Node<T> *cur_Node = root;

    while(cur_Node != NULL)
    {
        if(cur_Node->get_data() == val)
        {
            if(!cur_Node->get_left() && !cur_Node->get_right())
            {
                 if (!temp_Node)
                 {
                     root = NULL;
                 }
                 else if (temp_Node->get_left() == cur_Node)
                 {
                     temp_Node->set_left(NULL);
                 }
                 else
                 {
                     temp_Node->set_right(NULL);
                 } 
            }
            else if (cur_Node->get_left() && !cur_Node->get_right())
            {
                 if (!temp_Node)
                 {
                     root = cur_Node->get_left();
                 }
                 else if (temp_Node->get_left() == cur_Node)
                 {
                     temp_Node->set_left(cur_Node->get_left());
                 }
                 else
                 {
                     temp_Node->set_right(cur_Node->get_left());
                 } 
            }
            else if (!cur_Node->get_left() && cur_Node->get_right())
            {
                if (!temp_Node)
                {
                    root = cur_Node->get_right();
                }   
                else if (temp_Node->get_left() == cur_Node)
                {
                      temp_Node->set_left(cur_Node->get_right());
                }
                 else
                {
                    temp_Node->set_right(cur_Node->get_right());
                } 
            }
            else
            {
                Node<T> *suc_Node = cur_Node->get_right();
                while (suc_Node->get_left() != NULL)
                {
                    suc_Node = suc_Node->get_left();
                    int suc_Data = suc_Node->get_data();
                    remove(suc_Node->get_data());
                    suc_Node->set_data(suc_Data);
                }
                return;
            }
        }
        else if (cur_Node->get_data() < val)
        {
            temp_Node = cur_Node;
            cur_Node = cur_Node->get_right();
        }
        else
        {
            temp_Node = cur_Node;
            cur_Node = cur_Node->get_left();
        }
    }         
    return;
}

template <class T>
int BST<T>::get_size()
{
       
}