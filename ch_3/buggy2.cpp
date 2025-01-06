#include <iostream>

#include <iostream>

int main()
{
    int x;
    std::cout << x << '\n'; // Use of uninitialized variable leads to undefined result

    return 0;
}

// seems like my compiler is protecting me by initializing to zero