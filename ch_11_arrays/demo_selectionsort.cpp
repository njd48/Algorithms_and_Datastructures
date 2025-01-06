
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

void printArr(int N, int* array)
{
    std::cout << "[ ";
    for (int j=0 ; j<N ; j++)
    {
        std::cout << array[j] << "  " ;
    }
    std::cout << "]\n";
}

void selectionSort(int N, int* array)
{
    int dummy_small = array[0];
    int dummy_inx = 0;

    for (int j=0 ; j<N ; j++) 
    {
        // find smallest element after j
        dummy_small = array[j];
        dummy_inx   = j;
        for (int k=j+1 ; k<N ; k++) 
        {
            if (array[k]<dummy_small) {
                dummy_small = array[k];
                dummy_inx   = k;
            }
        }
        // perform swap
        // replace element j with the smallest
        array[dummy_inx] = array[j];
        array[j]         = dummy_small;
    }
}

void bubbleSort_u(int N, int* A)
{
    int dink{};

    for (int j=1 ; j<N ; j++) 
    {
        // cycle through the array and successively
        // swap elements according to size comparison
        // last element will therefore be the largest
        // repeat on the remaining array elements
        // from 0 to N-j
        for (int k=0 ; k<(N-j) ; k++)
        {
            if (A[k]>A[k+1])
            {
                dink   = A[k];
                A[k]   = A[k+1];
                A[k+1] = dink;
            }
        }
    }
}

int bubbleSort_o(int N, int* A)
{
    // the same with a small optimization
    // to terminate early when sorted
    // returns int n_iter for testing purposes

    int n_iter{};
    bool swap_occured = 0;
    int dink{};

    for (int j=1 ; j<N ; j++) 
    {
        // cycle through the array and successively
        // swap elements according to size comparison
        // last element will therefore be the largest
        // repeat on the remaining array elements
        // from 0 to N-j
        swap_occured = 0;

        for (int k=0 ; k<(N-j) ; k++)
        {
            if (A[k]>A[k+1])
            {
                swap_occured = 1;
                dink   = A[k];
                A[k]   = A[k+1];
                A[k+1] = dink;
            }
        }

        n_iter = j;

        if (!swap_occured){
            break;
        }
    }
    return n_iter;
}

int main()
{
    int Array0[]{ 30, 50, 20, 10, 40, 31, 23, 8 };
    constexpr int N{ static_cast<int>(sizeof(Array0)/sizeof(Array0[0])) };

    //printArr(N, Array0);

    //-----------------------------------------------------

    std::cout << "test selection sort:\n\n";

    int Array1[N];
    setArray(N, Array1, Array0);

    std::cout << "input:  ";
    printArr(N, Array1);

    selectionSort(N, Array1);

    std::cout << "output: ";
    printArr(N, Array1);

    std::cout << "-------------------------------------------\n";

    //------------------------------------------------------

    std::cout << "test bubble sort:\n\n";

    int Array2[N];
    setArray(N, Array2, Array0);

    std::cout << "input:  ";
    printArr(N, Array2);    

    bubbleSort_u(N, Array2);

    std::cout << "output: ";
    printArr(N, Array2);

    std::cout << "-------------------------------------------\n";

    //------------------------------------------------------

    std::cout << "test optim bubble sort:\n\n";

    int n_iter{};
    int Array3[N];
    setArray(N, Array3, Array0);

    std::cout << "input:  ";
    printArr(N, Array3);   

    n_iter = bubbleSort_o(N, Array3);

    std::cout << "output: ";
    printArr(N, Array3);
    std::cout << "after " << n_iter << " iterations\n";

    std::cout << '\n';

    std::cout << "input:  ";
    printArr(N, Array3);    

    n_iter = bubbleSort_o(N, Array3);

    std::cout << "output: ";
    printArr(N, Array3);
    std::cout << "after " << n_iter << " iterations\n";

    return 0;
}