//
// 

#include <iostream>
#include "fncs.h"    //Self header
//----------------------------------------------------------------

int getInteger()
{
    int value;
    std::cout << "Supply an integer input...\n"; 
    std::cin >> value;
    return value;
}

//----------------------------------------------------------------

int addition(int x, int y)
{
    return x+y;
}
