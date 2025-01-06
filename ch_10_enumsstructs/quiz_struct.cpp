
// 

#include <iostream>
#include <typeinfo>
#include <string>

// Define struct Advert and functions
struct Advert
{
    int views{};
    double perc_clicked {};
    double clickvalue{};
};

void printAdRevenue(Advert& ad)
{
    std::cout << "no. ads viewed:      " << ad.views << '\n';
    std::cout << "perc. ads clicked:   " << ad.perc_clicked << "% \n";
    std::cout << "income from each ad: " << ad.clickvalue << '\n';
    double total_earning = (ad.clickvalue)*(ad.perc_clicked/100)*((double)ad.views);
    std::cout << "Total earnings:      " << total_earning << '\n';
}


// Define struct 'fraction' and functions
struct Fraction
{
    int num{};
    int denom{1};
};

void readInFraction(Fraction& input)
{
    std::cout <<"input a fraction:  numerator = ...\n";
    std::cin  >> input.num;
    std::cout <<"Denominator = ...\n";
    std::cin  >> input.denom;
}

Fraction mult( const Fraction& x, const Fraction& y )
{
    return { x.num*y.num, x.denom*y.denom };
}

void printFraction(Fraction& x )
{
    std::cout << "Result:  " << x.num << '/' << x.denom <<'\n';
}

// ////////////////////////////////////////
// 
int main()
{
    // ----------------------------------------------------------
    Advert advert{};
    std::cout << "How many ads were viewed by users?...\n";
    std::cin  >> advert.views;
    std::cout << "What percentage did viewers click on?...\n";
    std::cin  >> advert.perc_clicked;
    std::cout << "How much money is made per ad click?...\n";
    std::cin  >> advert.clickvalue;

    printAdRevenue(advert);

    // ----------------------------------------------------------
    // ----------------------------------------------------------
    Fraction frac1{};
    Fraction frac2{};
    Fraction result{};
    readInFraction(frac1);
    readInFraction(frac2);

    result = mult(frac1, frac2);

    printFraction(result);

    return 0;
}