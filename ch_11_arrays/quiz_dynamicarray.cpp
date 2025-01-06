
#include <iostream>
#include <iterator>

template<typename T>
void printArrVert(int N, T* array)
{
    
    for (int j=0 ; j<N ; j++)
    {
        std::cout << "[ ";
        std::cout << array[j] ;
        std::cout << " ]\n";
    }
    
}

template<typename T>
void bubbleSort_o(int N, T* A)
{
    // the same with a small optimization
    // to terminate early when sorted
    // returns int n_iter for testing purposes

     // int n_iter{};
    bool swap_occured = 0;
    T dink{};

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

        //n_iter = j;

        if (!swap_occured){
            break;
        }
    }
    //return n_iter;
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
    // Question 1: input a list of names and
    //     sort them alphabetically.

    int N{};

    std::cout << "How many names will you enter:...\n";
    std::cin >> N; 

    // Allocate the memory
    std::string* array{ new std::string[N]{} };

    // Prompt the user for inputs
    for (int j = 0; j<N; j++)
    {
        std::cout << "Enter name " << j+1 << ":  ";
        std::cin  >> array[j];
        //std::cout << '\n';
    }

    // Sort
    bubbleSort_o( N, array );

    std::cout << "Alphabetical list of names: \n";
    printArrVert( N, array);


    return 0;
}