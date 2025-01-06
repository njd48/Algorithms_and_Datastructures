
#include <iostream>
#include <iterator>


int main()
{
    // ----------------
    // Static memory allocation (static and global variables)
    // Automatic memory allocation ( function parameters and local variables...
    //       memory is freed when the code-block ends )
    // Dynamic memory allocation: may not be known at compile time
    //

    // 'new' operator
    int* ptr1{ new int (5) }; // direct initialization
    int* ptr2{ new int {6} }; // uniform init.

    *ptr1 = 7;

    // free the memory
    delete ptr1;     // <--- ptr1 is now dangling
    ptr2 = nullptr;  // <--- best to do this

    // Handling bad_alloc exceptions
    // std::nothrow returns a nullptr if allocation fails.
    int* value { new (std::nothrow) int{} }; // ask for an integer's worth of memory
    if (!value) // handle case where new returned null
    {
        // Do error handling here
        std::cerr << "Could not allocate memory\n";
    }

    // can dynamically give some memory to nullpointers
    if (!ptr2){
        ptr2 = new int;
    }

    // MEMORY LEAK:  scoping issue
    {
        int* leaky_ptr{ new int{} };
        // This ptr will go out of scope
        // but the memory will not be free'd
    }

    // MEMORY LEAK:  change in pointer's role
    int value2 = 5 ;
    int* ep{ new int{} };  //allocate memory

    // std::cout << ep << '\n';

    ep = &(value2);  // memory was not free'd but address was lost


    return 0;
}