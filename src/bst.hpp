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
    // Recursive counter
    // param: Current node for count
    // returns: number of nodes found
    int count_rec(Node<T>* cur_Node);


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
    std::vector<int> inorder_Data;
    Node<T> *cur_Node;
    Node<T> *prev_Node; 
    
    cur_Node = root; 
    while (cur_Node != NULL) 
    { 
        if (cur_Node->get_left() == NULL) 
        { 
            inorder_Data.push_back(cur_Node->get_data()); 
            cur_Node = (cur_Node->get_right()); 
        } 
        else 
        { 
            prev_Node = cur_Node->get_left(); 

            while (prev_Node->get_right() != NULL && prev_Node->get_right() != cur_Node) 
                prev_Node = prev_Node->get_right(); 

            if (prev_Node->get_right() == NULL)
            { 
                prev_Node->set_right(cur_Node); 
                cur_Node = cur_Node->get_left(); 
            }
            else 
            {
                prev_Node->set_right(NULL); 
                inorder_Data.push_back(cur_Node->get_data()); 
                cur_Node = cur_Node->get_right(); 
            } 
        } 
    }
    *vec = inorder_Data;
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
    Node<T> * new_Node = NULL;
    Node<T> *prev_Node = NULL;
    Node<T> *temp_Node = NULL;

    new_Node = new Node<T>(new_data);
    temp_Node = root;

    while(temp_Node != NULL)
    {
        prev_Node = temp_Node;

        if(temp_Node->get_data() < new_Node->get_data())
        {
            temp_Node = temp_Node->get_right();
        } else 
        {
            temp_Node = temp_Node->get_left();
        }
    }

    if (prev_Node == NULL)
    {
        root = new_Node;
    } 
    else 
    {
        if (prev_Node->get_data() < new_Node->get_data())
        {
            prev_Node->set_right(new_Node);
        } else 
        {
            prev_Node->set_left(new_Node);
        }
    }
}

template <class T>
Node<T> *BST<T>::search(T val)
{
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
    if (root != NULL)
    {
        node_count = count_rec(root);
    }
    return node_count;
}

template<class T>
int BST<T>::count_rec(Node<T>* cur_Node)
{
    int rec_count = 1; 

    if (cur_Node->get_left() != NULL){
        rec_count += count_rec(cur_Node->get_left());
    }

    if (cur_Node->get_right() != NULL){
        rec_count += count_rec(cur_Node->get_right());
    }

    return rec_count;
}