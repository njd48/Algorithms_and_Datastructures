
//

#include <iostream>
#include "foo.h"
#include "goo.h"

// this one is in the global namespace
void printResult( int x )
{
    std::cout << "Result: " << x << '\n';
}


namespace penn
{
    // we are now in penn namespace
    void doResult( int x)
    {
        std::cout << "Pennsylvania\n";
        ::printResult(x);  // :: grabs function from the global namespace
    }
}


int main()
{

    namespace active = foo; // Utilizing namespace alias

    int x{2}, y{3}, z{};

    z = active::doSomething(x,y);
    printResult(z);

    z = goo::doSomething(x,y);
    printResult(z);
    penn::doResult(z);

    return 0;
}