

#include <iostream>
#include <cmath>
#include "GraphM.cpp"
#include "myqueue.cpp"

template <typename T>
void printVec(std::vector<T>& x) {
    std::cout << "{ ";  
    for ( auto a : x ){
        std::cout << a << " ";
    }
    std::cout << "}\n";
}

void setGraphProperties( Graph& G, int V, int epv ) 
{
    G.resize(V);

    for ( int i = 0 ; i < V ; i++ ) 
    {
        int v = 0;

        for( v = 0 ; v<epv ; v++ ) {
            int j = i;
            while ( j == i ){ // Dont connect to self
                j = rand()%V; 
                // if connection already exists return to the top of the while loop
                if( G.isEdge(i,j) ) { 
                    j = i; 
                } 
           
            } 
            G.addEdge( i, j );
        }
    }
}

void DepthFirstSearchVisit(  Graph& G, std::vector<int>& parent, int u, int time ){

    time++;
    G.nodeCol( u, grey );
    G.nodeDiscTime( u, time );

    for ( int v = 0 ; v < G.getNumVerts() ; v++  ) {
        if (G.isEdge(u,v)) {
            if ( G.nodeCol(v) == white ) 
            {
                parent[v] = u;
                DepthFirstSearchVisit( G, parent, v, time );
            }
        }
    }

    time++;
    G.nodeCol( u, black );    
    G.nodeFinTime( u, time );

}

void DepthFirstSearch( Graph& G ) {

    int V = G.getNumVerts();

    std::vector<int> parent(V);

    // Set 'em all up
    for ( int u = 0 ; u < V ; u++ ) 
    {   
        G.nodeCol( u, white );
        parent[u] = -1;
    }   

    int time = 0;

    // Enact
    for ( int u = 0 ; u < V ; u++ ) 
    {
        if (G.nodeCol( u ) == white) {
            DepthFirstSearchVisit( G, parent, u, time );
        }
    }

}

int main () 
{
    //--------------------------------------------//
        // Set a graph of so many verticies,      //
        // and comparable number of edges         //
        int V = 12;                               //
        int epv = (int)( 1.0*log(V)  );          //
    //                                            //
        Graph myGraph;                            //
        setGraphProperties(  myGraph, V, epv );   //
    //--------------------------------------------//
    
    // Display some characteristics before continuing
    std::cout << '\n';
    std::cout << "Characteristic edge per vertex ratio: |E|/|V| ~ " << epv << '\n';
    myGraph.displayAdj();
    myGraph.displayNodes();
    myGraph.displayState();

    // Implement breadth first search starting on node 0;
    DepthFirstSearch( myGraph );
    myGraph.displayNodes();


}