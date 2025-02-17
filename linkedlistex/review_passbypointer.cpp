#include <iostream>
#include <string>

void printByValue(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const std::string& ref) // The function parameter is a reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
}

void printByAddress(const std::string* ptr) // The function parameter is a pointer that holds the address of str
{
    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

void passByAddress( int* x ) {

    // can also use assert(x); to break the program in case of nullptr.

    if (x) { // Protection against a nullpointer
        (*x)++;// Value of parameter is modified
        std::cout << *x << '\n';
    } else {
        std::cout << "you got a nullptr.\n";
    }
    
}

void printIDNumber(const int *id=nullptr) // Default input with nullptr
{
    if (id)
        std::cout << "Your ID number is " << *id << ".\n";
    else
        std::cout << "Your ID number is not known.\n";
}


void nullify_ptr(int* ptr) // variable here is actually a copy of the input ptr
{
    ptr = nullptr; // Make the function parameter a null pointer, doesnt change it in the global scope.
}

// Nullify a pointer by editing it in a funciton when it is passed by reference
void nullify_byref(int*& refptr) // refptr is now a reference to a pointer
{
    refptr = nullptr; // Make the function parameter a null pointer
}

int main()
{
    std::string str{ "Hello, world!" };
    
    // &var is the address of var. & is the address operator 
    // & ref is a function parameter which is a reference to the input variable


    printByValue(str); // pass str by value, makes a copy of str
    printByReference(str); // pass str by reference, does not make a copy of str
    printByAddress(&str); // pass str by address, does not make a copy of str

    //----------------------------------------------
    // Define a pointer ahead of time, pass to fnc
    //
    std::string* ptr{ &str };
    printByAddress( ptr );

    //----------------------------------------------
    // Pass by address, value gets modified
    //
    int x = 1;
    passByAddress( &x );
    passByAddress( &x );
    passByAddress( nullptr );

    //----------------------------------------------
    // Pass with a nullptr option
    //
    int user = 143;
    printIDNumber( &user );
    printIDNumber(); //<-- defaults to nullpter in absence of input

    //----------------------------------------------
    // Nulifying?
    //
    int* p{ &user };

    std::cout << "1: " << *p << '\n';
    nullify_ptr( p );
    std::cout << "2: " << *p << '\n';
    nullify_byref( p );
    std::cout << "3: " << *p << '\n';


    return 0;
}