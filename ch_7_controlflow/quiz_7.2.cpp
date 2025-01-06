
//
#include <iostream>
#include <cassert>
#include <cmath>

// Program

bool isPrime(int x)
{    
    if ( x < 2) { // Rule out low numbers
        return false;
    }
    else if (x == 2) { // Two is prime
        return true;
    }
    else // Test numbers larger than two
    { 
        int n = ceil( sqrt(x) ); // Limits the search space

        for ( int i = 2; i<=n ; i++)
        {
            if ( (x%i) == 0 ) { // x has a factor other than 1 or x
                return false;
            }
        }
    }

    return true;
}

int main()
{
    //isPrime(26);
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417)); 

    std::cout << "Success!\n";

    return 0;
}