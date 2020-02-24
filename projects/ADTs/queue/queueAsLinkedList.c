/** queueAsLinkedList.c
* ===========================================================
* Name: Troy Weingart
* Section: n/a
* Project: Lesson14 - Queue ADT implemented using linked list
* ===========================================================
*/
#include "queueAsLinkedList.h"

/** queuePush() - puts an element onto the top of the queue
 * @param - queue a ptr to the queue structure
 * @param - element the character to push onto the queue
 */
void queueEnqueue(QueueAsLinkedList* queue, int element) {
    appendElementLinkedList(queue, element);
}


/** queuePop() - pops an element off the queue
 * @param queue - a ptr to the queue structure
 * @return - the top of the queue on success, -1 on failure
 */
int queuePop(QueueAsLinkedList* queue) {
    int elem = getElementLinkedList(queue, 0);
    deleteElementLinkedList(queue, 0);
    return elem;
}


/** queueIsEmpty() - determines if the queue is empty
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is empty or false
 */
bool queueIsEmpty(QueueAsLinkedList queue) {
    if (lengthOfLinkedList(&queue) == 0) {
        return true;
    }
    return false;
}


/** queueIsFull() - determines if the queue is full
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is fullor false
 */
bool queueIsFull(QueueAsLinkedList queue) {
    return false;
}


/** queueInit() - initializes the queue structure
 */
QueueAsLinkedList* queueInit() {
    return createLinkedList();
}


/** queuePeek() - returns the item on the top of the
 * queue but doesn't remove it
 * @param queue - a ptr to the queue structure
 * @return - the item on the top of the queue
 */
int queuePeek(QueueAsLinkedList queue) {
    return getElementLinkedList(&queue, 0);
}


/** queueSize() - determines the size of the queue
 * @param queue - a ptr to the queue structure
 * @return - number of items in the queue
 */
int queueSize(QueueAsLinkedList queue) {
    return lengthOfLinkedList(&queue);
}


/** queuePrint() - outputs the queue to the console
 * @param queue - the queue structure
 */
void queuePrint(QueueAsLinkedList queue) {
    printLinkedList(&queue);
}