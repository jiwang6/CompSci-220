/** rpn.c
* ===========================================================
* Name: Jim Wang 17 April 2020
* Section: T2A
* Project: PEX3
* Purpose: Evaluate postfix expression.
* ===========================================================
*/

#include "rpn.h"
#include "shuntingAlgo.h"
#include "mathFuncts.h"

char* evalRPN(QueueAsLinkedList* postfix) {
	StackAsLinkedList* compStack = stackInit();


	char arg1[16], arg2[16]; // argument 1, argument 2
	char op; // operator

	long double dArg1, dArg2; // double values of argument 1 and argument 2
	

	while (!queueIsEmpty(postfix)) {

		if (strchr(queuePeek(postfix), ' ')) { // if mixed number
			dArg1 = evalMN(queueDequeue(postfix));
			sprintf(arg1, "%.10lf", dArg1);

			stackPush(compStack, &arg1);
		} else if (strchr(queuePeek(postfix), '/') && !strchr(queuePeek(postfix), ' ')) { // if just fraction
			dArg1 = evalF(queueDequeue(postfix));
			sprintf(arg1, "%.10lf", dArg1);

			stackPush(compStack, &arg1);
		}
		if (isdigit(queuePeek(postfix)[0]) || isdigit(queuePeek(postfix)[1])) {
			stackPush(compStack, queueDequeue(postfix));
		} else if(mathOp(queuePeek(postfix)[0])) { // operand
			strcpy(arg2, stackPop(compStack));
			strcpy(arg1, stackPop(compStack));
			op = queueDequeue(postfix)[0];
			dArg1 = strtod(arg1, NULL);
			dArg2 = strtod(arg2, NULL);

			switch (op) {
			case '+':
				dArg1 = mathAdd(dArg1, dArg2);
				break;
			case '-':
				dArg1 = mathSub(dArg1, dArg2);
				break;
			case '/':
				dArg1 = mathDiv(dArg1, dArg2);
				break;
			case '*':
				dArg1 = mathMul(dArg1, dArg2);
				break;
			case '^':
				dArg1 = mathPow(dArg1, dArg2);
				break;
			default:
				dArg1 = (double)-1;
				break;
			}
			sprintf(arg1, "%.10lf", dArg1);
			stackPush(compStack, &arg1);			
		}
	}
	char* finVal = calloc(20, sizeof(char));
	
	convertMN(stackPeek(compStack));

	strcpy(finVal, convertMN(stackPop(compStack)));
	deleteLinkedList(compStack);

	return finVal;
}


double evalMN(char* input) {
	double ret;
	int w, n, d; // whole number, num, denom

	sscanf(input, "%d %d/%d", &w, &n, &d);

	ret = (double)w + ((double)n / (double)d);

	return(ret);

}
double evalF(char* input) {
	double ret;
	int w, n, d; // whole number, num, denom

	sscanf(input, "%d/%d", &n, &d);

	ret = ((double)n / (double)d);

	return ret;
}

char* convertMN(char* dRes) {
	char* sRes = calloc(32, sizeof(char));

	double numb = strtod(dRes, NULL); // double of number
	int whol = (int)numb; // whole number of MN
	int nume = (numb - whol) * 1000000; // numerator of MN

	int deno = 1000000; // denominator of MN

	
	int nume1 = nume / gcd(nume, deno); // integer numerator to be returned
	int deno1 = deno / gcd(nume, deno); // integer denominator to be returned

	// "fix" double errors - oh my goodness this is so dumb why did I choose to turn everything into doubles
	if (gcd(nume, deno) < 10) {
		nume1 = (nume + 1) / gcd((nume+1), deno);
		deno1 = deno / gcd((nume+1), deno);

		if (gcd((nume + 1), deno) < 10) {
			nume1 = nume / gcd(nume, (deno - 1));
			deno1 = (deno - 1) / gcd(nume, (deno - 1));
		}
	}

	
	if (nume1 !=0) {
		if (whol != 0)
			sprintf(sRes, "%d %d/%d",whol, nume1, deno1);
		else
			sprintf(sRes, "%d/%d", nume1, deno1);
	}
	else {
		sprintf(sRes, "%d", whol);
	}
	return sRes;
}

int gcd(int a, int b) {
	int rem; // remainder variable after modulo

	while (a != 0) {
		rem = b % a;
		b = a;
		a = rem;
	}
;
	return b;
}
