#include <iostream>
#include <string>
#include <vector>
#include <cmath>
//#include 


int main() {

    std::vector prime { 2, 3, 5, 7, 11 };

    std::cout << "length: " << std::size(prime) << '\n';
    std::cout << "length: " << prime.size() << '\n';

    // No bounds checking, undefined behavior:
    std::cout << prime[5] << '\n';

    // .at() member function does runtime bounds checking
    // std::cout << prime.at(5) << '\n';

    constexpr int index{ 3 };
    std::cout << prime[index] << '\n';  // cnst implicitly converted to std::size_t

    // Quiz -----------------------------------------------------------------
    // Initialize a std::vector with the following values: ‘h’, ‘e’, 
    // ‘l’, ‘l’, ‘o’. Then print the length of the array (use std::size()). 
    // Finally, print the value of the element with index 1 using the 
    // subscript operator and the at() member function.
    //
    // The program should output the following:
    // The array has 5 elements.
    // ee

    std::vector letters { 'h', 'e', 'l', 'l', 'o' };  

    std::cout << "length: " << letters.size() << '\n';
    std::cout << "2nd :   " << letters[1] << letters.at(1) << '\n';

    return 0;
}