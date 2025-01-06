
//

#include <iostream>
#include <typeinfo>
#include <string>

using length = int; // type alias

struct Fraction // this tutorial uses a convention
{               // where program-defied types start with capital 
    int num{};  // letters and dont use a suffix
    int denom{};
};

int main()
{
    length a = 5;

    std::cout << "a = " << a << '\n'; //<< ", b = " << b << '\n';

    Fraction fraction{ 3,4 }; // capitalizing convention here

    std::cout << "frac = " << fraction.num << '/' << fraction.denom << '\n';

    return 0;
}