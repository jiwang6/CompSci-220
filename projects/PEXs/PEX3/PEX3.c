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
	char* infix = malloc(51 * sizeof(char)); 
	printf("enter your godforsaken expression: \n");

	//scanf("%s", infix);

	fgets(infix, 50, stdin);

	char* temp1 = infix;

	StackAsLinkedList* operators = stackInit();
	QueueAsLinkedList* operands = queueInit();

	// print input buffer
	while (*temp1) { // iterate through every character

		printf("%c", *temp1);

		temp1++;
	}

	temp1 = infix;

	printf("\n");

	// blind sort into stack and queue
	while (*temp1) { // iterate through every character
		if (isdigit(*temp1) || ((*temp1 == '-' || *temp1 == '+') && isdigit(*(temp1 + 1)))) {
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

	double* postfix = malloc(51 * sizeof(double));
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

	

	/*
	// stack test
	
	StackAsLinkedList * s = stackInit();
	
	if (stackIsEmpty(s))
		printf("empty stack\n");

	stackPush(s, 0);
	stackPush(s, 1);
	stackPush(s, 2);

	stackPrint(s);
	printf("stack has %d nodes\n", stackSize(s));
	printf("top element: %lf\n", stackPeek(s));

	if (!stackIsEmpty(s))
		printf("not empty stack\n");

	printf("popped: %lf\n", stackPop(s));
	stackPrint(s);
	printf("stack has %d nodes\n", stackSize(s));
	printf("top element: %lf\n\n", stackPeek(s));
	


	// queue test

	QueueAsLinkedList* q = queueInit();
	
	if (queueIsEmpty(q))
		printf("empty queue\n");

	queueEnqueue(q, 0.5);
	queueEnqueue(q, 1.5);
	queueEnqueue(q, 2.5);

	queuePrint(q);
	printf("queue has %d nodes\n", queueSize(q));
	printf("front element: %lf\n", queuePeek(q));

	if (!queueIsEmpty(q))
		printf("not empty queue\n");

	printf("dequeued: %lf\n", queueDequeue(q));
	queuePrint(q);
	printf("queue has %d nodes\n", queueSize(q));
	printf("front element: %lf\n", queuePeek(q));
	
	
	printf("%lf", mathPow(2, 3));
	*/

	return 0;
}
