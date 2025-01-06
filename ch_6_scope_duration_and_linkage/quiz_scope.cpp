
//

#include <iostream>

void printSmaller( int x )
{
    std::cout << "Smaller: " << x << '\n';
}
void printLarger( int x )
{
    std::cout << "Larger: " << x << '\n';
}

int main()
{

    int smaller{}, larger{};

    std::cout << "Input an integer:";
    std::cin >> smaller;

    std::cout << "Input a larger integer:";
    std::cin >> larger;

    // Sub-block
    // swap variables if user messes up

        
    if (smaller > larger)
    {
        int z{};  // z is created here

        z       = smaller;
        smaller = larger;
        larger  = z;

    } // z is destroyed here

    printSmaller(smaller);
    printLarger(larger);

    return 0;
}