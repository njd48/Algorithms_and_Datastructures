

#include <iostream>
#include "myFunc.hpp"

int main()
{
    int x = 5;

    std::cout << x << " : " ;

    x = upOnePow(x);

    std::cout << x << '\n';

    return 0;
}