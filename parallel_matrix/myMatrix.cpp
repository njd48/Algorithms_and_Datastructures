
#ifndef MATRIX_H
#define MATRIX_H

// #define BOUNDS_CHECKING
#ifdef BOUNDS_CHECKING
    #include <cassert>
#endif

enum Option {
    none = 0,
    zeros,
};

template <class T> 
class Matrix {

    private:

        bool m_init = false;
        int m_M;
        int m_N;
        T* m_vals;

    public:

        Matrix();
        Matrix( int, int );
        ~Matrix();

        void fillZeros();
        void fillZeros( int, int );

        void resize( int, int, Option padding = zeros );

        const int nrows() const { return m_M; };
        const int ncols() const { return m_N; };
        const bool isInit() const { return m_init; };

        const T at( int, int ) const;
        void assign( int, int, T );
        void copyFrom( const Matrix<T>& );

};

template <class T> 
Matrix<T>::Matrix(){
    m_init = false;
    m_M = 0;
    m_N = 0;
}
        
template <class T> 
Matrix<T>::Matrix( int M, int N ){

    m_M = M;
    m_N = N;
    m_vals = new T[ m_M * m_N ];
    m_init = true;
    fillZeros();
}
        
template <class T> 
Matrix<T>::~Matrix(){

    if (m_init) {
        delete[] m_vals;
        m_init = false;
    }
}

template <class T> 
void Matrix<T>::fillZeros( ){
    for ( int i = 0 ; i < m_M ; i++ ){
        for ( int j = 0 ; j < m_N ; j++ ){
            m_vals[ m_N*i + j ] = 0;
        }
    }
}

template <class T> 
void Matrix<T>::fillZeros( int m, int n ){

    #ifdef BOUNDS_CHECKING
    assert( m <= m_M && n <= m_N );
    #endif

    // Right block
    for ( int i = 0 ; i < m_M ; i++ ){
        for ( int j = n ; j < m_N ; j++ ){
            m_vals[ m_N*i + j ] = 0;
        }
    }

    //lower left block
    for ( int i = m ; i < m_M ; i++ ){
        for ( int j = 0 ; j < n ; j++ ){
            m_vals[ m_N*i + j ] = 0;
        }
    }
}

template <class T> 
void Matrix<T>::resize( int M, int N, Option padding ) {

    if ( M == m_M && N == m_N ){
        return;
    }

    if ( M==0 && N==0 ) {
        
        delete[] m_vals;
        m_M = M;
        m_N = N;
        m_init = false;
        return;

    }

    T* oldvals = m_vals;
    T* newvals = new T[ M*N ];

    int minM = ( M + m_M - abs( m_M - M )  )/2;
    int minN = ( N + m_N - abs( m_N - N )  )/2;

    // Fill values
    
    for ( int i = 0 ; i < minM ; i++ ) {
        for ( int j = 0 ; j < minN ; j++ ) {

            newvals[ M * i + j ] = oldvals[  m_N * i + j  ];

        }
    }
  

    m_M = M;
    m_N = N;
    m_vals = newvals;
    if (isInit()) {
        delete[] oldvals;
    } else {
        m_init = true;
    }

    if ( padding == zeros ) {
        fillZeros( minM, minN );
    }
    
}



template <class T> 
const T Matrix<T>::at( int i, int j ) const {

    #ifdef BOUNDS_CHECKING
    assert( i < m_M && j < m_N );
    #endif

    return m_vals[ m_N*i + j ];
}


template <class T> 
void Matrix<T>::assign( int i, int j, T a ){

    #ifdef BOUNDS_CHECKING
    assert( i < m_M && j < m_N );
    #endif

    m_vals[ m_N*i + j ] = a;
}

template <class T> 
void Matrix<T>::copyFrom( const Matrix<T>& B )
{
    resize(         0,         0, none );
    resize( B.nrows(), B.ncols(), none );

    for (int i = 0; i < m_M ; i++ ){
        for (int j = 0; j < m_N; j++ ){
            assign(  i, j, B.at(i,j) );
        }
    }
}
        

#endif