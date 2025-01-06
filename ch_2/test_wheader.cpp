//
//

#include <iostream>

// Forward Declaration (to beecome header inclusion)
#include "fncs.h"
#include "gee_im_a_tree.h"  // contains redundant header
// functions defined in fncs.cpp

int main()
{

    int x { getInteger() };
    int y { getInteger() };

    std::cout << x << " + " << y << " is " << addition( x, y ) << "\n";

    return 0;
}
