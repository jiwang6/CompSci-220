/** listAsLinkedList.h
* ================================================================
* Name: CS220
* Section: n/a
* Project: Lesson12 - Implementation of Linked List Library
* =================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "listAsLinkedList.h"

Node * findSmallest(Node *firstNode);
void swapData(Node * j, Node * k);

LinkedList* createLinkedList() {
    LinkedList* list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->numberOfElements = 0;

    return list;
}

void deleteLinkedList(LinkedList* list) {
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

void appendElementLinkedList(LinkedList* list, int element) {
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
        list->tail->next = newNode; // link to list

    }
    list->tail = newNode; // define new end of list
    list->numberOfElements++;
}

int lengthOfLinkedList(LinkedList* list) {
    return list->numberOfElements;
}

void printLinkedList(LinkedList* list) {
    Node* tempPtr = list->head;
    while (tempPtr != NULL) {
        printf("%d -> ", tempPtr->data);
        tempPtr = tempPtr->next;
    }
    printf("NULL\n");
}

int getElementLinkedList(LinkedList* list, int position) {
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

void deleteElementLinkedList(LinkedList* list, int position) {
    if (list->numberOfElements == 0 || list->numberOfElements <= position) {
        printf("Error\n");
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

    if (tempPtr == list->head && tempPtr == list->tail) { // only 1 item in list
        list->head = NULL;
        list->tail = NULL;
    } else if (tempPtr == list->head) { //removing head
        list->head = tempPtr->next;
    } else if (tempPtr == list->tail) { //removing tail
        list->tail = prevPtr;
        list->tail->next = NULL;
    } else {  // internal node
        prevPtr->next = tempPtr->next;
    }
    list->numberOfElements--;
    free(tempPtr);
}

void insertElementLinkedList(LinkedList* list, int position, int element) {
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
    Node* prevPtr = NULL;

    while (tempPtr != NULL && curPos < position) {
        curPos++;
        prevPtr = tempPtr;
        tempPtr = tempPtr->next;
    }

    if (tempPtr == NULL) { //empty list
        list->head = newNode;
        list->tail = newNode;
    } else if (tempPtr == list->head) { // insert at the head
        list->head = newNode;
        newNode->next = tempPtr;
    } else {  // insert internally
        newNode->next = tempPtr;
        prevPtr->next = newNode;
    }
    list->numberOfElements++;

}

void changeElementLinkedList(LinkedList* list, int position, int newElement) {
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

int findElementLinkedList(LinkedList* list, int element) {
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

/** -------------------------------------------------------------------
 * insertSortLinkedList() - Perform an insertion sort on a LinkedList
 * @param list - the LinkedList to sort
 */
void insertSortLinkedList(LinkedList* list) {
        int insertElem;
        Node* tempPtr = list->head->next;
        Node* tempPrevPtr = list->head;
        Node* insPtr;
        Node* insPrevPtr = list->head;
        while (tempPtr != NULL) {
            insertElem = tempPtr->data; // the item to insert
            insPtr = list->head;
            while (insPtr->data < insertElem && insPtr != tempPtr) {   // find the insertion
                insPrevPtr = insPtr;
                insPtr = insPtr->next;
            }
            if (insPtr != tempPtr) {
                tempPrevPtr->next = tempPtr->next;
                tempPtr->next = insPtr;
                insPrevPtr->next = tempPtr;
                if (insPtr == list->head) {
                    list->head = insPtr; // error?
                }
            }
            tempPrevPtr = tempPtr;
            tempPtr = tempPtr->next;
        }
    }

/** -------------------------------------------------------------------
 * selSortLinkedList() - Perform an selection sort on a LinkedList
 * @param list - the LinkedList to sort
 */
void selSortLinkedList(LinkedList *list) {
    Node* tempPtr = list->head;
    Node* nodeWithSmallest;
    while (tempPtr != NULL) {
        nodeWithSmallest = findSmallest(tempPtr);
        swapData(tempPtr, nodeWithSmallest);
        tempPtr = tempPtr->next;
    }
}

/**
 * Find the node that contains the smallest element in a sub-section of a LinkedList
 * @param firstNode - the node in the LinkedList to start the search
 * @return A pointer to the node that contains the smallest element
 */
Node * findSmallest(Node *firstNode) {
    Node * nodeWithSmallest = firstNode;
    Node * nodePtr = firstNode;
    while (nodePtr != NULL) {
        if (nodePtr->data < nodeWithSmallest->data) {
            nodeWithSmallest = nodePtr;
        }
        nodePtr = nodePtr->next;
    }
    return nodeWithSmallest;
}

/**
 * Given a array and two positions within the array, swap the contents
 * of the two positions.
 * @param array - the array to change
 * @param j - one location in the array
 * @param k - another location in the array
 */
void swapData(Node * j, Node * k) {
    int temp = j->data;
    j->data = k->data;
    k->data = temp;
}