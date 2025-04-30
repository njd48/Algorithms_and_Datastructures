
#ifndef ERATOSTHANES_H
#define ERATOSTHANES_H

#include <vector>

namespace eratosthanes {

    bool primeDiv( int n, std::vector<int>& past ){

        for ( int i = 0 ; i < past.size() ; i++ ) {
            if ( 0 == n%past[i] ) { return false; }
        }
        return true;
    }


    int sieveNext( int N ) 
    {
        int pAfterN;
        std::vector<int> primes;

        primes.emplace_back(2);

        // First couple of primes
        for ( int i = 3; i < N; i++  ){

            if (primeDiv(i, primes)) { primes.emplace_back(i); }
        }

        // Next prime (including N)
        if ( primeDiv( N, primes)  ) {
            return N;
        } else {
            int N_lo;
            while ( true ) {
                N_lo = N;
                N    = 2*N;

                for ( int i = N_lo; i<N ; i++ ) {
                    if (primeDiv(i, primes)) { return i; }
                }
            }
        }
    }

    

};

#endif