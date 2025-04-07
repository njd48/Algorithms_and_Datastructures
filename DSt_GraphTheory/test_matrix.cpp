

#include <iostream>
#include "myMatrix.cpp"

int main() {

    int M = 3;
    int N = 4;

    Matrix<int>  A;

    A.resize(M,N);

    //-------------------------------------------
    std::cout << "Initialize Matrix:...\n";
    A.display();
    std::cout << '\n';

    //-------------------------------------------
    std::cout << "Assign vals to Matrix:...\n";
    A.assign( 0, 1 , 13 );
    A.assign( 1, 0,  -1);

    A.display();
    std::cout << '\n';

    //-------------------------------------------
    std::cout << "request values from Matrix:...\n";
    
    std::cout << " find at (0,0): " << A.at(0,0) << '\n';
    std::cout << " find at (0,1): " << A.at(0,1) << '\n';
    std::cout << " find at (1,0): " << A.at(1,0) << '\n';
    
    std::cout << '\n';

    //-------------------------------------------
    std::cout << "Resize Matrix:...\n";
    A.resize( 2, 3 );
    A.display();
    std::cout << '\n';

    //-------------------------------------------
    std::cout << "Transpose Matrix:...\n";
    Matrix<int> B = A.transpose();
    B.display();
    std::cout << '\n';





}