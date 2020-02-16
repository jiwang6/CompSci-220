/** stackAsArray.h
* ===========================================================
* Name: Troy Weingart
* Section: n/a
* Project: Example11a - Stack ADT implemented with C array
* ===========================================================
*/
#ifndef USAFA_CS220_S19_STACKASARRAY_H
#define USAFA_CS220_S19_STACKASARRAY_H
#include <stdbool.h>

#define STACK_MAX_SIZE 100

typedef struct {
    char letter[STACK_MAX_SIZE]; //the array storing the contents of the stack
    int top; //the current index of the top of the stack
} StackAsArray;

/** stackPush() - puts an element onto the top of the stack
 * @param - stack a ptr to the stack structure
 * @param - element the character to push onto the stack
 * @return - 1 on success, -1 on failure
 */
int stackPush(StackAsArray* stack, char element);


/** stackPop() - pops an element off the stack
 * @param stack - a ptr to the stack structure
 * @return - the top of the stack on success, -1 on failure
 */
char stackPop(StackAsArray* stack);


/** stackIsEmpty() - determines if the stack is empty
 * @param stack - a ptr to the stack structure
 * @return - true if the stack is empty or false
 */
bool stackIsEmpty(StackAsArray stack);


/** stackIsFull() - determines if the stack is full
 * @param stack - a ptr to the stack structure
 * @return - true if the stack is fullor false
 */
bool stackIsFull(StackAsArray stack);


/** stackInit() - initializes the stack structure
 * @param stack - a ptr to the stack structure
 */
void stackInit(StackAsArray* stack);


/** stackPeek() - returns the item on the top of the
 * stack but doesn't remove it
 * @param stack - a ptr to the stack structure
 * @return - the item on the top of the stack
 */
char stackPeek(StackAsArray stack);


/** stackSize() - determines the size of the stack
 * @param stack - a ptr to the stack structure
 * @return - number of items in the stack
 */
int stackSize(StackAsArray stack);


/** stackPrint() - outputs the stack to the console
 * @param stack - the stack structure
 */
void stackPrint(StackAsArray stack);

#endif //USAFA_CS220_S19_STACKASARRAY_H
