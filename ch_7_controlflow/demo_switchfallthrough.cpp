
//
#include <iostream>

bool isVowel(char c)
{
    switch (c)
    {
        // A case of successive 'or' comparisons 
        // by utilizing switch fallthrough
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
    }
}

int main()
{
    char c1{'o'}, c2{'w'};
    bool var1, var2;

    var1 = isVowel(c1);
    var2 = isVowel(c2);

    std::cout << c1 << " is vowel = " << var1 << '\n';
    std::cout << c2 << " is vowel = " << var2 << '\n';

    return 0;
}