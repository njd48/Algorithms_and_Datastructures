
#include <iostream>
#include "myMatrix.cpp"
#include "matrixMult.cpp"

template <typename T> 
void dispMatrix( const Matrix<T>& A ){

    int M = A.nrows();
    int N = A.ncols();

    for ( int i = 0 ; i < M ; i++ ){

        std::cout << "[ ";

        for ( int j = 0 ; j < N-1 ; j++ )
        {
            std::cout << A.at(i,j) << ", ";
        }

        std::cout << A.at( i, N-1 ) << " ]\n";;
    }
    std::cout << '\n';

}

template <typename T> 
void matrixAdd( const Matrix<T>& A, const Matrix<T>& B, Matrix<T>& C ) {

    #ifdef BOUNDS_CHECKING
    assert( A.nrows() == B.nrows() && B.nrows() == C.nrows() );
    assert( A.ncols() == B.ncols() && B.ncols() == C.ncols() );
    #endif

    for ( int i = 0 ; i < C.nrows() ; i++ ){
        for ( int j = 0 ; j < C.ncols() ; j++ )
        {
            C.assign( i, j, A.at(i,j) + B.at(i,j) );
        }
    }


}

int main () {

    int M = 2;
    int N = 3;

    Matrix<double> A;

    std::cout << "have matrix A preinitialized.  is init?: " << A.isInit() << '\n';

    Matrix<double> B(M, N);

    std::cout << "have matrix B, initialized MxN to all zeros.  isinit?: " << B.isInit() << '\n';
    std::cout << "display matrix B.\n";

    dispMatrix( B );

    std::cout << "try to modify the values in matrix B.\n";

    B.assign( 0, 0, 1 );
    B.assign( 0, 1, -1 );
    B.assign( 1, 1, 1 );

    dispMatrix(B);

    std::cout << "Status of matrix A: " << A.nrows() << 'x' << A.ncols() << " \n";
    std::cout << "Try to copy B into A.\n";

    A.copyFrom(B);

    dispMatrix(A);

    std::cout << "Modify A and display both.\n";

    A.assign( 1, 0, -1 );
    A.assign( 0, 1, 0 );

    dispMatrix(A);
    dispMatrix(B);

    std::cout << "Add A to B and make C\n";
    Matrix<double> C;
    C.copyFrom(B);

    matrixAdd(  A, B, C );
    
    dispMatrix(C);

    std::cout << "can I multiply? show C = A*B^T \n";

    B.resize( N, M );
    C.resize( M, M );

    matrixMult( A, B, C );

    dispMatrix(C);


    return 0;
}

