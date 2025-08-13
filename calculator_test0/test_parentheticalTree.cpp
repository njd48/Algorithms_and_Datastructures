

#include <iostream>
#include <random>
#include "operations.cpp"
#include "opera.cpp"
#include "utils.cpp"
#include "parentheticalTree.cpp"
#include "calculator.cpp"



int main() {

    int N = 22;

    int n_tests = 12;

    std::vector<Opera*>   chainHead( n_tests );
    std::vector<treeNode*> treeHead( n_tests );
    
    for ( int i = 0 ; i < n_tests ; i++ ) {

        // Construct System
        // 
        chainHead[i] = randomOperaChain( N );
        treeHead[i]  = new treeNode( chainHead[i] );

        renderOperaChain(chainHead[i]);        
        constructParentheticalTree( treeHead[i], chainHead[i] );

        std::cout << "Parenthetical Tree: ";
        treeHead[i]->displayGraphPlus();
        std::cout << '\n';

        // Test tree's ability to pop
        //
        Opera* p;
        bool validP;
        while ( treeHead[i]->nChildren() > 0 ) {

            p = treeHead[i]->pop(  );

            std::cout << p << " : \n";
            //if (validP) { std::cout << "true " << '\n'; }
            //else{         std::cout << "false" << '\n';}
            std::cout << "Parenthetical Tree: ";
            treeHead[i]->displayGraphPlus();
            std::cout << '\n';
        }





        delete chainHead[i];
        delete treeHead[i];
        std::cout << std::endl;
    }

    
}