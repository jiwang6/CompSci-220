/** stackAsLinkedList.h
* ===========================================================
* Name: Jim Wang
* Section: T2A
* Project: Stack ADT using linked list
* ===========================================================
*/

#pragma once

#include <stdbool.h>
#include "listAsLinkedList.h"

typedef LinkedList StackAsLinkedList; // same struct, diff name

/** stackInit() - creates stack struct
 */
StackAsLinkedList* stackInit();

/** stackPush() - pushes element to top of stack
 * @param stack - ptr to stack struct
 * @param element - element to be put into structure
 * @return - 1 if successful, -1 if not
 */
void stackPush(StackAsLinkedList* stack, double element);

/** stackPop() - pops an element off top of stack
 * @param stack - ptr to stack struct
 * @return - double stack element pushed off top
 */
double stackPop(StackAsLinkedList* stack);

/** stackIsEmpty() - returns whether stack is empty
 * @param stack - ptr to stack struct
 * @return - TRUE if empty, FALSE if not empty
 */
bool stackIsEmpty(StackAsLinkedList* stack);

/** stackIsFull() - returns whether stack is full
 * @param stack - ptr to stack struct
 * @return - TRUE if full, FALSE if not
 */
bool stackIsFull(StackAsLinkedList* stack);

/** stackPeek() - returns top element of stack without removing
 * @param stack - ptr to stack struct
 * @return - element at top of stack
 */
double stackPeek(StackAsLinkedList* stack);

/** stackSize() - returns size of stack
 * @param stack - ptr to stack struct
 * @return - size of stack
 */
int stackSize(StackAsLinkedList* stack);

/** stackPrint() - prints stack
 * @param stack - ptr to stack strcut
 */
void stackPrint(StackAsLinkedList* stack);