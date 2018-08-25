#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include "LinkedList.h"
#include <iostream>
using namespace std;
template <class T>
LinkedList<T>::LinkedList()
{
    head=NULL;
    
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{
    // took help in this code form friend and internet
    if(otherLinkedList.head == NULL)
    {
        head = NULL;
    }
    else{
        head = new ListItem<T>(otherLinkedList.head->value);
        head->prev = NULL; head->next = NULL;
        ListItem<T>* copy = (otherLinkedList.head)->next;
        ListItem<T>* now = head;
        
        while(copy != NULL){
            now->next = new ListItem<T>(copy->value);
            (now->next)->prev = now;
            now = now->next;
            copy = copy->next;
        }
        now->next = NULL;
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    delete head;
    
}

template <class T>
void LinkedList<T>::insertAtHead(T item)
{
    ListItem<T>* new_node=new ListItem<T>(item);
    if (head==NULL) {
        head=new_node;
        head->next=NULL;
        head->prev=NULL;
    }
    else {
        
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
        new_node->prev=NULL;
    }
    
}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
    ListItem<T>* pointer= new ListItem<T>;
    pointer->value=item;
    pointer->next=NULL;
    pointer->prev=NULL;
    
    if (head==NULL) {
        head=pointer;
        head->next=NULL;
        head->prev=NULL;
    }
    else{
        ListItem<T>* temporary=head;
        while (temporary->next!=NULL) {
            temporary=temporary->next;
        }
        temporary->next=pointer;
        pointer->prev=temporary;
        pointer->next=NULL;
    }
}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
    ListItem<T>* temporary1= new ListItem<T>;
    temporary1->value=toInsert;
    temporary1->next=NULL;
    
    if (head==NULL) {
        return;
    }
    
    ListItem<T>* temporary2= head;
    while (temporary2->value!=afterWhat) {
        temporary2=temporary2->next;
    }
    if (temporary2->next==NULL) {
        insertAtTail(toInsert);
    }
    else{
        temporary1->next=temporary2->next;
        (temporary2->next)->prev=temporary1;
        temporary1->prev=temporary2;
        temporary2->next=temporary1;
    }
}

template <class T>
void LinkedList<T>::insertSorted(T item)
{
    if (head==NULL) {
        insertAtHead(item);
    }
    ListItem<T>* temporary= head;
    T value;
    for (int i=0; i<length(); i++) {
        for (int j=0; j<length()-1; j++) {
            value=temporary->value;
            temporary->value=temporary->next->value;
            temporary->next->prev=temporary->prev;
            temporary->next=temporary->next->next;
            temporary->prev=temporary->next;
            temporary->next->value=value;
        }
    }
}

template <class T>
ListItem<T>* LinkedList<T>::getHead()
{
    if (head==NULL) {
        return NULL;
    }
    else
        return head;
}

template <class T>
ListItem<T>* LinkedList<T>::getTail()
{
    ListItem<T>* node=head;
    if (head==NULL) {
        return NULL;
    }
    else
    {   int count=0;
        while (node->next!=NULL) {
            node=node->next;
            count++;
        }
        node=head;
        for (int i=0; i<count-1; i++) {
            node=node->next;
        }
        return node->next;
    }
}

template <class T>
ListItem<T> *LinkedList<T>::searchFor(T item)
{
    ListItem<T>* search=head;
    
    int count=0;
    if (head==NULL) {
        return NULL;
    }
    if (search->value==item) {
        return search;
    }
    while (search->value!=item && search->next!=NULL) {
        search=search->next;
        count++;
    }
    
    
    if (count!=0){
        return search;
    }
    return NULL;
}

template <class T>
void LinkedList<T>::deleteElement(T item)
{
    if (head==NULL) {
        return;
    }
    if (head->value==item) {
        deleteHead();
        return;
    }
    
    ListItem<T>* delete_item=head;
    while (delete_item->next!=NULL) {
        if (delete_item->value==item) {
            delete_item->prev->next=delete_item->next;
            delete_item->next->prev=delete_item->prev;
            delete delete_item;
            break;
        }
        delete_item=delete_item->next;
    }
}

template <class T>
void LinkedList<T>::deleteHead()
{
    
    if(head==NULL){
        cout<<"list is empty";
        return;
    }
    else if (head->next == NULL)
    {
        return;
    }
    else{
        ListItem<T> *delete_node=head;
        head=delete_node->next;
        head->prev=NULL;
        delete delete_node;
    }
}

template <class T>
void LinkedList<T>::deleteTail()
{
    
    ListItem<T> *delete_node=head;
    ;
    
    if(head==NULL)
    {  cout<<"the list is empty..";}
    
    ListItem<T> *temporary;
    while (delete_node->next!=NULL) {
        delete_node=delete_node->next;
    }
    if (delete_node->next!=NULL) {
        delete_node->prev->next=NULL;
        delete_node->prev=NULL;
        delete delete_node;
    }
    
    
    
}

template <class T>
int LinkedList<T>::length()
{
    ListItem<T>* len=head;
    
    int count=1;
    if (len->next==NULL) {
        return count;
    }
    while (len->next!=NULL) {
        count++;
        len=len->next;
    }
    
    return count;
}

template <class T>
void LinkedList<T>::reverse()
{
    ListItem<T>* curr = head;
    ListItem<T>* temporary = NULL;
    
    if (temporary==NULL) {
        return;
    }
    else if (temporary->next==NULL){
        return;
    }
    else{
        while(curr!=NULL){
            temporary=curr->prev;
            curr->prev=curr->next;
            curr->next=temporary;
            curr=curr->prev;
        }
        if(temporary != NULL )
            head = temporary->prev;
    }
}



template <class T>
void LinkedList<T>::parityArrangement()
{
    ListItem<T>* temporary=head;
    ListItem<T>* pointer=new ListItem<T>;
    
    if (temporary->next==NULL || length()<=2) {
        return;
    }
    else{
        temporary=temporary->next;
        for (int i=0; i<(length()/2)+1; i++) {
            pointer->value=temporary->value;
            
            
            
            ListItem<T>* temporary=head;
            while (temporary->next!=NULL) {
                temporary=temporary->next;
            }
            temporary->next=pointer;
            pointer->prev=temporary;
            pointer->next=NULL;
            
            (temporary->prev)->next = temporary->next;
            (temporary->next)->prev = temporary->prev;
            pointer = temporary;
            temporary = (temporary->next)->next;
        }
    }
}



#endif
