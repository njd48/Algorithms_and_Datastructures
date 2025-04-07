

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <cassert>

template <class T>
class Matrix 
{
    private:
        int M, N;
        std::vector< std::vector<T> > vals;

    public:
        Matrix( );
        ~Matrix();

        // Data access methods
        void resize( int, int );
        T    at(     int, int );
        void assign( int, int , T );

        // mathematical operations
        Matrix<T> transpose();

        // Display
        void display();
        void displayRow( int );

};

template <class T>
Matrix<T>::Matrix(  ){
    M = 0;
    N = 0;

    vals.resize( M );
    for ( int i = 0 ; i < M ; i++ ){
        vals[i].resize(N);
    }
};

template <class T>
Matrix<T>::~Matrix(){  
    //
};

template <class T>
void Matrix<T>::resize( int m, int n ){

    M = m;
    N = n;

    vals.resize( M );    
    for ( int i = 0 ; i < M ; i++ ){
        vals[i].resize(N);
    }
}

template <class T>
T Matrix<T>::at( int i, int j ){
    return vals[i][j];
}

template <class T>
void Matrix<T>::assign( int i, int j, T a ){
    assert( i < M );
    assert( j < N ); 
    vals[i][j] = a;
}


template <class T>
Matrix<T> Matrix<T>::transpose() {
    Matrix<T> B(N,M);

    for( int i = 0 ; i < M ; i++ ){
        for( int j = 0 ; j < N ; j++ ){
            B.vals[j][i] = vals[i][j];
        }
    }

    return B;
}


template <class T>
void Matrix<T>::display(  ){
    
    for( int i = 0 ; i < M ; i++ ){
        std::cout << "[ " ;
        for( int j = 0 ; j < N ; j++ ){
            //std::cout<< "here inside\n";
            std::cout << "\t" << vals[i][j] ;
        }
        std::cout << " ]\n" ;
    }
}

template <class T>
void Matrix<T>::displayRow( int i  ){
        std::cout << "[ " ;
        for( int j = 0 ; j < N ; j++ ){
            //std::cout<< "here inside\n";
            std::cout << "\t" << vals[i][j] ;
        }
        std::cout << " ]\n" ;
}


#endif