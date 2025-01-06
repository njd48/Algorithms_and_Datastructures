
//
#include <iostream>

bool isVowel(char c)
{
    return false;
}

int main()
{

    std::cout << "\nProgram: quiz on loops\n";

    std::cout << "------------------------------------------------\n";

    std::cout << "print the alphabet:\n";
    {
        int a = 'a';    // record ascii code for 'a'
        int i = 0;      // indexing var
        char var = 'a'; // char

        while (i < 26 )
        {
            var = static_cast<char>( a+i );
            std::cout << var;

            if ( (i+1)%10 == 0 ) { // divisible by 10
                std::cout << '\n';
            }
            else {
                std::cout << ", ";
            }

            i++;
        }

        std::cout << "done.\n";
        
    } //------------------------------------------------------------
    std::cout << "------------------------------------------------\n";

    return 0;
}