
// 

#include <iostream>
#include <typeinfo>
#include <string>

enum Color
{
    black, // assigned 0, and so on
    red,
    blue,
    green,
    white,
    cyan,
    yellow,
    magenta,
};

std::string getColor(Color color)
{
    switch(color)
    {
        case black: return "black";
        case red:   return "red";
        case blue:  return "blue";
        default:    return "???";
        // too lazy to write the rest
    }
}

// Teaching operator<< how to print the enumerator
std::ostream& operator<<(std::ostream& out, Color color)
{
    switch (color)
    {
        case black: out << "black"; break;
        case red:   out << "red";   break;
        case blue:  out << "blue";  break;
        default:    out << "???";   break;
        // too lazy to write the rest
    }
    return out;
}

// ////////////////////////////////////////
// Main
int main()
{
    
    Color shirt = blue;
    Color fish  = static_cast<Color>(1);  // fish is red

    // Implicit convertion to integral values
    // naive output 2
    // but after redefining the behavior of cout<< (above)
    // we get the result we want
    std::cout << "your shirt is " << shirt <<'\n';

    // Assign str outputs
    // using switch block in a function
    std::cout << "your shirt is " << getColor(shirt) <<'\n';

    // demonstration of static cast conversion 
    // of integer to an unscoped enumerator
    std::cout << "the fish is " << fish <<'\n';

    // std::cin cannot recognize these program defined 
    // enumerators.  so use static casts on integral values:
    int input{};

    std::cout << "What color is your dog's fur?\n" 
            << "(0=black, 1=red, 2=blue):...\n" ;
    std::cin >> input;

    Color dog = static_cast<Color>(input);

    std::cout << "The dog is " << dog << '\n';

    return 0;
}