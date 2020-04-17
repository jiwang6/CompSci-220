#include "shuntingAlgo.h"

bool toRpn(char* infix, QueueAsLinkedList* outputQueue) {
	char* token = calloc(256, sizeof(char));
	bool lastWasOperator = true;
	StackAsLinkedList* operatorStack = stackInit();

	for (char* ptr = infix, *tmpPtr = NULL; *ptr != '\0'; ptr++) { // set pointer to infix start; until pointer hits end; increment by 1
		token = calloc(256, sizeof(char)); // zero out token
		while(*ptr == ' ') // skip space
			ptr++;
		if (lastWasOperator && (*ptr == '-' || isdigit(*ptr))) { // expecting number, handles numbers
			tmpPtr = ptr + 1; // look ahead
			while ((!amIaMathOperator(*tmpPtr) || *tmpPtr == '/') && *tmpPtr != ' ' && *tmpPtr != '\0') // double digit numbers
				tmpPtr++; // move until tmpPtr hits end of number, most likely ' '
			if (*tmpPtr == ' ' && isdigit(*(tmpPtr + 1))) { // handles mixed numbers
				tmpPtr++; // moves to first digit of numberator
				tmpPtr = strchr(tmpPtr, '/') + 1; // strstr(tmpPtr, '/') + 1 // finds address of '/'
				while (isdigit(*tmpPtr)) // move until end of denom
					tmpPtr++;
			}
			strncpy(token, ptr, (int)(tmpPtr - ptr)); //copy entire denom

			// enqueue 
			queueEnqueue(outputQueue, token);
			lastWasOperator = false;
			ptr = tmpPtr - 1;
		} else {
			lastWasOperator = true; // handles operators
			token[0] = *ptr;
			if (*ptr == '(') {
				stackPush(operatorStack, "(");
				lastWasOperator = true;
			} else if (*ptr == ')') { 
				while (!stackIsEmpty(operatorStack) && ('(' != (stackPeek(operatorStack)[0]))) { // empty or until it hits '(', whatever first
					strcpy(token, stackPop(operatorStack)); // might be breaking here
					queueEnqueue(outputQueue, token);
				}
				
				if ('(' != stackPeek(operatorStack)[0]) {
					char* pH = stackPop(operatorStack);
					free(pH);
				}
				
				if (stackIsEmpty(operatorStack))
					return false;
				else
					strcpy(token, stackPop(operatorStack));
				lastWasOperator = false;
			} else { // handle all other operators
				int prec = precedence(token[0]);
				char temp[2];
				while (!stackIsEmpty(operatorStack) && (prec <= precedence(stackPeek(operatorStack)[0]))) { // pop into queue
					strcpy(temp, stackPop(operatorStack)); // error shouldn't be enqueuing (
					queueEnqueue(outputQueue, temp);
				}
				stackPush(operatorStack, token);
			}		
		} 
	}

	// empty remaining stack into queue
	while (!stackIsEmpty(operatorStack)) {
		strcpy(token, stackPop(operatorStack));
		queueEnqueue(outputQueue, token);
	}
	return true;
}

bool amIaMathOperator(char potOp) {
	char arr[] = "*/+-^()";

	if (strchr(arr, potOp)) {
		return true;
	} else {
		return false;
	}
}

int precedence(char token) {
	switch (token) {
		case '(':
		case ')':
			return 0;
			break;
		case '^':
			return 3;
			break;
		case '*':
		case '/':
			return 2;
			break;
		case '+':
		case '-':
			return 1;
			break;
		default:
			return -1;
			break;
	}
}