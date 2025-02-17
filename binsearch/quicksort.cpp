
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
// Funcs for mergesort
//
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


//------------------------------------------------------------------------------------------
// Funcs for testing
//
bool runATest_cocktail( std::vector<int>& x ) { 

    std::cout << '\t' << "running cocktail sort test...\n";
    std::cout << '\t' << "input vec:  "; 
    printV( x );

    partCocktailSort( (int)x.size(), 0,  x );

    std::cout << '\t' << "output vec: ";
    printV( x );
    bool s = sorted(x.size(),x) ;
    std::cout << '\t' << "sorted:     " << s << '\n';
    return s;
}
void test_partition( std::vector<int>& x) {
    std::cout << '\t' << "running partition test...\n";
    std::cout << '\t' << "input vec:  "; 
    printV( x );

    int J = partitionQS( 0, (int)x.size(),  x );
    std::cout << '\t' << "J="<< J <<"           ";
    for (int j=0; j<J ; j++){
        std::cout <<"   ";
    }
    std::cout << "*\n";
    std::cout << '\t' << "output vec: ";
    printV( x );
}

bool test_quickSort( std::vector<int>& x, int NThreshold ) { 

    std::cout << '\t' << "running quickSort "<< NThreshold <<" test...\n";
    std::cout << '\t' << "input vec:  "; 
    printV( x );

    quickSort(  x, NThreshold );

    std::cout << '\t' << "output vec: ";
    printV( x );
    bool s = sorted(x.size(),x) ;
    std::cout << '\t' << "sorted:     " << s << '\n';
    return s;
}
/*
bool runATest_sort( std::vector<int>& x ) { 

    std::cout << '\t' << "running quickSort test...\n";
    std::cout << '\t' << "input vec:  "; 
    printV( x );

    quickSort(  x );

    std::cout << '\t' << "output vec: ";
    printV( x );
    bool s = sorted(x.size(),x) ;
    std::cout << '\t' << "sorted:     " << s << '\n';
    return s;
}
*/
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
double testPerformanceQuick( int N, int NThreshold ) {

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
        quickSort( arr, NThreshold );
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

//std::cout << "Test cocktail sort:... \n";   
 //   runATest_cocktail( x1 ) ;    
  //  runATest_cocktail( x2 ) ;    
   // runATest_cocktail( x3 );
/*
std::cout << "Test partition:... \n";
    std::vector x1 = { 1, 8, 6 };
    test_partition( x1 );
    std::vector x2 = { 6, 1, 4, 3 };
    test_partition( x2 );
    std::vector x3 = { 6, 6, 4, 7, 5};
    test_partition( x3 );
    std::vector x4= {  5, 2, 8, 1, 6, 3, 1 };
    test_partition( x4 );
    std::vector x5 = { 6, 8, 1, 7, 3, 1, 5, 9, 2, 3, 1 };
    test_partition( x5 ) ;
*/
    //---------------------------------------------------------------
    // Test quickSort() function 
    //
    std::cout << "test quickSort(): \n";

   
    std::vector x1 = { 1, 8, 6 };
    test_quickSort( x1, 'i' ) ;
 
    std::vector x2 = { 6, 1, 4, 3 };
    test_quickSort( x2, 'i' ) ;

    std::vector x3 = { 6, 6, 4, 7, 5};
    test_quickSort( x3, 'i' );

    std::vector x33 = {  5, 2, 8, 1, 6, 3, 1 };
    test_quickSort( x33, 'i' ) ;

    std::vector x4 = { 6, 8, 1, 7, 3, 1, 5, 9, 2, 3, 1 };
    test_quickSort( x4, 'c' ) ;

    std::vector x5 = { 64, 8, 12, 7, 3, 1 };
    test_quickSort( x5, 'c' ) ;

    std::vector x6 = { 6, 3, 7, 8, 3, 55, 3 ,3, 1 };
    test_quickSort( x6, 'c' ) ;

/* */

    //---------------------------------------------------------------
    // time performance of mergeSort() and quickSort()
    //

    std::cout << "time performance of mergeSort(), and successive optimization attempts of quickSort(): \n";

    std::vector<string> col1 = { "" , "" , "" , "array size", "N" };
    std::vector<string> col2 = { "" , "" , "mergeSort()", "avg walltime", "t (s)" };
    std::vector<string> col3 = { "" , "" , "" , "array size", "N" };
    std::vector<string> col4 = { "" , "" , "" , "array size", "N" };


    int NN;
    std::cout << "-------------------------------------------------------------------------------------\n";
    std::cout << "           " << '\t' << "|              " << '\t' << "| subinsr N< 3 " << '\t' << "| subinsr N<25 " << '\t' << "| subinsr N<50 " << "\t\n";
    std::cout << "           " << '\t' << "|              " << '\t' << "| pivot x[1]   " << '\t' << "| pivot x[1]   " << '\t' << "| pivot x[1]   " << "\t\n";
    std::cout << "           " << '\t' << "|  mergeSort() " << '\t' << "|  quickSort() " << '\t' << "|  quickSort() " << '\t' << "|  quickSort() "  << "\t\n";
    std::cout << " array size" << '\t' << "| avg wall time" << '\t' << "| avg wall time" << '\t' << "| avg wall time" << '\t' << "| avg wall time"<< "\t\n";
    std::cout << "         N " << '\t' << "|    t (s)     " << '\t' << "|    t (s)     " << '\t' << "|    t (s)     " << '\t' << "|    t (s)     " << "\t\n";
    std::cout << "-------------------------------------------------------------------------------------\n";
    for ( double EE = 5; EE < 18; EE += 1 ){ 
        NN = (int)( pow( 2.0, EE ) );
        std::cout << '\t' << NN << "\t| " << testPerformanceMerge(    NN ) << "\t| " 
                                          << testPerformanceQuick(    NN, 3 )  << "\t| " 
                                          << testPerformanceQuick(    NN, 25 )  << "\t| "
                                          << testPerformanceQuick(    NN, 50 )  << "\t| "
                                          <<'\n';
    }

    
}