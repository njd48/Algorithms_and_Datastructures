
#include <iostream>
#include "myArray.h"
#include <string>
#include <cassert>
#include <cmath>



//------------------------------------------------------------------------------------------
// partial sorts for supplement with quickSort Sort
//
void partInsertionSort( int N, int S, Array& x ) {
    // int N = x.N;

    int j;
    int temp ;

    for ( int i = S+1 ; i < N ; i++ ) {
        j = i-1;
        temp = x[i];
        while (j>=0 && x[j] > temp) {
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = temp;
    }
}


//------------------------------------------------------------------------------------------
// Funcs for quicksort
//

int pickPivot( int L, int R, Array& x  ){
    // Pivot is start val
    int P = x[L];
    return P;
}
int partitionQS( int L, int R, Array& x  ) {

    // Algorithm:
    // - pick pivot, 
    // - move values by swapping across the pivot
    // - identify the index which divides the array into 
    //   low and high values and return it

    int i = L;
    int j = R-1;
    int P = pickPivot( L, R, x );
    //std::cout << '\t' << "P=" << P << '\n';
    int temp;

    while ( true ) {

        while( x[i] < P ){ i++; }

        while( x[j] > P ){ j--; }

        if (i>=j) {
            return j+1;
        }

        temp = x[i];
        x[i] = x[j];
        x[j] = temp;

        i++;
        j--;
    }
   
}
void partialQuickSort( int L, int R, Array& x, int NThreshold )  {

    int N = R-L;

    // Early returns
    if (N <= 1) {
        return;
    } else if ( N <= NThreshold ){
        // Pass to a insertion sort for small arrays
        partInsertionSort( N, L, x );
        return;
    }
 
    int J = partitionQS( L, R, x );

    partialQuickSort( L, J, x, NThreshold );
    partialQuickSort( J, R, x, NThreshold );   
   
}
void quickSort( Array& x, int NThreshold ) {

    partialQuickSort(  0, (int)x.N, x , NThreshold );
}


//------------------------------------------------------------------------------------------
// Funcs for mergesort
//
void merge( int L, int M, int R, Array& x ){
     // Indi left,   mid, right,

     // Temporary Vector:
        Array y(R-L);   

        int jj = 0;
        for ( int j = L; j<R ; j++ ){
            y[jj] = x[j];
            jj++;
        }
        //std::cout << "y vec: " ;
        //printV( y );


        int j = L;
        int i = 0;
        int k = M-L;
        while ( ( j<R ) ) {
            if (y[i] > y[k] && k < R-L ) {  
                // append right val (advance right cursor)       
                x[j] = y[k];
                
                //std::cout << "(i,k) = " << i << ' ' << k << '\n';
                k++;
            } else if ( i < M-L ){ 
                // append left val (advance left cursor)
                x[j] = y[i];
                //
                //std::cout <<  "(i,k) = " << i << ' ' << k <<'\n';
                i++;
            } else {
                // 
                //x[j]
            }            
            //std::cout << "j = " << j << '\n';
            j++; 
            //printV(x);
        } 
}

void partialMergeSort(  int N, int S, Array& x ) {
    // N  num elements of subarray
    // S  starting index for subarray
    int temp;
    //std::cout << NN << ' ' << N << ' ' << S << '\n';
    //assert( NN == N+S );
    //std::cout << N << " out here\n";

    if ( N <= 2) {
        // if N==1 do nothing
        if (N==2) {
            if (x[S+0] >= x[S+1]) { 
                // swap
                // std::cout << S << " in if here\n";
                temp   = x[S+0];
                x[S+0] = x[S+1];
                x[S+1] = temp;
            }
        }

    } else {
        int M = (N/2);
        int S2 = S+M;
        //std::cout << " else here\n";
        //std::cout << S  << ", " << M << '\n';
        //std::cout << S2 << ", " << N-M << '\n';
        partialMergeSort(    M,  S, x ); // <- merge sort left half-array
        partialMergeSort(  N-M, S2, x ); // <- merge sort right half-array
        //std::cout << " finished partial sort\n";
        //printV(x);
        //std::cout << S  << ", " << S2  << ", "<< S+N << '\n';
        merge(  S, S2, S+N,           x );
    }
}

void mergeSort(  Array& x ){
    // int N = ;
    partialMergeSort( (int)x.N, 0, x);
}





