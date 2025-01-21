#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cassert>
//#include 


// Print an array
template <typename T>
void printV( const std::vector<T>& arr ) // explicitly specifying <int>
{     
    int N = arr.size();
    std::cout << "[ ";
    for (int i = 0 ; i < N-1 ; i++ ) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[N-1] << "]\n";
}

// For Q3 and 4
int handle_input() {
    int input;

    while ((input < 1)||( input > 9)) {
        std::cout << "Input a number between 1 and 9 ...\n";
        std::cin >> input;

        // i copied this following ::cin handling from the solution
        // if the user entered an invalid character
        if (!std::cin) // apparently !::cin reports a 'failed extraction'
                       // for now i assume this has to do with the type: int input
            std::cin.clear(); // reset any error flags

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        // ^ ignore any extra characters in the input buffer 
        // (regardless of whether we had an error or not)
    }

    return input; 
}


template <typename T>
int Q3_find( const std::vector<T>& arr, T x ) {
   
    bool found = false;
    int ans;
    for (int i = 0 ; i < arr.size() ; i++ ) {

        if (arr[i]==x) {
            ans   = i;
            found = true;            
            break;
        }
    }
    if (!found) {  
        // std::out << "err: value " << n << " not found in array.\n";
        return -1;
    } else {
        return ans;
    }
}

template <typename T>
void Q3_prompt( const std::vector<T>& arr )
{
    int input = handle_input( );
    // input = static_cast<T>(input);
    int inx = Q3_find( arr, input );

    if (inx == -1) {
        std::cout << "Value, " << input << ", not found in array.\n";
    } else {
        std::cout << "Value, " << input << ", found at index, " << inx << '\n';
    }    
}


int main(){

    /* Question #3
    Ask the user for a value between 1 and 9. If the user does not enter 
    a value between 1 and 9, repeatedly ask for an integer value until 
    they do. If the user enters a number followed by extraneous input, 
    ignore the extraneous input.  Print the array. Write a function 
    template to search the array for the value that the user entered. 
    If the value is in the array, return the index of that element. 
    If the value is not in the array, return an appropriate value. If 
    the value was found, print the value and index. If the value was not 
    found, print the value and that it was not found.
    */
    std::vector<int> ref_arr{ 4, 6, 7, 3, 8, 2, 1, 9};
    printV( ref_arr );

    // Test find function
    // should return 4 and -1
    // std::cout << Q3_find(  ref_arr, 8 ) << ' '<< Q3_find(  ref_arr, 0.01 ) << '\n';

    // Test Prompt
    Q3_prompt(  ref_arr );


    /* Question #4 
    Modify the prior program so that it can handle a std::vector 
    containing non-int numeric values, such as 
    */
    std::vector ref_arr2{ 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9 };
    /**/
    printV( ref_arr2 );

    // Test Prompt 
    // Q3_prompt(  ref_arr2 );  error organizing types of inputs in func templates.
}