
#ifndef MYDLL_H
#define MYDLL_H

#include <iostream>



template <class T>
class DList { 

    protected: 
        struct node {
            T key;
            struct node *next;
            struct node *prev;
        };
        typedef struct node *NODEPTR;
        NODEPTR head;  // Points to first node
        NODEPTR tail;  // Points to last node

    public:
        DList();
        ~DList();

        bool isEmpty();
        void push( T nu );
        T pop();

        void insertAfter( T a, T b ) ;
        
        int search( T val );        
        void remove( T val );

        void displayForward();
        void displayBackward();

};

template <class T>
DList<T>::DList() {
    head = nullptr;
    tail = nullptr;
}

template <class T>
DList<T>::~DList() {

    NODEPTR p, q;

    if ( isEmpty() ) {
        return;
    }

    p = head; 
    while ( p != nullptr ) {
        q = p->next;
        delete p;
        p = q;
    }
}

template <class T>
bool DList<T>::isEmpty() {
    if (head == nullptr) { 
        return true ;
    } else { 
        return false ;
    }
}

template <class T>
void DList<T>::push( T nu ) { // Appends to front of list

    //std::cout << "here inside \n";

    NODEPTR p; 

    p = new node;

    p->key = nu;
    p->next = head;
    p->prev = nullptr;    

    if (head != nullptr) {
        head->prev = p;
    }
    if (tail == nullptr) {
        tail = p;
    }

    head = p;

    //std::cout << head << '\n';
    //std::cout << p->next << '\n';
    //std::cout << p->key << '\n';

    //std::cout << "here end inside \n";

}

template <class T>
T DList<T>::pop( ) { // remove node from front of list

    NODEPTR p;
    T returnval;

    if (isEmpty()){
        std::cout << "Error, list is empty.\n";
        return returnval;
    }

    p          = head;
    returnval  = p->key;
    head       = p->next;
    head->prev = nullptr;
    delete p;    
    return returnval;

}

template <class T> 
int DList<T>::search( T val ) {

    NODEPTR p = head;
    int i = 0;

    while ( p != nullptr ){
        if (p->key == val ){
            return i;
        } else {
            p = p->next;
            i++;
        }
    }

    return i;
    std::cout << "Error: value, " << val << ", was not found.";
} 

template <class T> 
void DList<T>::remove( T val ) {

    NODEPTR p = head;

    while ( p != nullptr ){
        if (p->key == val ){
            //----------------------------
            if (p->next != nullptr) {
                (p->next)->prev = p->prev;
            }
            if (p->prev != nullptr) {
                (p->prev)->next = p->next;
            }            

            delete p;            
            return;
            //----------------------------
        } else {
            p = p->next;
        }
    }
    
    std::cout << "warning: value, " << val << ", was not found. Nothing happened.";
} 

template <class T>
void DList<T>::insertAfter( T old, T nu ) { // insert nu after old

    NODEPTR p, q, r;

    p = head;
    while ( p != nullptr ) {
        if ( p->key == old ) {

            q = new node;
            q->key = nu;
            q->next = p->next;
            q->prev = p;
            p->next = q;

            if (q->next != nullptr) {
                (q->next)->prev = q;
            }

            return;

        } else {
            p = p->next;
        }        
    }

    std::cout << "error: value, " << old << " was not found in list. Item was not inserted.\n";

}


template <class T>
void DList<T>::displayForward( ) {

    if (isEmpty()) {
        std::cout << "list: H[ ]T\n"; 
    } else { 
        NODEPTR p;

        std::cout << "list: H[ ";
        p = head;
        while ( p != nullptr ) {
            std::cout << (p->key) << ", ";
            p = p->next;
        }
        std::cout <<  " ]T\n";
    }
    
}

template <class T>
void DList<T>::displayBackward( ) {

    if (isEmpty()) {
        std::cout << "list: T[ ]H\n"; 
    } else { 
        NODEPTR p;

        std::cout << "list: T[ ";
        p = tail;
        while ( p != nullptr ) {
            std::cout << (p->key) << ", ";
            p = p->prev;
        }
        std::cout <<  " ]H\n";
    }
    
}


#endif