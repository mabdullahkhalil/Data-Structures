#ifndef __AVL_H
#define __AVL_H
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;


template <class T>
struct AvLNode
{
    string value;
    T key;
    AvLNode *parent; // pointer to parent node
    AvLNode *left; // pointer to left child
    AvLNode *right; // pointer to right child
    
    /*You can add additional variables if necessary*/
    
    AvLNode(string Val, T k)
    {
        this->value = Val;
        this->key = k;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    }
};
template <class T>
class AvL
{
    AvLNode<T> *root;
    
public:
    // Constructor
    AvL();
    
    // Destructor
    ~AvL();
    
    // Insertion Function
    void insert(string val, T k); // inserts the given key value pair into the tree
    
    void delete_node(T k); // deletes the node for the given key
    
    AvLNode<T> *search(T k); // takes key as an input and returns the node pointer if key exists and NULL pointer if key does not exists
    
    void replace(T oldk, T newk); // replaces old key with the new key, value remains same.
    
    void balance(AvLNode<T> *n); //balancing the tree
    
    // rotation update functions.
    void updateLL(AvLNode<T> *n); // left left rotation
    void updateRR(AvLNode<T> *n); // left left rotation
    
    
    AvLNode<T>* checkbalance(AvLNode<T>* n);
    
    int nodeHeight(AvLNode<T> *n); // returns height of the subtree from given node
    
    AvLNode<T> *getRoot(); // returns root of the AVL tree
    
    /*You can add additional functions if necessary*/
};

#endif
