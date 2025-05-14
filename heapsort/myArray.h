
#ifndef MYARRAY_H
#define MYARRAY_H

struct Array {
    int  N;
    int* A;

    Array( int n ){
        N = n;
        A = new int[N];
    }
    ~Array(){
        delete[] A;
    }
    //int operator[]( const int i ){ return A[i]; }
    int& operator[]( const int i ){ return A[i]; }
};

void printArr( Array& x ) {

    std::cout << "[ " << x[0];
    for ( int i = 1; i < x.N ; i++ ) {
        
        std::cout << ' ' << x[i];
    }
    std::cout << " ]\n";
}

void buildRandArr( Array& x ) {
    int rndCut = 100;
    for ( int i = 0; i < x.N ; i++ ) {
        
        x[i] = rand()%rndCut ;
    }
}

bool isSorted( Array& x ){

    if (x.N <= 1) { 
        return true; 
    }

    for ( int i = 1; i < x.N ; i++ ) {
        if ( x[i] < x[i-1] ) {
            return false;
        }
    }
    return true;
}

#endif