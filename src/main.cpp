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

    cout << "-----------------------------------------------------" << endl;
    cout << "                  TEST ALGORITHMS                    " << endl;
    cout << "-----------------------------------------------------" << endl;

    int compCount = 0;
    int moveCount = 0;

    int arr1[16] = {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};

    insertionSort(arr1,16, compCount, moveCount);
    cout << "Move count for insertion sort: " << moveCount << endl;
    cout << "Comperison count for insertion sort: " << compCount << endl;
    displayArray(arr1, 16);

    int arr2[16] = {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    moveCount = 0;
    compCount = 0;

    mergeSort(arr2,16, compCount, moveCount);
    cout << "Move count for merge sort: " << moveCount << endl;
    cout << "Comperison count for merge sort: " << compCount << endl;
    displayArray(arr2, 16);

    int arr3[16] = {9, 5, 8, 15, 16, 6, 3, 11, 18, 0, 14, 17, 2, 9, 11, 7};
    moveCount = 0;
    compCount = 0;

    quickSort(arr3,16, compCount, moveCount);
    cout << "Move count for quick sort: " << moveCount << endl;
    cout << "Comperison count for quick sort: " << compCount << endl;
    displayArray(arr3, 16);

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "                PERFORMANCE ANALYSIS                 " << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "                     NOT SORTED                      " << endl;
    cout << "-----------------------------------------------------" << endl;

    performanceAnalysis(false);

    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "                   ALREADY SORTED                    " << endl;
    cout << "-----------------------------------------------------" << endl;

    performanceAnalysis(true);


return 0;
}
