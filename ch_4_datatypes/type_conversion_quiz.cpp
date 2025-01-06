#include <iostream>

void printDub( double x )
{
    std::cout << "val: " << x << '\n';
}

void printInt( int x )
{
    std::cout << "val: " << x << '\n';
}

int main()
{
    char a{};
    std::cout << "Input a char...\n";
    std::cin  >> a;

    std::cout << "Static cast to integer: ";
    printInt( static_cast<int>( a ) );

    std::cout << "Implicit conversion to integer: ";
    printInt( a );

    return 0;
}