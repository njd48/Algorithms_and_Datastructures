#include <iostream>

int main()
{
 
 std::cout << "\n---------------------------------------\n" 
        "sizes of float types\n";
 // Print byte number for each datatype
    std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
    std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
    std::cout << "long double:\t" << sizeof(long double) << " bytes\n";


    std::cout << "\n---------------------------------------\n" 
        "some examples of float datatypes\n";
    float xf { 5.05f }; // suffix f for float
    double xd { 5.0 };  // decimal included
    long double xdd {0.134567876543};  //

    std::cout << "f,d,dd: \n" << xf << '\n' << xd << '\n' << xdd <<'\n';

    std::cout << "\n---------------------------------------\n" 
        "some examples of printing floats\n";
    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << '\n';

    std::cout << "\n---------------------------------------\n" 
        "Demonstrate special floats representing +/- inf and NaN\n";

    double zero {0.0};
    double posinf { 5.0 / zero }; // positive infinity
    std::cout << posinf << '\n';

    double neginf { -5.0 / zero }; // negative infinity
    std::cout << neginf << '\n';

    double nan { zero / zero }; // not a number (mathematically invalid)
    std::cout << nan << '\n';

    return 0;
}