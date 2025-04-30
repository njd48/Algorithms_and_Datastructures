

#include <iostream>

#include "basic_hash_table.cpp"

int main () {

    HashTable myHT;

    myHT.insert( 3 );
    myHT.insert( 5 );
    myHT.insert( 8 );
    myHT.insert( 9 );
    myHT.display();
    std::cout << '\n';

    std::cout << "Protect against duplicate elements:\n";
    myHT.insert( 3 );
    
    std::cout << '\n';
    std::cout << "Search for elements:\n" ;
    std::cout << "is  4 in the table?: " << myHT.search( 4 ) << '\n';
    std::cout << "is  8 in the table?: " << myHT.search( 8 ) << '\n';
    std::cout << "is 10 in the table?: " << myHT.search( 10 ) << '\n';

    std::cout << '\n';
    std::cout << "Delete elements 5 and 9 and 10  :\n" ;
    myHT.remove(  5 );
    myHT.remove(  9 );
    myHT.remove( 10 );

    myHT.display();

    std::cout << '\n';
    std::cout << "Empty the table  :\n" ;
    myHT.remove(  3 );
    myHT.remove(  8 );

    myHT.display();

    std::cout << '\n';
    std::cout << "Random table, obtain vital statistics  :\n" ;

    for (  int i = 0 ; i < 16 ; i ++ ) {
        int x = rand()%N_KEYS;
        myHT.insert(x);
    }
    myHT.display();

    std::cout << "num stored elements: " << myHT.numel() << '\n';
    std::cout << "max in table:        " << myHT.max() << '\n';
    std::cout << "min in table:        " << myHT.min() << '\n';

    std::cout << "remove the minimum and try that again.\n";
    myHT.remove( myHT.min() );
    std::cout << "min in table: " << myHT.min() << '\n';


    // does it start with nullptrs
    //std::cout << myHT.atslot(0) <<'\n';

    return 0;
}