
//
#include <iostream>

int main()
{
    std::cout << "Enter your height in centimeters: \n";

    int x{};
    std::cin >> x;

    if ( x > 180 )
    {
        std::cout << "result: " << x << " cm > 180 cm \n";
        std::cout << "You may ride!\n";
    }
    else
    { // addition of code blocks admit multiple statements
        std::cout << "result: " << x << " cm < 180 cm \n";
        std::cout << "not tall enough to ride!\n";
    }

    return 0;
}