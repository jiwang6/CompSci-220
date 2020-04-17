/** listAsLinkedList.h
* ================================================================
* Name: Jim Wang
* Section: T2A
* Project: Linked List Library
* =================================================================
*/

#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node of the linked list
typedef struct node {
    char data[10];
    struct node* next;
} Node;

// Define Linked List DataStructure
typedef struct {
    Node* head;
    Node* tail;
    int numberOfElements;
} LinkedList;

/** createLinkedList() - creates linked list structure
 */
LinkedList* createLinkedList();

/** deleteLinkedList() - deletes linked list structure
 * @param list - pointer to ll structure
 */
void deleteLinkedList(LinkedList* list);

/** appenedElementLinkedList() - appends element to ll structure
 * @param list - ptr to ll structure
 * @param element - char*  element to be appeneded
 */
void appendElementLinkedList(LinkedList* list, char* element);

/** lengthOfLinkedList() - returns lenth of ll structure
 * @param list - ptr to ll structure
 * @return - integer value for length of ll structure
 */
int lengthOfLinkedList(LinkedList* list);

/** printLinkedList() - prints ll strucutre
 * @param list - ptr to ll
 */
void printLinkedList(LinkedList* list);

/** getElementLinkedList() - returns a specific element of a linked list
 * @param list - ptr to ll struct
 * @param position - position of element requested
 * @return - element of linked list requested, -1 if index doesn't exist
 */
char*  getElementLinkedList(LinkedList* list, int position);

/** changeElementLinkedList() - changes element value for position specified
 * @param list - ptr to ll struct
 * @param position - index of element to be replaced
 * @param newElement - new char*  value to go into position
 */
void changeElementLinkedList(LinkedList* list, int position, char* newElement);


/** deleteElementLinkedList() - deletes element at the position specified
 * @param list - ptr to ll struct
 * @param position - index of element to be replaced
 */
void deleteElementLinkedList(LinkedList* list, int position);

/** insertElementLinkedList() - inserts new element into ll struct @ position specified
 * @param list - ptr to ll struct
 * @param position - index of element new value will be inserted into
 * @param element - new char*  value to go into position
 */
void insertElementLinkedList(LinkedList* list, int position, char* element);

/** findElementLinkedList() - finds position of element specified
 * @param list - ptr to ll struct
 * @param element - element value to be found
 */
int findElementLinkedList(LinkedList* list, char* element);

/** swapData() - swaps data in two specified nodes
 * @param j - first node of data to be swapped
 * @param k - second node of data to be swapped
 */
void swapData(Node* j, Node* k);

void printLinkedListOut(LinkedList* list);