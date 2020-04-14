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

void queueEnqueue(QueueAsLinkedList* queue, char* element) {
    appendElementLinkedList(queue, element);
}

char* queueDequeue(QueueAsLinkedList* queue) {
    char* elem = getElementLinkedList(queue, 0);
    char* temp = malloc(10 * sizeof(char));
    strcpy(temp, elem);
    deleteElementLinkedList(queue, 0);
    return temp;
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

char* queuePeek(QueueAsLinkedList* queue) {
    return getElementLinkedList(queue, 0);
}

int queueSize(QueueAsLinkedList* queue) {
    return lengthOfLinkedList(queue);
}

void queuePrint(QueueAsLinkedList* queue) {
    printLinkedList(queue);
}