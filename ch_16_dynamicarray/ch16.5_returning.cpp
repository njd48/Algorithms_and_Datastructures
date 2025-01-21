#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cassert>
//#include 


// Print an array
template <typename T>
void printV( const std::vector<T>& arr ) // explicitly specifying <int>
{     
    int N = arr.size();
    std::cout << "[ ";
    for (int i = 0 ; i < N-1 ; i++ ) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[N-1] << "]\n";
}

void doSomething( const std::vector<int>& v1, std::vector<int>& v2 ) {
    // v2 is non-constant, can we edit it in-place?
    int N = v2.size();
    assert( v1.size() == N );

    int jr, jl;

    for (int i = 0 ; i < N ; i++ ) {
        jr = ( i+1 % N );
        jl = ( i-1 % N );
            if (jl<0){ 
                jl = jl+N;
            }
        v2[i] = v1[jl] + v1[jr];
    }
}


std::vector<int> generateV() // return by value
{   // We're intentionally using a named object here so mandatory copy elision doesn't apply
    std::vector arr1 { 1, 2, 3, 4, 5 }; // copies { 1, 2, 3, 4, 5 } into arr1
    return arr1;
}

int main() {

    std::vector prime { 2, 3, 5, 7, 11 };
    

    std::vector arr2{ prime }; // demo copy semantics
    arr2[0] = 1;
    printV( prime );
    printV(arr2);

    std::vector arr3{ generateV() }; // copy into arr3, values inside function are destroyed
    // This copying operation may be computationally expensive.
    printV(arr3);

    // Try passing a reference to an empty array and modifying in place
    std::vector<int> v1{ 1,2,1,3,1 };
    std::vector<int> v2( v1.size() ); // <--recepticle for output

    printV(v2);
    doSomething( v1, v2 );
    printV(v1);
    printV(v2);
    // yes it works

/*
-------- Quiz ------------------------------------------------------ 
*/

    return 0;
}