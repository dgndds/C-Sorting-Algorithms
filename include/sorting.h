#ifndef SORTING_H
#define SORTING_H




    void insertionSort(int *arr, int size, int &compCount, int &moveCount);
    void quickSort(int *arr, int size, int &compCount, int &moveCount);
    void mergeSort(int *arr, int size, int &compCount, int &moveCount);
    void quickSortRecur(int *theArray, int first, int last);
    void partition(int *theArray, int first, int last, int &pivotIndex);
    void choosePivot(int *theArray, int first, int last);
    void merge(int *theArray, int first, int mid, int last);
    void mergesort( int *theArray, int first, int last);





#endif // SORTING_H
