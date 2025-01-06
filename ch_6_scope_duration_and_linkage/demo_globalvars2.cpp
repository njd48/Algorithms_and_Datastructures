
//

#include <iostream>

#include "cnsts.h" // contains constants in a namespace
                   // this file treats them as run time constants

//=================================================================================
//=== Fncs ===

double accel_NewtonsLaw(  double m, double r )
{
    return (cnsts::newton_G) * m / ( r*r );
}

//=================================================================================
//=== Main ===

int main()
{
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