
#include <iostream>
#include <iterator>


void printArr(int N, int* array)
{
    std::cout << "[ ";
    for (int j=0 ; j<N ; j++)
    {
        std::cout << array[j] << "  " ;
    }
    std::cout << "]\n";
}


int main()
{
    // ----------------
    // Static memory allocation (static and global variables)
    // Automatic memory allocation ( function parameters and local variables...
    //       memory is freed when the code-block ends )
    // Dynamic memory allocation: may not be known at compile time
    //
    // -----------------------------------
    //
    // Dynamic arrays:
    //

    int N{};

    std::cout << "Enter an integer for array length:...\n";
    std::cin >> N; 

    // Allocate the memory
    int* array{ new int[N]{} };

    printArr( N, array );

    // Free the memory
    delete[] array;

    return 0;
}