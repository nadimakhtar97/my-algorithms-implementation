#include<iostream>
#include<math.h>
using namespace std;


struct MinHeap{
    int* hrr; // pointer to array of element in heap
    int capacity; // maximum possible size of MinHeap
    int heapSize; // current number of element in minheap

    MinHeap(int capacity){
        this->capacity = capacity;
        heapSize = 0;
        hrr = new int[capacity];
    }

    int height(){
        return ceil(log2(heapSize+1)) -1;
    }
}

int main(){

}