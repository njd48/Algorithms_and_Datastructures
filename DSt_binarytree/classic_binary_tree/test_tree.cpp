
#include <iostream>

#include "binary_search_tree.cpp"


int main()
{

    std::cout << "(*) Create a tree...\n";
    // Random initialization of N value tree
    TreeNode* myTree = randTree( 12 );
    
    // Insert a few test values
    int tVal1 = 12; treeInsert( myTree, tVal1);
    int tVal2 = 51; treeInsert( myTree, tVal2);
    int tVal3 = 14; treeInsert( myTree, tVal3);
   
    std::cout << '\t';  
    displayTree( myTree );

    //-------------------------------------------------------------------------------
    std::cout << "(*) Try searching the tree...\n";

    std::cout << "    element, " << tVal2 << ", found at mem address: " << treeSearch( myTree, tVal2 ) << '\n';
    std::cout << "    element, " << tVal3 << ", found at mem address: " << treeSearch( myTree, tVal3 ) << '\n';
    //-------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------
    std::cout << "(*) Basic algorithms on the tree...\n";

    std::cout << "    tree minimum: " << treeMin( myTree ) -> val << '\n';
    std::cout << "    tree maximum: " << treeMax( myTree ) -> val << '\n';
    std::cout << "    successor of " << tVal1 << ": " << successor( myTree, tVal1 ) -> val << '\n';
    std::cout << "    successor of " << tVal2 << ": " << successor( myTree, tVal2 ) -> val << '\n';
    std::cout << "    successor of " << tVal3 << ": " << successor( myTree, tVal3 ) -> val << '\n';
    std::cout << "    successor of " << treeMax(myTree)->val << ": " << successor( myTree, treeMax(myTree)->val )  << '\n';
    std::cout << "    predecessor of " << tVal1 << ": " << predecessor ( myTree, tVal1 ) << '\n';
    std::cout << "    predecessor of " << tVal2 << ": " << predecessor ( myTree, tVal2 ) -> val << '\n';
    std::cout << "    predecessor of " << tVal3 << ": " << predecessor ( myTree, tVal3 ) -> val << '\n';
    //-------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------
    std::cout << "(*) Remove items from the tree...\n";
    std::cout << '\t';  displayTree(myTree);
    
    remove( myTree, tVal1);
    std::cout << '\t';  displayTree(myTree);
    remove( myTree, tVal2);
    std::cout << '\t';  displayTree(myTree);
    remove( myTree, tVal3);
    std::cout << '\t';  displayTree(myTree);
    //-------------------------------------------------------------------------------

    return 0;
}