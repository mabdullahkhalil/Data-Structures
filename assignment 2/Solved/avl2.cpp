#ifndef __AVL2_CPP
#define __AVL2_CPP
#include "avl2.h"
#include "time.h"
#include <stdio.h>
#include <fstream>

template <class T>
AvL<T>::AvL(string filename)
{
    root=NULL;
    ifstream file;
    file.open(filename);
    int rand=0;
    T key;
    char* ptr;
    if(file.fail()){
       cout<<"NO FILE"<<endl;
    }
    int j=0;
    cout<<"time starting "<<endl;
    while (!file.eof()) {
        char line[50];
        string value;
        char tempkey[4];
        file.getline(line,50);
        int i=0;
        while (line[i] != ' ') {
            value=value+line[i];
            rand=i;
            i++;
        }
       i=i+1;
        int m=0;
        while (line[i+1]!=NULL) {
            tempkey[m]=line[i];
            m++;
            i++;
        }
        key=atof(tempkey);
      //  key=strtod(tempkey, ptr);
        
        insert(value, key);
        j++;
    }
    cout<<"the number of items loaded are "<<j<<endl;
    file.close();

}

template <class T>
AvL<T>::~AvL()
{
}

template <class T>
AvLNode<T>* AvL<T>::search(T src)
{
    AvLNode<T>* temporary=root;
    if (temporary->key==src) {
        return temporary;
    }
    else if (temporary->key!=src){
        while (true){
            if (src < temporary->key) {
                temporary=temporary->left;
                if (temporary==NULL){
                    return NULL;
                }
                
                else if (temporary->key==src){
                    return temporary;
                }
            }
            else if (src >temporary->key) {
                temporary=temporary->right;
                if (temporary==NULL){
                    return NULL;
                }
                
                else if (temporary->key==src){
                    return temporary;
                }
            }
            
            
        }
    }
    return temporary;
}


template <class T>
void AvL<T>::replace(T oldS, T newS)
{
    string val=search(oldS)->value;
    delete_node(oldS);
    insert(val, newS);
}

template <class T>
void AvL<T>::delete_node(T scr)
{
    AvLNode<T>* node_to_be_del=search(scr);
    AvLNode<T>* nodedel_parent=search(scr)->parent;
    
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
        if (checkbalance(nodedel_parent)!=NULL) {
            balance(checkbalance(nodedel_parent));
        }
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
        if (checkbalance(nodedel_parent)!=NULL) {
            balance(checkbalance(nodedel_parent));
        }
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
        if (checkbalance(nodedel_parent)!=NULL) {
            balance(checkbalance(nodedel_parent));
        }
        return;
    }
    
    // codition with two nodes....effed up situation lol..
    
    else if (node_to_be_del->right!=NULL && node_to_be_del->left!=NULL){
        AvLNode<T>* temp=search(scr);
        int count=0;
        temp=temp->right;
        while (temp->left!=NULL) {
            temp=temp->left;
            count++;
        }
        T storing_key=temp->key;
        string storing_val=temp->value;
        
        
        delete_node(temp->key);
        
        node_to_be_del->value=storing_val;
        node_to_be_del->key=storing_key;
        //    cout<<"nodedel parent "<<nodedel_parent->key<<endl;
        if (nodedel_parent==NULL){
            return;
        }
        if (checkbalance(nodedel_parent)!=NULL) {
            balance(checkbalance(nodedel_parent));
        }
        
        return;
    }
    
}

template <class T>
void AvL<T>::insert(string ID, T scr)
{
    AvLNode<T>* pointer= new AvLNode<T>(ID,scr);
    AvLNode<T>* temporary=root;
    
    if (root==NULL) {
        root=pointer;
    }
    else{
        if (scr < temporary->key)
        {
            while (true) {
                if (scr < temporary->key && temporary->left!=NULL) {
                    temporary=temporary->left;
                }
                else if (scr >temporary->key && temporary->right!=NULL){
                    temporary=temporary->right;
                }
                else if (scr > temporary->key && temporary->right==NULL){
                    
                    temporary->right=pointer;
                    pointer->parent=temporary;
                    pointer->right=NULL;
                    pointer->left=NULL;
                    if (checkbalance(search(scr))!=NULL) {
                        balance(checkbalance(search(scr)));
                    }
                    
                    return;
                }
                else if (scr < temporary->key && temporary->left==NULL){
                    
                    temporary->left=pointer;
                    pointer->parent=temporary;
                    pointer->right=NULL;
                    pointer->left=NULL;
                    if (checkbalance(search(scr))!=NULL) {
                        balance(checkbalance(search(scr)));
                    }
                    
                    return;
                }
                
            }
        }
        if (scr > temporary->key)
        {
            while (true) {
                if (scr < temporary->key && temporary->left!=NULL) {
                    temporary=temporary->left;
                }
                else if (scr >temporary->key && temporary->right!=NULL){
                    temporary=temporary->right;
                }
                else if (scr > temporary->key && temporary->right==NULL){
                    temporary->right=pointer;
                    pointer->parent=temporary;
                    pointer->right=NULL;
                    pointer->left=NULL;
                    if (checkbalance(search(scr))!=NULL) {
                        balance(checkbalance(search(scr)));
                    }
                    //checking
                    
                    return;
                }
                else if (scr < temporary->key && temporary->left==NULL){
                    temporary->left=pointer;
                    pointer->parent=temporary;
                    pointer->right=NULL;
                    pointer->left=NULL;
                    if (checkbalance(search(scr))!=NULL) {
                        balance(checkbalance(search(scr)));
                    }
                    
                    return;
                }
            }
        }
        
    }
    
}

template<class T>
int AvL<T>::nodeHeight( AvLNode<T> *n)
{
    if (n==NULL) {
        return 0;
    }
    int left_tree_height=nodeHeight(n->left);
    int right_tree_height=nodeHeight (n->right);
    
    if (left_tree_height>right_tree_height) {
        return left_tree_height+1;
    }
    else  (right_tree_height>left_tree_height);
    return right_tree_height+1;
}

template<class T>
AvLNode<T>* AvL<T>::getRoot()
{
    return root;
}

template<class T>
T* AvL<T>::getTopFive()
{
    T array[5];
    vector<T> tempp;
    //tempp.resize(5);
    AvLNode<T>* p=root;
    
    inorder(p,tempp);
    for (int i=0; i<5;i++) {
        array[i]=tempp[i];
    }
    return array;
}

template<class T>
T AvL<T>::getAverage()
{
    vector<T> allKeys;
    inorder(root, allKeys);
    T sum = 0;
    for(int i = 0;i< allKeys.size();++i)
        sum+=allKeys[i];
    
    return (sum/allKeys.size());
}

template<class T>
void AvL<T>::displayAll(AvLNode<T> *P)
{
    if (P!=NULL) {
     //   cout<<"p->right: "<<P->right->key<<endl;
        displayAll(P->right);
        cout<<P->key<<endl;
        displayAll(P->left);
    }
    
    
}




template<class T>
void AvL<T>::updateLL(AvLNode<T> *n){
    AvLNode<T> *noderight=n->right->left;
    n->right->parent=n->parent;
    if (n->parent!=NULL && n==n->parent->left) {
        n->parent->left=n->right;
    }
    else if (n->parent!=NULL && n==n->parent->right) {
        n->parent->right=n->right;
    }
    if (n->right->parent==NULL) {
        root=n->right;
    }
    if (n->right->left!=NULL) {
        n->right->left->parent=n;
    }
    n->parent=n->right;
    n->right->left=n;
    n->right=noderight;
    
}


template<class T>
void AvL<T>::updateRR(AvLNode<T> *n){
    
    AvLNode<T> *noderight=n->left->right;
    n->left->parent=n->parent;
    if (n->parent!=NULL && n==n->parent->left) {
        n->parent->left=n->left;
    }
    else if (n->parent!=NULL && n==n->parent->right) {
        n->parent->right=n->left;
    }
    if (n->left->parent==NULL) {
        root=n->left;
    }
    if (n->left->right!=NULL) {
        n->left->right->parent=n;
    }
    n->parent=n->left;
    n->left->right=n;
    n->left=noderight;
    
}



template<class T>
AvLNode<T>* AvL<T>::checkbalance(AvLNode<T>* n){
    while (n!=root) {
        int height=nodeHeight(n->left)-nodeHeight(n->right);
        if (height>1||height<-1) {
            
            return n;
        }
        n=n->parent;
    }
    if (nodeHeight(root->left)-nodeHeight(root->right)>1 || nodeHeight(root->left)-nodeHeight(root->right)<-1) {
        return root;
    }
    return NULL;
}


template<class T>
void AvL<T>::balance(AvLNode<T>* n){
    
    while ((nodeHeight(n->left)-nodeHeight(n->right)) > 1 || (nodeHeight(n->left)-nodeHeight(n->right)) < -1) {
        if (nodeHeight(n->left) > nodeHeight(n->right)) {
            if (nodeHeight(n->left->left) > nodeHeight(n->left->right)) {
                updateRR(n->left);
            }
            else if(nodeHeight( n->left->right)>nodeHeight( n->left->left)){
                updateLL(n->left);
                updateRR(n);
            }
        }
        else if (nodeHeight(n->left) < nodeHeight(n->right)){
            if (nodeHeight(n->right->right) > nodeHeight(n->right->left)) {
                updateLL(n->right);
            }
            else if(nodeHeight( n->right->left)>nodeHeight( n->right->right)){
                updateRR(n->right);
                updateLL(n);
            }
        }
    }
}


template<class T>
vector<T> AvL<T>::inorder(AvLNode<T>* n,vector<T>& temp){
    
    if (n!=NULL) {
        //   cout<<"p->right: "<<P->right->key<<endl;
        inorder(n->right,temp);
        temp.push_back(n->key);

        inorder(n->left,temp);
        
        if (temp[5]!=NULL) {
            return temp;
        }
    }
    return temp;
    
}

#endif
