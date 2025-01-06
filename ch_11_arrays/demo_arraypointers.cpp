
//

#include <iostream>
#include <iterator>
//#include <typeinfo>
//#include <string>
//#include <time.h>

void printArr(int N, int* array)
{
    std::cout << "[ ";
    for (int j=0 ; j<N ; j++)
    {
        std::cout << array[j] << "  " ;
    }
    std::cout << "]\n";
}

void fnc1(int* ptr)
{
    *ptr = 2;
}

int main()
{
    std::cout << "----------------------------------------------------------\n";

    int array[]{ 84, 92, 76, 81, 56};  // This is a fixed array
    constexpr int N{ static_cast<int>(sizeof(array)/sizeof(array[0]) )};

    int* ptr{ array };  

    // Demonstrate array decay
    std::cout << "Address of array element 0:      " << &array[0] << '\n';
    std::cout << "By way of implicit conversion...\n";
    std::cout << "Array decays to a pointer:       " << array << '\n';
    std::cout << "Dereference recoveres element 0: " << *array << '\n';
    std::cout << "ptr to array dereference, same:  " << *ptr << '\n';

    // Passing ararys by address
    std::cout << "----------------------------------------------------------\n";
    std::cout << "altering arrays in func \n\n";
    
    std::cout << "input:  ", printArr(N, array);
    fnc1(array);
    std::cout << "output: ", printArr(N, array);

    std::cout << "----------------------------------------------------------\n";
    std::cout << "Pointer Arithmetic: \n\n";

    // (ptr + 1) takes you to the next-door memory address
    std::cout << "+0: " << array   << '\t' << *(array)   << '\n';
    std::cout << "+1: " << array+1 << '\t' << *(array+1) << '\n';
    std::cout << "+2: " << array+2 << '\t' << *(array+2) << '\n';

    std::cout << '\n'<< "Identical to indexing: \n\n";
    std::cout << "[0]: " << array[0] << '\t' << &array[0] << '\n';
    std::cout << "[1]: " << array[1] << '\t' << &array[1] << '\n';
    std::cout << "[2]: " << array[2] << '\t' << &array[2] << '\n';

    std::cout << '\n';

    // Iterating through array with pointers
    std::cout << "Iterating through pointers: \n";
    std::cout << "input:  ", printArr(N, array);
    int ii = 0;
    for (int* j = array; j != array+N; j++) {
        // so j is actually a pointer here
        *(j) = N-ii;
        ii++;
    }
    std::cout << "output: ", printArr(N, array);

    // curious behaviour with the subscript operator
    // it commutes due to pointer arithmetic
    std::cout << 1[array] << '\n';  // Equivalent to array[2]




    return 0;
}