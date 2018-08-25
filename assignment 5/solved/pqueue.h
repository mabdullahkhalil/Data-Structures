#ifndef PQUEUE__H
#define PQUEUE__H
#include <iostream>
#include <math.h>
using namespace std;

template<class T>
class pqueue
{
protected:
    int size;
    vector<T> newvec;
    
public:
    int numE;
    T* heap;
    pqueue(vector<T> nums,int x){
        numE=x;
        size=nums.size();
        heap=new T[nums.size()];
        T* newheap=new T[nums.size()];
        heap=makeheap(newheap,nums);

    }
    
    
    
    T* makeheap(T* heap,vector<T> nums){
        vector<T> dummy;
        heap[0]=nums[0];
        for (int i=1; i<nums.size(); i++) {
            heap[i]=nums[i];
            int m=floor((i-1)/2);
            int x=i;
            while (heap[m]>heap[x]) {
                T temp=heap[x];
                heap[x]=heap[m];
                heap[m]=temp;
                x=m;
                m=floor((m-1)/2);
            }
        }
        for (int i=0; i<nums.size(); i++) {
            dummy.push_back(heap[i]);
        }
        newvec=dummy;
        return heap;
    }
    
    T ExtractMin(){
        T returning=heap[0];
        newvec.erase(newvec.begin());
        T* thisheap=new T[newvec.size()];
        heap=makeheap(thisheap, newvec);
        size=newvec.size();
        return returning;
    }
    
    int getsize(){
        return size;
    }
    
};


#endif
