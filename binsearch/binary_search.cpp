

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

template <typename T>
void printV( std::vector<T>& x ) {
    int N = x.size();
    std::cout << "[ ";
    for ( int i=0 ; i < N-1 ; i++ ) {
        std::cout << x[i] << ", ";
    }
    std::cout << x[N-1] << "]\n";
}

//------------------------------------------------------------------------------------------
// Funcs for quicksort
//
void partInsertionSort( int N, int S, std::vector<int>& x ) {
    // int N = x.size();

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
int pickPivot( int L, int R, std::vector<int>& x  ){
    // Pivot is start val
    int P = x[L];
    return P;
}
int partitionQS( int L, int R, std::vector<int>& x  ) {

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
void partialQuickSort( int L, int R, std::vector<int>& x, int NThreshold )  {

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
void quickSort( std::vector<int>& x, int NThreshold ) {

    partialQuickSort(  0, (int)x.size(), x , NThreshold );
}

//------------------------------------------------------------------------------------------
// Funcs for binsearch
//
int binSearch( std::vector<int>& x , int target ) {

    // Assume sorted
    // Find the index of target
    // or return empty

    int R = x.size();
    int L = 0;

    int i = ((R-L)/2);

    while (L<R) {

        if ( x[i] == target ) {
            return i;
        } else if (x[i] < target ) {
            L = i;
            i = L + ((R-L)/2);
        } else {
            R = i;
            i = L + ((R-L)/2);
        }
    }

    std::cout << "Error: Target, " << target << " Is not a member of input vector.\n";
    return 0;

}

//------------------------------------------------------------------------------------------
// Linear Search
//

int linSearch( std::vector<int>& x , int target ) {

    // Assume sorted
    // Find the index of target
    // or return empty

    int N = x.size();

    for (int i ; i<N ; i++) {

        if ( x[i] == target ) {
            return i;
        }
    }

    std::cout << "Error: Target, " << target << " Is not a member of input vector.\n";
    return 0;

}



//------------------------------------------------------------------------------------------
// Funcs for testing
//
std::vector<int> init_test_vec( int N ){

    std::vector<int> x(N);

    for ( int i = 0; i<N; i++){
        x[i] = rand()%100-50;
    }

    partialQuickSort( 0, N, x, 30 );

    return x;
}

void runtest_binsearch( int N ) {

   // int N = 12;

    std::vector<int> x( N ) ;
    x = init_test_vec(  N ) ;

    int i      = rand()%N;
    int target = x[i];

    int i_bin = 0;
    int i_lin = 0;

    std::cout << "";
    
    std::cout << '\t' << "input vec: ";
    printV( x );

    i_bin = binSearch(  x, target );
    i_lin = linSearch(  x, target );

    std::cout << '\t' << "target:              " << target << '\n';
    std::cout << '\t' << "is chosen at:        " << i      << '\n';
    std::cout << '\t' << "binsearch found at:  " << i_bin  << '\n';
    std::cout << '\t' << "linsearch found at:  " << i_lin  << '\n';

    x =  std::vector<int>();
}

//------------------------------------------------------------------------------------------
// 
//
int main() 
{

    int n_tests = 15;
    int N;


    for (int i = 0; i< n_tests ; i++) {
        N = 5 + rand()%25;
        runtest_binsearch( N );
    }

}
