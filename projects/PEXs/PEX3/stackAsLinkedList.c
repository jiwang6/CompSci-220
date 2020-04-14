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

void stackPush(StackAsLinkedList* stack, char* element) {
    appendElementLinkedList(stack,element);
}

char* stackPop(StackAsLinkedList* stack) {
    int elemPos = lengthOfLinkedList(stack)-1;
    char* elem = getElementLinkedList(stack, elemPos);
    char* temp = malloc(10 * sizeof(char));
    strcpy(temp, elem);
    deleteElementLinkedList(stack, elemPos);
    return temp;
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

char* stackPeek(StackAsLinkedList* stack) {
    return getElementLinkedList(stack, lengthOfLinkedList(stack)-1);
}

int stackSize(StackAsLinkedList* stack) {
    return lengthOfLinkedList(stack);
}

void stackPrint(StackAsLinkedList* stack) {
    printLinkedList(stack);
}