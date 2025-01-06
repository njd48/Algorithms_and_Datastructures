
//
#include <iostream>

bool isVowel(char c)
{
    return false;
}

int main()
{

    std::cout << "\nProgram: Demonstration of loops\n";
    std::cout << "------------------------------------------------\n";
    std::cout << "print no. between 1 and 10:\n";
    {
        
        for ( int i = 1; i<=10 ; i++ )
        {
            std::cout << i << ", ";
        }
        std::cout << "done.\n";

        
    } //------------------------------------------------------------
    std::cout << "------------------------------------------------\n";

    std::cout << "print no. between 1 and 50 using while:\n";
    {
        
        int i = 1;
        while (i <= 50 )
        {

            // print leading zero
            if (i < 10) {
                std::cout << '0';
            }  

            // the digit
            std::cout << i; 

            if ( i%10 == 0 ) { // divisible by 10
                std::cout << '\n';
            }
            else {
                std::cout << ", ";
            }

            //
            i++;
        }

        std::cout << "done.\n";
        
    } //------------------------------------------------------------
    std::cout << "------------------------------------------------\n";

        std::cout << "demonstrate nested while loop:\n";
    {
        
        int i = 1;
        int j;
        while (i <= 10 )
        {
            j = 1;
            while ( j <= i )
            {

                // print leading zero
                //if (j < 10) {
                //    std::cout << '0';
                //}  

                // the digit
                std::cout << j << ", "; 

                j++;
            }
            //
            std::cout << '\n';
            i++;
        }

        std::cout << "done.\n";
        
    } //------------------------------------------------------------
    std::cout << "------------------------------------------------\n";

    return 0;
}