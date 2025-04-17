
#ifndef INTPART_H
#define INTPART_H

#include <iostream>
#include <cmath>      // <-- using cmath is not in the spirit of the game

namespace ip {

int fastApxSqrt( int n ) {

    float N  = (float) n;
    float nn = N;
    // std::cout << "n           = " << nn << '\n';
    int   m  = *( int * ) (&nn); // log
    m =  532487669 + (m >> 1);                // div 2
    // std::cout << "(1/2)log(n) = " << m << '\n';
    nn = *( float * ) (&m);      // exp
    //  std::cout << "n^(1/2)     = "<< nn << '\n';

    nn = N/nn; // one newton step

    m = (int) nn;

    return m;
}



struct Part {
    int m;
    int star;
    int rem;
};



int sumPartition( const Part& p ) {
    int n = p.m * p.star + p.rem;
    return n;
}



void dispPartition( const Part& p ) {

    std::cout << "[ ";
    std::cout << p.rem << " ";
    if (p.m>10) {
        int m = 10;
        for ( int i = 0 ; i < m ; i++ ){
            std::cout << p.star <<" ";
        }
        std::cout << "... ";
    } else {
        for ( int i = 0 ; i < p.m ; i++ ){
            std::cout << p.star <<" ";
        }
    }
    std::cout << "]\n";

    std::cout << "mems:  m = " << p.m << ", star = " 
              << p.star << ", rem = " << p.rem << '\n';

}



Part intPartition_NSO( int n ) {

    // Construct near suboptimal integer partition

    //int m = fastApxSqrt( n );
    int m = sqrt(n);

    Part p;
    p.m    = m;
    p.star = m;
    p.rem  = n - m*m;

    return p;
}
/*
*/

}
#endif
