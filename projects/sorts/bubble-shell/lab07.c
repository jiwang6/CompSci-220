/** lab07.c
* ===========================================================
* Name: Troy Weingart and David Caswell
* Section: n/a
* Project: Lab 7 - Bubble / Shell
* ===========================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab07.h"


// Local function prototypes
void fillArray(int array[]);
void swap(int* x, int* y);
void print(int nums[]);
void InsertionSortInterleaved(int numbers[], int numbersSize, int startIndex, int gap);

int main() {
//    int nums[n];
    int nums[] = {8,4,2,16,14,10,6,12};
//    int nums[] = {7,3,1,15,13,9,5,11};

//    fillArray(nums);
    printf("Bubble Sort\n");
    BubbleSort(nums, n);
    print(nums);

    printf("\n Shell Sort\n");
    int gapValues[] = {5,3,1};  // number/size of sets to sort
    // fillArray(nums);
    ShellSort(nums, n, gapValues, 3);
    print(nums);
    return 0;
}

/** -------------------------------------------------------------------
 * BubbleSort() - Perform anbubble sort on an array
 * @param numbers - the array to sort
 * @param numbersSize - the size of the array to sort
 */
void BubbleSort(int numbers[], int numbersSize)
{
    for (int i = 0; i < numbersSize -1;i++)
    {
        for (int j = 0; j< numbersSize -i -1;j++)
        {
            if (numbers[j] > numbers[j+1])
            {
                swap(&numbers[j], &numbers[j+1]);
            }
        }
    }
}


void InsertionSortInterleaved(int numbers[], int numbersSize, int startIndex, int gap) {
    for (int i = startIndex + gap; i < numbersSize; i = i + gap) {
        int j = i;
        while (j - gap >= startIndex && numbers[j] < numbers[j - gap]) {
            swap(&numbers[j], &numbers[j - gap]);
            j = j - gap;
        }
    }
}

/** -------------------------------------------------------------------
 * ShellSort() - Perform a shell sort on a an array
 * @param numbers - the array to sort
 * @param numbersSize - the size of the array to sort
 */
void ShellSort(int numbers[], int numbersSize, int gapValues[], int gapValuesSize) {
    for (int gapIndex = 0; gapIndex < gapValuesSize; gapIndex++)
    {
        for (int i = 0; i < gapValues[gapIndex]; i++)
        {
            InsertionSortInterleaved(numbers, numbersSize, i, gapValues[gapIndex]);
        }
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
    for (int i=0;i<n;i++) {
        printf("%d ",nums[i]);
    }
    printf("\n");
}