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
#include "rpn.h"


int main(void) {
	printf("ok this whole remote learning thing is pretty wack\n");

	// stack test
	/*
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
	*/
	
	printf("%lf", mathPowe(2, 3));

	return 0;
}
