
#include <iostream>
#include <vector>
#include "integer_partition.cpp"
#define NBITSINT 32
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// resolved! -- Program still needs work for
//     exceptional cases and agreement for inf/nan results 
//     occuring during large integer powers 
// resolved! -- Possible error is coming from choice of 
//     integer partition functions
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

double naivePow( double x, int n) {

    double y = 1;

    // Prelim checks
    if (n==0) {
        x = 1;
    } else if ( n < 0 ) {
        x = 1/x;
        //n = -n;

        if (n == -2147483648) { // Smallest int
            y = x;
            n = 2147483647; // Largest int
        } else {
            n = -n;
        }
    } 

    for ( int i = 0; i < n ; i++ ) {
        y = x*y;
    }

    return y;

}

double myPowRecur(double x, int n) {

    double ans;

    bool flag_SI = false;

    // Prelim checks
    if ( n < 0 ) {
        x = 1/x;
        //n = -n;

        if (n == -2147483648) { // Smallest int
            flag_SI = true;
            n = 2147483647; // Largest int
        } else {
            n = -n;
        }
    } 

    if ( n==0 ) {
        ans = 1;
        return ans;
    } 

   // std::cout << "prelim check done\n";

    // div
    int k = n/2;

    ans = myPowRecur( x, k );

    ans = ans*ans;

    // add back the odd power
    if ( n%2 == 1 ) {
        ans = x*ans;
    }

    if ( flag_SI ) {  // lost power from smallestInt flag
        ans = x*ans;
    }

    return ans;
}

double myPowPartitRecur(double x, int n) {

    using namespace::ip;

    double ans;

    // Edgecase
    if (n == -2147483648) { // Smallest int
        return (1/x)*myPowPartitRecur( x, n+1 );
    }

    // Prelim checks   
    if ( n < 0 ) {
        x = 1/x;
        n = -n;  // doesnt work for min value of type (int)
    } 
    
    if ( n < 10 ) {
        return naivePow(x,n);
    }

    // Enact near suboptimal integer partition
    Part p = intPartition_NSO( n ); 

    // Divide work and recurse
    double y_star, y_rem; 

    if ( p.rem > p.star ) {
        y_star = myPowPartitRecur( x, p.star );
        y_rem  = y_star * myPowPartitRecur( x, p.rem-p.star );
           
    } else {
        y_rem  = myPowPartitRecur( x, p.rem );
        y_star = y_rem * myPowPartitRecur( x, p.star-p.rem );
    }

    // Assemble the partitioned answer
    ans = y_rem;

    for ( int i = 0; i < p.m ; i++ ){
        ans = y_star*ans;
    }

    return ans;
}

double myPowBits( double x, int n ) {

    double ans = 1;

    // Prelim checks
    if (n==0) {
        x = 1;
    } else if ( n < 0 ) {
        x = 1/x;
        //n = -n;

        if (n == -2147483648) { // Smallest int
            ans = x;
            n = 2147483647; // Largest int
        } else {
            n = -n;
        }
    } 

    // Obtain the bit representation of n, and then get x^(2^k)
    bool b;
    double x2k = x;

    // k-th bit of n
    for ( int k = 0; k < NBITSINT ; k++ ){

        b =  (n & ( 1 << k )) >> k;

        if ( b ) {
            ans = ans*x2k;
        }
        x2k = x2k*x2k; //x^(2^(k+1))
    }

    return ans;

}

void testPowFuncs( int N ) {

    int restrictPow = 6;

    int n;
    double x;
    double y1, y2, y3, y4;
    
    printf("\n");
    printf("  inputs (x^n)          |    naivePow      myPowRecur     myPowPartitRecur     myPowBits\n");
    printf("------------------------+-----------------------------------------------------------\n");

    for ( int i = 0; i< N; i++) {
        // Set up the test
        n = (2*(rand()%2)-1)* (rand()%restrictPow);
        x = (double)( (2*(rand()%2)-1)*(rand()%50)  ) + ( (double)(rand()%10000) / 10000.0 ) ;  
        y1 = naivePow( x, n);
        y2 = myPowRecur( x, n);
        y3 = myPowPartitRecur( x, n);
        y4 = myPowBits( x, n);

        // Report
        
        printf("%0.4e ^ %i \t| %0.6e  %0.6e  %0.6e  %0.6e \n", x, n, y1, y2, y3, y4 );
    }
}

void testPowFuncs_edge(  ) {

    int LargestInt  =  2147483647;
    int SmallestInt = -2147483648;

    std::vector<int> testPows {  (3*LargestInt)/4, (3*SmallestInt)/4, LargestInt/2, SmallestInt/2, 
        LargestInt/2, SmallestInt/2, 3*(LargestInt/4), 3*(SmallestInt/4), LargestInt, SmallestInt };
    int N = testPows.size();

    int n; 
    double x;
    double y1, y2, y3, y4;
    
    printf("\n");
    printf("  inputs (x^n)              |    naivePow      myPowRecur     myPowPartitRecur     myPowBits \n");
    printf("----------------------------+------------------------------------------------------------\n");

    for ( int i = 0; i< N; i++) {
        // Set up the test
        n = testPows[i];//%restrictPow;
        x = (double)( (2*(rand()%2)-1)*(rand()%50)  ) + ( (double)(rand()%10000) / 10000.0 ) ;  
        y1 = naivePow( x, n);
        y2 = myPowRecur( x, n);
        y3 = myPowPartitRecur( x, n);
        y4 = myPowBits( x, n);

        // Report
        
        printf("%0.4e ^ %i \t| %0.6e  %0.6e  %0.6e  %0.6e \n", x, n, y1, y2, y3, y4 );
    }
}

double timeTest( int n, int N_tests, double (*f)( double, int ) ) {
    
    clock_t start_time;
    clock_t end_time;

    double x, y; 

    //----------------------------------------------------//
    start_time = clock();
        for ( int i = 0 ; i < N_tests ; i++ ) 
        {
            x = (double)( (2*(rand()%2)-1)*(rand()%50)  ) 
              + ( (double)(rand()%10000) / 10000.0 ) ;  

            y = f( x, n );
        }
    end_time   = clock();
    //----------------------------------------------------//

    double cpu_time = ((double) (end_time - start_time)) / (double)CLOCKS_PER_SEC;

    double time_per_eval = cpu_time/( (double)(N_tests) );

    return time_per_eval; // in seconds
}

void evalPerformance_powers( int n_low, int n_high, int N_rows ) {

    // fixed parameter
    int base_n_tests = 4096;

    // Set test powers and associated num tests, decay numtests for larger N
    std::vector<int> nvals(N_rows);
    std::vector<int> NTvals(N_rows);

    int dn = (n_high - n_low)/(N_rows-1);

    for ( int i = 0 ; i < N_rows ; i++ ) {
        nvals[i] = n_low + i*dn;
        NTvals[i] = base_n_tests / (  (int)sqrt(nvals[i]/n_low)  );
    }

    // init outputs and test
    int n, N;
    double t1, t2, t3, t4;

    printf("\n");
    printf("   \t| time per evaluation (s) \n");
    printf(" n \t|   naivePow     myPowRecur   myPowPartitRecur     myPowBits \n");
    printf("--------+-------------------------------------------------------\n");

    for ( int i = 0 ; i < N_rows ; i++ ) {
        n  = nvals[i];
        N  = NTvals[i];
        t1 = timeTest( n, N, &naivePow ); //
        t2 = timeTest( n, N, &myPowRecur );
        t3 = timeTest( n, N, &myPowPartitRecur );
        t4 = timeTest( n, N, &myPowBits );

        printf("%i \t| %0.6e  %0.6e  %0.6e  %0.6e \n", n, t1, t2, t3, t4 );
    }

}

int main() 
{

    //myPowPartitRecur( 1.8, -23456789);
    //myPowPartitRecur( 1.05, -2147483648 );

    //std::cout << "2.0^0 = " << myPowBits( 2.0, 0 ) << '\n';
    //std::cout << "2.0^1 = " << myPowBits( 2.0, 1 ) << '\n';
    //std::cout << "2.0^2 = " << myPowBits( 2.0, 2 ) << '\n';

    testPowFuncs( 12 );
   // testPowFuncs_edge();
    
    // std::cout << timeTest( 50, 100, &naivePow );

    evalPerformance_powers(  40, 10737410, 11 );

    return 0;
}