

#ifndef GRAPHM_H
#define GRAPHM_H

// Implements Graphs with adjacency matrix
#include <vector>
#include "myMatrix.cpp"

enum Color  // establishes symbolic constants
{             
    white = 0, // Should be white by default
    grey, 
    black,
};

class Graph {

    private:
        int V = 0;
        int E = 0;

        Matrix<int> adj;

        // Node properties for depth first search.
        std::vector<Color> attr;
        std::vector<int> discTime;
        std::vector<int> finTime;

    public:
        Graph();
        ~Graph();

    

        // basic tool methods
        int resize( int ); 
        int addNode();
        void addEdge( int, int );
        void removeEdge( int, int );
        void removeNode( int );
        bool isEdge( int, int );
        
        void nodeCol( int, Color );
        Color nodeCol( int );
        void nodeDiscTime( int, int );
        int nodeDiscTime( int );
        void nodeFinTime( int, int );
        int nodeFinTime( int );

        // examining methods
        int getNumVerts(){ return V; };
        int getNumEdges(){ return E; };
        void displayAdj();
        void displayState();
        void displayNodes();
};

Graph::Graph(){
    V = 0;
    E = 0;
    adj.resize(V,V);
    attr.resize(V);
};
Graph::~Graph(){
    //for ( int i = 0 ; i < V ; i++ ) 
   // {
    //    Adj[i].~List();
    //}
    // Does the destructor for List and stdvector automatically take care of this?
};

int Graph::resize( int newsize ){
    V = newsize;
    adj.resize(V,V);

    attr.resize(V);
    discTime.resize(V);
    finTime.resize(V);
    //attr[V] = white;
    return V;
};

int Graph::addNode(){
    V++;
    adj.resize(V,V);

    attr.resize(V);
    discTime.resize(V);
    finTime.resize(V);
    //attr[V] = white;
    return V;
};

void Graph::addEdge( int u, int v ) {
    //if( u==v ){
    //    std::cout << "warning: Connecting node to self is disallowed.  nothing happened.\n";
    //    return;
    //}
    if ( u>V || v>V ) {
        std::cout << "warning: node not in graph. nothing happened.\n";
        return;
    }

    // check if not already connected 
    if ( adj.at(u,v) == 1 && adj.at(v,u) == 1 ) {
        // do nothing
    } else {
        adj.assign( u, v, 1 ); 
        adj.assign( v, u, 1 ); ; //<-- remove if directed graph.

        E++;
    }

    
}

void Graph::removeEdge( int u, int v ) {

     // check if already no edge
     if ( adj.at(u,v) == 0 && adj.at(v,u) == 0 ) {
        // do nothing
    } else {
        adj.assign( u, v, 0 ); 
        adj.assign( v, u, 0 ); ; //<-- remove if directed graph.

        E--;
    }
}

void Graph::removeNode( int u ) {
    // Procedure: clear all node u adjacencies
    // Destroy node u's list
    // potential problem with std::vector holding an empty slot at position u.
    // Rearrange the Adj vector

    for ( int v = 0; v < V ; v++ ) { // in directed graphs, i would have to search all v's for connections to u
        
        if ( adj.at(u,v) == 1 ) {
            adj.assign( u, v, 0);
            adj.assign( v, u, 0);
            E--;
        }
    }

    // It's better to do this the hard way and then
    // tell the user to use remove() sparingly
    // due to the computational cost.
    // --- Insert code to rearrange Adj vector here.

}

bool Graph::isEdge( int u , int v ) {
    if ( adj.at(u,v) ) { 
        return true; 
    } else { 
        return false; }
}

void Graph::nodeCol( int i, Color colval ) {
    attr[i] = colval;
}
Color Graph::nodeCol( int i ) {
    return attr[i];
}
void Graph::nodeDiscTime( int i, int t ){
    discTime[i] = t;
};
int Graph::nodeDiscTime( int i ){
    return discTime[i];
};
void Graph::nodeFinTime( int i, int t ){
    finTime[i] = t;
};
int Graph::nodeFinTime( int i ){
    return finTime[i];
};

//=============================================================================

void Graph::displayAdj() {
    for ( int i = 0 ; i<V ; i++ ){
        std::cout<< "node " << i << ": ";
        adj.displayRow(i);
    }
}

void Graph::displayState()
{
    std::cout << "Graph State: V = " << V << ", E = " << E << '\n';
}

void Graph::displayNodes() {

    std::string colWord;

    std::cout << "node colorings: { ";
    for ( int i = 0 ; i<V ; i++ ){

        switch ( attr[i] ) {
            case white: {colWord = "white"; break;}
            case black: {colWord = "black"; break;}
            case grey:  {colWord = "grey"; break;}
        }

        std::cout << i << ": " << colWord << "  ";
    }
    std::cout << "}\n";
}

/*
*/

#endif 