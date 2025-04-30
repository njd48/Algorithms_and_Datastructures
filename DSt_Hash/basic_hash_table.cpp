
#ifndef HASHTABLE_H
#define HASHTABLE_H

#define M_HASH 12 // table entries
#define N_KEYS 200 // admissible key values

#include "mydoublelinklist.cpp"
#include "eratosthanes.cpp"

#define List DList<int>

namespace hashfnc {

    int hash( int );


    // unique hash with no collision
    #if M_HASH == N_KEYS
        int hash( int key ) {
            return key;
        }
    #endif

    // hash with at most two admissible keys per slot
    #if fasle// M_HASH == N_KEYS/2
        int hash( int key ) {
            return key/2;
        }
    #endif

    // Universal hash
    #if true
       

        int hash( int key ) {
            //static const int s_p = 7;
            static const int s_p = eratosthanes::sieveNext( N_KEYS );
            static const int s_a = 12;
            static const int s_b = 5;

            return ( ( s_a*key + s_b) % s_p ) % M_HASH;
        }
    #endif

};

using namespace hashfnc;

class HashTable {

    private:
        int N;
        List** slots;

    public:
        
        // --- Constr destr ------------------
        HashTable();
        ~HashTable();

        // --- Standard operations -----------
        List* slotHead( int i );
        void insert( int key );
        bool search( int key );
        void remove( int key );

        // --- Vital Stats -----------
        int numel();
        int max( );
        int min( );

        // --- Auxilliary and Diagnostics -----
        void display( );

};

//-------------------------------------------------------------------------
// Constructor and Destruct
//-------------------------------------------------------------------------

HashTable::HashTable() {
    N     = 0;
    slots = new List*[M_HASH]; 
}
HashTable::~HashTable() {

    
    for ( int h = 0; h < M_HASH ; h++ ) {
        if (slots[h] != nullptr ) delete slots[h];
    }
    
    delete slots;
}

//-------------------------------------------------------------------------
// Standard Operations
//-------------------------------------------------------------------------

List* HashTable::slotHead( int i ) {
    return (slots[i]);
}

void HashTable::insert( int key ) {

    if ( key < 0 || key >= N_KEYS ) {
        std::cout << "error: key, " << key << " is not admissible. Nothing happened.\n";
        return;
    }

    int h = hash(key);

    if ( slots[h] == nullptr ) {
        slots[h] = new List;
        slots[h]->push(key);

    } else {
        if ( slots[h]->contains(key)) {
            std::cout << "warning: key, " << key << ", is already contained here.\n";
            return;
        } else {
            slots[h]->push( key );
        }
    }    
    N++;
}
bool HashTable::search( int key ) {

    int h = hash(key);

    if ( slots[h] == nullptr ) {
        return false;

    } else {
        if ( slots[h]->contains(key)) {
            return true;
        } else {
            return false;
        }
    }    
}
void HashTable::remove( int key ) {

    int h = hash(key);

    if ( slots[h] == nullptr ) {
        std::cout<< "warning: key, " << key << ", is not in the table, nothing happened.\n"; 
        return;
    }


    slots[h]->remove( key );
    N--;


    if ( slots[h]->isEmpty() ) {
        delete slots[h];
        slots[h] = nullptr;
    }
}

//-------------------------------------------------------------------------
// Vital Stats
//-------------------------------------------------------------------------
int HashTable::numel() {
    return N;
}
int HashTable::max(){
    if(N==0) {return MININT;}
    for ( int h = M_HASH-1 ; h >=0 ; h-- ) {

        if ( slots[h] != nullptr ) {
            return slots[h]->max();
        }
    }
}
int HashTable::min(){

    if(N==0) {return MAXINT;}
    for ( int h = 0 ; h < M_HASH ; h++ ) {

        if ( slots[h] != nullptr ) {
            return slots[h]->min();
        }
    }
}




//-------------------------------------------------------------------------
// Diagnostic
//-------------------------------------------------------------------------

void HashTable::display() {

    //std::cout << "hash table with (key,vals)\n";
    std::cout << "Slot | Contents\n";
    for (  int h = 0 ; h < M_HASH ; h++ ) {

        printf("%04d | ", h);

        if ( slots[h] != nullptr ) {
            slots[h]->display();
        } 

        printf(" \n");
    }
}


#endif