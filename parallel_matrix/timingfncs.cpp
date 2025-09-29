


#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include "myMatrix.cpp"
#include "matrixMult.cpp"
#define MAT Matrix<double>

// srand((unsigned)time(NULL));



void randomMatrix( MAT& A ){

    double val;

    for ( int i = 0 ; i < A.nrows() ; i++ ){
        for ( int j = 0 ; j < A.ncols() ; j++ )
        {
            val =  3.5 * ( -0.5 + ((double)rand()/(double)RAND_MAX) );
            A.assign( i, j, val );
        }
    }

}

// (void)(*fmul)(MAT&,MAT&,MAT&),
void timeTrial(  int N_lo, int N_hi, int n_trials, void(*fmul)(const MAT&, const MAT&, MAT& ) ) {

    // Multiply two square N by N matricies
    int n_repetitions = 3;

    MAT A, B, C;

    std::vector<int>    Nvals( n_trials );
    

    // Arrange exponentially graded test sizes of matricies
    // between N_lo and N_hi 
    //
    Nvals[0]          = N_lo; 
    Nvals[n_trials-1] = N_hi;

    double Ngradation = exp( ( 1.0/((double)(n_trials-1)) )*log( ((double)N_hi) / ((double)N_lo) ) );

    for ( int n = 1 ; n < n_trials -1 ; n++ ){

        Nvals[n] = Ngradation * Nvals[n-1];

    }

    // initialize timing vars
    //
    std::vector<double>   t_ms( n_trials );

    time_t t_start, t_end;

    double progress;


    std::cout << "|   N    |   t (ms)   |\n";
    std::cout << "|--------|------------|\n";

    // Set up:  set matrix size, init random matrix, begin timer, multiply, record, repeat.
    int N;

    for ( int n = 0 ; n < n_trials ; n++ ) {

        N = Nvals[n];

        A.resize( N,N );
        B.resize( N,N );
        C.resize( N,N );

        progress = 0.0;

        for ( int k = 0 ; k < n_repetitions ; k++  ){

            randomMatrix( A );
            randomMatrix( B );

            t_start = time(0);
            fmul( A, B, C );
            t_end   = time(0);
            progress += difftime( t_end,t_start ) ;

        }

        t_ms[n] = progress*1000.0/n_repetitions;

        //std::cout << "| " << N << "\t\t| " << t_ms[n] << "\t| " <<  <<  " \n";
        printf( " %7i | %1.4e \n",  N, t_ms[n] );
    }
}

/*
*/

int main() {


    timeTrial( 100, 1000, 7, &matrixMult );
}