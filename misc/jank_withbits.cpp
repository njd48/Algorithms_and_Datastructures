
#include <iostream>
#include <vector>
#include <cmath>

#define NBITS  32

int main() {

    int n = 4;

    std::cout << "input: " << n << '\n';

    std::vector<bool> gas (NBITS);

    // k-th bit of n
    for ( int k = 0; k < NBITS ; k++ ){
       gas[k] =  (n & ( 1 << k )) >> k;
    }

    // Have to display backward
    for ( int k = NBITS-1 ; k >= 0 ; k-- ){
        std::cout << gas[k] << ' ';
    }
    std::cout << '\n';

    // can I add it back up?
    int n_reconstr = 0;

    for ( int k = 0 ; k < NBITS ; k++ ){        
        if ( gas[k] ) {
            n_reconstr += pow( 2, k );
        }
     }
     std::cout << "reconstructed: " << n_reconstr << '\n';
    

    


    return 0;
}