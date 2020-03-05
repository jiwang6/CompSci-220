/** bstAsLinkedDT.h
* ================================================================
* Name: first last
* Section: xxx
* Project: Header for BST library
* =================================================================
*/

#ifndef USAFA_CS220_S20_STUDENT_BSTASLINKEDDS_H
#define USAFA_CS220_S20_STUDENT_BSTASLINKEDDS_H

#include <stdio.h>

typedef struct _bstNode {
    int data;
    struct _bstNode* left;
    struct _bstNode* right;
} BSTnode;

/** ----------------------------------------------------------
 * insertBST() inserts an item into a BST
 * @param node - a pointer to the root of the BST to instert
 * the item in.
 * @param item - the data item to insert into the BST
 * @return returns a pointer to the root of the BST
 * ----------------------------------------------------------
 */
BSTnode* insertBST(BSTnode* node, int item);


/** ----------------------------------------------------------
 * printInorderBST() traverses and prints the BST
 * inorder.
 * @param node - a pointer to the root of the BST
 * ----------------------------------------------------------
 */
void printInorderBST(BSTnode* nodePtr);


/** ----------------------------------------------------------
 * printPreorderBST() traverses and prints the BST
 * preorder.
 * @param node - a pointer to the root of the BST to
 * ----------------------------------------------------------
 */
void printPreorderBST(BSTnode* nodePtr);


/** ----------------------------------------------------------
 * printPostorderBST() traverses and prints the BST
 * postorder.
 * @param node - a pointer to the root of the BST
 * ----------------------------------------------------------
 */
void printPostorderBST(BSTnode* nodePtr);
#endif //USAFA_CS220_S20_STUDENT_BSTASLINKEDDS_H
