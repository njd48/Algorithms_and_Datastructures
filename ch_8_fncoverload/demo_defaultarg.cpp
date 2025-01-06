
//
#include <iostream>
#include <cassert>
#include <cmath>

// Program

/*
int add(int x, int y) // integer version
{
    std::cout << "1:intint"<< '\n';
    return x + y;
}
*/

void print(  int x, int y = 10 )
{
    std::cout << "Result: " << x << ", " << y <<'\n';
}

int rollDie( int sides = 6 )
{
    srand(time(NULL));
    return (rand() % sides) + 1;
}


int main()
{

    print(3);
    print(2,4);

    std::cout << "roll die: result: " << rollDie() << '\n'; 

    return 0;
}