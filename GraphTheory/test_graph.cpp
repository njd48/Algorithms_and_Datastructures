
#include <iostream>
#include "GraphL.cpp"

int main() {

    Graph myGraph;

    // How many nodes?
    int N = 5;
    for ( int i = 0 ; i <N ; i++ ){
        myGraph.addNode();
    }
    myGraph.addEdge(2,4);
    myGraph.addEdge(1,4);
    myGraph.addEdge(2,3);
    myGraph.addEdge(3,4);

    // Connect every node to node 0
    for ( int i = 1; i<N ; i++ ){ 
        myGraph.addEdge(0,i);
    }

    std::cout << '\n';
    std::cout << "Here's my graph so far:...\n";
    myGraph.displayAdj();
    myGraph.displayState();

    // Try removing an edge
    std::cout << '\n';
    std::cout << "Try removing an edge:...\n";
    myGraph.removeEdge(0,1);
    myGraph.displayAdj();
    myGraph.displayState();

    // Try removing a node
    std::cout << '\n';
    std::cout << "Try removing a node:...\n";
    myGraph.removeNode( 3 );
    myGraph.displayAdj();
    myGraph.displayState();

    return 0;
}