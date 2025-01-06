#include <iostream>


short countUpShort( short x)
{
    x = x+1;
    std::cout << "+1 gives " << x << "\n|";
    return x;
    // This function also appears to accept unsigned shorts and returns a short
}

unsigned short countUpUns( unsigned short x)
{
    x = x+1;
    std::cout << "+1 gives " << x << "\n|";
    return x;
}

//-------- Main begins here ------------------------------------------------------

int main()
{

    std::cout << "--------------------------------------------------\n";
    std::cout << "Experimenting with integer overflows. \n";

    //=============================================================

    std::cout << "Begin with \'short\' signed integers... \n|";

    short a { 32765 };

    std::cout << "Begin with \n|" << "a = " << a << "\n|";

    for ( int i = 0 ; i<= 5 ; i++ )
    {
        a = countUpShort(a);
    }

    std::cout << '\n';

    //=============================================================

    std::cout << "Now try unsigned short ints .. \n|";

    unsigned short b { 2*32766 };

    std::cout << "Begin with \n|" << "b = " << b << "\n|";

    for ( int i = 0 ; i<= 5 ; i++ )
    {
        b = countUpUns(b);
    }

    std::cout << '\n';

    //=============================================================

    return 0;
}