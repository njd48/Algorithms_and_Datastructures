//
// 

#include <iostream>
//----------------------------------------------------------------

int getValFromUser()
{
    int value;
    std::cout << "Supply an integer input...\n"; 
    std::cin >> value;
    return value;
}

//----------------------------------------------------------------

int doubleNumber( int input )
{
    return 2*input;
}
//----------------------------------------------------------------

void printValue(int num)
{
    std::cout << num ;
}

//----------------------------------------------------------------

int main()
{

    int num1{ getValFromUser() };
    int num2{};

    num2 = doubleNumber(num1);

    std::cout << "times 2 is:  ";
    printValue(num2);    
    std::cout <<'\n';
    
    return 0;
}