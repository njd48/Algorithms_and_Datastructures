
#include <iostream>
#include <iomanip>
#include <complex>
#include <cmath>

//
//
// Trying math with complex numbers
// best revisit this again
// 

int main()
{
    // Junk I dont understand
    using namespace std::complex_literals;
    std::cout << std::fixed << std::setprecision(1);

    // Declaration of vars
    const double PI = std::acos(-1);
    std::complex<double> z, z1, z2;

    //--------------------------------------------------
    // Testing our math
    //--------------------------------------------------

    // Can we write 1 + i ?
    z = 1.0 + 1i*2.0;
    std::cout << z <<'\n';

    // Eulers formula
    z  = 1i*PI;
    z1 = std::exp( z ) ;
    std::cout << "exp( i pi ) = " << z1 << "\n";
    
    //--------------------------------------------------
    return 0;
}