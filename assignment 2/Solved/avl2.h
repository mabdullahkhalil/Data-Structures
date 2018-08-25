#ifndef __AVL2_H
#define __AVL2_H
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
    AvL(string filename);
    
    // Destructor
    ~AvL();
    
    // Insertion Function
    void insert(string ID, T scr); // inserts the given score ID pair into the tree
    
    void delete_node(T scr); // deletes the node for the given score
    
    AvLNode<T> *search(T scr); // takes score as an input and returns the node pointer if ID with that score exists and NULL pointer if score does not exist
    
    void replace(T oldS, T newS); // replaces old key with the new key, value remains same.
    
    int nodeHeight(AvLNode<T> *n); // returns height of the subtree from given node
    
    AvLNode<T> *getRoot(); // returns root of the AVL tree
    
    T* getTopFive(); // returns top 5 scores of class in an array
    
    T getAverage(); // returns average of all scores
    
    void displayAll(AvLNode<T> *P); // displays scores of all students
    
    
    
    void balance(AvLNode<T> *n); //balancing the tree
    
    // rotation update functions.
    void updateLL(AvLNode<T> *n); // left left rotation
    void updateRR(AvLNode<T> *n); // left left rotation
    
    
    AvLNode<T>* checkbalance(AvLNode<T>* n);
    
    vector<T> inorder(AvLNode<T>* n,vector<T>& temp);
    /*You can add additional functions if necessary*/
};

#endif
