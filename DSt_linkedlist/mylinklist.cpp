
#ifndef MYLL_H
#define MYLL_H

#include <iostream>



template <class T>
class List { 

    protected: 
        struct node {
            T info;
            struct node *next;
        };
        typedef struct node *NODEPTR;
        NODEPTR listptr;  // Points to first node

    public:
        List();
        ~List();

        bool isEmpty();
        void push( T nu );
        T pop();

        void insertAfter( T a, T b ) ;

        void display();

};

template <class T>
List<T>::List() {
    listptr = nullptr;
}

template <class T>
List<T>::~List() {

    NODEPTR p, q;

    if ( isEmpty() ) {
        return;
    }

    p = listptr; 
    while ( p != nullptr ) {
        q = p->next;
        delete p;
        p = q;
    }
}

template <class T>
bool List<T>::isEmpty() {
    if (listptr == nullptr) { 
        return true ;
    } else { 
        return false ;
    }
}

template <class T>
void List<T>::push( T nu ) { // Appends to front of list

    //std::cout << "here inside \n";

    NODEPTR p; 

    p = new node;

    p->info = nu;
    p->next = listptr;
    listptr = p;

    //std::cout << listptr << '\n';
    //std::cout << p->next << '\n';
    //std::cout << p->info << '\n';

    //std::cout << "here end inside \n";

}

template <class T>
T List<T>::pop( ) { // remove node from front of list

    NODEPTR p;
    T returnval;

    if (isEmpty()){
        std::cout << "Error, list is empty.\n";
        return returnval;
    }

    p         = listptr;
    returnval = p->info;
    listptr   = p->next;
    delete p;    
    return returnval;

}

template <class T>
void List<T>::insertAfter( T old, T nu ) { // insert nu after old

    NODEPTR p, q;

    p = listptr;
    while ( p != nullptr ) {
        if ( p->info == old ) {

            q = new node;
            q->info = nu;
            q->next = p->next;
            p->next = q;

            return;

        } else {
            p = p->next;
        }        
    }

    std::cout << "error: value, " << old << " was not found in list. Item was not inserted.\n";

}


template <class T>
void List<T>::display( ) {

    if (isEmpty()) {
        std::cout << "list: [ ]\n"; 
    } else { 
        NODEPTR p;

        std::cout << "list: [ ";
        p = listptr;
        while ( p != nullptr ) {
            std::cout << (p->info) << ", ";
            p = p->next;
        }
        std::cout <<  " ]\n";
    }
    
}


#endif