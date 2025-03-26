

#include <iostream>
#include <string_view>

class Date
{
private:
    int m_year{};
    int m_month{};
    int m_day{};
    
    
public: // <--- Access specifier    
    void print(  ) const { // <--- member function, use const
        std::cout <<  m_month  <<  '/'  <<  m_day  <<  '/'  <<  m_year << '\n';
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

