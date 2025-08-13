

#include <iostream>
#include <string>

#include "calculator_io.cpp"

int main()
{

    std::string input{};
    bool tester = false;

    while (true) {
        std::cout << "testing valid parenthesis.\n";
        std::cout << "give input, (q to exit). \n";
        std::cin  >> input;

        if ( input[0]=='q') {
            break;
        }

        tester = validParenthesis(input);

        std::cout << tester << '\n';
    }

}