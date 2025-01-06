#include <iostream>

int main()
{
 
    std::cout << "\n---------------------------------------\n" ;
        "I have had difficulty with these chars. \n";

    std::cout << "size of char:\t" << sizeof(char) << " bytes\n";
    std::cout << "size of char16_t:\t" << sizeof(char16_t) << " bytes\n";
    std::cout << "size of char32_t:\t" << sizeof(char32_t) << " bytes\n";

    std::cout << "\n---------------------------------------\n" 
        "character literals and unicode\n";

    char var1{ 'a' };
    char var2{ 97 };
    std::cout << " var1 = " << var1 << '\n';
    std::cout << " var2 = " << var2 << '\n';
/*
    std::cout << "\n---------------------------------------\n" 
        "Comparisons\n";

    int x{3},y{4};
    std::cout << "isEqual("<< x <<","<< y <<") = " << (x==y) <<'\n';
 */

    return 0;
}