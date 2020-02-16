/** lab09.c
* ===========================================================
* Name: Troy Weingart and David Caswell
* Section: n/a
* Project: Lab 9 - Quick Sort
* ===========================================================
* Instructions:
*    1) Complete TASKS Below
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab09.h"

// Local function prototypes
void fillArray(int array[]);
void swap(int *x, int *y);
int partition(int numbers[], int lBound, int rBound);
void print(int nums[]);

int main() {
//    int nums[N];
//    int nums[] = {8,4,2,16,14,10,6,12};
    int nums[] = {10,3,2,11,17,1,9,6};

//    fillArray(nums);
    print(nums);
    printf("\n");

    quickSort(nums, 0, n - 1);



    return 0;
}

/**
 * partition() - partition the sublist in to two lists
 * of elements larger and smaller than the selected pivot
 * @param array - the array to sort
 * @param lBound - the left bound of the sublist
 * @param rBound - the right bound of the sublist
 */
int partition(int numbers[], int lBound, int rBound) {
    int midpoint = lBound + (rBound - lBound) / 2;
    int pivot = numbers[midpoint];
    int l = lBound;
    int h = rBound;

    printf("%d\n", pivot);

    int done = 0;
    while (done == 0)
    {
        // increment l while numbers[l] < pivot
        while (numbers[l] < pivot) {
            l++;
        }

        // Decrement h while pivot < numbers[h]
        while (pivot < numbers[h]) {
            h--;
        }

        // If there are zero or one elements remaining,
        // all numbers are partitioned.  Return h
        if (l >= h) {
            done = 1;
        }
        else
        {
            swap(&numbers[l], &numbers[h]);

            l++;
            h--;
        }
    }
    return h;
}

/** -------------------------------------------------------------------
 * quickSort() - Perform a quick sort on a portion of an array, from lBound
 * to rBound
 * @param array - the array to sort
 * @param lBound - the starting index of the sublist to sort
 * @param rBound - the ending index of the sublist to sort
 */
void quickSort(int numbers[], int lBound, int rBound) {
    if (lBound >= rBound) { return; }

    int divPt = partition(numbers, lBound, rBound);
    print(numbers);
    quickSort(numbers, lBound, divPt);
    quickSort(numbers, divPt + 1, rBound);

}

/** ----------------------------------------------------------
 * fillArray() - fills array with random ints from 0 - N-1
 * @param array is the array of integers
 * ----------------------------------------------------------
 */
void fillArray(int array[]) {
    //set up for and then seed random number
    //generator
    static int seedDone = 0; //static variables retain their value between calls


    // fill array with random ints from 0 to 99
    for (int i = 0; i < n; i++) {
        array[i] = (int) rand() % 100;
    }
}

//swaps two integer values
void swap(int *x, int *y) {
    int temp;

    temp = *y;
    *y = *x;
    *x = temp;
}

/* 
void print(int nums[],int n) {
    for (int i=0;i<n;i++) {
        printf("%d ",nums[i]);
    }
    printf("\n");
}
*/

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