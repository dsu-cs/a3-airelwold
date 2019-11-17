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
    int i;
};

template <class T>
BST<T>::BST()
{
    root = NULL;
    i = 0;
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

    /*if (root != NULL)
    {
        root->get_left;
        root->get_right;
    }*/
    

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

    root->getleft() = BST (inorder, begin, i - 1);  
    root->getright() = BST (inorder, i + 1, end); */ 

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
    /*if (root == NULL)
    {
        root = createNode(new_data);
    }
    else if (new_data<=root->data)
    {
        root->left=insert(root->left, new_data);
    }
    else
    {
        root->right=insert(root->right, new_data);
    }
    return root;*/
    //Node<T>* BST<T>::search(T) [width T = int];
}

template <class T>
Node<T> *BST<T>::search(T val)
{
    while (root != NULL)
    {
        if (root->get_data() == val)
        {
            break;
        }
        root = root->get_left();
        root = root->get_right();
    }
    return root;
    
    /*while (root != NULL)
    {
        if (root->get_data() == val)
        {
        return(root);
        }
        else if (i )
        {
            root->get_left();
        }
        else
        {
            root->get_right();
        }
    return(NULL);
    }*/

}

template <class T>
void BST<T>::remove(T val)
{
}

template <class T>
int BST<T>::get_size()
{
    
}