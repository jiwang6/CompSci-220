/** pex3.c
* ===========================================================
* Name: Jim Wang
* Section: T2A
* Project: PEX3
* Purpose:
	PEX3 main driver
* Documentation:
* 	heavily referenced course-provided linked list, stack, and queue 
* ===========================================================
*/

// put ascii codes for numbers into ADTs

#include "mathFuncts.h"
#include "shuntingAlgo.h"
#include "rpn.h"


int main(void) {

	LinkedList* list =  createLinkedList();

	appendElementLinkedList(list, "12");

	printLinkedList(list);
	

	StackAsLinkedList* stack = stackInit();

	stackPush(stack, "fuck");
	stackPush(stack, "this");
	stackPush(stack, "pex");
	stackPush(stack, "1/2");


	stackPrint(stack);


	printf("%s\n", stackPop(stack));
	stackPrint(stack);

	QueueAsLinkedList* queue = queueInit();

	queueEnqueue(queue, "bruh");
	queueEnqueue(queue, "uh");
	queueEnqueue(queue, "ree");
	queueEnqueue(queue, "3.14/qtpie");

	queuePrint(queue);
	printf("%s\n", queueDequeue(queue));



	queuePrint(queue);

	/*
	char* infix = malloc(51 * sizeof(char)); // create input buffer
	printf("enter your godforsaken expression: \n");

	//scanf("%s", infix); // prolly not a good idea - sscanf later

	fgets(infix, 50, stdin);

	// end of main function

	char* delim = " ";

	char* token;
	char* reset = infix;

	// create ADTs

	StackAsLinkedList* opStack = stackInit(); // operator stack
	QueueAsLinkedList* opQueue = queueInit(); // operand queue

	

	// testing tokenizing and blind sort
		
	printf("\ntoken: \"%s\"\n", delim);
	token = strtok(infix, delim);
	// tokenizing string
	while (token != NULL) {
		printf("%s\n", token); // print token to be pushed/enqueued
		if (isdigit(*token)) {
			queueEnqueue(opQueue, *token);
			queueEnqueue(opQueue, *token+1);
			printf("digit\n");
		} else {
			stackPush(opStack, *token);
		}
		token = strtok(NULL, delim);
	}

	// print out ADTs
	printf("operator stack:\n");
	stackPrint(opStack);
	printf("operand queue:\n");
	queuePrint(opQueue);


	free(infix);

	deleteLinkedList(opStack);
	deleteLinkedList(opQueue);

	*/
	/*
	// print to buffer to check good
	printf("input buffer:\n");
	while (temp1 != '\n') { // iterate through every character

		printf("%c", *temp1);

		temp1++;
	}

	temp1 = infix;

	printf("\n");

	// blind sort into stack and queue - ignoring order of operations, mixed numbers, etc
	while (*temp1) { // iterate through every character
		if (isdigit(*temp1) || ((*temp1 == '-' || *temp1 == '+') && isdigit(*(temp1 + 1)))) { // conditional looks for integers and converts from string into int
			// Found a number
			int val = strtol(temp1, &temp1, 10); // Read number
			char valc[30];
			sprintf(valc, "%c", val);
			queueEnqueue(operands, *valc);
		} else if (*temp1 != ' ') {
			stackPush(operators, *temp1);
		}
	temp1++;
	}
	
	// print out ADTs
	printf("operator stack:\n");
	stackPrint(operators);
	printf("operand queue:\n");
	queuePrint(operands);

	// shove stack onto queue
	while (!stackIsEmpty(operators)) {
		queueEnqueue(operands, stackPop(operators));
	}

	// print out ADTs
	printf("operator stack:\n");
	stackPrint(operators);
	printf("output queue:\n");
	queuePrint(operands);

	double* postfix = malloc(51 * sizeof(double)); // is this necessary? might have better luck with just keeping in adt and considering indiv nodes rather than dealing w string
	double* temp2 = postfix;

	while (!queueIsEmpty(operands)) { // while queue is not empty
		*temp2 = queueDequeue(operands); // load values into temp2
		temp2++;
	}

	*temp2 = '\0';

	temp2 = postfix;

	// print rpn
	printf("\nrpn:\n");

	while (*temp2) { // iterate through every character
		if (1) { // if long
			printf("%lf0 ", *temp2);
		} else {
			printf("%c ", (char)*temp2);
		}

		temp2++;
	}


	free(infix);
	free(postfix);

	deleteLinkedList(operators);
	deleteLinkedList(operands);

	*/
	



	return 0;
}
 