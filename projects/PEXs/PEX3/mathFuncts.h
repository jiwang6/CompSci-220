/** mathFuncts.h
* ===========================================================
* Name: Jim Wang
* Section: T2A
* Project: Math Function Library for RPN Implementation
* ===========================================================
*/

#pragma once

#include <math.h>
#include "stackAsLinkedList.h"
#include "queueAsLinkedList.h"

/* mixed num implementation for later
typedef struct mixedNum {
    int whole;
    int num;
    int denom;
} mNum;

mNum* getFraction();
*/

/** mathAdd() - adds two arguments
 * @param arg1 - first double to be added
 * @param arg2 - second double to be added
 */
double mathAdd(double arg1, double arg2);

/** mathSub() - subtracts second argument by first
 * @param arg1 - double to be subtracted from
 * @param arg2 - double to be subtracted by
 */
double mathSub(double arg1, double arg2);

/** mathMul() - multiplies two arguments
 * @param arg1 - first double to be pultiplied
 * @param arg2 - second double to be multiplied
 */
double mathMul(double arg1, double arg2);

/** mathDiv() - divides first element by second
 * @param arg1 - double to be divided from
 * @param arg2 - double to be divided by
 */
double mathDiv(double arg1, double arg2);

/** mathPow() - takes first argument to the second element's power
 * @param arg1 - base double
 * @param arg2 - exponent double
 */
double mathPow(double arg1, double arg2);