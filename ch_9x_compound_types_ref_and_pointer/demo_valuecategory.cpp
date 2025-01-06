
//

#include <iostream>

void setInitialCondition( int x )
{
    std::cout << "Smaller: " << x << '\n';
}
int return5()
{
    return 5;
}

int main()
{

    {
    int x { 5 }; // 5 is an rvalue since it is a literal?
    int y { x }; // x is a modifiable lvalue expression

    const double d{1.2}; // 1.2 is rvalue (literal)
    int z { return5() };  // return5() is rvalue expression (since the result is returned by value)
    int w {x+1};  // x+1 is also rvalue, 
    // These rvalue expressions produce a temporary value
    // that is not an identifyable object

    x = y;  // lvalue y will implicitly convert to rvalue
    std::cout << x << y << d << z << w <<'\n';
    } // destroy above vars


/*
    int smaller{}, larger{};

    std::cout << "Input an integer:";
    std::cin >> smaller;

    std::cout << "Input a larger integer:";
    std::cin >> larger;
*/
    return 0;
}