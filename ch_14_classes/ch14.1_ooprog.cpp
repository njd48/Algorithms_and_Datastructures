

#include <iostream>
#include <string_view>

struct Cat
{
    std::string_view name{ "cat" };
    int numLegs{ 4 };
};

struct Dog
{
    std::string_view name{ "dog" };
    int numLegs{ 4 };
};

struct Chicken
{
    std::string_view name{ "chicken" };
    int numLegs{ 2 };
};

struct Snake
{
    std::string_view name{ "snek" };
    int numLegs{ 0 };
};

int main()
{
    constexpr Cat animal;
    std::cout << "a " << animal.name << " has " << animal.numLegs << " legs\n";


// Quiz (Q.1) update to have a struct for a snake

    constexpr Snake animal2;
    std::cout << "a " << animal2.name << " has " << animal2.numLegs << " legs\n";

    return 0;
}

