
//

#include <iostream>

int g_value{ 1 };


void printResult( int x )
{
    std::cout << "Result: " << x << '\n';
}

int main()
{
    std::cout << "a global var: \n";
    printResult(g_value);

    int z{ 4 };
    int g_value{2};  // shadows, Hides global g_value

    std::cout << "new vars defined:\n";
    printResult(z);
    printResult(g_value);

    { // Sub-block

        std::cout << "I've entered the blocc\n";

        printResult(z);
        printResult(g_value);

        // int z{};  // z (shadow) is created here

        z = 5;  // if z is not initialized in the block,
                // then this will redefine z 

        std::cout << "I've redefined z in the blocc\n";
        printResult(z);
        
    } // z is destroyed here

    // the other z lives on outside the block
    std::cout << "I've left the blocc\n";
    printResult(z);

    std::cout << "g_value is: " << g_value << '\n';
    std::cout << "access the global variable with ::g_value;  Result: " << ::g_value << '\n';

    return 0;
}