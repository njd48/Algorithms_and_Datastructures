

#ifndef KDV_H
#define KDV_H

#include <iostream>
#include <cstddef>
#include <complex>
    #define complex_t std::complex<double>

//#include "KdV_filestream.cpp"
#include "RK4_solver.cpp"

#define DOMAINSIZE 100

class KdV_env {

private:

    // --- Env size ---------------
    const size_t N = DOMAINSIZE;

    // --- Principle Simulation Variables ---  
    double     t = 0.0; 
    complex_t* Udata0;
    complex_t* Udata1;

    complex_t** U0 = &Udata0;
    complex_t** U1 = &Udata1;

    void swap_alias();

    // --- Solver Class ---------------
    RK4_solver solver = RK4_solver(N);

    // --- State vars -----------------
    bool initialized = false;

    // --- Derived parameters -----
    double dx;

public:
    // --- Public parameters ------
    double dt      = 0.0;
    double t_final = 0.0;
    double t_write = 0.0;

    // --- constr destr -------
    KdV_env();
    ~KdV_env();

    // --- Retrievals ---------
    double time() { return t; }

    // --- Ev -----------------
    void set_initial();
    void write2file();
    void run();


};

//------------------------------------------------------------------------------
// constr and destr
//------------------------------------------------------------------------------

KdV_env::KdV_env(  ){
    
    Udata0 = new complex_t[N];
    Udata1 = new complex_t[N];
    dx  = 1. / (double)(N-1);

}
KdV_env::~KdV_env(){
    delete Udata0;
    delete Udata1;

}

//------------------------------------------------------------------------------
// private methods
//------------------------------------------------------------------------------

void KdV_env::swap_alias() {
    complex_t* temp = *U0;
    *U0 = *U1;
    *U1 = temp;
}

//------------------------------------------------------------------------------
// public methods
//------------------------------------------------------------------------------

void KdV_env::set_initial() {
    using namespace std::complex_literals;
    complex_t x = 0. + 0.*1i;
    for ( size_t n = 0; n<N ; n++ ){
        x += dx;
        Udata0[n]= sin(x);
    }
    initialized = true;
}

void KdV_env::write2file() {
    std::cout<< "here writing at time, t = " << t << '\n';
}

void KdV_env::run() {

    bool eflag = false;
    bool write = true;
    if ( !initialized ) {
        std::cout << "error: system initial condition was not set. cannot run.\n";
        eflag = true;
    } 
    if ( dt <= 0 ) {
        std::cout << "error: invalid timestep. cannot run.\n";
        eflag = true;
    } 
    if ( t_final <= 0 ) {
        std::cout << "error: specify finite t_final. cannot run.\n";
        eflag = true;
    }
    if ( t_write <=0 ) {
        std::cout << "warning: invalid write period, t_write.  output will not be saved. \n";
        write = false;
    }

    if (eflag) { 
        return; 
    }
    //----------------------------------------------------------------------

    size_t P   = (size_t)( t_final / dt );

    if (write) {

        size_t P_w = (size_t)( t_write / dt );

        size_t n_writes = P/P_w;

        write2file();

        int timeIndex = 0;

        for ( size_t n =0 ; n < n_writes ; n++ ) {
            for ( size_t p = 0; p < P_w ; p++ ){
                
                solver.timestep( dt, *U0, *U1 );
                swap_alias();
                t += dt;
                timeIndex++;
                std::cout << timeIndex << '\n';
            }
            write2file();
        }

        if ( n_writes*P_w < P ) {
            std::cout << "amhere?\n";
            for ( size_t p = 0; p < P-n_writes*P_w  ; p++ ){
                solver.timestep( dt, *U0, *U1 );
                swap_alias();
                t += dt;
                timeIndex++;
                std::cout << timeIndex << '\n';
            }
            write2file();
        }
        std::cout << "expected final time index: " << P << '\n';

    } else {
        for ( size_t p = 0; p < P ; p++ ) 
        {
            solver.timestep( dt, *U0, *U1 );
            swap_alias();
            t += dt;
        }
    }

}



#endif
