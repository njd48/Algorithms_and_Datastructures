
//

#include <iostream>

// Declare a global variable
double g_x{};
const double g_G{ 6.67430e-11 }; // Newton

// It is conventional to use prefix g_
// for global variables

//=================================================================================
//=== Fncs ===

void setGravityEarth( )
{
    g_x = 9.81;
    std::cout << "Perscribed Earth Gravity: " << g_x << " m/2^2 \n";
}

double accel_NewtonsLaw(  double m, double r )
{
    return g_G * m / ( r*r );
}

//=================================================================================
//=== Main ===

int main()
{

    setGravityEarth();
    std::cout << "Newtons Cnst.: G = " << g_G << " m^2 / kg^2 \n";

    double r_earth = 6378.0e3;   // (m)
    double m_earth = 5.97219e24; // (kg) 
    double y_earth; // gravitational accel

    y_earth = accel_NewtonsLaw( m_earth, r_earth );
    
    std::cout << "g_earth by Newton's law: " << y_earth << " m/s^2 \n";
    std::cout << "Errors" << y_earth - g_x << " m/s^2 \n";


    return 0;
}