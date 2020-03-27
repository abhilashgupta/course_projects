#ifndef HEAP_H
#define HEAP_H

#include<vector>
#include<iostream>
using namespace std;

template<class C>
class Heap
{
public:
    int currentSize;    //stores the number of places in the heap array actually storing valid numbers
    vector<C> array;    //heap array
    //void buildHeap();
    void percolateDown(int hole)    //standard code for percolating down a hole created at any place in the heap
    {
        int child;                  //used in the removemax method
        C tmp=array[hole];
        for(;hole*2<=currentSize;hole=child)
        {
            child=hole*2;
            if(child!=currentSize && array[child+1]>array[child])
                child++;
            if(tmp<array[child])
                array[hole]=array[child];
            else
                break;
        }
        array[hole]=tmp;
    }
    Heap(){         //constructor
        currentSize = 1;
        //array.assign(10,-255);
        array.push_back(-255);          //as the 0th element of the heap array is not used ie invalid value stored
    }


    Heap(int size)      //constructor overloaded
    {
        currentSize=size;
        array.assign(size,-255);
    }

    Heap(const vector<C> &items)    //constructor overloaded
    {
        array.assign(items.size()+1 , -255);
        array[1]=items[0];
        currentSize=1;
        for(int i=1;i<items.size();i++)
            this.Insert(items[i]);
    }

    void Insert(C item)     //Insert method implemented by percolateup standard algorithm
    {
        if(currentSize==array.size()-1)
            array.resize(array.size()*2);
        int hole=currentSize++;
        for(;hole>1&&array[hole/2]<item;hole=hole/2)
            array[hole]=array[hole/2];      //hole percolating up
        array[hole]=item;
        //currentSize++;
    }


    void DeleteMax ()       //deletes the max element which is always stored at array[1]
    {
        array[1] = array[--currentSize];
        percolateDown(1);   //by percolating down the hole created at array[1]
    }
    bool IsEmpty()
    {
        if(currentSize==0)
            return true;        //checks if the heap array is empty or not
        else
            return false;
    }
    void display()      //display function for heap
    {
        for(int i=0; i < array.size();i++)
            cout<<array[i]<<" ";
        cout<<endl;
    }
};

#endif
