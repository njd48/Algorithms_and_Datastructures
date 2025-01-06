
//
#include <iostream>
#include <limits>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble()
{
    double x;
    
    while (true)
    {
        std::cout << "Enter a double... ";
        std::cin >> x;
        
        // Test for extraction failure
        if (std::cin.fail()) // has a previous extraction failed?
        {
            // yep, so let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine(); // and remove the bad input
            std::cout << "Invalid input. ";
        }
        else
        {
            ignoreLine();
            return x;
        }
    }

}

char getOper()
{
    char c;

    while (true)
    {
        std::cout << "Enter an operation ( +, -, *, / )... ";
        std::cin >> c;
        ignoreLine();

        switch (c)
        {
            case '+':
            case '-':
            case '*':
            case '/':
                return c;
            default:
                std::cout << "that's not vaild, try again.  ";
        }
    }
}

void printResult(  double x, char oper, double y)
{
    double result{};

    switch(oper)
    {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        default:
            std::cerr << "Error: do not recognize operator: \'" << oper << "\' \n";
            break;
    }

    std::cout << "Result: " << x << ' ' << oper << ' ' << y << " = " << result << '\n';

}

int main()
{

    double x{}, y{};
    char oper{};

    // Start taking inputs from user
    x = getDouble();
    oper = getOper();
    y = getDouble();
    // giving a char for x, for example, causes this to fail immediately.


    printResult(x, oper, y);

    return 0;
}