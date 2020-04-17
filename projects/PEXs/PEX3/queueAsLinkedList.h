/** queueAsLinkedList.h
* ===========================================================
* Name: Jim Wang
* Section: T2A
* Project: Queue ADT using linked list
* ===========================================================
*/

#pragma once

#include <stdbool.h>
#include "ListAsLinkedList.h"

typedef LinkedList QueueAsLinkedList; // same structure, different name

/** queueInit() - creates queue structure
 */
QueueAsLinkedList* queueInit();

/** queueEnqueue() - inserts element at top (back) of queue
 * @param queue - ptr to queue struct
 * @param element - char* variable to be put into queue
 */
void queueEnqueue(QueueAsLinkedList* queue, char* element);

/** queueDequeue() - removes elemt from bottom (front) of queue
 * @param queue - ptr to queue structure
 * @return - the bottom char* value of queue datastruct
 */
char* queueDequeue(QueueAsLinkedList* queue);

/** queueIsEmpty() - returns if queue is empty or not
 * @param queue - ptr to queue struct
 * @return - TRUE if empty, FALSE if not
 */
bool queueIsEmpty(QueueAsLinkedList* queue);

/** queueIsFull() - returns that queue is not full
 * @param queue - ptr to queue struct
 * @return -  TRUE if full, FALSE if not full
 */
bool queueIsFull(QueueAsLinkedList* queue);

/** queuePeek() - returns item from bottom of queue without removing
 * @param queue - ptr to queue struct
 * @return - the item on the bottom of the queue
 */
char* queuePeek(QueueAsLinkedList* queue);

/** queueSize() - returns size of queue
 * @param queue - ptr to queue struct
 * @return - number of items queue
 */
int queueSize(QueueAsLinkedList* queue);

/** queuePrint() - outputs queue struct
 * @param queue - ptr to queue struct
 */
void queuePrint(QueueAsLinkedList* queue);

/** queuePrintOut() - outputs queue struct for RPN
 * @param queue - ptr to queue struct
 */
void queuePrintOut(QueueAsLinkedList* queue);