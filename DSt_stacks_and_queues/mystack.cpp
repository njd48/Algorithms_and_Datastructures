
#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>

#define STACKSIZE 12

template <class T>
class Stack {

private:
    int top;
    T *nodes;

public: 
    Stack();
    bool isEmpty (void);
    bool isFull (void);
    void push( T  );
    T pop( int & );   // <- pop and test
    T pop(void);

    ~Stack();

    void display();
};

// --- Fnc Templates -------------------------------
//

// Constructor
template <class T> 
Stack<T>::Stack()
{
    top = -1;
    nodes = new T[STACKSIZE];
}

// Destructor
template <class T> 
Stack<T>::~Stack()
{
    delete nodes;
}

// Methods

template <class T> 
bool Stack<T>::isEmpty()
{ 
    return ( top < 0 );
}

template <class T> 
bool Stack<T>::isFull()
{ 
    return ( top == STACKSIZE );
}

template <class T> 
void Stack<T>::push( T val )
{ 
    if (isFull()) {
        std::cout << "Stack Overflow! element was not pushed.\n";
        return;
    } else {
        top++;
        nodes[top] = val;
    }    
}

template <class T> 
T Stack<T>::pop( void )
{
    T p;

    if (isEmpty()) {
        std::cout << "Stack Underflow.\n";
        return p;

    } else {
        p = nodes[top];
        top--;
        return p;
    }
}

template <class T> 
T Stack<T>::pop( int &undy ) // pop and test
{
    T p;

    if (isEmpty()) {
        undy = 1;
        return p;

    } else {
        undy = 0;
        p = nodes[top];
        top--;
        return p;
    }
}


// Display whole stack for debung purposes
template <class T> 
void Stack<T>::display( void ) 
{
    
    //std::cout << typeid(nodes[top]).name() <<'\n';
    if (isEmpty()) {

        std::cout << "top:   " << top << ",  ";
        std::cout << "stack: [ empty ]\n";

    } else {

        std::cout << "top:   " << top << ",  ";

        std::cout << "stack: [ ";
        for (int i = 0; i<top ; i++ ) {
            std::cout << nodes[i] << ", ";
        }
        std::cout << nodes[top] << " ]\n";

    }
}


#endif