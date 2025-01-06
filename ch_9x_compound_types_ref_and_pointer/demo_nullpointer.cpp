
//

#include <iostream>
#include <typeinfo>
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

    int* ptr {};  //nullpointer

    //dereferencing a nullpointer will crash the program
    //  std::cout << *ptr << '\n';

    int x = 5;
    ptr = &x;

    if (ptr == nullptr ){
        std::cout << "ptr is null\n";
    } else {
        std::cout << "ptr is not null\n";
    }

    ptr = nullptr;
    std::cout << "ptr is: " << (ptr==nullptr ? "null" : "non-null") << " \n";

    // null pointers implicitly convert o boolean false
    std::cout << "ptr is: " << (ptr ? "not null\n" : "null\n" );

    return 0;
}