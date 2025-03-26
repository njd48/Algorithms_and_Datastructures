

#include <iostream>
#include <string_view>

class Date
{
public: // <--- Access specifier
    int year{};
    int month{};
    int day{};
    
    
    
    void print(  ) const { // <--- member function, use constref
        std::cout <<  month  <<  '/'  <<  day  <<  '/'  <<  year << '\n';
    } 
};

/*
struct Person
{
    std::string name{};
    int age{};

    void kisses(const Person& person) {// <-- member function with another input    
        std::cout << name << " kisses " << person.name << '\n';
    }
};
*/



int main()
{

    const Date today{ 2025, 03, 25 };

    today.print();  // now this works by (const& today)

    return 0;
}

