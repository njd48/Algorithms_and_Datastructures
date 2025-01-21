
#include <iostream>
#include <vector>
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

bool sorted(  int N, const std::vector<int>& x  ){

    for (int i = 0 ; i<N-1 ; i++ )
    {
        if (x[i+1] < x[i])
        {
            return false;
        }
    }
    return true;
}

// To generate permutation of the array
void shuffle(  int n, std::vector<int>& a)
{
    for (int i = 0; i < n; i++)
        std::swap(a[i], a[rand() % n]);
}
 
// Sorts array a[0..n-1] using Bogo sort
void bogoSort( std::vector<int>& a )
{
    int n = a.size();
    // if array is not sorted then shuffle
    // the array again
    while (!sorted( n, a))
        shuffle( n, a );
}


/*void shift1( int L, int R, std::vector<int>& x ){
    for (int i = R ; i>=L ; i--) {
        x[i+1] = x[i];        
    }
}*/

void merge( int L, int M, int R, std::vector<int>& x ){
     // Indi left,   mid, right,

     // Temporary Vector:
        std::vector<int> y(R-L);   

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

//template <typename T>
void partialMergeSort(  int N, int S, std::vector<int>& x ) {
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

void mergeSort(  std::vector<int>& x ){
    // int N = ;
    partialMergeSort( (int)x.size(), 0, x);
}



bool runATest_sort( std::vector<int>& x ) { 

    std::cout << '\t' << "running mergeSort test...\n";
    std::cout << '\t' << "input vec:  "; 
    printV( x );

    mergeSort(  x );

    std::cout << '\t' << "output vec: ";
    printV( x );
    bool s = sorted(x.size(),x) ;
    std::cout << '\t' << "sorted:     " << s << '\n';
    return s;
}

bool runATest_merge( std::vector<int>& x ) {
    int N = x.size();

    std::cout << '\t' << "running merge test...\n";
    std::cout << '\t' << "input vec:  "; 
    printV( x );

    merge(  0, (int)(N/2), N, x );

    std::cout << '\t' << "output vec: ";
    printV( x );
    bool s = sorted(N,x);
    std::cout << '\t' << "sorted:     " << s << '\n';

    return s;
}

double testPerformanceMerge( int N ) {

    int n_tests = 64; 

    std::vector<double> walltime(n_tests);
    std::vector<int> arr(N);

    clock_t   start_time;
    clock_t     end_time;
    double  average_time;

    for ( int i = 0; i < n_tests ; i++ ) {
        // Form random int array
        for (int j = 0 ; j < N ; j++ ){
            arr[j] = ( rand()%100 ); // rand int between 0 and 99;
        }
        
        start_time = clock();
        mergeSort( arr );
        end_time   = clock();

        // average time in seconds
        walltime[i] = ((double)(end_time - start_time))/CLOCKS_PER_SEC;

        average_time = average_time + walltime[i];
        
    }

    // Compute average
    average_time = average_time/n_tests;
    return average_time;

}

double testPerformanceBogo( int N ) {
    // Don't do this
    int n_tests = 1; 

    std::vector<double> walltime(n_tests);
    std::vector<int> arr(N);

    clock_t   start_time;
    clock_t     end_time;
    double  average_time;

    for ( int i = 0; i < n_tests ; i++ ) {
        // Form random int array
        for (int j = 0 ; j < N ; j++ ){
            arr[j] = ( rand()%100 ); // rand int between 0 and 99;
        }
        
        start_time = clock();
        bogoSort( arr );
        end_time   = clock();

        // average time in seconds
        walltime[i] = ((double)(end_time - start_time))/CLOCKS_PER_SEC;

        average_time = average_time + walltime[i];
        
    }

    // Compute average
    average_time = average_time/n_tests;
    return average_time;

}


int main() {

    int s;

    //---------------------------------------------------------------
    // Test merge function 
    //
    std::cout << "test merge(): \n";
    // Merging of two already sorted vectors

    std::vector v1 = { 3, 7,       1, 2};
    runATest_merge( v1 ) ;

    std::vector v2 = { 4, 6, 8,    1, 5, 5 };
    runATest_merge( v2 ) ;

    std::vector v3 = { 1,          6, 8};
    runATest_merge( v3 ) ;


    //---------------------------------------------------------------
    // Test mergeSort() function 
    //
    std::cout << "test mergeSort(): \n";
    
    std::vector x1 = { 1, 8, 6 };
    //std::cout << "here in main\n";
    runATest_sort( x1 ) ;

    std::vector x2 = { 6, 8, 1, 7, 3, 1, 5, 9, 2, 3, 1 };
    runATest_sort( x2 ) ;

    std::vector x3 = { 64, 8, 12, 7, 3, 1 };
    runATest_sort( x3 ) ;

    std::vector x4 = { 6, 3, 7, 8, 3, 55, 3 ,3, 1 };
    runATest_sort( x4 ) ;

    //---------------------------------------------------------------
    // time performance of mergeSort()
    //

    std::cout << "time performance of mergeSort(): \n";

    int NN;
    std::cout << "--------------------------------------------------\n";
    std::cout << "           " << '\t' << "|  mergeSort() " << '\t' << "|   bogoSort() " << "\t\n";
    std::cout << " array size" << '\t' << "| avg wall time" << '\t' << "| avg wall time" << "\t\n";
    std::cout << "         N " << '\t' << "|    t (s)     " << '\t' << "|    t (s)     " << "\t\n";
    std::cout << "--------------------------------------------------\n";
    for ( double EE = 5; EE < 20; EE += 1 ){ 
        NN = (int)( pow( 2.0, EE ) );
        std::cout << '\t' << NN << "\t| " << testPerformanceMerge( NN ) << "\t| " << 'x' <<'\n';
    }
}