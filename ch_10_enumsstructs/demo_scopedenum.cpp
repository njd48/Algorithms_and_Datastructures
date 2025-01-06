
// 

#include <iostream>
#include <typeinfo>
#include <string>


// Teaching operator<< how to print the enumerator 
/*
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
*/

// ////////////////////////////////////////
// Main
int main()
{

    // enum class makes a scoped enumerator.
    // this prevents erroneous statements where
    // two enums interfere with eachother ( i.e. fruit==color).
    // they done implicitly convert to integers either
    // but you can use static_cast.
    enum class Color
    {
        red, 
        blue,
    };
    enum class Fruit
    {
        banana,
        apple,
    };
    // ------------------------------------------------
    
    Color color = Color::red;
    Fruit fruit = Fruit::banana;

    
    if (color == Color::red)  {
        std::cout << "color is red\n";
    } else {
        std::cout << "color is not red\n";
    }

    std::cout << "use static cast? " << static_cast<int>(color) << '\n';

    return 0;
}