
#include <iostream>
#include <vector>


#include "myArray.h"
#include "heapsort.h"
#include "heapsort.cpp"
#include "other_sorts.cpp"


double testPerformanceHeap( int N ) {

    int n_tests = 64; 

    std::vector<double> walltime(n_tests);
    Array arr(N);

    clock_t   start_time;
    clock_t     end_time;
    double  average_time;

    for ( int i = 0; i < n_tests ; i++ ) {
        // Form random int array
        for (int j = 0 ; j < N ; j++ ){
            arr[j] = ( rand()%100 ); // rand int between 0 and 99;
        }
        
        start_time = clock();
        heapSort( arr );
        end_time   = clock();

        // average time in seconds
        walltime[i] = ((double)(end_time - start_time))/CLOCKS_PER_SEC;

        average_time = average_time + walltime[i];
        
    }

    // Compute average
    average_time = average_time/n_tests;
    return average_time;

}

double testPerformanceMerge( int N ) {

    int n_tests = 64; 

    std::vector<double> walltime(n_tests);
    Array arr(N);

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
    Array arr(N);

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

    
        //---------------------------------------------------------------
        // time performance of heapSort(), mergeSort(), and quickSort()
        //
    
        std::cout << "time performance of heapSort(), mergeSort(), and quickSort(): \n";
    
        //std::vector<string> col1 = { "" , "" , "" , "array size", "N" };
        //std::vector<string> col2 = { "" , "" , "mergeSort()", "avg walltime", "t (s)" };
        //std::vector<string> col3 = { "" , "" , "" , "array size", "N" };
        //std::vector<string> col4 = { "" , "" , "" , "array size", "N" };
    
    
        int NN;
        std::cout << "-------------------------------------------------------------------------------------\n";
        std::cout << "           " << '\t' << "|              " << '\t' << "|              " << '\t' << "| subinsr N<25 " << "\t\n";
        std::cout << "           " << '\t' << "|              " << '\t' << "|              " << '\t' << "| pivot x[1]   " << "\t\n";
        std::cout << "           " << '\t' << "|  heapSort()  " << '\t' << "|  mergeSort() " << '\t' << "|  quickSort() " << "\t\n";
        std::cout << " array size" << '\t' << "| avg wall time" << '\t' << "| avg wall time" << '\t' << "| avg wall time" << "\t\n";
        std::cout << "         N " << '\t' << "|    t (s)     " << '\t' << "|    t (s)     " << '\t' << "|    t (s)     " << "\t\n";
        std::cout << "-------------------------------------------------------------------------------------\n";
        for ( double EE = 5; EE < 20; EE += 1 ){ 
            NN = (int)( pow( 2.0, EE ) );
            std::cout << '\t' << NN << "\t| " << testPerformanceHeap(     NN  ) << "\t| " 
                                              << testPerformanceMerge(    NN  )  << "\t| " 
                                              << testPerformanceQuick(    NN, 25 )  << "\t| "
                                              <<'\n';
        }
    
        
    }