#include <iostream>

int main()
{
 
    // Demonstrates queued inputs when
    // cin recieves more than len 1 string
    char x{};

    std::cout << "Enter characters ... ";

    std::cin >> x;  // <-- takes first element of string
    std::cout << "result: " << x << '\n';

    std::cin >> x;  // <-- takes input from queue (2nd element of str)
    std::cout << "result: " << x << '\n';


    return 0;
}