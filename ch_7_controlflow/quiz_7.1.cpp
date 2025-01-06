
//
#include <iostream>
#include "myCnsts.h"

double calculateHeight(double initialHeight, double seconds)
{
    double distanceFallen { myCnsts::gravity * seconds * seconds / 2 };
    double heightNow { initialHeight - distanceFallen };

    // Check whether we've gone under the ground
    // If so, set the height to ground-level
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

double calculateAndPrintHeight(double initialHeight, double time)
{
    double height  = calculateHeight(initialHeight, time);

    std::cout << "At " << time << " seconds, the ball is at height: " << height << "\n";

    return height;
}

int main()
{
    double initialHeight{};
    double height{};
    double time{0}, dt{0.7};
    
    std::cout << "Enter the initial height of the tower in meters: ";    
    std::cin >> initialHeight;


    bool ball_airborne{true};
    while (ball_airborne)
    {
        height = calculateAndPrintHeight( initialHeight, time );

        if (height <= 0)
            ball_airborne = false;
        else
            time += dt; 
    }




    return 0;
}