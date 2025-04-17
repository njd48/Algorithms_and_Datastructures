
#include <iostream>

// Is rand() working as I intend?

int main() {

    int N = 16;
    for (  int i = 0 ; i<N ; i++){
        std::cout << 2*(rand()%2)-1 << ' ';
    }
    std::cout << '\n';
}