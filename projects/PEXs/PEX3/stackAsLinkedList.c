/** stackAsLinkedList.c
* ===========================================================
* Name: Jim Wang
* Section: T2A
* Project: Stack ADT using Linked List
* Documentation: Heavily referenced provided course matrieral
* for ADT implementation
* ===========================================================
*/

#include "stackAsLinkedList.h"

void stackPush(StackAsLinkedList* stack, double element) {
    appendElementLinkedList(stack,element);
}

double stackPop(StackAsLinkedList* stack) {
    int elemPos = lengthOfLinkedList(stack)-1;
    double elem = getElementLinkedList(stack,elemPos);
    deleteElementLinkedList(stack,elemPos);
    return elem;
}

bool stackIsEmpty(StackAsLinkedList* stack) {
    if (lengthOfLinkedList(stack) == 0) {
        return true;
    }
    return false;
}

bool stackIsFull(StackAsLinkedList* stack) {
    return false;
}

StackAsLinkedList* stackInit() {
    return createLinkedList();
}

double stackPeek(StackAsLinkedList* stack) {
    return getElementLinkedList(stack, lengthOfLinkedList(stack)-1);
}

int stackSize(StackAsLinkedList* stack) {
    return lengthOfLinkedList(stack);
}

void stackPrint(StackAsLinkedList* stack) {
    printLinkedList(stack);
}