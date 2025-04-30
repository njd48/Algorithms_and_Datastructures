
#ifndef KDV_CALC_H
#define KDV_CALC_H

#include <complex>
    #define complex_t std::complex<double>

// =============================================================
//  Functions
// =============================================================

namespace KdVcalcs {

    void mderiv1periodic( size_t L, size_t N, double dx, complex_t *U, complex_t *D1  )
    {
        // Logic, trying to presage multithreading
        if ( 0>=L && 0<N ) {
            D1[0] = -1/(2.*dx)*( U[1]-U[N-1] );
            L=L+1;
        }
        if ( (N-1)>=L ) { // <--- Dubious! what the total aray size again?
            D1[N-1] = -1/(2.*dx)*( U[0]-U[N-2] );
            N = N-1;
        }

        for( size_t j = L ; j < N ; j++ ) {
            D1[j] = -1/(2.*dx)*( U[j+1] - U[j-1] );
        }
    }

    void RHS( size_t L, size_t N, double dx, complex_t *U, complex_t *rhs ) 
    {
       mderiv1periodic( L, N, dx, U, rhs );
    }
};

// =============================================================
//  solver class
// =============================================================

class RK4_solver {

private:
    size_t N;

    double dx;

    complex_t* temp1; 

    complex_t* k1; 
    complex_t* k2; 
    complex_t* k3; 
    complex_t* k4;

public:
    RK4_solver( size_t );
    ~RK4_solver( );

    void timestep( double dt, complex_t *u0, complex_t *u1 );



};


RK4_solver::RK4_solver( size_t n ) {
    N = n;
    temp1 = new complex_t[N];
    k1    = new complex_t[N];
    k2    = new complex_t[N];
    k3    = new complex_t[N];
    k4    = new complex_t[N];

    dx = 1. / (double)(N-1);
}
RK4_solver::~RK4_solver(  ) {
    delete temp1;
    delete k1;
    delete k2;
    delete k3;
    delete k4;
}

void RK4_solver::timestep( double dt, complex_t *u0, complex_t *u1 ){

    KdVcalcs::RHS( 0, N, dx, u0, k1 );
    
    for( int i = 0; i<N ; i++ ){ 
        temp1[i] = u0[i] + 0.5*dt*k1[i]; 
    }

    KdVcalcs::RHS( 0, N, dx, temp1, k2 );

    for( int i = 0; i<N ; i++ ){ 
        temp1[i] = u0[i] + 0.5*dt*k2[i]; 
    }

    KdVcalcs::RHS( 0, N, dx, temp1, k3 );

    for( int i = 0; i<N ; i++ ){ 
        temp1[i] = u0[i] + dt*k3[i]; 
    }

    KdVcalcs::RHS( 0, N, dx, temp1, k4 );

    for( int i = 0; i<N ; i++ ){ 
        u1[i] = u0[i] + (dt/6.0)*( k1[i] + 2.0*k2[i] + 2.0*k3[i] + k4[i] ) ; 
    }
}


#endif