/** lab08.h
* ===========================================================
* Name: CS220
* Section: n/a
* Project: Lab 8 - Merge Sort
* ===========================================================
*/
#ifndef USAFA_CS220_S20_STUDENT_LAB08_H
#define USAFA_CS220_S20_STUDENT_LAB08_H

// constant representing size of input
#define n 8

//function prototypes
/** -------------------------------------------------------------------
 * MergeSort() - Perform a mergesort on a portion of an array, from lBound
 * to rBound
 * @param numbers - the array to sort
 * @param lBound - the starting index of the sublist to sort
 * @param rBound - the ending index of the sublist to sort
 */
void MergeSort(int numbers[], int lBound, int rBound);

#endif //USAFA_CS220_S20_STUDENT_LAB08_H
