/** lab06.c
* ===========================================================
* Name: Jim Wang
* Section: T2A
* Project: Lab 6 - in place merge sort
* ===========================================================
* Instructions:
*    1) Complete TASKS Below
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab08.h"

// Local function prototypes
void fillArray(int array[]);
void swap(int* x, int* y);
void Merge(int array[], int lBound, int mid, int rBound);
void print(int nums[]);

int main() {

    int nums[] = {12,7,28,2,10,4,42,8};

     /* TASK 0 - implement the function, mergeSort() below
      *  Help - the merge prototype is given to you above
      */
    // fillArray(nums);
    // print(nums, N);

    print(nums);
    printf("\n");

    MergeSort(nums,0,n-1);
    
    printf("\n");
    print(nums);

    return 0;
}

/**
 * Merge() - Given two sorted sublists array[lBound..mid] and array[mid+1..rBound],
 * merge them into a single sorted list in array[lBound..rBound]
 * @param array - the array to sort
 * @param lBound - the lowest index of the first sublist
 * @param mid - the highest index of the first sublist
 * @param rBound - the highest index of the second sublist
 */
void Merge(int numbers[], int lBound, int mid, int rBound) {
    int lBound2 = mid + 1; // lowest index of the second sublist

    // exit condition if highest in first sublist is \leq than lowest in second sublist
    if (numbers[mid] <= numbers[lBound2]) 
        return;
    
    // loop condition: bounds do not cross
    while (lBound <= mid && lBound2 <= rBound) {
        // if element 1 is in the right place, increment element
        if (numbers[lBound] <= numbers[lBound2]) { 
            lBound++;
        } else {
            int value = numbers[lBound2]; // value to be moved into the front of the array
            int index = lBound2;

            // moving all numbers in first array left one, overrides value to be moved
            while (index != lBound) {
                numbers[index] = numbers[index - 1];
                index--;
            }
            numbers[lBound] = value; // finally moves value to front of the array

            // increment EVERYTHING!
            lBound++;
            lBound2++;
            mid++;
        }
    }


}

/** -------------------------------------------------------------------
 * MergeSort() - Perform a mergesort on a portion of an array, from lBound
 * to rBound
 * @param array - the array to sort
 * @param lBound - the starting index of the sublist to sort
 * @param rBound - the ending index of the sublist to sort
 */
void MergeSort(int numbers[], int lBound, int rBound) {
    if (lBound < rBound) {
        int m = (lBound + (rBound - 1)) / 2; // avoids overflow error

        
        MergeSort(numbers, lBound, m); // call sort on first half
        MergeSort(numbers, m + 1, rBound); // call sort on second half

        Merge(numbers, lBound, m, rBound); // merge first and second halves
        print(numbers);
    }
}

//swaps two integer values
void swap(int* x, int* y) {
    int temp;

    temp = *y;
    *y = *x;
    *x = temp;
}

//fills an array of size n with random values
void fillArray(int array[]) {
    //set up for and then seed random number
    //generator
    //static int seedDone = 0; //static variables retain their value between calls

    // modified so the seed is only done once
    /* if (!seedDone) {
        struct timespec time;
        clock_gettime(CLOCK_REALTIME, &time);
        srandom((unsigned) (time.tv_nsec ^ time.tv_sec));
        seedDone = 1;
    }
    */

    // fill array with random ints from 0 to 99
    for (int i = 0; i < n; i++) {
        array[i] = (int) rand() % 100;
    }
}

void print(int nums[]) {
    printf("{");
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            printf("%d, ", nums[i]);
        }
        else {
            printf("%d}", nums[i]);
        }
    }
    printf("\n");
}