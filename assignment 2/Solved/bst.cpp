#ifndef __BST_CPP
#define __BST_CPP
#include <iostream>
#include "bst.h"
#include <cstdlib>
#include <fstream>
#include <vector>
#include "time.h"
using namespace std;
template <class T>
bst<T>::bst()
{
    root=NULL;
}

template <class T>
void bst<T>::insert(string val,T key1)
{
    
    bst_node<T>* pointer= new bst_node<T>(val,key1);
    bst_node<T>* temporary=root;

    if (root==NULL) {
        root=pointer;
    }
    else{
        if (key1 < temporary->key)
        {
            while (true) {
                if (key1 < temporary->key && temporary->left!=NULL) {
                    temporary=temporary->left;
                }
                else if (key1 >temporary->key && temporary->right!=NULL){
                  temporary=temporary->right;
                }
                else if (key1 > temporary->key && temporary->right==NULL){

                    temporary->right=pointer;
                    pointer->parent=temporary;
                    pointer->right=NULL;
                    pointer->left=NULL;
                    return;
                }
                else if (key1 < temporary->key && temporary->left==NULL){

                    temporary->left=pointer;
                    pointer->parent=temporary;
                    pointer->right=NULL;
                    pointer->left=NULL;
                    return;
                }
                
            }
        }
        if (key1 > temporary->key)
        {
            while (true) {
                if (key1 < temporary->key && temporary->left!=NULL) {
                    temporary=temporary->left;
                }
               else if (key1 >temporary->key && temporary->right!=NULL){
                  temporary=temporary->right;
                }
               else if (key1 > temporary->key && temporary->right==NULL){
                   temporary->right=pointer;
                    pointer->parent=temporary;
                    pointer->right=NULL;
                    pointer->left=NULL;
                    return;
                }
                else if (key1 < temporary->key && temporary->left==NULL){

                    temporary->left=pointer;
                    pointer->parent=temporary;
                    pointer->right=NULL;
                    pointer->left=NULL;

                    return;
                }
            }
        }

    }
}
template <class T>
bst_node<T>* bst<T>::search(T key1)
{
    bst_node<T>* temporary=root;
    if (temporary->key==key1) {
        return temporary;
    }
    else if (temporary->key!=key1){
        while (true){
            if (key1<temporary->key) {
                temporary=temporary->left;
            }
            else if (key1>temporary->key) {
                temporary=temporary->right;
            }
            else if (temporary->key==key1){
                return temporary;
            }
        }
    }
    return temporary;
}

template <class T>
void bst<T>::delete_node(T key1)
{
    bst_node<T>* node_to_be_del=search(key1);
    
    if (node_to_be_del->key==root->key && root->left==NULL && root->right==NULL) {
        root=NULL;
    }
    // codition if the node is a leaf...
    
    else if (node_to_be_del->left==NULL && node_to_be_del->right==NULL){
        if (node_to_be_del->parent->right==node_to_be_del) {
            node_to_be_del->parent->right=NULL;
        }
        else  if (node_to_be_del->parent->left==node_to_be_del) {
            node_to_be_del->parent->left=NULL;
        }
        delete node_to_be_del;
        return;
    }

    //condition with one node.
    
    else if (node_to_be_del->right==NULL){
        if (node_to_be_del->parent->right==node_to_be_del) {
            node_to_be_del->left->parent=node_to_be_del->parent;
            node_to_be_del->parent->right=node_to_be_del->left;
        }
        else  if (node_to_be_del->parent->left==node_to_be_del) {
            node_to_be_del->left->parent=node_to_be_del->parent;
            node_to_be_del->parent->left=node_to_be_del->left;

        }
        delete node_to_be_del;
        return;
    }
    else if (node_to_be_del->left==NULL){
        if (node_to_be_del->parent->right==node_to_be_del) {
            node_to_be_del->right->parent=node_to_be_del->parent;
            node_to_be_del->parent->right=node_to_be_del->right;
        }
        else  if (node_to_be_del->parent->left==node_to_be_del) {
            node_to_be_del->right->parent=node_to_be_del->parent;
            node_to_be_del->parent->left=node_to_be_del->right;
        }
        delete node_to_be_del;
        return;
    }
    
    // codition with two nodes....effed up situation lol..
    
    else if (node_to_be_del->right!=NULL && node_to_be_del->left!=NULL){
        bst_node<T>* temp=search(key1);
        int count=0;
        temp=temp->left;
        while (temp->right!=NULL) {
            temp=temp->right;
            count++;
        }
        T storing_key=temp->key;
        string storing_val=temp->value;
        

        delete_node(temp->key);
        
        node_to_be_del->value=storing_val;
        node_to_be_del->key=storing_key;
        return;
    }
    
    
        
    
    
}

template <class T>
int bst<T>::height( bst_node<T> *temp)
{
    if (temp==NULL) {
        return -1;
    }
    int left_tree_height=height(temp->left);
    int right_tree_height=height (temp->right);
    
    if (left_tree_height>right_tree_height) {
        return left_tree_height+1;
    }
    else  (right_tree_height>left_tree_height);
    return right_tree_height+1;
}


template<class T>
void bst<T>::replace(T old_key,T new_key)
{
    string value=search(old_key)->value;
        delete_node(old_key);
  //  delete_node(search(old_key));
    insert(value, new_key);
}

template <class T>
bst_node<T>* bst<T>::getroot()
{
    return root;

}
#endif
