/** stackAsLinkedList.c
* ===========================================================
* Name: Troy Weingart
* Section: n/a
* Project: Lesson13 - Stack ADT implemented using linked list
* ===========================================================
*/
#include "stackAsLinkedList.h"

int main() {
    printf("build passed\n");

    StackAsLinkedList* testStack = stackInit(); 

    stackPush(testStack, 5);

    printf("uwu your stack is %d big", stackSize(*testStack));

    return 0;
}

/** stackPush() - puts an element onto the top of the stack
 * @param - stack a ptr to the stack structure
 * @param - element the character to push onto the stack
 */
void stackPush(StackAsLinkedList* stack, int element) {
    appendElementLinkedList(stack,element);
}


/** stackPop() - pops an element off the stack
 * @param stack - a ptr to the stack structure
 * @return - the top of the stack on success, -1 on failure
 */
int stackPop(StackAsLinkedList* stack) {
    int elemPos = lengthOfLinkedList(stack)-1;
    int elem = getElementLinkedList(stack,elemPos);
    deleteElementLinkedList(stack,elemPos);
    return elem;
}


/** stackIsEmpty() - determines if the stack is empty
 * @param stack - a ptr to the stack structure
 * @return - true if the stack is empty or false
 */
bool stackIsEmpty(StackAsLinkedList stack) {
    if (lengthOfLinkedList(&stack) == 0) {
        return true;
    }
    return false;
}


/** stackIsFull() - determines if the stack is full
 * @param stack - a ptr to the stack structure
 * @return - true if the stack is fullor false
 */
bool stackIsFull(StackAsLinkedList stack) {
    return false;
}


/** stackInit() - initializes the stack structure
 */
StackAsLinkedList* stackInit() {
    return createLinkedList();
}


/** stackPeek() - returns the item on the top of the
 * stack but doesn't remove it
 * @param stack - a ptr to the stack structure
 * @return - the item on the top of the stack
 */
int stackPeek(StackAsLinkedList stack) {
    return getElementLinkedList(&stack,lengthOfLinkedList(&stack)-1);
}


/** stackSize() - determines the size of the stack
 * @param stack - a ptr to the stack structure
 * @return - number of items in the stack
 */
int stackSize(StackAsLinkedList stack) {
    return lengthOfLinkedList(&stack);
}


/** stackPrint() - outputs the stack to the console
 * @param stack - the stack structure
 */
void stackPrint(StackAsLinkedList stack) {
    printLinkedList(&stack);
}