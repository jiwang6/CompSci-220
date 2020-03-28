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

// Define a node of the linked list
typedef struct node {
    double data;
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
 * @param element - double element to be appeneded
 */
void appendElementLinkedList(LinkedList* list, double element);

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
double getElementLinkedList(LinkedList* list, int position);

/** changeElementLinkedList() - changes element value for position specified
 * @param list - ptr to ll struct
 * @param position - index of element to be replaced
 * @param newElement - new double value to go into position
 */
void changeElementLinkedList(LinkedList* list, int position, double newElement);


/** deleteElementLinkedList() - deletes element at the position specified
 * @param list - ptr to ll struct
 * @param position - index of element to be replaced
 */
void deleteElementLinkedList(LinkedList* list, int position);

/** insertElementLinkedList() - inserts new element into ll struct @ position specified
 * @param list - ptr to ll struct
 * @param position - index of element new value will be inserted into
 * @param element - new double value to go into position
 */
void insertElementLinkedList(LinkedList* list, int position, double element);

/** findElementLinkedList() - finds position of element specified
 * @param list - ptr to ll struct
 * @param element - element value to be found
 */
int findElementLinkedList(LinkedList* list, double element);


/** selSortLinkedList - performs selection sort on ll struct
 * @param list - ptr to ll struct
 */
void selSortLinkedList(LinkedList *list);

/** insertSortLinkedList - performs insertion sort on ll struct
 * @param list - ptr to ll struct
 */
void insertSortLinkedList(LinkedList* list);

/** findSmallest() - finds smallest element in ll struct
 * @param firstNode - ptr to first node struct in ll struct
 * @return - node struct for smallest element in ll struct
 */
Node* findSmallest(Node* firstNode);

/** swapData() - swaps data in two specified nodes
 * @param j - first node of data to be swapped
 * @param k - second node of data to be swapped
 */
void swapData(Node* j, Node* k);