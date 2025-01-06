
// 

#include <iostream>
#include <typeinfo>
#include <string>

// Define struct
struct Employee
{
    int id {};
    int age {};
    double wage {};
};

struct Something
{
    int x{};
    int y{};     // value initialization by default
    int z{ 2 };  // defaults to 2
};

void printEmployee(const Employee& employee)
{
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

// example of return by struct
Something getZeroCoordinate()
{
    // already specified the type in the function declaration
   return { 0,0,0 };  // creates temp var and passes back to the caller
}

// ////////////////////////////////////////
// Main
int main()
{
    // ------------------------------------------------
    Employee joe;
        joe.id   = 14;
        joe.age  = 32;
        joe.wage = 60000.0;
    Employee frank;
        frank.id   = 15;
        frank.age  = 28;
        frank.wage = 45000.0;

    if (frank.wage < joe.wage){
        std::cout << "joe makes more than frank\n";
    } else {
        std::cout << "joe makes less than frank\n";
    }

    // Frank got a promotion
    frank.wage += 5000.0;

    // It is joe's birthday
    joe.age++;

    // -----------------------------------------------
    // Aggregate initialization of struct members
    Employee robert = { 1, 34, 65000.0 }; // copy-list initialization
    //Employee tuco ( 3, 45, 62500.0 );   // direct initialization
    // ^^^ doesnt seem to work, needs (C++20)
    Employee daniel { 2, 25, 45000.0};    // list initialization

    // Default member initialization 
    Something var1; // initialization is already carried out in struct
    Something var2{3,3,3}; // initialization overrides default values

    std::cout <<"var1 (default): "<< var1.x << ", " << var1.y <<", "<< var1.z << '\n'; 
    std::cout <<"var2          : "<< var2.x << ", " << var2.y <<", "<< var2.z << '\n'; 

    // Passing by struct
    printEmployee( robert );

    // Return by struct
    Something m = getZeroCoordinate();

    std::cout << "Size of struct something: " << sizeof(m) << '\n';
    std::cout << "Size of struct employee:  " << sizeof(robert) << '\n';

    return 0;
}