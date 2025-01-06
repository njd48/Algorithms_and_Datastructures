
// 

#include <iostream>
#include <typeinfo>
#include <string>


// ------ Question 1 ------------------------------------------------------
enum MonsterType
{
    ogre,
    dragon,
    orc,
    spider,
    slime,
};

std::ostream& operator<<(std::ostream& out, MonsterType type)
{
    switch (type)
    {
        case ogre:   out << "ogre"; break;
        case dragon: out << "dragon";   break;
        case orc:    out << "orc";  break;
        case spider: out << "giant_spider";   break;
        case slime:  out << "slime";   break;
        default:     out << "???"; break;
        // too lazy to write the rest
    }
    return out;
}

struct Monster
{
    std::string name{};
    MonsterType type{};
    int health{};
};

void printMonster( const Monster& m )
{
    std::cout << "This " << m.type << ", named " << m.name << ", has health " << m.health << '\n';
}

//------------ Question 2 -----------------------------------------

template <typename T>
struct Triad
{
    T x{};
    T y{};
    T z{};
};

// Deduction guide 
// template<typename T>
// Triad(T,T,T)->Triad<T>;


template <typename T>
void print(const Triad<T>& tri)
{
    std::cout << "[ " << tri.x << ", " << tri.y << ", " << tri.z << " ]\n";
}

// ////////////////////////////////////////
// 
int main()
{
    // -- Question 1 -------------------------------------
    Monster monster1{ "Thrag", ogre, 123 };
    Monster monster2{ "Blurp", slime, 23 };

    printMonster(monster1);
    printMonster(monster2);

    // -- Question 2 --------------------------------------
    // These 4 lines copied from the prompt should compile
    //
    Triad<int> t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad<double> t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

    //-------------------------------------------------------------------------

    return 0;
}