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
    int result{};

    num1 = getValFromUser();
    num2 = getValFromUser();
    result = num1 + num2;

    std::cout << num1 << " + " << num2 << " = " << result << "\n";
    
    return 0;
}