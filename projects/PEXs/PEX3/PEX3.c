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

#include "mathFuncts.h"
#include "shuntingAlgo.h"
#include <string.h>

#include "rpn.h"



int main(void) {
	char thing = 'y';

	do {
	printf("enter infix expression:\n");
	
	char* infix = calloc(64, sizeof(char));
	
	// fgets(infix, 50, stdin);
	scanf("%[^\n]s", infix);

	QueueAsLinkedList* output = queueInit();

	toRpn(infix, output);

	queuePrintOut(output);

	printf("\n");

	queuePrint(output);

	deleteLinkedList(output);
	
	free(infix);


	printf("another?\n");
	scanf("%c", &thing);

	} while (thing == 'y');

	return 0;
}
 

/* 

issue list:
	mixed numbers don't work
	parentheses exist after popping
*/