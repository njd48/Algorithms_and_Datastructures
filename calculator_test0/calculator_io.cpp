
#ifndef CALCULATOR_IO_H
#define CALCULATOR_IO_H

#include <iostream>
#include <vector>
#include <string>
#include "operations.cpp"
#include "opera.cpp"


bool validParenthesis( std::string );

//==================================================

bool validParenthesis( std::string input ) {

    // Key via  1:'(' ,, 2:'[' ,, 3:'{'
    // Key via  1:'(' ,, 2:'[' ,, 3:'{'

    std::vector<int> myStack;

    char myChar;
    int value     = 0;
    int prevValue = 0;
    bool flag1    = false;
    bool validity = true;

    for ( int n = 0; n < input.length(); n++ ) {

        myChar = input[n];
        // std::cout << myChar << '\n';

        if ( myChar == '(' ) {  
            myStack.push_back(1);
        } else if ( myChar == ')' ) {  
            flag1 = true;
        }         

        if ( flag1 ) {

            if ( myStack.empty() ){
                validity = false;
                return validity;
            }

            prevValue = myStack.back();
            myStack.pop_back();
            flag1 = false;
        }
    }

    if ( !myStack.empty() ) {
        validity = false;
    }

    return validity;
}


#endif