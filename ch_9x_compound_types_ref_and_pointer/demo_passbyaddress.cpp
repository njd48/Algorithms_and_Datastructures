
//

#include <iostream>
#include <typeinfo>
#include <string>

void printByValue1( std::string y )
{
    std::cout << "result: " << y << '\n';
}

void printByRef( std::string& y ) // parameter y is now a reference
{
    std::cout << "result: " << y << '\n';
}

void printByAddr( std::string* y) //parameter y is a pointer to the memory
{
    std::cout << "result: " << *y << '\n';
}

void addOne(int& y)
{
    y++; // y is a reference to the input
}

void printInt(const int& y)
{
    std::cout << "result: " << y << '\n'; // y is a reference to the input
}

void greet(std::string* name=nullptr ) // argument defaults to nullpointer
{
    std::cout << "hello ";
    std::cout << ( name ? *name : "guest" ) <<'\n';
}

void nullify(int*& refptr)
{
    refptr = nullptr;
}

int main()
{

    // Pass By address
    std::string s = "The dingo ate my baby!";
    printByAddr(&s);

    // optional arguments by defaulting to nullpointer
    // function detects the nullpointer
    greet();
    std::string sname = "John";
    greet(&sname);

    // Pass by address by reference (what?)
    // function intakes a reference to a pointer
    // rather than a copy.
    // pointer is modified in the function
    int x = 5;
    int* ptr = &x;
    std::cout << "ptr is " << (ptr ? "not null\n" : "null\n");
    nullify( ptr );
    std::cout << "ptr is " << (ptr ? "not null\n" : "null\n");



    return 0;
}