

// This header file forward-declares external constants

#ifndef CNSTS_H
#define CNSTS_H

namespace cnsts
{
    // constexpr double pi { 3.1415926 };
    // constexpr double gravity { 9.81 };
    // constexpr double newton_G { 6.67430e-11 };

    // Far mor optimal to use external variables
    // otherwise, one would need to recompile all
    // files which use this header
    extern const double pi;
    extern const double gravity;
    extern const double newton_G;
}

#endif