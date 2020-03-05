/** bstAsLinkedDT.c
* ================================================================
* Name: first last
* Section: xxx
* Project: Header for BST library
* =================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "bstAsLinkedDS.h"

/** ----------------------------------------------------------
 * insertBST() inserts an item into a BST
 * @param node - a pointer to the root of the BST to instert
 * the item in.
 * @param item - the data item to insert into the BST
 * @return returns a pointer to the root of the BST
 * ----------------------------------------------------------
 */
BSTnode* insertBST(BSTnode* node, int item) {
    if (node == NULL) {
        BSTnode *newNode = malloc(sizeof(BSTnode));
        newNode->data = item;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (item < node->data) {
        node->left = insertBST(node->left, item);
    } else {
        node->right = insertBST(node->right, item);
    }
    return node;
}

/** ----------------------------------------------------------
 * printInorderBST() traverses and prints the BST
 * inorder.
 * @param node - a pointer to the root of the BST
 * ----------------------------------------------------------
 */
void printInorderBST(BSTnode* node) {
    if (node == NULL) {
        return;
    }
    printInorderBST(node->left);
    printf("%d ",node->data);
    printInorderBST(node->right);
}

/** ----------------------------------------------------------
 * printPreorderBST() traverses and prints the BST
 * preorder.
 * @param node - a pointer to the root of the BST to
 * ----------------------------------------------------------
 */
void printPreorderBST(BSTnode* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ",node->data);
    printPreorderBST(node->left);
    printPreorderBST(node->right);
}

/** ----------------------------------------------------------
 * printPostorderBST() traverses and prints the BST
 * postorder.
 * @param node - a pointer to the root of the BST
 * ----------------------------------------------------------
 */
void printPostorderBST(BSTnode* node) {
    if (node == NULL) {
        return;
    }
    printPostorderBST(node->left);
    printPostorderBST(node->right);
    printf("%d ",node->data);
}