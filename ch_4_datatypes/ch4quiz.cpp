//
//

#include <iostream>
// #include <string>   // Enables std::string

double operate( double x, double y, char opr)
{
    switch (opr) 
    {
    case '+':
        return x+y;
    case '-':
        return x-y;
    case '*':
        return x*y;
    case '/':
        return x/y;
    default:
        std::cout << "error: operator \'" << opr << "\' not recognized\n";
        return 0;
    }
}

int main()
{

    // input two doubles and operate on them according to choice of the user
    double x{}, y{}, result{};
    char opr{};

    std::cout << "Input a double...\n";
    std::cin  >> x;
    std::cout << "Input another double...\n";
    std::cin  >> y;
    std::cout << "Input an operation (+,-,*,/)...\n";
    std::cin  >> opr;

    result = operate(x,y,opr);
    std::cout << "result: " << result << '\n';

    return 0;
}