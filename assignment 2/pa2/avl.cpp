#ifndef __AVL_CPP
#define __AVL_CPP
#include "avl.h"
#include "time.h"
#include <fstream>

template <class T>
AvL<T>::AvL()
{
}

template <class T>
AvL<T>::~AvL()
{
}

template <class T>
AvLNode<T>* AvL<T>::search(T k)
{
}

template <class T>
void AvL<T>::replace(T ok, T nk)
{
}

template <class T>
void AvL<T>::delete_node(T k)
{
}

template <class T>
void AvL<T>::insert(string val, T k)
{
}

template<class T>
int AvL<T>::nodeHeight( AvLNode<T> *n)
{
}

template<class T>
AvLNode<T>* AvL<T>::getRoot()
{
	return root;
}

#endif
