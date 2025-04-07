

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

std::vector<double> BreadthFirstSearch( Graph& G, int s ) {

    int V = G.getNumVerts();

    std::vector<double> dist(V);
    std::vector<int> parent(V);

    assert ( s < V );

    // Set 'em all up
    for ( int u = 0 ; u < V ; u++ ) {   
        if( u != s ) 
        {
            G.nodeCol( u, white );
            dist[u]   = HUGE_VAL;
            parent[u] = -1;
        }   
    }

    Queue<int> Q;
    Q.enqueue( s );

    // Enact
    int u ;
    while( !Q.isEmpty() ) {

        u = Q.dequeue();

        for ( int v = 0 ; v < V ; v++ ) {   
            if( G.isEdge(u,v) ) 
            {
                if( G.nodeCol(v) == white ) 
                {
                    G.nodeCol(v,grey);
                    dist[v] = dist[u] + 1.0;
                    parent[v] = u;
                    Q.enqueue(v);
                }
            }
        }

        G.nodeCol(u,black);

    }

    return dist;
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
    std::vector<double> dist0 = BreadthFirstSearch( myGraph, 0 );

    std::cout << '\n';
    std::cout << "Result: Node distances from node zero:...\n";
    printVec( dist0 );
    std::cout << "Changed graph coloring through process:...\n";
    myGraph.displayNodes();

    // Implement breadth first search starting on node 2;
    std::vector<double> dist2 = BreadthFirstSearch( myGraph, 2 );

    std::cout << '\n';
    std::cout << "Result: Node distances from node 2:...\n";
    printVec( dist2 );
    std::cout << "Changed graph coloring through process:...\n";
    myGraph.displayNodes();

}