
// 

#include <iostream>
#include <typeinfo>
#include <string>
//-------------------------//
#include "classtemplate.h" //
//-------------------------//

// ////////////////////////////////////////
// 
int main()
{
    // Demonstration of function templates
    std::cout << max( 4, 6)    << '\n';
    std::cout << max(1.2, 3.4) << '\n';

    // Demonstration of class templates
    Pair<int,int>    p1{ 5, 6 };
    Pair<double,double> p2{ 1.5, 0.8};
    std::cout << max(p1) << '\n';
    std::cout << max(p2) << '\n';

    // multitype pairs
    Pair<int,double> ppp{ 30, 4.45};
    pront(ppp);


    // ----------------------------------------------------------


    // ----------------------------------------------------------
 

    return 0;
}