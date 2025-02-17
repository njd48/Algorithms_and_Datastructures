

#include <iostream>
#include <string_view>

class Date
{
public: // <--- Access specifier
    int day{};
    int month{};
    int year{};
    
    void print( ){ // <--- member function
        std::cout << day << '/' << month << '/' << year << '\n';
    } 
};

struct Person
{
    std::string name{};
    int age{};

    void kisses(const Person& person) {// <-- member function with another input    
        std::cout << name << " kisses " << person.name << '\n';
    }
};




int main()
{

    Date today{ 3, 2, 2025 };

    today.day = 4;

    today.print(); // today is an 'implicit object' with respect to this function call


    // memberfnc with another input 
    Person joe{ "Joe", 29 };
    Person kate{"Kate", 27};

    joe.kisses(kate);

    return 0;
}

