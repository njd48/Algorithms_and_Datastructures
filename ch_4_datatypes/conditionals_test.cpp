#include <iostream>

int main()
{
 
    int x{};
    std::cout << "Give an integer... ";
    std::cin >> x;

    if (x==0)
        std::cout << "the value is zero\n";
    else if ( x > 0 )
        std::cout << "the value is positive\n";
    else
        std::cout << "the value is negative\n";

    return 0;
}