

#include <iostream>
#include "heapsort.h"


void maxHeapify( Heap& H, int i ) {
    int L = H.left(i);
    int R = H.right(i);
    int larg = i;

    // std::cout << '\t' << "in level " << i << '\n';

    if ( L < H.N ) {
        if ( H[L] > H[i] ) {
            larg = L;
        } 
    } 

    if ( R < H.N ) {
        if ( H[R] > H[larg] ){
            larg = R;
        } 
    }

    if ( larg != i ) {
        int t   = H[i];
        H[i]    = H[larg];
        H[larg] = t;

        maxHeapify( H, larg );
    }
}


void buildHeap( Heap& H ) {

    for ( int i = (H.N/2)-1 ; i>=0 ; i-- ) {
        // std::cout << "here, " << i << ", " << H.N << '\n';
        maxHeapify( H, i );
    }

}

Heap buildHeap( Array& A ) {

    Heap H = Heap( A );

    buildHeap( H );

    return H;
}

void heapSort( Array& A ) {

    Heap H = buildHeap(A);

    int t;

    for ( int i = A.N-1 ; i >=0 ; i-- ) {

        t    = A[i];
        A[i] = A[0];
        A[0] = t;

        H.N--;
        maxHeapify( H, 0 );
    }
}