
//

#include <iostream>
#include <typeinfo>
#include <string>
#include <time.h>

void printByRef( int varname , std::string& y ) // parameter y is now a reference
{
    std::cout << "Result: s" << varname << " = " << y <<'\n';
    return;
}

std::string strcatByValue( std::string x, std::string y  )
{
    std::string z = x + y;
    return z;
}

void strcatByRef( std::string& x , std::string& y, std::string& z  ) // parameter y is now a reference
{
    z = x + y;
    return;
}

void strcatByAddr( std::string* x, std::string* y, std::string* z) //parameter y is a pointer to the memory
{
    *z = *x + *y;
    return;
}

std::string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}


int main()
{

    // Test parameters
    const int length = 155;
    const int n_iter = 100000000;

    // String Vars
    std::string q  = gen_random(length);
    std::string r  = gen_random(length);
    std::string s1 = gen_random(2*length);
    std::string s2 = gen_random(2*length);
    std::string s3 = gen_random(2*length);
    std::string* ptr_q = &q;
    std::string* ptr_r = &r;
    std::string* ptr_s = &s3;

    //Clock Vars
    clock_t init, end;
    double time1, time2, time3;

    //verify it working
    //s1 = strcatByValue(q, r);
    //strcatByRef(q,r,s2);
    //strcatByAddr(&q,&r,&s3);
    //printByRef( 1, s1 );
    //printByRef( 2, s2 );
    //printByRef( 3, s3 );

    // Begin testing //////////////////////////////////////////
    init = clock();
    for (int j = 0; j<n_iter; j++) {
        s1 = strcatByValue( q, r );
    }
    end = clock();
    time1 = (double)( end - init ) / CLOCKS_PER_SEC;

    init = clock();
    for (int j = 0; j<n_iter; j++) {
        strcatByRef( q, r, s2 );
    }
    end = clock();
    time2 = (double)( end - init ) / CLOCKS_PER_SEC;

    init = clock();
    for (int j = 0; j<n_iter; j++) {
        strcatByAddr( ptr_q, ptr_r, ptr_s );
    }
    end = clock();
    time3 = (double)( end - init ) / CLOCKS_PER_SEC;
    // ////////////////////////////////////////////////////////

    std::cout << "wall time for three different methods of concatenating\n" 
              << "std::string of length " << length << ", n = " << n_iter <<" times.\n";
    std::cout << "1: time by value:     " << time1 << " s \n"
              << "2: time by reference: " << time2 << " s \n"
              << "3: time by address:   " << time3 << " s \n";

    return 0;
}