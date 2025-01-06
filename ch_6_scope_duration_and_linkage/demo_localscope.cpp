
//

#include <iostream>
#include "foo.h"
//#include "goo.h"

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

    int x{2}, y{3};

    { // Sub-block

        int z{};  // z is created here

        z = active::doSomething(x,y); // x and y can still be accessed

        printResult(z);

        
    } // z is destroyed here

    // printResult(z); //compiler error: z not declared in this scope
    std::cout << "I've left the blocc\n";
    // printResult(z);
    // penn::doResult(z);

    return 0;
}