/** listAsDoubleLinkedList.h
* ================================================================
* Name: first last
* Section: xxx
* Project: Header for Double-Linked List Library
*
* Instructions:  Complete the implementation file for this header file
* 
* =================================================================
*/
#ifndef USAFA_CS220_S20_STUDENT_LISTASDOUBLELINKEDLIST_H
#define USAFA_CS220_S20_STUDENT_LISTASDOUBLELINKEDLIST_H
#include <stdbool.h>

// Define a node of the linked list
typedef struct node {
    int data;
    struct node* next;
	struct node* prev;
} Node;

// Define the type (meta-data) that manages the linked list of nodes
typedef struct {
    Node* head;
    Node* tail;
    int numberOfElements;
} DoubleLinkedList;

// Functions that manipulate a linked list
DoubleLinkedList* createLinkedList();
void deleteLinkedList(DoubleLinkedList* list);
void appendElementLinkedList(DoubleLinkedList* list, int element);
int lengthOfLinkedList(DoubleLinkedList* list);
void printLinkedList(DoubleLinkedList* list);
int getElementLinkedList(DoubleLinkedList* list, int position);
void changeElementLinkedList(DoubleLinkedList* list, int position, int newElement);

void deleteElementLinkedList(DoubleLinkedList* list, int position);
void insertElementLinkedList(DoubleLinkedList* list, int position, int element);
int findElementLinkedList(DoubleLinkedList* list, int element);


#endif //USAFA_CS220_S20_STUDENT_LISTASDOUBLELINKEDLIST_H
