#include "sorting.h"
#include "auxArrayFunctions.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>

using namespace std;

/*
* Title: Algorithm Efficiency and Sorting
* Author: Muhammed Doðancan Yýlmazoðlu
* ID: 21801804
* Section: 3
* Assignment: 1
* Description: Implementation of sorting functions
*/

void insertionSort(int *arr, int size, int &compCount, int &moveCount){

  for (int unsorted = 1; unsorted < size; ++unsorted) {

    int nextItem = arr[unsorted];
    moveCount++;

    int loc = unsorted;

    for (  ;(loc > 0) && (arr[loc-1] > nextItem); --loc){
        arr[loc] = arr[loc-1];
        compCount++;
        moveCount++;
    }

    arr[loc] = nextItem;
    moveCount++;
  }
}

void partition(int *theArray, int first, int last, int &pivotIndex, int &compCount, int &moveCount) {

   int pivot = theArray[first]; // copy pivot
   moveCount++;

          // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {
      // Invariant: theArray[first+1..lastS1] < pivot
      //            theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      if (theArray[firstUnknown] < pivot) {  	// belongs to S1
          compCount++;
		  ++lastS1;
    	  swap(theArray[firstUnknown], theArray[lastS1]);
          moveCount++;
      }	// else belongs to S2
   }
   // place pivot in proper position and mark its location
   swap(theArray[first], theArray[lastS1]);
   moveCount++;
   pivotIndex = lastS1;
}

void quickSortRecur(int *theArray, int first, int last, int &compCount, int &moveCount){
    int pivotIndex;

    if (first < last) {

      // create the partition: S1, pivot, S2
    partition(theArray, first, last, pivotIndex, compCount, moveCount);

      // sort regions S1 and S2
    quickSortRecur(theArray, first, pivotIndex-1, compCount, moveCount);
    quickSortRecur(theArray, pivotIndex+1, last, compCount, moveCount);
    }
}

void quickSort(int *arr, int size, int &compCount, int &moveCount){
    quickSortRecur(arr,0,size - 1, compCount, moveCount);
}

void merge(int *theArray, int first, int mid, int last, int &compCount, int &moveCount) {

	int tempArray[last]; 	// temporary array

    int first1 = first; 	// beginning of first subarray
    int last1 = mid; 		// end of first subarray
    int first2 = mid + 1;	// beginning of second subarray
    int last2 = last;		// end of second subarray
    int index = first1; // next available location in tempArray

   for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
      if (theArray[first1] < theArray[first2]) {
         compCount++;
         tempArray[index] = theArray[first1];
         moveCount++;
         ++first1;
      }
      else {
          tempArray[index] = theArray[first2];
          moveCount++;
          ++first2;
      }
   }

	// finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index)
      tempArray[index] = theArray[first1];
      moveCount++;

   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index)
      tempArray[index] = theArray[first2];
      moveCount++;

   // copy the result back into the original array
   for (index = first; index <= last; ++index)
      theArray[index] = tempArray[index];
      moveCount++;

}

void mergesort( int *theArray, int first, int last, int &compCount, int &moveCount) {

	if (first < last) {

      int mid = (first + last)/2; 	// index of midpoint

      mergesort(theArray, first, mid, compCount, moveCount);

      mergesort(theArray, mid+1, last, compCount, moveCount);

      // merge the two halves
      merge(theArray, first, mid, last, compCount, moveCount);
   }
}

void mergeSort(int *arr, int size, int &compCount, int &moveCount){
    mergesort(arr, 0 ,size - 1, compCount, moveCount);
}


void performanceAnalysis(bool sorted){

    int moveCount[6][3] = {{0, 0},{0, 0}};
    int compCount[6][3] = {{0, 0},{0, 0}};
    double durations[6][3] = {{0, 0},{0, 0}};


    for(int i = 5000; i <= 30000; i += 5000){

        int* arr1;
        int* arr2;
        int* arr3;

        if(sorted){
            createAlreadySortedArrays(arr1, arr2, arr3, i);
        }else{
            createRandomArrays(arr1, arr2, arr3, i);
        }


        int j = 0;

        double duration = 0;

        clock_t startTime = clock();

        insertionSort(arr1,i, compCount[(i/5000) - 1][j], moveCount[(i/5000) - 1][j]);

        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        durations[(i/5000) - 1][j] = duration;
        j++;

        startTime = clock();

        mergeSort(arr2,i, compCount[(i/5000) - 1][j], moveCount[(i/5000) - 1][j]);


        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        durations[(i/5000) - 1][j] = duration;
        j++;

        startTime = clock();

        quickSort(arr3,i, compCount[(i/5000) - 1][j], moveCount[(i/5000) - 1][j]);


        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        durations[(i/5000) - 1][j] = duration;
    }

    cout << "-----------------------------------------------------" << endl;
    cout << "Part c - Time analysis of Insertion Sort" << endl;
    printf("%-15s %-16s %-15s %-15s \n", "Array Size","Time Elapsed","compCount","moveCount");

    for(int i = 0; i < 6; i++){
        printf("%-15d %-4.0lf %-10s  %-15d %-15d \n", (i+1)*5000, durations[i][0] , " ms", compCount[i][0],  moveCount[i][0]);
    }

    cout << "-----------------------------------------------------" << endl;
    cout << "Part c - Time analysis of Merge Sort" << endl;
    printf("%-15s %-16s %-15s %-15s \n", "Array Size","Time Elapsed","compCount","moveCount");

    for(int i = 0; i < 6; i++){
        printf("%-15d %-4.0lf %-10s  %-15d %-15d \n", (i+1)*5000, durations[i][1] , " ms", compCount[i][1],  moveCount[i][1]);
    }

    cout << "-----------------------------------------------------" << endl;
    cout << "Part c - Time analysis of Quick Sort" << endl;
    printf("%-15s %-16s %-15s %-15s \n", "Array Size","Time Elapsed","compCount","moveCount");

    for(int i = 0; i < 6; i++){
        printf("%-15d %-4.0lf %-10s  %-15d %-15d \n", (i+1)*5000, durations[i][2] , " ms", compCount[i][2],  moveCount[i][2]);
    }
}



