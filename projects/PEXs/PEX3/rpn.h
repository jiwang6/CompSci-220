/** rpn.h
* ===========================================================
* Name: Jim Wang 17 April 2020
* Section: T2A
* Project: PEX3
* Purpose: Evaluate postfix expression.
* ===========================================================
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "shuntingAlgo.h"

/** ----------------------------------------------------------
* evalRPN(); evaluates an RPN expression passed to it
	within a queue.
* @param outputQueue: queue containing RPN expression
* @return: string containing final result
*/
char* evalRPN(QueueAsLinkedList* outputQueue);


/** ----------------------------------------------------------
* evalMN(); converts a mixed number string into a double
* @param input: location of input string
* @return: double approximating the mixed number passed in
*/
double evalMN(char* input);

/** ----------------------------------------------------------
* evalF(); converts a fraction into a double
* @param input: location of input string
* @return: double approximating the fraction passed in
*/
double evalF(char* input);


/** ----------------------------------------------------------
* convertMN(); converts a decimal string into a mixed number 
	string
* @param dRes: location of string containing decimal to be
	converted
* @return: string containing mixed number representation of
	decimal
*/
char* convertMN(char* dRes);


/** ----------------------------------------------------------
* gcd(); finds gcd of two integers passed to it
* @param a: integer a 
* @param b: integer b
* @return: integer greatest common denominator of a and b
*/
int gcd(int a, int b);