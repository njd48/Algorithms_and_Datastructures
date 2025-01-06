
//
#include <iostream>
#include <cassert>
#include <cmath>

// Program
//----------------------------------------------------

namespace cnst 
{
    const int sides = 6;  // sides on the die
}

// ----- Functions -----------------------------------

int rollDie( int sides = cnst::sides )
{
    return (rand() % sides) + 1;
}

void record( int result, int hist[cnst::sides] )
{
    hist[result-1] ++;
}

// ----- Main      -----------------------------------

int main()
{
    srand( time(NULL) ); // Set random seed

    // Initialize Vars
    int N = 5000;             // number of experiments
    // int sides = 6;           // sides on the die
    int result;              // Most recent roll
    int hist[cnst::sides]{}; // histogram array

    double pdf[cnst::sides]{};  // prob density fnc
    double expected{0.0};
    double sndmoment{0.0};
    double variance{0.0};
    

    // Commence rolling dice
    for ( int i=0; i < N ; i++ )
    {
        result = rollDie(  );
        record( result, hist );
    }

    // Display histogram
    std::cout << "roll : occurences\n";
    std::cout << "-----------------\n";
    for ( int i = 0; i < cnst::sides; i++)
    {
        std::cout << "  " << i+1 << "  :  " << hist[i] << '\n';
    }
    std::cout << "-----------------\n";

    // Statistics
    for (int i=0; i < cnst::sides; i++){
        std::cout << "guh";
        pdf[i] = hist[i]/N;

        expected  += (i+1)*pdf[i];
        sndmoment += (i+1)*(i+1)*pdf[i];
    }

    variance = sndmoment - expected*expected;

    // Display Statistics
    std::cout << "mean roll: " << expected << '\n';
    std::cout << "variance:  " << variance << '\n';

    return 0;
}