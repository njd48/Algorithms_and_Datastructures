

#include <iostream>

#include "mydoublelinklist.cpp"



int main() {

    // Initialize 
    DList<int> myList;

    // Checking fncs?
    std::cout << "is empty: " << myList.isEmpty() << '\n';

    myList.displayForward();
    myList.displayBackward();

    // Add and remove elements
    std::cout << "push elements...\n";
    myList.push( 3 );
    myList.push( 5 );
    myList.push( 7 );
    
    myList.displayForward();
    myList.displayBackward();

    std::cout << "is empty: " << myList.isEmpty() << '\n';
    
    std::cout << "pop this one: " << myList.pop() << " (behaves like stack)"<<'\n';

    myList.displayForward();


    
    std::cout << "Try inserting a few elements after 3...\n";

    myList.insertAfter(  3, 88 );
    myList.displayForward();

    myList.insertAfter(  3, 6 );
    myList.displayForward();

    myList.insertAfter(  3, 8 );
    myList.displayForward();

    std::cout << "Search for element 8 and 6...\n";
    std::cout << 8 << " found at position " << myList.search(8) << '\n'; 
    std::cout << 6 << " found at position " << myList.search(6) << '\n'; 

    std::cout << "Search and delete element 8 ...\n";
    myList.remove(  8 );
    myList.displayForward();
    /*
    */

   return 0;
}