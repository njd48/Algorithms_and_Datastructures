

#include <iostream>

#include "mylinklist.cpp"



int main() {

    // Initialize 
    List<int> myList;

    // Checking fncs?
    std::cout << "is empty: " << myList.isEmpty() << '\n';

    myList.display();

    // Add and remove elements
    myList.push( 3 );
    myList.push( 5 );
    myList.push( 7 );
    myList.display();

    std::cout << "is empty: " << myList.isEmpty() << '\n';

    std::cout << "pop this one: " << myList.pop() << " (behaves like stack)"<<'\n';

    myList.display();

    std::cout << "Try inserting a few elements after 3...\n";

    myList.insertAfter(  3, 88 );
    myList.display();

    myList.insertAfter(  3, 6 );
    myList.display();

    myList.insertAfter(  3, 8 );
    myList.display();


   // return 0;
}