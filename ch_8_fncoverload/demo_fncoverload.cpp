
//
#include <iostream>
#include <cassert>
#include <cmath>

// Program

int add(int x, int y) // integer version
{
    std::cout << "1:intint"<< '\n';
    return x + y;
}

double add(double x, double y) // floating point version
{
    std::cout << "2:doubdoub"<< '\n';
    return x + y;
}

int add(int x, int y, int z) // integer version with three args
{
    std::cout << "3:intintint"<< '\n';
    return x + y + z;
}

int main()
{

    std::cout << add( 2, 2 ) << '\n';
    std::cout << add( 3.2, 3.2) << '\n';
    std::cout << add( 1, 4, 2) << '\n';
    return 0;
}