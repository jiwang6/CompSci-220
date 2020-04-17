/** listAsLinkedList.c
* ================================================================
* Name: Jim Wang
* Section: T2A
* Project: Linked List Library
* Documentation: Heavily referenced provided course matrieral
* for ADT implementation
* =================================================================
*/

#include "listAsLinkedList.h"

LinkedList* createLinkedList() {
    LinkedList* list = calloc(1, sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->numberOfElements = 0;

    return list;
}

void deleteLinkedList(LinkedList* list) {
    Node* tempPtr = list->head;
    Node* freePtr = NULL;

    while (tempPtr != NULL) {
        freePtr = tempPtr;
        tempPtr = tempPtr->next;
        free(freePtr);
    }
    free(list);
}

void appendElementLinkedList(LinkedList* list, char* element) {
    Node* newNode = calloc(1, sizeof(Node));
    strcpy(newNode->data, element);
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        list->tail->next = newNode;

    }
    list->tail = newNode;
    list->numberOfElements++;
}

int lengthOfLinkedList(LinkedList* list) {
    return list->numberOfElements;
}

void printLinkedList(LinkedList* list) {
    Node* tempPtr = list->head;
    while (tempPtr != NULL) {
        printf("%s -> ", tempPtr->data);
        tempPtr = tempPtr->next;
    }
    printf("NULL\n");
}

char* getElementLinkedList(LinkedList* list, int position) {
    if (list->numberOfElements == 0 || list->numberOfElements <= position) {
        return "n/a";
    }
    int curPos = 0;
    Node* tempPtr = list->head;
    while (curPos < position) {
        curPos++;
        tempPtr = tempPtr->next;
    }
    return tempPtr->data;
}

void deleteElementLinkedList(LinkedList* list, int position) {
    if (list->numberOfElements == 0 || list->numberOfElements <= position) {
        printf("Error in dELL\n");
        exit(0);
    }

    int curPos = 0;
    Node* tempPtr = list->head;
    Node* prevPtr = NULL;

    while (curPos < position) {
        curPos++;
        prevPtr = tempPtr;
        tempPtr = tempPtr->next;
    }

    if (tempPtr == list->head && tempPtr == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else if (tempPtr == list->head) { 
        list->head = tempPtr->next;
    } else if (tempPtr == list->tail) {
        list->tail = prevPtr;
        list->tail->next = NULL;
    } else {
        prevPtr->next = tempPtr->next;
    }
    list->numberOfElements--;
    free(tempPtr); // issue here, freeing char pointer where we still need
}

void insertElementLinkedList(LinkedList* list, int position, char* element) {
    if (list->numberOfElements < position) {
        printf("Error\n");
        exit(0);
    }

    Node* newNode = calloc(1, sizeof(Node));
    strcpy(newNode->data, element);
    newNode->next = NULL;

    int curPos = 0;
    Node* tempPtr = list->head;
    Node* prevPtr = NULL;

    while (tempPtr != NULL && curPos < position) {
        curPos++;
        prevPtr = tempPtr;
        tempPtr = tempPtr->next;
    }

    if (tempPtr == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else if (tempPtr == list->head) {
        list->head = newNode;
        newNode->next = tempPtr;
    } else {
        newNode->next = tempPtr;
        prevPtr->next = newNode;
    }
    list->numberOfElements++;

}

void changeElementLinkedList(LinkedList* list, int position, char* newElement) {
    if (list->numberOfElements == 0 || list->numberOfElements <= position) {
        printf("Error\n");
        exit(0);
    }

    int curPos = 0;
    Node* tempPtr = list->head;

    while (curPos < position) {
        curPos++;
        tempPtr = tempPtr->next;
    }
    strcpy(tempPtr->data, newElement);
}

int findElementLinkedList(LinkedList* list, char* element) {
    int curPos = 0;
    Node* tempPtr = list->head;

    while (tempPtr!= NULL && tempPtr->data != element ) {
        curPos++;
        tempPtr = tempPtr->next;
    }
    if (tempPtr != NULL) {
        return curPos;
    }
    return -1;
}

void swapData(Node * j, Node * k) {
    char* temp = j->data;
    strcpy(j->data, k->data);
    strcpy(k->data, temp);
}

void printLinkedListOut(LinkedList* list) {
    Node* tempPtr = list->head;
    while (tempPtr != NULL) {
        printf("%s ", tempPtr->data);
        tempPtr = tempPtr->next;
    }
}