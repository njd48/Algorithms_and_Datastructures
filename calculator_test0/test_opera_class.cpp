#include <iostream>
#include <string>
#include "opera.cpp"
#include "utils.cpp"


int main() {

    
    Opera* operaChain = new Opera( 4., plus );
    std::cout << "init success.\n";

    operaChain->append( 4., plus );
    std::cout << "append success.\n";

    operaChain->append( 5., minus );
    std::cout << "append success.\n";

    operaChain->append( 2., nothing );
    std::cout << "append success.\n";

    std::cout << "present state of chain: \n";
    renderOperaChain( operaChain );

    std::cout << "try resolving this expression left to right: \n";
    while ( operaChain->next() != nullptr ) {
        operaChain->resolve();
        renderOperaChain( operaChain );
    }
    
    delete operaChain;
}