
//

#include <iostream>
#include <iterator>
//#include <typeinfo>
//#include <string>
//#include <time.h>

enum StudentNames
{
    kenny,    // 0
    kyle,     // 1
    stan,     // ...
    cartman,
    butters,
    wendy,
    no_students,  // 6
};

namespace animals
{
    enum Animal
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        no_animals,
    };

    std::ostream& operator<<(std::ostream& out, Animal animal)
    {
        switch (animal)
        {
            case chicken:  out << "chicken"; break;
            case dog:      out << "dog";   break;
            case cat:      out << "cat";  break;
            case elephant: out << "elephant"; break;
            case duck:     out << "duck";   break;
            case snake:    out << "snake";  break;
            default:       out << "???";   break;
        }
        return out;
    }
}

// ---------------------------------
// functions of arrays
void somefnc(int N, double* array)
{
    double x  = 0.0;
    double NN = (double)(N-1);
    for (int j=0; j<N; j++){
        x = ((double)j)/NN;
        array[j] = x;
    }
}

void printArraySize(double array[])
{
    std::cout << "number of elements: " << sizeof(array)/sizeof(array[0]) << " <--this is wrong obv."<<'\n';
}

int main()
{
    constexpr int N = 20;
    double examplearray[N]{};
    for (int j=0; j<N; j++){
        examplearray[j] = (double)j;
       // std::cout << examplearray[j] << '\n';
    }

    // Initialize array using enums
    int testScore[no_students]{};
    testScore[stan] = 76;

    for (int j=0; j<no_students; j++) {
       // std::cout << testScore[j] << '\n';
    }

    // ----------------------------------------------------
    // Passing arrays to functions
    //
    somefnc( N, examplearray);

    for (int j=0; j<N; j++){
        // examplearray[j] = (double)j;
       std::cout << examplearray[j] << '\n';
    }

    // Determine length of arrays
    // std::size() only works in C++17 and beyond
    // I have C++14.  use sizeof() instead
    std::cout << "number of elements: " << sizeof(examplearray)/sizeof(examplearray[0]) << '\n';

    // Doesnt quite work inside a function
    // instead sizeof() will return the size of a pointer
    printArraySize( examplearray );

    // ------------------------------------------------------
    // Quiz
    //
    int days = 365;
    double temperature[days]{};
    std::cout << temperature[235]<<'\n';

    int no_legs[animals::no_animals]{};
    no_legs[animals::elephant] = 4;
    std::cout << "Elephant has " << no_legs[animals::elephant] << " legs\n";

    return 0;
}