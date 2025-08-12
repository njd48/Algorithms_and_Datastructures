
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <vector>
#include "operations.cpp"
#include "opera.cpp"
#include "parentheticalTree.cpp"

// Outstanding issues
//  -1- resolve functions delete the tail node 


// forward declare 
void constructParentheticalTree( treeNode*, Opera* );
void resolveOperation( OperationGroup,  Opera*, bool& );
void resolveParenthesis(  Opera*, bool& );
void resolveExpression(   Opera*, bool& );
void fullResolve(  treeNode*,   Opera* );

//=====================================================================================

void constructParentheticalTree( treeNode* t, Opera* p ) {

    while ( p != nullptr ) {

        if ( isOParen( p->getOperation() ) ) {

            t = t->addChild( p );

        } else if ( isCParen( p->getOperation() ) ) {
            
            t->validate();
            t = t->getParent();

        } 

        p = p->next();
    }    

    t->validate();

}

void resolveOperation( OperationGroup grp, Opera* node , bool& flag ){ 

    Opera* p = node;
    OperationGroup g;

    while ( p != nullptr  ) {

        if ( isCParen( p->getOperation() ) ){
            return;
        }

        g = operationGroup( p->getOperation() );

        if ( g == grp ) {

            p->resolve();
            flag = true;

        } else {

            p = p->next();

        }        
    }
}

void resolveParenthesis(  Opera* p, bool& flag ){
    // Removes parenthesis once fully evaluated

    Opera* q = p->prev();

    std::cout << p->getVal() << q->showOperation() << '\n';
    std::cout << isCParen( p->getOperation() ) << '\n';
    std::cout << isOParen( q->getOperation() ) << '\n';

    if ( isCParen( p->getOperation() ) ) {
        if ( q != nullptr  ) {
            if ( isOParen( q->getOperation() ) ) {
                p->changeOperation( dropParenthesis( p->getOperation() ) );
                q->changeOperation( dropParenthesis( q->getOperation() ) );
                flag = true;
            }
        }
    }

    if ( q == nullptr && p->next() == nullptr ) {
        if ( p->getOperation() == nothing ) {
            flag = true;
        }
    }
};

void resolveExpression(Opera* node, bool& flag ){
    resolveOperation(  multDiv, node, flag );
    resolveOperation( addSubtr, node, flag );
    resolveParenthesis(         node, flag );
}

void fullResolve(Opera* headNode){

    //------------------------------------------------------------------------------//
    // Procedure: 
    //
    //    (1) Call construct parentheticalTree
    //    (2) pop sub-chains out of the tree like a stack
    //        sequentially evaluating
    //    (*) when empty evaluate the remaining expression
    //
    //------------------------------------------------------------------------------//

    bool chainAltered;

    // (1)
    //
    treeNode* treeHead = new treeNode( headNode );

    constructParentheticalTree( treeHead, headNode );

    // (2)
    //
    Opera* p;
    bool validP;
    while ( treeHead->nChildren() > 0 ) {

        chainAltered = false;

        p = treeHead->pop( validP );

        // if ( !validP ) {
        //     std::cout << "Error: invalid parenthetical encountered. exiting.\n";
        //     return;
        // }

        std::cout << p << '\n';
        resolveOperation( multDiv,  p, chainAltered  );
        renderOperaChain( headNode );
        std::cout << p << '\n';
        resolveOperation( addSubtr, p, chainAltered );
        renderOperaChain( headNode );
        std::cout << p << '\n';
        resolveParenthesis( p, chainAltered );
        renderOperaChain( headNode );

        if ( !chainAltered ) {
            std::cout << "Error: expression did not resolve. stopped at: ";
            renderOperaChain( headNode );
            return;
        }
    }

    resolveExpression( headNode, chainAltered );




    delete treeHead;
}


#endif