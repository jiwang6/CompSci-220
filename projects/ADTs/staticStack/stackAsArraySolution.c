/** stackAsArraySolution.c
* ===========================================================
* Name: Troy Weingart
* Section: n/a
* Project: Example11a - Stack ADT implemented with C array
* ===========================================================
*/
#include <stdio.h>
#include "stackAsArray.h"


/** Task 0) - Implement the functions below
 * Note - each function is less that 7 lines of code
 * 0) test each function in Example09_stack.c
 */

int main() {
    printf("bitdefender RETARDED\n");

    StackAsArray test[STACK_MAX_SIZE];
    stackInit(test);



    return 0;
}

/** stackPush() - puts an element onto the top of the stack
 * @param - stack a ptr to the stack structure
 * @param - element the character to push onto the stack
 * @return - 1 on success, -1 on failure
 */
int stackPush(StackAsArray* stack, char element) {
    if (!stackIsFull(*stack)) {
        stack->top++;
        stack->letter[stack->top] = element;
        return 1;
    } else {
        return -1;
    }
}

/** stackPop() - pops an element off the stack
 * @param stack - a ptr to the stack structure
 * @return - the top of the stack on success, -1 on failure
 */
char stackPop(StackAsArray* stack){
    if (!stackIsEmpty(*stack)) {
        char ltr = stack->letter[stack->top];
        stack->top--;
        return ltr;
    } else {
        return '\0';
    }
}


/** stackInit() - initializes the stack structure
 * @param stack - a ptr to the stack structure
 */
void stackInit(StackAsArray* stack) {
    stack->top = -1;
}

/** stackPeek() - returns the item on the top of the
 * stack but doesn't remove it
 * @param stack - a ptr to the stack structure
 * @return - the item on the top of the stack
 */
char stackPeek(StackAsArray stack){
    if (!stackIsEmpty(stack)) {
        return stack.letter[stack.top];
    }
    return -1;
}

/** stackSize() - determines the size of the stack
 * @param stack - a ptr to the stack structure
 * @return - number of items in the stack
 */
int stackSize(StackAsArray stack){
    return stack.top+1;
}

/** stackPrint() - outputs the stack to the console
 * @param stack - the stack structure
 */
void stackPrint(StackAsArray stack) {
    for (int i = stack.top; i >= 0; i--) {
        printf("%d:'%c'\n",i,stack.letter[i]);
    }
    printf("\n");
}

/** stackIsFull() - determines if the stack is full
 * @param stack - a ptr to the stack structure
 * @return - true if the stack is fullor false
 */
bool stackIsFull(StackAsArray stack) {
    if (stack.top == STACK_MAX_SIZE-1) {
        return true;
    }
    return false;
}

/** stackIsEmpty() - determines if the stack is empty
 * @param stack - a ptr to the stack structure
 * @return - true if the stack is empty or false
 */
bool stackIsEmpty(StackAsArray stack){
    if (stack.top == -1) {
        return true;
    }
    return false;
}