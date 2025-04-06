
#include <iostream>
#include <vector>

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Program unfinished
//

double naivePow( double x, int n) {

    double y = 1;

    // Prelim checks
    if (n==0) {
        x = 1;
    } else if ( n < 0 ) {
        x = 1/x;
        n = -n;
    } 

    for ( int i = 0; i < n ; i++ ) {
        y = x*y;
    }

    return y;

}

double myPow(double x, int n) {


    // Prelim checks
    if (n==0) {
        x = 1;
    } else if ( n < 0 ) {
        x = 1/x;
        n = -n;
    } 
    //std::cout << "here1\n";

    int    inx  = 0;
    int    k    = n;
    int    rems = 0;
    
    double myass  = (double)n;
    int evil_num = *( reinterpret_cast<int*>(&myass) );
    evil_num = evil_num;
    evil_num += 2;

    //std::cout << '\t'<< "evil num: " << evil_num << '\n';
    //std::cout << "here2\n";
    

    std::vector<double>    y( evil_num );
    std::vector<double> twos( evil_num );

    double ans;

    twos[0] = 1;
    twos[1] = 2;
    y[0]    = x;
    y[1]    = x*x;

    k = k/2;
    if ( k%2 ){ rems++; }// is odd 

    //std::cout << "here3\n";

    inx = 1;
    while( k > 1 ) {
       std::cout << "here4, k = " << k << '\n';

        twos[inx+1] = twos[inx]*twos[inx];
        y[inx+1]    = y[inx]*y[inx];

        k = k/2;


        inx++;
        if ( k%2 ){ rems =rems*2; }  // is odd         
    }
    ans = y[inx];

    //std::cout << "here5\n";

    
    int i;
    while ( rems > 0 ) {
        i = 0;
        while ( (i < evil_num+1) && (twos[i] <= rems) ) {
            i++;
        } 
        i--;

        ans  = ans*y[i];
        rems = rems - twos[i];
    }
    

        
    return ans;
}

void testPows( int N ) {

    int restrictPow = 11;

    int n;
    double x;
    double y1;
    double y2;
    
    printf("  input    naivePow     myPow   \n");

    for ( int i = 0; i< N; i++) {
        // Set up the test
        n = rand()%restrictPow;
        x = (double)( (2*rand()%2-1)*(rand()%1000)  ) + (double)( (rand()%10000)/10000 ) ;  
        y1 = naivePow( x, n);
        y2 = myPow( x, n);

        // Report
        
        printf(" %8.6f  %8.6f  %8.6f \n", x, y1, y2);
    }
}

/*
double testPerformanceMerge( int N ) {

    int n_tests = 64; 

    std::vector<double> walltime(n_tests);
    std::vector<int> arr(N);

    clock_t   start_time;
    clock_t     end_time;
    double  average_time;

    for ( int i = 0; i < n_tests ; i++ ) {
        // Form random int array
        for (int j = 0 ; j < N ; j++ ){
            arr[j] = ( rand()%100 ); // rand int between 0 and 99;
        }
        
        start_time = clock();
        mergeSort( arr );
        end_time   = clock();

        // average time in seconds
        walltime[i] = ((double)(end_time - start_time))/CLOCKS_PER_SEC;

        average_time = average_time + walltime[i];
        
    }

    // Compute average
    average_time = average_time/n_tests;
    return average_time;

}
*/

int main() 
{
    double x = 2.00001;  
    int    n = 7;
    std::cout << "naivePow():   ";
    std::cout << x << '^' << n << " = " << naivePow( x, n) << '\n';
    std::cout << "   myPow():   ";
    std::cout << x << '^' << n << " = " << myPow( x, n) << '\n';
    // std::cout <<  myPow( 1.5, 5 ) << '\n';
    //testPows( 12 );

    return 0;
}