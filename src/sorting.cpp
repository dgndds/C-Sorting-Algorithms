#include "sorting.h"
#include <iostream>
#include <string>

using namespace std;

void insertionSort(int *arr, int size, int &compCount, int &moveCount){

    for (int unsorted = 1; unsorted < size; ++unsorted) {

    int nextItem = arr[unsorted];


    for ( int loc = unsorted ;loc > 0; --loc){
        arr[loc] = arr[loc-1];

        if(arr[loc-1] > nextItem){
            arr[loc] = nextItem;
        }
    }
  }


}

//void choosePivot(int *theArray, int first, int last){
//    int temp = theArray[0];
//    theArray[0] = theArray[first];
//    theArray[first] = temp;
//}

void partition(int *theArray, int first, int last, int &pivotIndex) {

	// place pivot in theArray[first]
//   choosePivot(theArray, first, last);

   int pivot = theArray[first]; // copy pivot

          // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {
      // Invariant: theArray[first+1..lastS1] < pivot
      //            theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      if (theArray[firstUnknown] < pivot) {  	// belongs to S1
		  ++lastS1;
    	  swap(theArray[firstUnknown], theArray[lastS1]);
      }	// else belongs to S2
   }
   // place pivot in proper position and mark its location
   swap(theArray[first], theArray[lastS1]);
   pivotIndex = lastS1;
}

void quickSortRecur(int *theArray, int first, int last){
    int pivotIndex;

    if (first < last) {

      // create the partition: S1, pivot, S2
    partition(theArray, first, last, pivotIndex);

      // sort regions S1 and S2
    quickSortRecur(theArray, first, pivotIndex-1);
    quickSortRecur(theArray, pivotIndex+1, last);
    }
}

void quickSort(int *arr, int size, int &compCount, int &moveCount){


    quickSortRecur(arr,0,size - 1);
}

void merge(int *theArray, int first, int mid, int last) {

	int tempArray[last]; 	// temporary array

    int first1 = first; 	// beginning of first subarray
    int last1 = mid; 		// end of first subarray
    int first2 = mid + 1;	// beginning of second subarray
    int last2 = last;		// end of second subarray
    int index = first1; // next available location in tempArray

   for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
      if (theArray[first1] < theArray[first2]) {
         tempArray[index] = theArray[first1];
         ++first1;
      }
      else {
          tempArray[index] = theArray[first2];
          ++first2;
      }
   }

	// finish off the first subarray, if necessary
   for (; first1 <= last1; ++first1, ++index)
      tempArray[index] = theArray[first1];

   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index)
      tempArray[index] = theArray[first2];

   // copy the result back into the original array
   for (index = first; index <= last; ++index)
      theArray[index] = tempArray[index];

}

void mergesort( int *theArray, int first, int last) {

	if (first < last) {

      int mid = (first + last)/2; 	// index of midpoint

      mergesort(theArray, first, mid);

      mergesort(theArray, mid+1, last);

      // merge the two halves
      merge(theArray, first, mid, last);
   }
}

void mergeSort(int *arr, int size, int &compCount, int &moveCount){
    mergesort(arr, 0 ,size - 1);
}






