/** stackAsLinkedList.h
* ===========================================================
* Name: Troy Weingart
* Section: n/a
* Project: Lesson13 - Stack ADT implemented using linked list
* ===========================================================
*/
#ifndef USAFA_CS220_S19_STUDENT_STACKASLIST_H
#define USAFA_CS220_S19_STUDENT_STACKASLIST_H
#include <stdbool.h>
#include "listAsLinkedList.h"

typedef LinkedList StackAsLinkedList;

/** stackPush() - puts an element onto the top of the stack
 * @param - stack a ptr to the stack structure
 * @param - element the character to push onto the stack
 * @return - 1 on success, -1 on failure
 */
void stackPush(StackAsLinkedList* stack, int element);


/** stackPop() - pops an element off the stack
 * @param stack - a ptr to the stack structure
 * @return - the top of the stack on success, -1 on failure
 */
int stackPop(StackAsLinkedList* stack);


/** stackIsEmpty() - determines if the stack is empty
 * @param stack - a ptr to the stack structure
 * @return - true if the stack is empty or false
 */
bool stackIsEmpty(StackAsLinkedList stack);


/** stackIsFull() - determines if the stack is full
 * @param stack - a ptr to the stack structure
 * @return - true if the stack is fullor false
 */
bool stackIsFull(StackAsLinkedList stack);


/** stackInit() - initializes the stack structure
 */
StackAsLinkedList* stackInit();

/** stackPeek() - returns the item on the top of the
 * stack but doesn't remove it
 * @param stack - a ptr to the stack structure
 * @return - the item on the top of the stack
 */
int stackPeek(StackAsLinkedList stack);


/** stackSize() - determines the size of the stack
 * @param stack - a ptr to the stack structure
 * @return - number of items in the stack
 */
int stackSize(StackAsLinkedList stack);


/** stackPrint() - outputs the stack to the console
 * @param stack - the stack structure
 */
void stackPrint(StackAsLinkedList stack);

#endif //USAFA_CS220_S19_STUDENT_STACKASLIST_H
