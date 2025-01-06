
//

#include <iostream>
#include <cstring>
//#include <iterator>
//#include <typeinfo>
//#include <string>
//#include <time.h>



int main()
{
    
    char myString[]{"string"};
    const int length{ static_cast<int>(sizeof(myString)/sizeof(myString[0]))};

    std::cout << myString << '\n';

    for (int j=0; j<length ; j++)
    {
        std::cout << static_cast<int>(myString[j]) << ' ';
    }
    std::cout << "\nnote the null terminator ^^"<<'\n';
 
    myString[1]='p';
    std::cout << myString << '\n';

    char string2[20]{"pen"};
    const int length2{ static_cast<int>(sizeof(string2)/sizeof(string2[0]))};

    std::cout << string2 << " has length "<< length2 << '\n';
    std::cout <<" :: print ignores characters after null terminator\n";

    // Declare large char arrays for recieving inputs
    char name[255]{};

    std::cout << "Enter your name:...\n";
    std::cin.getline( name, static_cast<int>(sizeof(name)/sizeof(char)) );
    std::cout << "Result: " << name <<  '\n';

    // Test functions of <cstring> header
    char src[]{"message"};
    char dest[50];

    std::strcpy( dest, src );
    std::cout << dest << '\n';
    std::cout <<"num. letters: " << std::strlen(dest) << '\n';

    return 0;
}