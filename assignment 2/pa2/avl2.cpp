#ifndef __AVL2_CPP
#define __AVL2_CPP
#include "avl2.h"
#include "time.h"
#include <fstream>

template <class T>
AvL<T>::AvL(string filename)
{
}

template <class T>
AvL<T>::~AvL()
{
}

template <class T>
AvLNode<T>* AvL<T>::search(T src)
{
}

template <class T>
void AvL<T>::replace(T oldS, T newS)
{
}

template <class T>
void AvL<T>::delete_node(T scr)
{
}

template <class T>
void AvL<T>::insert(string ID, T scr)
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

template<class T>
T* AvL<T>::getTopFive()
{

}

template<class T>
T AvL<T>::getAverage()
{

}

template<class T>
void AvL<T>::displayAll(AvLNode<T> *P)
{

}

#endif
