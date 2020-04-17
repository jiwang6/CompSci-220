/** shuntingAlgo.h
* ===========================================================
* Name: Jim Wang 17 April 2020
* Section: T2A
* Project: PEX3
* Purpose: Validate, interpret, and convert an infix 
	expression to postfix.
* ===========================================================
*/

#include "shuntingAlgo.h"	

bool toRpn(char* infix, QueueAsLinkedList* outputQueue) {
	char* token = calloc(256, sizeof(char));
	bool lastWasOperator = true;
	StackAsLinkedList* operatorStack = stackInit();

	for (char* ptr = infix, *tmpPtr = NULL; *ptr != '\0'; ptr++) { // set pointer to infix start; until pointer hits end; increment by 1
		char* token = calloc(256, sizeof(char)); // zero out token
		while(*ptr == ' ') // skip space
			ptr++;

		if (lastWasOperator && (*ptr == '-' || isdigit(*ptr))) { // handles numbers
			tmpPtr = ptr + 1; // look ahead
			while ((!mathOp(*tmpPtr) || *tmpPtr == '/') && *tmpPtr != ' ' && *tmpPtr != '\0') // double digit numbers
				tmpPtr++; // move until tmpPtr hits end of number, most likely ' '
			if (*tmpPtr == ' ' && isdigit(*(tmpPtr + 1))) { // handles mixed numbers
				tmpPtr++; // moves to first digit of numberator
				tmpPtr = strchr(tmpPtr, '/') + 1; // finds address of '/'
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
					strcpy(token, stackPop(operatorStack)); 
					queueEnqueue(outputQueue, token);
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
					strcpy(temp, stackPop(operatorStack));
					queueEnqueue(outputQueue, temp);
				}
				stackPush(operatorStack, token);
			}		
		} 
		free(token);
	}

	// empty remaining stack into queue
	while (!stackIsEmpty(operatorStack)) {
		strcpy(token, stackPop(operatorStack));
		queueEnqueue(outputQueue, token);
	}
	return true;
}

bool mathOp(char potOp) {
	char arr[] = "*/+-^()"; // array of chars to be checked against

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

void preprocess(char* infix) {
	for (int i = 0; infix[i] != '\0'; i++)
	{
		if (infix[i] == '\n')
			infix[i] = '\0';
	}
}


bool isValid(char* infix) { // error checking
	int count1= 0, count2 = 0; // counts for parentheses
	char arr[] = "*/+-^"; // array of operators not including ()


	for (int i = 0; infix[i] != '\0'; i++)
	{
		if (infix[i] == '(')
			count1++;
		if (infix[i] == ')')
			count2++;
		if (!mathOp(infix[i]) && !isdigit(infix[i]) && infix[i] != ' ') // if anything not algebraic
			return false;
		if (infix[i] == '/' && infix[i + 1] == '-')
			return false;
	}

	if (count1 != count2)
		return false;

	if ((infix[strlen(infix) - 1] == ' ') || strchr(arr,infix[strlen(infix) - 1] ))
		return false;
	
	return true;
}