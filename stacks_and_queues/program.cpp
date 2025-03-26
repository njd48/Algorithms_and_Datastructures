


#include <iostream>

#include "mystack.cpp"
#include "myqueue.cpp"


int main() {

    //----------------------------------------------------------------------
    // Test basic operations on stack
    //----------------------------------------------------------------------

    // create the stack
    Stack<double> mystack;

    mystack.display(); // display contents of an empty stack

    double mydub = 5.014;

    // Push operations
    mystack.push( 3.14 );
    mystack.push( mydub );
    mystack.push( 7.132 );

    mystack.display();

    // pop operations
    std::cout << "Pop this one: " ;
    std::cout << mystack.pop()    << '\n';

    mystack.display();

    // pop and test?
    int und = 0;

    while (und==0) {
        mystack.pop(und);
        std::cout << und << '\n';
    }
    mystack.display();

    // Demonstrate overflow
    for (int i = 0 ; i < STACKSIZE+2 ; i++ )
    {
        mystack.push( (double)i + (double)(rand()%100)/100.0 );
    }
    mystack.display();

    std::cout << "====================================================================\n";

    //========================================================================

    //----------------------------------------------------------------------
    // Test basic operations on queue
    //----------------------------------------------------------------------

    Queue<int> myqueue;

    myqueue.display();

    // enqueue
    
    myqueue.enqueue( 3 );
    myqueue.enqueue( 7 );
    myqueue.enqueue( 9 );

    myqueue.display();

    // dequeue
    std::cout << "dequeue this one: " ;
    std::cout << myqueue.dequeue()    << '\n';

    myqueue.display();

    // detect overflow
    int i = 0;
    do {
        i++;
        myqueue.enqueue( i );
    } while( !myqueue.isFull() ) ;

    myqueue.display();

    myqueue.enqueue( 13 );

    myqueue.display();

    // detect underflows
    int undy = 0;
    int p    = 0;

    while (undy==0) {
        p = myqueue.dequeue( undy );
        std::cout << "undeflow = " << undy << ",  return val = " << p << '\n';
    }

    myqueue.display();

}
