
// Needs to be compiled with "gcc fast_inv_sqrt.c -lm"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define TABLE_SIZE 7
#define N_TIMETRIALS 10000000

//===========================================================================

float invSqrt( float x ) {

    float y = 1.0f / sqrtf(x);
    return y;
}

float Q_rsqrt( float x ) {

    int i;
    float x2;
    float y;
    //const float threeHalfs = 1.5f;

    x2 = x * (0.5f);
    y  = x;

    i  = * ( int * ) &y;                      // evil floating point bit level hacking
    i = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( float * ) &i;          
    y = y * ( 1.5f - ( x2 * y * y ) );   // Newton 1st iteration.
//    y = y * ( threeHalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return y;
}

//---------------------------------------------------------------------------

float FrelDiff( float x, float x1 ) {
    return fabsf( (x1-x)/x );
}
float FsumArr( int N, float* x ){

    float sum = 0;

    for (int i = 0; i<N ; i++){
        sum += x[i];
    }

    return sum;
}
float Fmean(   int N, float* x ) {
    float avg = FsumArr( N, x )/N;
    return avg;
}
float Fstdev(  int N, float* x ) {
    float dev = 0;
    float avg = Fmean( N, x );

    for ( int i = 0 ; i<N ; i++ ) {
        dev +=  (x[i]-avg)*(x[i]-avg) ; 
    }

    dev = sqrtf(dev/N);
    return dev;
}

double DrelDiff( double x, double x1 ) {
    return fabs( (x1-x)/x );
}
double DsumArr( int N, double* x ){

    double sum = 0;

    for (int i = 0; i<N ; i++){
        sum += x[i];
    }

    return sum;
}
double Dmean(   int N, double* x ) {
    double avg = DsumArr( N, x )/N;
    return avg;
}
double Dstdev(  int N, double* x ) {    
    double dev = 0;
    double avg = Dmean( N, x );

    for ( int i = 0 ; i<N ; i++ ) {
        dev +=  (x[i]-avg)*(x[i]-avg) ; 
    }

    dev = sqrt(dev/N);
    return dev;
}

//---------------------------------------------------------------------------

void pTests( int N ) {

    double t_tot_inv;
    double t_tot_Q_r;
    double t_pca_inv;
    double t_pca_Q_r;
    float maxErr;
    float avgErr;

    clock_t   start_time;
    clock_t     end_time;
    //double* t_inv = new double[N];
    //double* t_Q_r = new double[N];

    float* inval   = malloc( N*sizeof(float) );
    float* ans_inv = malloc( N*sizeof(float) );
    float* ans_Q_r = malloc( N*sizeof(float) );
    float* errs    = malloc( N*sizeof(float) );

    // Set input values 
    for ( int i = 0; i<N ; i++ ) 
    {
        inval[i] = ( (float)(rand()%10) ) + ( (float)(rand()%1000) )/1000; //float btween 1 and 10;
    }

    // Time check
    // regular inverse sqrt
    start_time = clock();
        for ( int i = 0; i<N ; i++ ) 
        {
            ans_inv[i] = invSqrt( inval[i] );
        }
    end_time   = clock();
    t_tot_inv = (double)(  ( end_time - start_time )/(CLOCKS_PER_SEC/1000)  );

    // Time check
    // fast inverse sqrt
    start_time = clock();
        for( int i = 0; i<N ; i++)
        {
            ans_Q_r[i] = Q_rsqrt( inval[i] );
        }
    end_time   = clock();
    t_tot_Q_r = (double)(  ( end_time - start_time )/(CLOCKS_PER_SEC/1000) );


    // compute errs
    for ( int i = 0; i<N ; i++)
    {
        errs[i] = FrelDiff( ans_inv[i], ans_Q_r[i] );

        if (errs[i] > maxErr) {
            maxErr = errs[i];
        }
    }

    // Finish calcs -----------------
    //t_tot_inv  = sumArr( N, t_inv);
    //t_tot_Q_r  = sumArr( N, t_Q_r);
    t_pca_inv  = t_tot_inv/N;
    t_pca_Q_r  = t_tot_Q_r/N;
    //maxErr;
    avgErr     = Fmean( N, errs);


    printf("Performance (w/ %i trials):    invSqrt()    Q_rsqrt() \n", N);

    //printf("%.4e \n", (float)CLOCKS_PER_SEC);

    printf("----------------------------------  ------------ ------------\n");
    printf("tot wall time:           (ms)        %.4e   %.4e   \n", t_tot_inv, t_tot_Q_r );
    printf("avg wall time per call:  (ms)        %.4e   %.4e   \n", t_pca_inv, t_pca_Q_r );
   // printf("sdev wall time per call: (un)    %.4e   %.4e \n");
    printf("max Error:               (.)         %.4e   %.4e   \n",      0.0f,   maxErr  );
    printf("avg Error:               (.)         %.4e   %.4e   \n",      0.0f,   avgErr  );

   //delete t_inv;
   //delete t_Q_r;

    free(inval);
    free(ans_inv);
    free(ans_Q_r);
    free(errs);
}

void quickTestAndPrint3TabAndDiff( int N ) {

    float x;
    float y;
    float z;
    float relErr;

    printf("   input  \t 1/sqrt() \t Q_rsqrt()\t rel. Err \n");
    printf("----------\t----------\t----------\t----------\t\n");

    for( int i = 0; i<N; i++ ) {

        x = 1.0+(float)(3*i-1) + (float)( rand()%1000 )/1000;
        y = invSqrt( x );
        z = Q_rsqrt( x );

        relErr = FrelDiff( y, z );

        printf(" %08.6f \t %08.6f \t %08.6f \t %.4e \n", x, y, z, relErr);

    }

    printf("----------\t----------\t----------\t----------\t\n");
    printf("\n");
}

//===========================================================================

int main() {

    printf("\n");
    printf("  preliminary checks:\n" );
    printf("\tsize of short:  %lu \n", sizeof(short)   );
    printf("\tsize of int:    %lu \n", sizeof(int)     );
    printf("\tsize of long:   %lu \n", sizeof(long)     );
    printf("\tsize of float:  %lu \n", sizeof(float)   );
    printf("\tsize of double: %lu \n", sizeof(double)  );
    printf("\n");

    // Set up tables to check evaluations
    //
    quickTestAndPrint3TabAndDiff( TABLE_SIZE );

    //
    pTests( N_TIMETRIALS );

    printf("\n Damn, why isn't it faster?\n");

}