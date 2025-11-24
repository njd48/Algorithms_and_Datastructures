

#include <iostream>
#include <vector> 
#include <random>
#include "vfncs.cpp"
#include <ctime>

template <typename T>
void dispV( std::vector<T>& v ){
    std::cout << "[ ";
    for ( int i = 0 ; i < v.size(); i++ ){
        std::cout << v[i] << ' ';
    }
    std::cout << "]";
    std::cout << '\n';
}

void randV( std::vector<int>& v ){
    for ( int i = 0 ; i < v.size() ; i++ ) {
        v[i] = rand()%100;
    }
}

int main() {

    #ifdef _OPENMP
    int nthreads, tid;

    // Begin of parallel region
    #pragma omp parallel private(nthreads, tid)
    {
        // Getting thread number
        tid = omp_get_thread_num();
        //printf("Welcome to GFG from thread = %d\n",
        //       tid);

        if (tid == 0) {

            // Only master thread does this
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d;  ",
                   nthreads);

            //std::cout << "my thread limit: " << omp_get_thread_limit() << '\n';
        }
    }
    #endif

    int N = pow(2,29);

    std::vector<int> x(N);
    std::vector<int> y(N);
    std::vector<int> z(N);

    randV(x);
    randV(y);

    //dispV(x);
    //dispV(y);
    clock_t t0, t1;

    t0 = clock();
    vf::add( x, y, z );
    t1 = clock();

    double elapsed = ((double)(t1-t0))/(CLOCKS_PER_SEC);
    std::cout << "elapsed time: " << elapsed  << '\n';
    //dispV(z);

}