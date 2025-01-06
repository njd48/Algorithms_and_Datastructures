//
//

#include <iostream>

// Forward Declaration
int getInteger();
// function defined in getInteger.cpp

int main()
{

    int x { getInteger() };
    int y { getInteger() };

    std::cout << x << " + " << y << " is " << x+y << "\n";

    return 0;
}
