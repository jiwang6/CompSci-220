/** mathFuncts.c
* ===========================================================
* Name: Jim Wang
* Section: T2A
* Project: Math Function Library for RPN Implementation
* Documentation: Heavily referenced provided course matrieral
* for ADT implementation
* ===========================================================
*/

#include "mathFuncts.h"

double mathAdd(double arg1, double arg2) {
	return arg1 + arg2;
}

double mathSub(double arg1, double arg2) {
	return arg1 - arg2;
}

double mathMul(double arg1, double arg2) {
	return arg1 * arg2;
}

double mathDiv(double arg1, double arg2) {
	return arg1 / arg2;
}

double mathPow(double arg1, double arg2) {
	return pow(arg1, arg2);
}