

#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>



template <class T>
class BinTree { 

    protected: 
        struct node {
            T key;
            struct node *left;
            struct node *right;
            struct node *parent;

            void walk(  ){
                if ( left != nullptr ) {
                    left->walk();
                }
                std::cout << key << ' ';
            
                if ( right != nullptr ) {
                    right->walk();
                }
                //std::cout << "here3\n";
            };
            void killChildren() {
                if ( left != nullptr ) {
                    left->killChildren();
                    delete left;
                }            
                if ( right != nullptr ) {
                    right->killChildren();
                    delete right;
                }
            }
        };
        typedef struct node *NODEPTR;
        NODEPTR root;  // Points to first node

    public:
        int size;

        BinTree();
        bool isEmpty();
        ~BinTree();

        
        void insert( T val );
        void* search( T val );
        //void* successor( T val );
        //void remove( T val );

        
        /*
        minimum();
        maximum();

        
        predecessor();
        
        search( T val );        
        */

        
        // void display();
        void list();
};


template <class T>
BinTree<T>::BinTree() {
    size = 0;
    root = nullptr;
}

template <class T>
bool BinTree<T>::isEmpty() {
    if (root == nullptr) {return true; } else { return false; }
}

template <class T>
BinTree<T>::~BinTree() {

    if (!isEmpty()) {
        
        root->killChildren();
        delete root;
    }
}

template <class T>
void BinTree<T>::insert( T val ) {

    if ( isEmpty() ) {
        root = new node;
        
        root->key = val;
        root->left = nullptr;
        root->right = nullptr;
        size++;
        return;
    } //--------

    NODEPTR p = root;
    NODEPTR q;
    bool found = false;
    bool L;

    while (!found) {

        if ( val == p->key ) {
            //std::cout << "warning: value, " << val << " is already in the tree. Nothing happened.\n";
            return;
        } 

        if ( val < p->key ){
            if (p->left == nullptr) {

                found = true;
                q = new node;
                q->left  = nullptr;
                q->right  = nullptr;

                p->left = q;

            } else if ( val > (p->left)->key ) {

                found = true;
                q = new node;
                q->left  = p->left;
                q->right = nullptr;

                p->left = q;
                
            } else {
                p = p->left;
            }        

        } else {
            if (p->right == nullptr) {
                found = true;
                q = new node;
                q->left  = nullptr;
                q->right = nullptr;

                p->right = q;
                
            } else if ( val < (p->right)->key ) {
                found = true;
                q = new node;
                q->right = p->right;
                q->left  = nullptr;

                p->right = q;
            } else {
                p = p->right;
            }
        }
    }
    
    q->key = val;

    size++;
}

template <class T>
void* BinTree<T>::search( T val ) {

    if (isEmpty()) {
        return nullptr;
    }

    NODEPTR p = root;

    while (p!=nullptr) {
        if ( val == p->key ){
            return p;
        } else if (val < p->key ){
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return p;
}

/*
template <class T>
void* BinTree<T>::successor( T val ) {

    NODEPTR p = search( val );
    NODEPTR q = p->right;

    if ( q == nullptr ) {
        //Successor must be parent
        std::cout << "error: successor must be parent, or does not exist in graph.\n";
        return p;
    }

    while ( q!=nullptr ) {
        if ( q->left != nullptr ) {
            q = q->left;
        } else {
            return q;
        }
    }

    

}

template <class T>
void BinTree<T>::remove( T val ) { //incomplete

    NODEPTR p = search( T val );

    if (p==nullptr) {
        std::cout << "warning: value, " << val << " not found. nothing happened.\n";
    }

    // Cases 
    bool noChildren = (p->left == nullptr && p->right == nullptr);
    bool oneChild  ;

}

*/

template <class T>
void BinTree<T>::list( ) { 
    
    if (isEmpty()) {
        std::cout << "list: [ ]\n"; 
    } else { 
        std::cout << "list: [ ";
        
        root->walk();

        std::cout <<  " ]\n";
    }

}





#endif