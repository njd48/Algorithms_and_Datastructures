//

#include <iostream>

struct Card
{
    int val;
    char suit;
};

void printCard( Card card)
{
    char *value[8];
    char *suit[8];

    switch (card.suit)
    {
        case 's':
            suit = "spades";
        case 'c':
            suit = "clubs";
        case 'h':
            suit = "hearts";
        case 'd':
            suit = "diamonds";
        default:
            std::cout << "error: suit not defined\n";
            return;
    }

    switch (card.val)
    {
        case 1:
            value = "ace";
        case 11:
            value = "jack";
        case 12:
            value = "queen";
        case 13:
            value = "king";
        default:  
            value = static_cast<char>(card.val);
    }

    
    std::cout << "In Print()\n";
}

int main()
{
    
    Card var{ 1, 'c'};

    printCard(var);

    return 0;
}
