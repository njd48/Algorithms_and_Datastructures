
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

    constexpr int fibonacci[]{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    // int N{}; // dont need this

    //-------------------------------------------------------
    // Simple for-each loop
    //
    for (auto fib : fibonacci)
    {
        std::cout << fib << ' '; // access each array
    }
    std::cout << '\n';

    //-------------------------------------------------------
    // With a reference :)), no copies here
    // const prevents alteration of the array
    //
    for (const auto& fib : fibonacci)
    {
        std::cout << fib << ' '; // access each array
    }
    std::cout << '\n';

    //-------------------------------------------------------
    // Quiz.
    //
    std::string nameList[]{ "Alex","Betty","Caroline","Dave","Emily","Fred","Greg","Holly" };

    std::string input{};
    bool found{0};

    std::cout << "Enter A name:... ";
    std::cin >> input;

    for (const auto& n : nameList )
    {
        if (n==input)
        {
            
            found = 1;
            break;
        }
    }

    if (found) {
        std::cout << input << " was found\n";
    } else {
    std::cout << input << " was not found.\n";
    }

    return 0;
}