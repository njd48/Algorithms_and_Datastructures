

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
//#include 



int main() {

    std::cout <<"Begin vector quiz:... \n";

    // ---(1)---------------------------------------------------------
    // Define a std::vector using CTAD and initialize it with the 
    // first 5 positive square numbers (1, 4, 9, 16, and 25).
    //
    int N = 5;
    std::vector<int> v1(N);

    std::cout << "{ ";
    int n{};
    for (int i = 0; i<N; i++){
        n = i+1;
        v1[i] = pow( (n), 2 );
        std::cout << "( " << n <<": "<< v1[i] << "),, ";
    }
    std::cout << "}\n";

    // ---(3)---------------------------------------------------------
    // Define a std::vector (using an explicit template type 
    // argument) to hold the high temperature (to the nearest 
    // tenth of a degree) for each day of a year (assume 365 
    // days in a year).
    std::vector<double> T_high(365);  // I guess the high temp is 0 every day

    // ---(4)---------------------------------------------------------
    // Using a std::vector, write a program that asks the user to 
    // enter 3 integral values. Print the sum and product of those 
    // values.
    // The output should match the following:
    //   Enter 3 integers: 3 4 5
    //   The sum is: 12
    //   The product is: 60
    int n_inputs = 3;
    std::vector<int> inputs(n_inputs);

    int sum  = 0;
    int prod = 1;

    std::cout << "enter 3 integers: \n";
    for (int i=0 ; i < n_inputs ; i++ ) {
        std::cin >> inputs[i];
        sum  = sum  + inputs[i];
        prod = prod * inputs[i];
    }
    std::cout << "Sum is:  " << sum  << '\n';
    std::cout << "Prod is: " << prod << '\n';

    //-------------------
    // 
    return 0;

}