/** lab07.h
* ===========================================================
* Name: TCS220
* Section: n/a
* Project: Lab 7 - Bubble / Shell Sorts
* ===========================================================
*/
#ifndef USAFA_CS220_S20_STUDENT_LAB07_H
#define USAFA_CS220_S20_STUDENT_LAB07_H

// constant representing size of input
#define n 8

/** -------------------------------------------------------------------
 * BubbleSort() - Perform anbubble sort on an array
 * @param numbers - the array to sort
 * @param numbersSize - the size of the array to sort
 */
void BubbleSort(int numbers[], int numbersSize);

/** -------------------------------------------------------------------
 * ShellSort() - Perform a shell sort on a an array
 * @param numbers - the array to sort
 * @param numbersSize - the size of the array to sort
 */
void ShellSort(int numbers[], int numbersSize, int gapValues[], int gapSize);

#endif //USAFA_CS220_S20_STUDENT_LAB07_H
