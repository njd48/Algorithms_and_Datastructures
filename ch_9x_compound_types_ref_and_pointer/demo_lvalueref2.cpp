
//

#include <iostream>
#include <string>

void printValue1( std::string y )
{
    std::cout << "result: " << y << '\n';
}

void printValue2( std::string& y ) // parameter y is now a reference
{
    std::cout << "result: " << y << '\n';
}

void addOne(int& y)
{
    y++; // y is a reference to the input
}

void printInt(const int& y)
{
    std::cout << "result: " << y << '\n'; // y is a reference to the input
}


int main()
{

    std::string x {"The dingo ate my baby!"};
    int y = 5;

    // making unneccesary copies of x into y
    // via this function call
    printValue1(x);

    // Pass by reference
    // no copy required
    printValue2(x); // inexpensive

    // Pass by reference can 
    // modify the functions argument
    std::cout << y << '\n';
    addOne(y);  // this will not admit rvalues
    // std::cout << y << '\n';

    // pass by constant reference
    printInt(y); //
    printInt(5); //admits rvalues


    return 0;
}