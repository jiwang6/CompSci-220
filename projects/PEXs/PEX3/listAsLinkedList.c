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
    LinkedList* list = malloc(sizeof(LinkedList));
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

void appendElementLinkedList(LinkedList* list, double element) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = element;
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
        printf("%lf -> ", tempPtr->data);
        tempPtr = tempPtr->next;
    }
    printf("NULL\n");
}

double getElementLinkedList(LinkedList* list, int position) {
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
    free(tempPtr);
}

void insertElementLinkedList(LinkedList* list, int position, double element) {
    if (list->numberOfElements < position) {
        printf("Error\n");
        exit(0);
    }

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

void changeElementLinkedList(LinkedList* list, int position, double newElement) {
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

int findElementLinkedList(LinkedList* list, double element) {
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

void insertSortLinkedList(LinkedList* list) {
    double insertElem;
    Node* tempPtr = list->head->next;
    Node* tempPrevPtr = list->head;
    Node* insPtr;
    Node* insPrevPtr = list->head;
    while (tempPtr != NULL) {
        insertElem = tempPtr->data;
        insPtr = list->head;
        while (insPtr->data < insertElem && insPtr != tempPtr) {
            insPrevPtr = insPtr;
            insPtr = insPtr->next;
        }
        if (insPtr != tempPtr) {
            tempPrevPtr->next = tempPtr->next;
            tempPtr->next = insPtr;
            insPrevPtr->next = tempPtr;
            if (insPtr == list->head)
                list->head = insPtr;
        }
        tempPrevPtr = tempPtr;
        tempPtr = tempPtr->next;
    }
}

void selSortLinkedList(LinkedList *list) {
    Node* tempPtr = list->head;
    Node* nodeWithSmallest;
    while (tempPtr != NULL) {
        nodeWithSmallest = findSmallest(tempPtr);
        swapData(tempPtr, nodeWithSmallest);
        tempPtr = tempPtr->next;
    }
}

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

void swapData(Node * j, Node * k) {
    double temp = j->data;
    j->data = k->data;
    k->data = temp;
}