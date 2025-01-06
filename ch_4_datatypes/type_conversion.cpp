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
    int a = 97;
    double x = 32.55;

    std::cout << "Begin with...\n"
        "int value: a = " << a <<'\n';
    std::cout << "double value: x = " << x << '\n';

    std::cout << "Type conversion implicit...\n";
    printDub( a );    
    printInt( x );

    std::cout << "Now using static cast on x...\n";
    printInt( static_cast<int>( x ) );

    std::cout << "Now using static cast int to char...\n";
    std::cout << a << " becomes " << static_cast<char>( a ) << '\n';

    return 0;
}