
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


    // int& invalidRef; //will throw an error
    // cannot bind to a non-modifyable lvalue or a rvalue
    // nor to a lvalue of different type
    // nor changed to reference another object
    int x {5};    // integer variable
    int& ref {x}; // lvalue reference, alias for x


    std::cout << "initial x, and ref:\n";
    std::cout << x << ", " << ref << '\n'; //prints x via ref

    x = 6;

    std::cout << "modify x:\n";
    std::cout << x << ", " << ref << '\n'; //prints x via ref

    ref = 7;

    std::cout << "modify ref:\n";
    std::cout << x << ", " << ref << '\n'; //prints x via ref

    // can destroy refs before var
    {
        int& ref2 = ref; // 
        // references cant reference references,
        // thus, ref2 is bound to x by this operation
        ref2++;
        std::cout << "modify ref2:\n";
        std::cout << x << ", " << ref2 << '\n'; //prints x via ref
    } // ref2 destroyed here

    std::cout << x << '\n';

    return 0;
}