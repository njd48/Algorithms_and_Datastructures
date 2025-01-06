
//

#include <iostream>
//#include <iterator>
//#include <typeinfo>
//#include <string>
//#include <time.h>

void setArray(int N, int* u, int* v)
{
    for (int j=0 ; j<N ; j++)
    {
        u[j] = v[j];
    }
}

void printMatrix(int M, int N, int* A)
{
    for (int j=0 ; j<M ; j++)
    {
        std::cout << "[ ";
        for (int k=0 ; k<N ; k++)
        {
            std::cout << "\t" << A[ N*j + k ]  ;
        }
        std::cout << " ]\n";
    }
}



int main()
{
    // A is an MxN matrix
    int A[][4]
    { 
        { 2, 4, 5, 1},
        { -1, 7, -1, 3},
        { 0, 3, 0, -2}
     };
    constexpr int M{ static_cast<int>( sizeof(A) / sizeof(A[0])) };
    constexpr int N{ static_cast<int>( sizeof(A[0]) / sizeof(A[0][0])) };

    std::cout << " A is a " << M << "x" << N << " matrix.\n";

    printMatrix(M,N, &(A[0][0]) );

    // --------------------------------------------------
    // Example: multiplication table
    constexpr int P = 9;
    int m_table[P][P]{};

    for (int j=1 ; j<=P ; j++) // left factor (row header)
    {
        for (int k=1 ; k<=P ; k++) // right factor (column header)
        {
            m_table[j-1][k-1] = j*k;
        }
    }

    std::cout << "multiplication table:\n";
    printMatrix( P, P, &(m_table[0][0]) );
 

    return 0;
}