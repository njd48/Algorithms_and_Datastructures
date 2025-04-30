
#include <iostream>

#include "bin_tree_preRB.cpp"
#include "red_black_tree.cpp"

#define TREECLASS BinTree

template <classname T>
void treeInsertRandNodes( T& tree,  int N_nodes ) {

    int x;
    int rndNumCut = 100;

    for ( int i = 0; i < N_nodes ; i++ ) 
    {
        //std::cout << i ;
        x = rand()%rndNumCut;
        tree.insert(x);
    }
}

int main()
{

    std::cout << "(*) Create a tree...\n";
    
    RBTree myTree;

    std::cout << "    is empty?: " << myTree.isEmpty() << '\n';

    //-------------------------------------------------------------------------------
    std::cout << "(*) Insert in the tree...\n";
    
    int tv1 = 8; 
    int tv2 = 11;
    int tv3 = 2;
    myTree.insert( tv1 );
    myTree.insert( tv2 );
    myTree.insert( tv3 );

    std::cout << "    is empty?: " << myTree.isEmpty() << '\n';
    std::cout << "    height:    " << myTree.height() << '\n';

    std::cout << "    ";    
    myTree.display();

    std::cout << "    Remove from tree...\n";
    myTree.remove( tv1 );
    myTree.remove( tv2 );
    myTree.remove( tv3 );

    std::cout << "    is empty?: " << myTree.isEmpty() << '\n';
    std::cout << "    height:    " << myTree.height() << '\n';
    std::cout << "    ";    
    myTree.display();

    //-------------------------------------------------------------------------------
    std::cout << "(*) Put them back and add random values ...\n";

    int N = 14;

    treeInsertRandNodes( myTree, N ) ;
    
    myTree.insert( tv1 );
    myTree.insert( tv2 );
    myTree.insert( tv3 );

    std::cout << "    is empty?: " << myTree.isEmpty() << '\n';
    std::cout << "    height:    " << myTree.height() << '\n';
    std::cout << "    ";    
    myTree.display();


    //-------------------------------------------------------------------------------
    std::cout << "(*) Try searching the tree...\n";

    std::cout << "    element, " << tv2 << ", found at mem address: " << myTree.search( tv2 ) << '\n';
    std::cout << "    element, " << tv3 << ", found at mem address: " << myTree.search( tv3 ) << '\n';
    std::cout << "    element, " << 102 << ", found at mem address: " << myTree.search( 102 ) << '\n';

    std::cout << "(*) Basic algorithms on the tree...\n";    
    std::cout << "    tree minimum: " << myTree.min()  << '\n';
    std::cout << "    tree maximum: " << myTree.max() << '\n';


    //-------------------------------------------------------------------------------
    std::cout << "(*) test some rotations on the tree...\n";

    myTree.testRotations();

    std::cout << "    ";    
    myTree.display();

    /*-----------



    */
    return 0;
}