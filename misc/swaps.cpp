

#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>

//-------------------------------------------------------------------------------------------
// Test how to swap random integers
//   (1) - Naive algorithm     : use a temporary variable
//   (2) - Naive++             : use a static temp var, saving one step of var destruction
//   (3) - Add/subtr technique :  i = (i+j) - j et cetera
//   (4) - Bitwise XOr          :  i = i ^ j ^ j et cetera
//--------------------------------------------------------------------------------------------

void swap_naive( int& a, int& b ) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_plus( int& a, int& b ) {
    static int temp = a;
    a = b;
    b = temp;
}

void swap_AS( int& a, int& b ) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void swap_BX( int& a, int& b ) {
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}


double timeTrial( std::vector<int>& X, long long M,  void(*fs)( int&, int& ) ) {

    // initialize 
    time_t t_start;
    time_t t_end;
    double duration_per_op;

    int N = X.size();
    // int M = 4 * N;
    // Proceed by swapping nearest neighbors and front to back.
    // do this M times
    t_start = time(0);

    for ( int m = 0 ; m < M; m++  ) {
        for ( int n = 0 ; n < N-1; n++  )
        {
            fs( X[ n ] , X[ n+1 ] );
        }
        fs( X[ N-1 ] , X[ 0 ] );
    }

    t_end     = time(0);
    duration_per_op  = difftime( t_end,t_start ) ;
    duration_per_op  = duration_per_op / ( (double)( M*N) ) * 1000000.0;

    return duration_per_op;
}




int main() {
    srand((unsigned)time(NULL));
    //timeTrial( 100, 1000, 7, &matrixMult );

    int a = rand()%128;
    int b = rand()%128;

    std::cout << "Are all swaps working fine?\n";

    std::cout << "initial vars:   " << a << ", " << b << '\n';

    swap_naive( a, b );
    std::cout << "Naive swap:     " << a << ", " << b << '\n';

    swap_plus( a, b );
    std::cout << "Naive plus:     " << a << ", " << b << '\n';

    swap_AS( a, b );
    std::cout << "add/subtr swp:  " << a << ", " << b << '\n';

    swap_BX( a, b );
    std::cout << "btws XOR swp:   " << a << ", " << b << '\n';

    std::cout << "\n";


    
    int N = 1000;
    long long M = 2* pow(  (long long)N, 2.0 ); // My cpu is very keeen to reject large numbers here
    std::vector<int> testArray( N );

    for ( int n = 0 ; n < N; n++ ){
        testArray[n] = rand();
    }

    std::cout << "Time trials, a test array with "<< N << " elements and "<< M*N <<"  sequential swaps :\n";


    std::cout << "Naive swap:     " \
    <<  timeTrial( testArray, M, &swap_naive )  << " ns per operation" << std::endl;

    std::cout << "Naive plus:     " \
    <<  timeTrial( testArray, M, &swap_plus )  << " ns per operation" << std::endl;

    std::cout << "add/subtr swp:  " \
    <<  timeTrial( testArray, M, &swap_AS )  << " ns per operation" << std::endl;

    std::cout << "btws XOR swp:   " \
    <<  timeTrial( testArray, M, &swap_BX )  << " ns per operation" << std::endl;


}

