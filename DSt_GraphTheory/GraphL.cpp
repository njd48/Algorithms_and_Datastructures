

#ifndef GRAPHL_H
#define GRAPHL_H

enum Color  // establishes symbolic constants
{             
    red, 
    green, 
    blue,
};

// Implements Graphs with adjacency lists

// #include <matrix.cpp>
#include <vector>
#include "mylinklist.cpp"

class Graph {

    private:
        int V;
        int E;

        std::vector< List<int> > Adj;

    public:
        Graph();
        ~Graph();

        // basic tool methods
        int addNode();
        void addEdge( int, int );
        void removeEdge( int, int );
        void removeNode( int );

        // examining methods
        void displayAdj();
        void displayState();
};

Graph::Graph(){
    V = 0;
    E = 0;
    Adj.reserve(V);
};
Graph::~Graph(){
    //for ( int i = 0 ; i < V ; i++ ) 
   // {
    //    Adj[i].~List();
    //}
    // Does the destructor for List and stdvector automatically take care of this?
};


int Graph::addNode(){
    V++;
    Adj.resize(V);
    return V;
};

void Graph::addEdge( int u, int v ) {
    if( u==v ){
        std::cout << "warning: Connecting node to self is disallowed.  nothing happened.\n";
        return;
    }
    if ( u>V || v>V ) {
        std::cout << "warning: node not in graph. nothing happened.\n";
        return;
    }

    Adj[u].push(v);
    Adj[v].push(u); //<-- remove if directed graph.

    E++;
}

void Graph::removeEdge( int u, int v ) {
    Adj[u].remove(v);
    Adj[v].remove(u); //<-- remove if directed graph
    E--;
}

void Graph::removeNode( int u ) {
    // Procedure: clear all node u adjacencies
    // Destroy node u's list
    // potential problem with std::vector holding an empty slot at position u.
    // Rearrange the Adj vector

    int v;

    while ( !(Adj[u].isEmpty()) ) { // in directed graphs, i would have to search all v's for connections to u
        v = Adj[u].pop();
        Adj[v].remove(u);
        E--;
    }

    // It's better to do this the hard way and then
    // tell the user to use remove() sparingly
    // due to the computational cost.
    // --- Insert code to rearrange Adj vector here.

}

void Graph::displayAdj() {
    for ( int i = 0 ; i<V ; i++ ){
        std::cout<< "node " << i << ":  adj";
        Adj[i].display();
    }
}

void Graph::displayState()
{
    std::cout << "Graph State: V = " << V << ", E = " << E << '\n';
}


/*
*/

#endif 