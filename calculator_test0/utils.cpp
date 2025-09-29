
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>
#include "operations.cpp"
#include "opera.cpp"
#include "parentheticalTree.cpp"

#define RANDRANGE 100

int       randDub()  { return static_cast<double>( rand()%RANDRANGE ); }
Operation randOp()   { return static_cast<Operation>( 1+rand()%4 );  }
Opera*  randomOperaChain( int N );
void renderOperaChain( Opera* );
void renderOperaChain( Opera*, Opera* );
void renderParensAndOpera( Opera*, treeNode* );


Opera* randomOperaChain( int N ) {

    int M = 1 + rand()%(int)log(N+1);

    std::vector<int> oPPos( M );
    std::vector<int> cPPos( M );


    int a,b,c;
    int m = 0;
    while ( m < M  ) {
        c = rand() % N;
        b = rand() % N;
        a = ( b+c - abs(b-c) )/2;
        b = ( b+c + abs(b-c) )/2;

        bool avail = true;
        for ( int i = 0 ; i<m ; i++ ) {
            if ( oPPos[i] == a || cPPos[i] == b || oPPos[i] == b || cPPos[i] == a  ) {
                avail = false;
                break;
            }
        }

        if (avail) {
            oPPos[m] = a;
            cPPos[m] = b;
            m++;
        }        
    }
   
    std::sort( oPPos.begin(), oPPos.end() );
    std::sort( cPPos.begin(), cPPos.end() );
    
    /* // printing for debug
    for ( auto a : oPPos ) {
        std::cout << a << ' ';
    }
    std::cout << '\n';
    for ( auto a : cPPos ) {
        std::cout << a << ' ';
    }
    std::cout << '\n';
    */


    Opera* head = new Opera( 0, plus );
    //std::cout << "head: " << head << ' ';

    a = 0;
    b = 0;

    if ( oPPos[0] == 0 ) {
        head->changeOperation( introduceOpenParenthesis(head->getOperation()) );
        a++;
    }
    
    
    // std::cout << head->getVal() << head->showOperation() << ' ';

    double v;

    for ( int i = 0 ; i < N ; i++ ) {

        Operation g = randOp();

        if (i==N-1) {
            g = nothing;
        }

        if ( b < M ) {
            if ( a < M ) {
                if ( oPPos[a] == i and cPPos[b] == i ) {
                    a++;
                    b++;
                } else if ( oPPos[a]==i ) {
                    g = introduceOpenParenthesis(g);
                    a++;
                } else if ( cPPos[b]==i ) {
                    g = introduceCloseParenthesis(g);
                    b++;
                }
            } else {
                if ( cPPos[b]==i ) {
                    g = introduceCloseParenthesis(g);
                    b++;
                }
            }
        }

        v = randDub();

        // std::cout << v << operationToString(g) << ' ';

        head->append( v, g );

        //std::cout << head->getVal() << head->getOperation() << ' ';
    }

    return head;
    
} 

void renderOperaChain( Opera* x  ){

    while ( x != nullptr ) {
        //std::cout << x;

        std::cout << x->getVal();

        std::cout << x->showOperation();

        x = x->next();
    }

    std::cout << '\n';
}

void renderOperaChain( Opera* x, Opera* tail ){

    while ( x != nullptr && x != tail->next() ) {
        //std::cout << x;

        std::cout << x->getVal();

        std::cout << x->showOperation();

        x = x->next();
    }

    std::cout << '\n';
}



void renderParensAndOpera( Opera* chainHead, treeNode* treeHead ){

    
}



#endif