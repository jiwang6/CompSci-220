/** lab06.c
* ===========================================================
* Name: Troy Weingart and David Caswell
* Section: n/a
* Project: Lab 6 - Selection / Insertion Sorts
* ===========================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab06.h"

// Local function prototypes
void fillArray(int array[]);
void swap(int* x, int* y);
void print(int nums[]);

int main() {
//    int nums[n];
    int nums[] = {6,2,22,17,3,38,10,4};
//    int nums[] = {7,3,1,15,13,9,5,11};

//    fillArray(nums);
    //SelectionSort(nums, n);
    //print(nums);

    // fillArray(nums);
    InsertionSort(nums, n);
//    print(nums);

    return 0;
}

/** -------------------------------------------------------------------
 * InsertionSort() - Perform an insertion sort on an array
 * @param numbers - the array to sort
 * @param numberSize - the size of the array to sort
 */
void InsertionSort(int numbers[], int numbersSize) {
    //int insertElem = 0;
    for (int i = 1; i < numbersSize; i++ ) {
        print(numbers);
        //insertElem = numbers[i]; // the item to insert
        int j = i;
        while (j > 0 && numbers[j] < numbers[j-1]) {   // move values up until we find the insertion
            swap(&numbers[j], &numbers[j-1]);
            //numbers[j+1] = numbers[j];                  // point
            j--;
        }
        //array[j+1] = insertElem;    // put the value in the empty slot
    }
}

/** -------------------------------------------------------------------
 * SelectionSort() - Perform an selection sort on an array
 * @param numbers - the array to sort
 * @param numberSize - the size of the array to sort
 */
void SelectionSort(int numbers[], int numbersSize) {
    int smallest = 0;
    int indexSmallest = 0;
    // process the array from left to right
    for (int i = 0; i < n - 1; i++) {
        // look for smallest value in the array

        indexSmallest = i;
        for (int j = i + 1; j < numbersSize; j++) {
            if (numbers[j] < numbers[indexSmallest]) {
                indexSmallest = j;
            }
        }
        // once found swap it with the value in the ith
        // position
        swap(&numbers[i],&numbers[indexSmallest]);
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
    // fill array with random ints from 0 to 29
    for (int i = 0; i < n; i++) {
        array[i] = (int) rand() % 30;
    }
}

void print(int nums[]) {
    printf("{");
    for (int i=0;i<n;i++) {
        if (i < n - 1)  {
            printf("%d, ",nums[i]);
        }
        else {
            printf("%d}", nums[i]);
        }
    }
    printf("\n");
}