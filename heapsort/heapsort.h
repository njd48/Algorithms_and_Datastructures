
#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "myArray.h"

struct Heap {
    int  N;
    int* A;
    bool indicator_arrayWrapper = false;

    Heap( int n ){
        N = n;
        A = new int[N];
    }
    Heap( Array& a ) { // Initialize heap as a mere pointer to an already existing array
        N = a.N;
        A = a.A;
        indicator_arrayWrapper = true;
    }
    ~Heap(){
        if ( !indicator_arrayWrapper ) {
            delete[] A;
        }        
    }
    int& operator[]( const int i ){ return A[i]; }
    int parent( int i ){ return (i-1)/2;   }
    int left(   int i ){ return 2*i+1; }
    int right(  int i ){ return 2*i+2; }
};

void maxHeapify( Heap& H, int i ) ;
void buildHeap( Heap& H ) ;
Heap buildHeap( Array& A ) ;
void heapSort( Array& A );

#endif