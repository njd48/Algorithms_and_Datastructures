#include <iostream>

int main()
{
 
    std::cout << "\n---------------------------------------\n" ;
        // "sizes of float types\n";

    std::cout << "size of bool:\t\t" << sizeof(bool) << " bytes\n";

    std::cout << "\n---------------------------------------\n" 
        "printing and negating\n";

    bool ass { true };
    std::cout << " var = " << ass << '\n';
    std::cout << "!var = " << !ass << '\n';

    std::cout << "\n---------------------------------------\n" 
        "Comparisons\n";

    int x{3},y{4};
    std::cout << "isEqual("<< x <<","<< y <<") = " << (x==y) <<'\n';


    return 0;
}