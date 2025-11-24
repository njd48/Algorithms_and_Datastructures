

#include "vfncs.hpp"
#include <vector>
#include <cassert>

using namespace std;

template <typename T> 
void vf::add( vector<T>& a, vector<T>& b, vector<T>& c ){

    assert( a.size() == b.size() );
    assert( a.size() == c.size() );

    // #ifdef _OPENMP 
    // int tid;
    // #pragma omp parallel private(tid)
    // {
    //     tid = omp_get_thread_num();
    //     if (tid==0){
    //         std::cout << "entering addition function\n";
    //         std::cout << "threads: " << omp_get_num_threads() << std::endl;
    //     }
    // }
    // #endif


    #pragma omp parallel for
    for ( int i = 0 ; i < c.size() ; i++ ){
        c[i] = a[i] + b[i];
    }

}

template <typename T> 
T vf::myFindMin( vector<T>& a ) {
    return 1;
}

