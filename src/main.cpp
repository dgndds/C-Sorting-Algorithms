#include <iostream>
#include <ctime>
#include "sorting.h"
#include "auxArrayFunctions.h"

using namespace std;

/*
* Title: Algorithm Efficiency and Sorting
* Author: Muhammed Doðancan Yýlmazoðlu
* ID: 21801804
* Section: 3
* Assignment: 1
* Description: main and tests
*/

int main(){
    int compCount = 0;
    int moveCount = 0;

    int arr[16] = {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};

    insertionSort(arr,16, compCount, moveCount);
    cout << "Move count for insertion sort: " << moveCount << endl;
    cout << "Comperison count for insertion sort: " << compCount << endl;
    displayArray(arr, 16);

//    arr = {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    moveCount = 0;
    compCount = 0;

    mergeSort(arr,16, compCount, moveCount);
    cout << "Move count for merge sort: " << moveCount << endl;
    cout << "Comperison count for merge sort: " << compCount << endl;
    displayArray(arr, 16);

   // arr = {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    moveCount = 0;
    compCount = 0;

    quickSort(arr,16, compCount, moveCount);
    cout << "Move count for quick sort: " << moveCount << endl;
    cout << "Comperison count for quick sort: " << compCount << endl;
    displayArray(arr, 16);

//    int moveCount = 0;
//    int compCount = 0;
//    int size = 5;

    //createRandomArrays(arr1, arr2, arr3, 5000);

//    displayArray(arr1, 5);
//
//    mergeSort(arr1,size, compCount, moveCount);
//
//    displayArray(arr1, 5);
//
//    cout << "Move count: " << moveCount << endl;
//    cout << "Comp count: " << compCount << endl;
//
//performanceAnalysis();

//createRandomArrays(arr1, arr2, arr3, 15000);
//
//        double duration = 0;
//
//        clock_t startTime = clock();
//
//        mergeSort(arr1,15000,compCount,moveCount);
//
//        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
//
//displayArray(arr1, 5);
//cout << "Move count: " << moveCount << endl;
//cout << "Comp count: " << compCount << endl;
//cout << "Duration: " << duration << " ms" << endl;

return 0;
}
