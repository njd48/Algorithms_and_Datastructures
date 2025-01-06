
//
#include <iostream>

int randomNumber()
{
    return 4;
}

int main()
{

    std::cout << "\ndemonstrate halting\n";
    std::cout << randomNumber() << '\n';

    // cleanup(); ???
    std::exit(0);  // exit and return 0 to the processor
                   // this does not clean the variables
                   
    std::cout << "this doesn't get executed.\n";

    return 0;
}