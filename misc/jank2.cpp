
#include <iostream>

// function handles? alias? pointer?

int add(int x, int y) { return x + y; }

int mul(int x, int y) { return x * y; }

int invoke(int x, int y, int (*f)(int, int)) {
    return f(x, y);
}

int main() {
  
    // Pass pointers to add & mul
    // function as required
    std::cout << "Addition: ";
    std::cout << invoke(20, 10, &add) << '\n';

    std::cout << "Multiplication: ";
    std::cout << invoke(20, 10, &mul) << '\n';

    return 0;
}
