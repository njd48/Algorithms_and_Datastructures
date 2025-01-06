//
//

#include <iostream>
#include <string>   // Enables std::string

int main()
{

    // Demonstrate memberfunction .length()
    // danger, this returns unsigned ints

    std::string name{ "Alek" };
    std::cout << "Your name is " << name << ", with " << name.length() << " letters.\n";
    

    return 0;
}