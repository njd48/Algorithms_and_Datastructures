#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cassert>
//#include 


// Need function templates to infer types
template <typename T>
void passByRef( const std::vector<T>& arr ) // explicitly specifying <int>
{       // Constant reference prevents erroneous copies from
        // being made in memory
        // void passByRef(const std::vector& arr) // compile error: CTAD can't be used to infer function
    std::cout << arr[0] << '\n';
}

// A totally generic template:
template <typename T>
void passByRef2( const T& arr ) {
    std::cout << arr[0] << '\n';
}

// Function prints the third element of an array
template <typename T>
void printThird( const std::vector<T>& arr ){
    // assert( arr.size() <= 3 ); << throws runtime error
    std::cout << arr[2] << '\n';
}

template <typename T>
void QuizFnc( const std::vector<T>& vec, int inx ){
    /*  Write a function that takes two parameters: a std::vector and 
    an index. If the index is out of bounds, print an error. If the 
    index is in bounds, print the value of the element.  */

    if ((inx < 0)||(inx >= vec.size() )) {
        std::cout << "Err: index, " << inx << ", out of bounds.\n";
    } else {
        std::cout << vec[inx] << '\n';
    }

}

int main() {

    std::vector prime { 2, 3, 5, 7, 11 };

    std::vector dbl {1.1, 1.2, 1.4};

    passByRef(prime);
    passByRef(dbl);

    passByRef2(prime);
    passByRef2(dbl);

    std::vector arr2{ 10, 11 }; 
    printThird( prime );   // <-- works fine
    printThird( arr2 );    // <-- undefined behavior
    // tutorial says using std::array is better 
    // so that you can static_assert the length
    // std::vector can do runtime assert

/*
-------- Quiz ------------------------------------------------------ 
    Write a function that takes two parameters: a std::vector and 
    an index. If the index is out of bounds, print an error. If the 
    index is in bounds, print the value of the element.
*/
    QuizFnc( prime, 3 );
    QuizFnc( prime, 5 ); // 5 is out of bounds


    return 0;
}