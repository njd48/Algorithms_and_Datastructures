
#include <iostream>
#include "integer_partition.cpp"

using namespace::ip;

int main() 
{

    printf("\n");
    printf("  preliminary checks:\n" );
    printf("\tsize of short:  %lu bits\n", 8*sizeof(short)   );
    printf("\tsize of int:    %lu bits\n", 8*sizeof(int)     );
    printf("\tsize of long:   %lu bits\n", 8*sizeof(long)     );
    printf("\tsize of float:  %lu bits\n", 8*sizeof(float)   );
    printf("\tsize of double: %lu bits\n", 8*sizeof(double)  );
    printf("\n");

    int magicnum = 0x5f3759df/3 ;

    std::cout << "\tmagic num: " << magicnum << '\n';

    int n      = 2147483647;
    int m = fastApxSqrt(n);

    std::cout << "fastSqrt(" << n << ") = " << m << '\n';

    Part p     = intPartition_NSO( n );
    int n_test = sumPartition( p );

    std::cout << "Test partition fnc:...\n";
    std::cout << "input:  " << n << '\n';
    std::cout << "Partit: ";
    dispPartition(p);
    std::cout << "sum:    " << sumPartition(p) << '\n';

    return 0;
}