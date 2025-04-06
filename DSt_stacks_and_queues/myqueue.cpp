
#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>

#define QUEUESIZE 12

template <class T>
class Queue {

private:
    int head;
    int tail;
    T *nodes;

public: 
    Queue();
    bool isEmpty (void);
    bool isFull (void);
    void enqueue( T  );
    T dequeue( void );
    T dequeue( int & );

    ~Queue();

    void display();
};

// --- Fnc Templates -------------------------------
//

// Constructor
template <class T> 
Queue<T>::Queue()
{
    head = QUEUESIZE-1;
    tail = QUEUESIZE-1;
    nodes = new T[QUEUESIZE];
}

// Destructor
template <class T> 
Queue<T>::~Queue()
{
    delete nodes;
}

// Methods
template <class T> 
bool Queue<T>::isEmpty()
{ 
    return ( head==tail );
}

template <class T> 
bool Queue<T>::isFull()
{ 
    if (( head == tail + 1 ) || ( head == 0 && tail == QUEUESIZE-1 )) {
        return true;
    } else {
        return false;
    }
}

template <class T> 
void Queue<T>::enqueue( T val )
{ 
    if (isFull()) {
        std::cout << "Queue Overflow! element was not enqueued.\n";
        return;
    } else {
        tail++;
        if (tail >= QUEUESIZE) {  tail = 0; }        
        nodes[tail] = val;
    }    
}

template <class T> 
T Queue<T>::dequeue( void )
{
    T p;

    if (isEmpty()) {
        std::cout << "Queue Underflow.\n";
        return p;

    } else {
        p = nodes[head];
        head++;
        if (head >= QUEUESIZE) {  head = 0; }    
        return p;
    }
}

template <class T> 
T Queue<T>::dequeue( int &undy )
{
    T p;

    if (isEmpty()) {
        undy = 1;
        return p;

    } else {
        undy = 0;
        head++;
        if (head >= QUEUESIZE) {  head = 0; }  
        p = nodes[head];          
        return p;
    }
}


// Display whole stack for debung purposes
template <class T> 
void Queue<T>::display( void ) 
{
    
    // do while tail neq head
    //std::cout << typeid(nodes[top]).name() <<'\n';
    if (isEmpty()) {

        std::cout << "head:  " << head << ",  ";
        std::cout << "tail:  " << tail << ",  ";
        std::cout << "queue: [ empty ]\n";

    } else {

        std::cout << "head:  " << head << ",  ";
        std::cout << "tail:  " << tail << ",  ";
        std::cout << "queue: [ ";

        int i = head;

        do {
            i++;
            if (i >= QUEUESIZE) { i = 0; } 
            std::cout << nodes[i] << ", ";
        } while ( i != tail );
        std::cout <<  " ]\n";

    }
}


#endif