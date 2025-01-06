
// 

#include <iostream>
#include <typeinfo>
#include <string>


enum Color  // establishes symbolic constants
{             
    red, 
    green, 
    blue,
};

enum CardSuits
{
    suit_clubs,
    suit_diamonds,
    suit_hearts,
    suit_spades, // suit_ reduces chances for naming colisions
};

// or use a name space
// which also helps not to pollute the global namespace
namespace feeling
{
    enum Feeling
    {
        tired,
        happy,
        blue,   //no collision with Color::blue
    };
}

namespace monster
{
    enum MonsterType
    {
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };
}

// ////////////////////////////////////////
// Functions
// 

void blueShirt(Color shirt)
{
    if (shirt == blue){
        std::cout << "Your shirt is blue\n";
    } else {
        std::cout << "Your shirt is not blue\n";
    }
    //return 0;
}

// ////////////////////////////////////////
// Main
int main()
{
    Color apple = red;
    Color shirt = Color::green;
    // Color socks = white; // error we havent defined white

    feeling::Feeling me {feeling::blue};

    blueShirt(shirt);

    // Instantiate monster
    monster::MonsterType monster1 = monster::troll;

    return 0;
}