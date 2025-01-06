
//
#include <iostream>

void printName(int x)
{
    switch (x)
    {
        case 1:
            std::cout << "one\n";
            break; // code in switch-block will continue executing without break statement
        case 2:
            std::cout << "two\n";
            // break;  
            [[fallthrough]]; // indicate an intentional switch fallthrough
        case 3:
            std::cout << "three\n";
            break;
        default:
            std::cout << "unknown\n";
            break;
    }

    std::cout << "ass\n";
    return;
}

int main()
{
    
    printName(2);

    return 0;
}