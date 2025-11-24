
#include <iostream>
#include <vector>


#define SREDUCE_PARAM 7

bool isSorted( std::vector<int> v ){

    for ( int i = 1 ; i < v.size() ; i++ ){

        if ( v[i-1] > v[i] ){
            return false;
        }
    }
    return true;
}

void dispV( std::vector<int>& x ){
    std::cout << "[";

    for ( auto a : x ) {
        std::cout << a << ' ';
    }

    std::cout << ']' << '\n';

}

void insertionSort( std::vector<int>& v, int begin, int end ){

    int a, b;
    int jrem;

    for ( int i = begin; i < end; i++ ){
        a    = v[i];
        jrem = i-1;
        while ( jrem >= begin ){
            if (v[jrem] <= a){
                break;
            }
            jrem--;
        }
        for ( int j = jrem+1 ; j <= i ; j++ ) {
            b    = v[j];
            v[j] = a;
            a    = b;
        }
    }

}

int partitionQS( std::vector<int>& v, int begin, int end ){

    if ( end <= begin ) {
        return begin;
    }

    int pivot = v[begin];

    int i = begin;
   // int j = end-1;

    int t;

    for ( int j = begin; j < end ; j++ ){

        if (v[j] < pivot ){
            t    = v[i];
            v[i] = v[j];
            v[j] = t;
            i++;
        }
    }

    // 
    t        = v[end-1];
    v[end-1] = v[i];
    v[i]     = t;

    return i;
}

void quickSort( std::vector<int>& v, int begin, int end  ){

    if (end-begin < SREDUCE_PARAM){
        insertionSort( v, begin, end );
        return;
    }

    int m = partitionQS( v, begin, end );

    quickSort( v, begin,   m );
    quickSort( v,     m, end );

}

int main () {

    size_t N   = 19;

    std::vector<int> x(N);

    // Test insertion Sort 
    //
    int m ;
    for ( int u = 0 ; u < 5 ; u++  ) {

        for ( int i = 0; i < N ; i++){
            x[i] = 10 + rand()%89;
        }
        std::cout << "in"<< u <<": ";
        dispV(x);

        quickSort( x, 0, N );
        std::cout << isSorted(x) << "  : ";
        dispV( x );

        //insertionSort( x, 0, N );
        //std::cout << isSorted(x) << "  : ";
        //dispV( x );

       /*
        m = partitionQS( x, 0, N );
        std::cout << m << " :  ";
        dispV( x );

        std::cout << partitionQS( x, 0, m )  << ' ';
        std::cout << partitionQS( x, m, N ) ;
        std::cout <<  ':';
        dispV( x );
         */
        //m = partitionQS( x, 0, m );
        //dispV( x );
        //std::cout << m << '\n';
        //std::cout << '\n';
    }

    std::vector<int> y = {3,2,1};
    N = y.size();
    std::cout << "in"<<  " : ";
    dispV(y);

    insertionSort( y, 0, N );
    std::cout << isSorted(y) << "  : ";
    dispV( y );


   
}