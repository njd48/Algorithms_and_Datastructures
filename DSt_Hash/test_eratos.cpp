

#include <iostream>
#include "eratosthanes.cpp"

int main() {

    //using namespace eratosthanes;

    int N_tests = 8;
    int n = 5;

    for (  int i = 0 ; i < N_tests ; i++ ){

        n = n + (4*n/3) + (rand()%n);

        std::cout << "first prime after "<< n << " is " << eratosthanes::sieveNext(n) << '\n';
    }

    

    return 0;
}