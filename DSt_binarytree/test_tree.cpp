
#include <iostream>

#include "binary_search_tree.cpp"


int main()
{

    BinTree<int> myTree;

    std::cout << "is empty: " << myTree.isEmpty() << '\n';

    myTree.insert( 15 );
    myTree.list();
    myTree.insert( 3 );
    myTree.list();
    myTree.insert( 17 );
    myTree.list();
    myTree.insert( 13 );
    myTree.list();
    myTree.insert( 6 );
    myTree.list();

    std::cout << "is empty: " << myTree.isEmpty() << '\n';

    

    
    std::cout << "\nSequential Tests \n";

    
    int n_tests = 4;
    int n_el    = 15;
    int val   ;
    for ( int n = 0; n < n_tests; n++ ) {

        BinTree<int> tree1;

        for ( int i = 0; i < n_el; i++ ) {
            val = rand()%100;
            //std::cout << val << ' ';
            tree1.insert( val );
        }
        //std::cout << '\n';
        tree1.list();

    }

    std::cout << "\nTest Search: \n";
    myTree.list();
    std::cout << " Item 3  found at: " << myTree.search(3) << '\n';
    std::cout << " Item 15 found at: " << myTree.search(15) << '\n';
    std::cout << " Item 7  found at: " << myTree.search(7) << '\n';
    //---------------------------------------------------------------------------

    //std::cout << "\nCan we search for successor?: \n";
    //myTree.list();
    //std::cout << " Successor of 3 found at: " << myTree.successor(3)<< '\n';





    return 0;
}