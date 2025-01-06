//
//

#include <iostream>
#include <string>   // Enables std::string

int main()
{
    std::string myAss{  };
    std::string myBalls{ };
    
    std::cout << "Enter your full name:...\n";
    std::getline( std::cin  >> std::ws, myAss );  
    // std::getline() needed to take strings with white spaces.
    // std::ws best practice to ignore default whitespace formatting

    std::cout << "Enter your age:...\n";
    std::getline( std::cin  >> std::ws, myBalls ); 

    std::cout << "Your name is " << myAss << ", and you are " << myBalls << " years old.\n";

    return 0;
}