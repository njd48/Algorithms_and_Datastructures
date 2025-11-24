

#include <iostream>
#include <vector>
#include <algorithm>

void dispV( std::vector<int>& x ){
    std::cout << "[";

    for ( auto a : x ) {
        std::cout << a << ' ';
    }

    std::cout << ']' << '\n';

}

int binsearch( std::vector<int>& x, int front, int back, int target){

    int i0 = front;
    int i1 = back-1;
    int f0 = x[i0];
    int f1 = x[i1];

    int i,f;

    // divide array untill arriving at 2 element base case
    while ( i1-i0 > 1 ) {

        i = (i1+i0)/2;
        f = x[i];

        if ( f == target ){
            return i;
        } else {
            if ( f > target ){
                f1 = f;
                i1 = i;
            } else {
                f0 = f;
                i0 = i;
            }
        }

    }

    if ( f0 == target ){
        return i0;
    } else if ( f1 == target ){
        return i1;
    } else {
        return -1;
    }

}

int main( ) {

    size_t N   = 10;

    // Input array, sorted integers
    //
    std::vector<int> x(N);

    for ( int i = 0; i < N ; i++){
        x[i] = rand()%100;
    }

    sort(x.begin(),x.end());
    dispV(x);

    // Does binsearch fail as expected?
    int i = binsearch ( x, 0, N, -33 );
    std::cout << "failure case is programmed to return -1: search for -33 in an array of all positives: found at " << i << '\n';

    // Search a few arrays
    int target;

    for ( int u = 0 ; u < 10 ; u++  ) {

        for ( int i = 0; i < N ; i++){
            x[i] = rand()%100;
        }
        sort(x.begin(),x.end());
        dispV( x );

        target = x[rand()%N];

        i = binsearch( x, 0, N, target);

        std::cout << "try to search for " << target << ": found at index " << i << '\n';
    }

}

