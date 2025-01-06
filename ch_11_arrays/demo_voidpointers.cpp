
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

int main()
{
    //-------------------------------------------------------
    // Void Pointer can point to anything
    //

    int    nVal{ 4 };
    float  fVal{ 1.12f };
    double dVal{ 3.14 };

    // All valid opitons for targets
    void* ptr;
    ptr = &nVal;
    ptr = &fVal;
    ptr = &dVal;

    // Cannot be dereferenced without a cast
    // because the type is not known by the pointer
    // *ptr; //<-- illegal
    std::cout << *( static_cast<double*>(ptr) ) << '\n';


    return 0;
}