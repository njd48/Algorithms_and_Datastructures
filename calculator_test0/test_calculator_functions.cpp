

#include <iostream>
#include <vector>
#include "utils.cpp"
#include "calculator.cpp"


int main() {

   
int N = 22;

    int n_tests = 12;

    std::vector<Opera*>   chainHead( n_tests );
    
    for ( int i = 0 ; i < n_tests ; i++ ) {

        // Construct System
        // 
        chainHead[i] = randomOperaChain( N );

        renderOperaChain(chainHead[i]);        

        fullResolve( chainHead[i] );

        renderOperaChain( chainHead[i] );

        delete chainHead[i];
        std::cout << std::endl;
    }

}