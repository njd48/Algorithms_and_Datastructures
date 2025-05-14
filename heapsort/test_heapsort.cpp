

#include <iostream>
#include "myArray.h"
#include "heapsort.h"
#include "heapsort.cpp"



int main(){

    int N = 15;

    Array A(N);

    std::cout << "Construct an array.\n";
    buildRandArr( A );
    printArr(A);
    std::cout << "sorted?: " << isSorted(A) << '\n';

    //std::cout << "Can I build a maxHeap from this?... \n";
    //Heap H = buildHeap(A);
    //printArr(A);

    std::cout << "Can I heapSort this?... \n";
    heapSort( A );
    printArr( A );
    std::cout << "sorted?: " << isSorted(A) << '\n';
}