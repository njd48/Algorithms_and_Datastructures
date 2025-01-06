
#ifndef PAIR_H
#define PAIR_H

template <typename T, typename U> 
struct Pair
{
    T first{};
    U second{};
};

template <typename T, typename U>
void pront( Pair<T,U>& p )
{
    std::cout << "[ " << p.first << ", " << p.second << " ]\n";
}

template <typename T>
constexpr T max(Pair<T, T>& p )
{
    return( p.first > p.second ? p.first : p.second );
}

// Maximum function for many datatypes
template <typename Y>
Y max( Y x, Y y )
{
    return (x > y) ? x : y;
}

#endif