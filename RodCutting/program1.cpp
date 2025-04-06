
#include <iostream>
#include <vector>
#include <cassert>
#include <climits>

void setPrices( std::vector<int>& p, int N ){

    assert( N+1 == p.size() );

    p[0] = 0;

    for ( int i = 1 ; i < N+1 ; i++ ){

        p[i] = p[i-1] + rand()%4;
    }
}

void printArr( std::vector<int>& P ) {

    printf("[ ");
    for ( auto p : P ){
        printf(" %i,", p);
    }
    printf( "]\n");
}

int max( std::vector<int>& X ) {

    int m = INT_MIN;

    for ( auto x : X ) {
        if ( x > m ) m = x;
    }
    return m;
}
int min( std::vector<int>& X ) {

    int m = INT_MAX;

    for ( auto x : X ) {
        if ( x < m ) m = x;
    }
    return m;
}


int maxCutRod_naiveRecursive(  const std::vector<int>& p, int N ) {

    int ans = 0;
    std::vector<int> V = p;

    for ( int i = 1 ; i<=N ; i++ ) 
    {
        V[i] = V[i] + maxCutRod_naiveRecursive( p,  N - i ) ;

        if (V[i] > ans) ans = V[i];
    }

    // printArr(V);

    return ans;
}

int maxCutRod_bottomUp(  const std::vector<int>& p, int N ) {

    int val1;
    int ans = 0;
    std::vector<int> V(N+1);

    for ( int j = 1 ; j <= N ; j++ )
    {
        int q = 0;

        for ( int i = 1 ; i<=j ; i++ ) {

            val1   = p[i]+V[j-i];
               
            if (val1 > q) q = val1;
        }
        V[j] = q;
    }

    ans = V[N];
   

    printArr(V);

    return ans;
}


int main() {

    int N = 6;
    std::vector<int> p(N+1);

    setPrices( p, N );

    std::cout << "Rod size: N = " << N << '\n';
    std::cout << "price distr: ";
    printArr( p );

    std::cout << "test min and max: " << min(p) << ' ' << max(p) << '\n';

    //------------------------------------------------
    std::cout << "solve by naive recursion \n";
    std::cout << "max val : " << maxCutRod_naiveRecursive( p, N ) << '\n';
    std::cout << '\n';
    std::cout << "solve by bottom up constr \n";
    int valfn = maxCutRod_bottomUp( p, N );
    std::cout << "max val : " << valfn << '\n';



}

