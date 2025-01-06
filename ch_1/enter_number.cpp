//
// 

#include <iostream>

int main()
{

    int num1{};
    int num2{};

    std::cout << "Supply an integer input...\n"; 

    std::cin >> num1;

    num2 = 2 * num1;

    std::cout << "time 2 is:  " << num2 << "\n";
    
    return 0;
}