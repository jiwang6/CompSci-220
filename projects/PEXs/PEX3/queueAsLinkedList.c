/** queueAsLinkedList.c
* ===========================================================
* Name: Jim Wang
* Section: n/a
* Project: Queue ADT using linked list
* Documentation: Heavily referenced provided course matrieral
* for ADT implementation
* ===========================================================
*/

#include "queueAsLinkedList.h"

QueueAsLinkedList* queueInit() {
    return createLinkedList();
}

void queueEnqueue(QueueAsLinkedList* queue, double element) {
    appendElementLinkedList(queue, element);
}

double queueDequeue(QueueAsLinkedList* queue) {
    double elem = getElementLinkedList(queue, 0);
    deleteElementLinkedList(queue, 0);
    return elem;
}

bool queueIsEmpty(QueueAsLinkedList* queue) {
    if (lengthOfLinkedList(queue) == 0) {
        return true;
    }
    return false;
}

bool queueIsFull(QueueAsLinkedList* queue) {
    return false;
}

double queuePeek(QueueAsLinkedList* queue) {
    return getElementLinkedList(queue, 0);
}

int queueSize(QueueAsLinkedList* queue) {
    return lengthOfLinkedList(queue);
}

void queuePrint(QueueAsLinkedList* queue) {
    printLinkedList(queue);
}