

#include <iostream>
#include <string>
#include <vector>
//#include 

/* 
void printv( std::vector* x ) {
 // not working yet
int N = x.size();

    std::cout << "{ ";
    for ( int i = 0; i < N ; i++ ) {        
        std::cout << x[i] << ", ";        
    }
    std::cout << "}\n";

}
*/


int main() {

    //-------------------
    // str containers

    std::string name = "Alex"; 
    std::cout << name  << '\n';

    int N = name.length();
    std::cout << "has length: " << N << '\n';

    //-------------------
    // vectors
    std::cout << "examine std::vectors \n";

    std::vector<int> empty{};
    
    std::vector<int> primes{ 2, 3, 5, 7, 11 };

    std::vector vowels { 'a', 'e', 'i', 'o', 'u' };  
    //automatically dedeuce str type?

    std::vector disease_names{ "chlamidia", "herpes", "AIDS" };

    // Array entry accesses
    std::cout << primes[0] << ' ' << primes[1] << '\n';

    for ( int i = 0 ; i < disease_names.size() ; i++ ){
        std::cout << disease_names[i] << ", ";
    }
    std::cout << '\n';

    // Predefined length
    std::vector<int> data(10);

    for ( int j = 0; j<10 ; j++){
        data[j] = 2*j;
        std::cout << data[j] << ", ";
    }
    std::cout << '\n';

    


    //-------------------
    // 
    return 0;

}