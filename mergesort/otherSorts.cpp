
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

/*
void quickSort( std::vector<int>& x ){

    int N = x.size();

    if ( N==1 ){

    } else if ( N==2 ) {

    } else {
        // Pick a pivot
    }
    
} 
*/
void cocktailSort( std::vector<int>& x ) {

    int N = x.size();

    if ( N== 1){
        return;
    }

    int held   = x[0];
    int i_held = 0;
    int i  = 1;
    int iL = 0;
    int iR = N;

    // Sweep forward, find largest
    // Sweep Backward, find smallest
    while ( iL < iR ) {
        
        held   = x[iL];
        i_held = iL; 
        // Upsweep
        for ( i = iL ;  i < iR ;  i++ ) {
            if ( x[i] > held ) {
                held   = x[i];
                i_held = i;
            }
        }
        x[i_held]  = x[iR-1];
        x[iR-1]    = held;
        iR--;

        //std::cout << "\t#  \t\t";
        //printV(x);

        if (iR<=iL){
            return;
        }
        // Downsweep
        i_held = iR-1;
        held   = x[i_held];
        for ( i = iR-1 ;  i>=iL ;  i-- ) {
            if (x[i] < held) {
                held   = x[i];
                i_held = i;
            }
        }
        x[i_held] = x[iL];
        x[iL]     = held;
        iL++;

        //std::cout << "\t#  \t\t";
        //printV(x);
    }

}

void gnomeSort( std::vector<int>& x ){

    int N    = x.size();

    if ( N== 1){
        return;
    }

    int temp ;
    int i    = 1;

    while (i<N) {
        if ( i == 0){
            i++;
        } else if ( x[i] < x[i-1] ) {
            temp   = x[i-1];
            x[i-1] = x[i];
            x[i]   = temp; 
            i--;
        } else {
            i++;
        }
    }
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
//
//
bool runATest_sort( std::vector<int>& x ) { 

    std::cout << '\t' << "running cocktailSort test...\n";
    std::cout << '\t' << "input vec:  \t"; 
    printV( x );

    cocktailSort(  x );

    std::cout << '\t' << "output vec: \t";
    printV( x );
    bool s = sorted(x.size(),x) ;
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
double testPerformanceGnome( int N ) {

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
        gnomeSort( arr );
        end_time   = clock();

        // average time in seconds
        walltime[i] = ((double)(end_time - start_time))/CLOCKS_PER_SEC;

        average_time = average_time + walltime[i];
        
    }

    // Compute average
    average_time = average_time/n_tests;
    return average_time;

}
double testPerformanceCocktail( int N ) {

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
        cocktailSort( arr );
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

/*
    //---------------------------------------------------------------
    // Test gnomeSort() function 
    //
    std::cout << "test gnomeSort(): \n";
    
    std::vector x1 = { 1, 8, 6 };
    //std::cout << "here in main\n";
    runATest_sort( x1 ) ;

    std::vector x2 = { 6, 8, 1, 7, 3, 1, 5, 9, 2, 3, 1 };
    runATest_sort( x2 ) ;


*/
    //---------------------------------------------------------------
    // Test cocktailSort() function 
    //
    std::cout << "test cocktailSort(): \n";
    
    std::vector x1 = { 1, 8, 6 };
    runATest_sort( x1 ) ;

    std::vector x2 = { 6, 8, 1, 7, 3, 1, 5, 9, 2, 3, 1 };
    runATest_sort( x2 ) ;

    std::vector x3 = { 64, 8, 12, 7, 3, 1 };
    runATest_sort( x3 ) ;

    std::vector x4 = { 6, 3, 7, 8, 3, 55, 3 ,3, 1 };
    runATest_sort( x4 ) ;

    
    //---------------------------------------------------------------
    // time performance of mergeSort() and gnomeSort() and cocktailSort
    //

    std::cout << "time performance of mergeSort() and gnomeSort() and cocktailSort(): \n";

    int NN;
    std::cout << "-------------------------------------------------------------------\n";
    std::cout << "           " << '\t' << "|  mergeSort() " << '\t' << "|  gnomeSort() " << '\t' << "|cocktailSort()" << "\t|\n";
    std::cout << " array size" << '\t' << "| avg wall time" << '\t' << "| avg wall time" << '\t' << "| avg wall time" << "\t|\n";
    std::cout << "         N " << '\t' << "|    t (s)     " << '\t' << "|    t (s)     " << '\t' << "|    t (s)     " << "\t|\n";
    std::cout << "-------------------------------------------------------------------\n";
    for ( double EE = 5; EE < 17; EE += 1 ){ 
        NN = (int)( pow( 2.0, EE ) );
        std::cout << '\t' << NN << "\t| " << testPerformanceMerge( NN ) << "\t| "
                                          << testPerformanceGnome( NN ) << "\t| "
                                       << testPerformanceCocktail( NN ) << "\t| \n";
    } 
    
}