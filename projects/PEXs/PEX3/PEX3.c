/** PEX3.c
* ===========================================================
* Name: Jim Wang 17 April 2020
* Section: T2A
* Project: PEX3
* Purpose: Convert infix expression to postfix and evaluate.
* Documentation:
* 	Code heavily references course-provided linked list, stack,
	and queue. This was used in the ADT libraries.
*	Received EI with Dr. Wilkinson for the shunting algo. This 
	helped tokenize my input.
*	Asked C3C Brummett and C3C Gills about methods of 
	converting to and evaluating RPN string.
* ===========================================================
*/

#include "mathFuncts.h"
#include "shuntingAlgo.h"
#include "rpn.h"


int main(void) {
	printf("RPN Calculator: \nThis calculator accepts algebraic expressions in human-readable or \"infix\" notation\n"
		"and converts it to a more machine-readable \"postfix\" notation. Additionally, it \n"
		"calculates the result of your input expression."
		"\n\nYour expression must be a valid algebraic expression ( ex: 1 + (3/2 - 2) ^ 5 )."
		"\nTo quit, enter a blank expression.\n\n");

	char* infix = calloc(64, sizeof(char)); // input buffer

	// initial prompt
	printf("Enter infix expression: ");
	fgets(infix, 63, stdin);

	preprocess(infix); // append null byte

	while (!isValid(infix) && (infix[0] != '\0')) { // input loop
		printf("Invalid input, try again: ");
		fgets(infix, 63, stdin);
		preprocess(infix);
	}

	while(infix[0] != '\0') { // continue until blank expression entered
		
		QueueAsLinkedList* output = queueInit();
		toRpn(infix, output);
		 		 printf("RPN: ");
 		queuePrintOut(output);
		// queuePrint(output);
		printf("\n");
				
 		char* result = evalRPN(output);
		printf("Evaluated expression: %s\n", result);
				 free(result);
		deleteLinkedList(output);
		free(infix);
		infix = calloc(64, sizeof(char));

		// check input 
		printf("Enter infix expression: ");
		fgets(infix, 63, stdin);

		preprocess(infix);
		while (!isValid(infix) && (infix[0] != '\0')) { 
			printf("Invalid input, try again: ");
			fgets(infix, 63, stdin);
			preprocess(infix);
		}

	}

	free(infix);

	return 0;
}