
//

#include <iostream>
#include <iterator>
//#include <typeinfo>
//#include <string>
//#include <time.h>

int getInput()
{
    bool ass = 1;
    int input;

    while (ass) {
    
        std::cout << "Enter an integer between 1 and 9...\n";
        std::cin >> input;

        //
        if (input<=9 && 1<=input ) {
            ass=0;
        } else if (input > 9) {
            std::cout << "too large\n";
        } else {
            std::cout << "too small\n";
        }

    }
    return input;
}

int main()
{
    constexpr int scores[]{ 84, 92, 76, 81, 56};
    constexpr int numStudents{ static_cast<int>(sizeof(scores)/sizeof(scores[0]) )};

    int totalScore = 0;

    // calculate average
    for (int j = 0; j<numStudents; j++){
        totalScore += scores[j];
        std::cout << j << ":  " << scores[j] <<'\n';
    }
    auto averageScore = static_cast<double>(totalScore)/numStudents;

    // calculate max
    int maxScore{0};
    for (int j = 0; j<numStudents; j++){
        if (scores[j] > maxScore) {
            maxScore = scores[j];
        }
    }

    std::cout << "avg score: " << averageScore <<'\n';
    std::cout << "max score: " << maxScore <<'\n';

    // ------------------------------------------------------------
    // Quiz
    //
    constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    constexpr int M{ static_cast<int>(sizeof(array)/sizeof(array[0]) ) };

    int indexval{};

    int input = getInput();

    for (int j = 0; j<M; j++)
    {
        if (input == array[j])
        {
            indexval = j;
            break;
        }
    }
    std::cout << input << " is located in index " << indexval <<'\n';

    // calculate max
    // by storing max index
    int maxIndex{0};
    for (int j = 0; j<numStudents; j++){
        if (scores[j] > scores[maxIndex]) {
            maxIndex = j;
        }
    }
    std::cout << "max score: " << scores[maxIndex] <<'\n';


    return 0;
}