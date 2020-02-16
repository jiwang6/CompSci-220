/** lab09.h
* ===========================================================
* Name: CS220
* Section: n/a
* Project: Lab 9 - Quick Sort
* ===========================================================
*/
#ifndef USAFA_CS220_S20_STUDENT_LAB09_H
#define USAFA_CS220_S20_STUDENT_LAB09_H

// constant representing size of input
#define n 8

//function prototypes
/** -------------------------------------------------------------------
 * quickSort() - Perform a quick sort on a portion of an array, from lBound
 * to rBound
 * @param array - the array to sort
 * @param lBound - the starting index of the sublist to sort
 * @param rBound - the ending index of the sublist to sort
 */
void quickSort(int array[], int lBound, int rBound);

#endif //USAFA_CS220_S20_STUDENT_LAB09_H
