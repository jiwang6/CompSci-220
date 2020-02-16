/** listAsLinkedList.h
* ================================================================
* Name: first last
* Section: xxx
* Project: Header for Linked List Library
*
* Instructions:  Complete the implementation file for this header file
* 
* =================================================================
*/
#ifndef USAFA_CS220_S20_STUDENT_LISTASLINKEDLIST_H
#define USAFA_CS220_S20_STUDENT_LISTASLINKEDLIST_H
#include <stdbool.h>

// Define a node of the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the type (meta-data) that manages the linked list of nodes
typedef struct {
    Node* head;
    Node* tail;
    int numberOfElements;
} LinkedList;

// Functions that manipulate a linked list
LinkedList* createLinkedList();
void deleteLinkedList(LinkedList* list);
void appendElementLinkedList(LinkedList* list, int element);
int lengthOfLinkedList(LinkedList* list);
void printLinkedList(LinkedList* list);
int getElementLinkedList(LinkedList* list, int position);
void changeElementLinkedList(LinkedList* list, int position, int newElement);

void deleteElementLinkedList(LinkedList* list, int position);
void insertElementLinkedList(LinkedList* list, int position, int element);
int findElementLinkedList(LinkedList* list, int element);

void selSortLinkedList(LinkedList *list);
void insertSortLinkedList(LinkedList* list);

#endif //USAFA_CS220_S20_STUDENT_LISTASLINKEDLIST_H
