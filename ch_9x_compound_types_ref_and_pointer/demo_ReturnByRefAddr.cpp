
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

const std::string& getProgramName() 
{
    static const std::string s_progName {"Universe"};

    return s_progName;
}

const int& getNextId() // function returns a reference to s
{
    static int s = 0; //initialized
    s++;  // increment
    return s;
}

const std::string& firstAlphabetical(const std::string& a, const std::string& b)
{
    return (a<b) ? a : b;
}

int& max(int& x, int& y)
{
    return (x>y) ? x : y;  //returns the reference x or y which is the max of the two
}

int main()
{

    // Pass By address
    std::string s = "The dingo ate my baby!";
    printByAddr(&s);

    // std::string returnByValue(); // returns a copy of a string, expensive

    // calling this returns a constant reference to the static const variable 
    // defined therin  (efficient).  Reference will not be left dangling
    // because it is a reference to a static variable
    std::cout << "This program is called: " << getProgramName() <<'\n';

    // Problem with nonconstant variable return by reference:
    // value may change, and references now refer to the 
    // current value, not the historical value. AVOID THIS
    const int& ref1 = getNextId();
    const int& ref2 = getNextId();
    std::cout << "Result: "<< ref1 << " and " << ref2 <<'\n';

    // replace with normal variables.  they are assigned a copy
    // of the result returned by reference. (but nullifying the
    // efficiency of return by reference)
    const int x1 = getNextId();
    const int x2 = getNextId();
    std::cout << "Result: "<< x1 << " and " << x2 <<'\n';

    // If a parameter is passed to a function by reference
    // it is safe to return that parameter by reference
    // std::string s defined above
    std::string t = getProgramName();
    std::cout << "This program is called: " << firstAlphabetical( s,t ) <<'\n';

    // curious use of return by ref being used to modify values.
    // if a function returns a reference
    // you can make assignments to the referenced variable
    int a = 2;
    int b = 4;

    max( a, b ) = 6;

    std::cout << "a = " << a << ", b = " << b << '\n';


    return 0;
}