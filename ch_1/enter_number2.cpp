//
// 

#include <iostream>

int main()
{

    int x{};
    int y{};
    int result1{};
    int result2{};

    std::cout << "Supply two integer inputs...\n"; 

    std::cout << "x = \n"; 
    std::cin >> x;

    std::cout << "y = \n"; 
    std::cin >> y;

    std::cout << "----------------------------------\n"
                 "results:\n";

    result1 = x + y ;

    std::cout << x << " + " << y << " = " << result1 << "\n";

    result2 = x - y;

    std::cout << x << " - " << y << " = " << result2 << "\n";
    
    return 0;
}