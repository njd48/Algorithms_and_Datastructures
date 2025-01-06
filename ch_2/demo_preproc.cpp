//
// 

#include <iostream>

// preprocessor directives
// #define BALLS

void doPrint()
{
    #ifdef BALLS
    std::cout << "is balls" << '\n';
    #endif

    #ifndef BALLS
    std::cout << "is not balls" << '\n';
    #endif
}

int main()
{

    doPrint();
    
    return 0;
}