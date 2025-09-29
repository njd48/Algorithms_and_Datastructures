

#include "myMatrix.cpp"

template <typename T>
void matrixMult( const Matrix<T>& A, const Matrix<T>& B, Matrix<T>& C ) {

    #ifdef BOUNDS_CHECKING
    assert( A.ncols() == B.nrows() );
    assert( C.nrows() == A.nrows() && C.ncols() == B.ncols() );
    #endif

    T val = 0;

    for ( int i = 0 ; i < C.nrows() ; i++ ){
        for ( int j = 0 ; j < C.ncols() ; j++ ) {

            val = 0;
            for ( int k = 0 ; k < A.ncols() ; k++ ){
                val += A.at(i,k) * B.at(k,j);
            }
            C.assign( i,j,val );
        }
    }

}