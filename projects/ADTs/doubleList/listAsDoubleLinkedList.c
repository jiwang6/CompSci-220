/** listAsDoubleLinkedList.c
* ================================================================
* Name: Troy Weingart
* Section: n/a
* Project: Lesson15 - Implementation of Double-Linked List Library
* =================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "listAsDoubleLinkedList.h"

DoubleLinkedList* createLinkedList() {
    DoubleLinkedList* list = malloc(sizeof(DoubleLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->numberOfElements = 0;
    return list;
}

void deleteLinkedList(DoubleLinkedList* list) {
    Node* tempPtr = list->head;
    Node* freePtr = NULL;

    // traverse the list freeing each
    // node as you go cannot free entire
    // list as free works only on
    // contiguous blocks of memory (a node)
    while (tempPtr != NULL) {
        freePtr = tempPtr;
        tempPtr = tempPtr->next;
        free(freePtr);
    }
    free(list);
}
void appendElementLinkedList(DoubleLinkedList* list, int element) {
    // create a new node on the heap as values on the stack
    // are free'd when the function ends
    Node* newNode = malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;


    // check to see if the list is empty add and handle that
    // special case
    if (list->head == NULL) {
        list->head = newNode;
    // list is not empty append node using tail ptr
    } else {
        newNode->prev = list->tail;
		list->tail->next = newNode;

    }
    list->tail = newNode;
    list->numberOfElements++;
}

int lengthOfLinkedList(DoubleLinkedList* list) {
    return list->numberOfElements;
}

void printLinkedList(DoubleLinkedList* list) {
    Node* tempPtr = list->head;
    while (tempPtr != NULL) {
        printf("%d -> ", tempPtr->data);
        tempPtr = tempPtr->next;
    }
    printf("NULL\n");
}

int getElementLinkedList(DoubleLinkedList* list, int position) {
    if (list->numberOfElements == 0 || list->numberOfElements <= position) {
        return -1;
    }
    int curPos = 0;
    Node* tempPtr = list->head;
    while (curPos < position) {
        curPos++;
        tempPtr = tempPtr->next;
    }
    return tempPtr->data;
}

void deleteElementLinkedList(DoubleLinkedList* list, int position) {
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

    if (tempPtr == list->head && tempPtr == list->tail) { // only 1 item in list
        list->head = NULL;
        list->tail = NULL;
    } else if (tempPtr == list->head) { //removing head
        list->head = tempPtr->next;
		list->head->prev = NULL;
    } else if (tempPtr == list->tail) { //removing tail
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    } else {  // internal node
        tempPtr->prev->next = tempPtr->next;
		tempPtr->next->prev = tempPtr->prev;
    }
    list->numberOfElements--;
    free(tempPtr);
}

void insertElementLinkedList(DoubleLinkedList* list, int position, int element) {
    if (list->numberOfElements < position) {
        printf("Error\n");
        exit(0);
    }
    // create a new node on the heap as values on the stack
    // are free'd when the function ends
    Node* newNode = malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;

    int curPos = 0;
    Node* tempPtr = list->head;

    while (tempPtr != NULL && curPos < position) {
        curPos++;
        tempPtr = tempPtr->next;
    }

    if (tempPtr == NULL) { //empty list
        list->head = newNode;
        list->tail = newNode;
    } else if (tempPtr == list->head) { // insert at the head
		newNode->next = list->head;
        list->head->prev = newNode;
		list->head = newNode;        
    } else {  // insert internally
        newNode->next = tempPtr;
		newNode->prev = tempPtr->prev;
        newNode->prev->next = newNode;
		newNode->next->prev = newNode;
    }
    list->numberOfElements++;

}

void changeElementLinkedList(DoubleLinkedList* list, int position, int newElement) {
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
    tempPtr->data = newElement;
}

int findElementLinkedList(DoubleLinkedList* list, int element) {
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