/** queueAsLinkedList.h
* ===========================================================
* Name: CS220
* Section: n/a
* Project: Lesson14 - Queue ADT implemented using linked list
* ===========================================================
*/
#ifndef USAFA_CS220_S19_STUDENT_QUEUEASLIST_H
#define USAFA_CS220_S19_STUDENT_QUEUEASLIST_H
#include <stdbool.h>
#include "ListAsLinkedList.h"

typedef LinkedList QueueAsLinkedList;

/** queueEnqueue() - puts an element onto the top of the queue
 * @param - queue a ptr to the queue structure
 * @param - element the character to push onto the queue
 */
void queueEnqueue(QueueAsLinkedList* queue, int element);


/** queueDequeue() - pops an element off the queue
 * @param queue - a ptr to the queue structure
 * @return - the top of the queue on success, -1 on failure
 */
int queueDequeue(QueueAsLinkedList* queue);


/** queueIsEmpty() - determines if the queue is empty
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is empty or false
 */
bool queueIsEmpty(QueueAsLinkedList queue);


/** queueIsFull() - determines if the queue is full
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is fullor false
 */
bool queueIsFull(QueueAsLinkedList queue);


/** queueInit() - initializes the queue structure
 */
QueueAsLinkedList* queueInit();

/** queuePeek() - returns the item on the top of the
 * queue but doesn't remove it
 * @param queue - a ptr to the queue structure
 * @return - the item on the top of the queue
 */
int queuePeek(QueueAsLinkedList queue);


/** queueSize() - determines the size of the queue
 * @param queue - a ptr to the queue structure
 * @return - number of items in the queue
 */
int queueSize(QueueAsLinkedList queue);


/** queuePrint() - outputs the queue to the console
 * @param queue - the queue structure
 */
void queuePrint(QueueAsLinkedList queue);

#endif //USAFA_CS220_S19_STUDENT_QUEUEASLIST_H
