
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

    std::string s {"The dingo ate my baby!"};
    int x = 5;

    std::cout << "x = " << x << '\n';

    std::cout << "the address-of operator (&)\n";
    std::cout << &x << '\n'; //memory address of x
    std::cout << typeid(&x).name() <<'\n'; //

    std::cout << "the dereference operator (*)\n";
    std::cout << *(&x) << '\n'; //value stored at memory address &x
    

    std::cout << "----------------------------------------------\n";
    
    int* ptr{ &x }; // pointer to the address of x

    std::cout << "pointer: \n";
    std::cout << *ptr << '\n'; 
    //'dereference' pointer to acquire the stored value

    //change pointer address
    int y = 6;
    ptr = &y;

    std::cout << *ptr << '\n';

    //change object value with dereference (*)
    *ptr = 7; 
    std::cout << y << '\n';
    std::cout << *ptr << '\n';

    std::cout << "----------------------------------------------\n";
    std::cout << "size of pointers: \n";
    char* chPtr{};
    int* iPtr{};
    double* dPtr{};
    long double* ldPtr{};
    std::cout << sizeof(chPtr) << " ,  " << sizeof(*chPtr) <<'\n'; 
    std::cout << sizeof(iPtr)  << " ,  " << sizeof(*iPtr) <<'\n'; 
    std::cout << sizeof(dPtr)  << " ,  " << sizeof(*dPtr) <<'\n'; 
    std::cout << sizeof(ldPtr) << " ,  " << sizeof(*ldPtr) <<'\n'; 

    return 0;
}