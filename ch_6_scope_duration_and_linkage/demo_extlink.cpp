
//

#include <iostream>
#include "ext.h"  //extern vars forward-declared here


void printResult( int x , int y)
{
    std::cout << "Result: " << x << " and " << y << '\n';
}

int main()
{
    std::cout << "test extern variables.. \n";
    printResult( g_x, g_y );
    return 0;
}