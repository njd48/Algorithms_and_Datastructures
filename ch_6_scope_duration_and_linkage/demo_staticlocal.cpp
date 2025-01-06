
//

#include <iostream>
#include "cnsts.h"

//=================================================================================
//=== Fncs ===

void incrementAndPrint()
{
    static int s_val{ 1 }; // Static declaration is never repeated

    ++s_val;

    std::cout << "Result: " << s_val << '\n';
}

double accel_NewtonsLaw(  double m, double r )
{   
    // static cnst is not destroyed at the end of this function
    static const double s_newton_G = cnsts::newton_G; 
    return s_newton_G * m / ( r*r );
}

//=================================================================================
//=== Main ===

int main()
{

    std::cout << "Testing static vars: ";
    incrementAndPrint(); // 2
    incrementAndPrint(); // 3
    incrementAndPrint(); // 4

    //-----------------------------------------------------------------

    double g_981   = cnsts::gravity; // (m/s^2) 
    double r_earth = 6378.0e3;       // (m)
    double m_earth = 5.97219e24;     // (kg) 
    double g_calc;                   // (m/s^2)


    g_calc = accel_NewtonsLaw( m_earth, r_earth );


    std::cout << "Newtons Cnst.: G = " << cnsts::newton_G << " m^2 / kg^2 \n";
    std::cout << "g_earth by assumption:   " << g_981 << " m/s^2 \n";
    std::cout << "g_earth by Newton's law: " << g_calc << " m/s^2 \n";
    std::cout << "Errors:                  " << g_calc - g_981 << " m/s^2 \n";


    return 0;
}