/** shuntingAlgo.h
* ===========================================================
* Name: Jim Wang 17 April 2020
* Section: T2A
* Project: PEX3
* Purpose: Validate, interpret, and convert an infix
	expression to postfix.
* ===========================================================
*/

#pragma once

#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mathFuncts.h"

/** ----------------------------------------------------------
* toRPN(); Accepts an infix expression and outputs the outfix
	conversion into a queue.
* @param infix: pointer to infix expression
* @param outputQueue: queue housing converted postfix 
	expression
* @return: returns true when done
*/
bool toRpn(char* infix, QueueAsLinkedList* outputQueue);


/** ----------------------------------------------------------
* mathOp(); Checks if a character "test" is a valid math 
	operator
* @param test: Character to be checked
* @return: true if a valid algebraic operation
*/
bool mathOp(char test);

/** ----------------------------------------------------------
* precedence(); returns the precedence of a math operation to 
	determine order of operations. Opertaions that are 
	calculated first have highest precedence.
* @param token: operator to be checked
* @return: integer precedence of a math operation
*/
int precedence(char token);


/** ----------------------------------------------------------
* preprocess(); appends a null byte to a passed string
* @param infix: address of passed string
*/
void preprocess(char* infix);

/** ----------------------------------------------------------
* isValid(); checks if passed string is valid
	algebraic expression
* @param infix: address of passed string
* @return: true if valid, false if not
*/
bool isValid(char* infix);
