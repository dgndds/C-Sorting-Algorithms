#ifndef SORTING_H
#define SORTING_H

/*
* Title: Algorithm Efficiency and Sorting
* Author: Muhammed Doðancan Yýlmazoðlu
* ID: 21801804
* Section: 3
* Assignment: 1
* Description: Header file of the sorting
*/

void insertionSort(int *arr, int size, int &compCount, int &moveCount);
void quickSort(int *arr, int size, int &compCount, int &moveCount);
void mergeSort(int *arr, int size, int &compCount, int &moveCount);
void quickSortRecur(int *theArray, int first, int last, int &compCount, int &moveCount);
void partition(int *theArray, int first, int last, int &pivotIndex, int &compCount, int &moveCount);
void choosePivot(int *theArray, int first, int last);
void merge(int *theArray, int first, int mid, int last, int &compCount, int &moveCount);
void mergesort( int *theArray, int first, int last, int &compCount, int &moveCount);
void performanceAnalysis(bool sorted);

#endif // SORTING_H
