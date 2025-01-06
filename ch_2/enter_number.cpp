//
// 

#include <iostream>

int getValFromUser()
{
    int value{};
    std::cout << "Supply an integer input...\n"; 
    std::cin >> value;
    return value;
}

int main()
{

    int num1{};
    int num2{};

    num1 = getValFromUser();

    num2 = 2 * num1;

    std::cout << "time 2 is:  " << num2 << "\n";
    
    return 0;
}