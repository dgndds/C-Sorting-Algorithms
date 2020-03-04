#include <iostream>
#include "sorting.h"
#include "auxArrayFunctions.h"

using namespace std;

int main(){
    int* arr1;
    int* arr2;
    int* arr3;

    int moveCount;
    int compCount;
    int size = 5;

    createRandomArrays(arr1, arr2, arr3, 5);

    displayArray(arr1, 5);

    quickSort(arr1,size, compCount, moveCount);

    displayArray(arr1, 5);

    return 0;
}
