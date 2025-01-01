/*
Exercise 18: BstInsert-AVL

Requirements:
Improve the BstInsert function by ensuring that the tree remains balanced by rotating it as needed.
Implement the helper functions listed below.

Constraints:
RotateSubTree: Rotates a subtree of the Binary Search Tree.
Rotate: Performs rotations based on a given side, key, and factor.
Balance: Checks the balance factor of a node and performs rotations if necessary to maintain balance.
Modify the InsertHelper function to call Balance.
*/




//API bst.h


#pragma once

#include <stddef.h>

#include "status.h"

typedef enum
{
    LEFT  = 0,
    RIGHT = 1
} side_t;

/* single node */
typedef struct BstNode bst_node_type;

struct BstNode
{
    int key;
    int value;
    bst_node_type* children[2];
};

/* BST control struct */
typedef struct Bst
{
    bst_node_type* root;
} bst_type;

/* action function signature */
typedef void(*bst_action_type)(const bst_node_type*);

status_type BstInsert(bst_type* bst, int key, int data);
int BstFindHeight(const bst_node_type* node);
void BstTraverse(const bst_node_type* node, bst_action_type action);








//function

#include "bst.h"
#include <stdlib.h>

/* Helper function to find maximum of two numbers */
int Max(int a, int b) {
    return (a > b) ? a : b;
}


/* Helper function to recursively insert a node into the BST */
bst_node_type* InsertHelper(bst_node_type* node, bst_node_type* newNode) {
    side_t side;
    
    /* If current node is NULL, this is where we insert */
    if (node == NULL) {
        return newNode;
    }

    /* Determine which side to insert based on key comparison */
    side = (newNode->key < node->key) ? LEFT : RIGHT;
    
    /* Recursively insert into appropriate subtree */
    node->children[side] = InsertHelper(node->children[side], newNode);
    
    /* Balance the tree after insertion */
    return Balance(node, newNode->key);
}

status_type BstInsert(bst_type* bst, int key, int data) {
    bst_node_type* newNode;

    /* Input validation */
    if (bst == NULL) {
        return ERROR;
    }

    /* Allocate memory for new node */
    newNode = (bst_node_type*)malloc(sizeof(bst_node_type));
    if (newNode == NULL) {
        return ERROR;
    }

    /* Initialize new node */
    newNode->key = key;
    newNode->value = data;
    newNode->children[LEFT] = NULL;
    newNode->children[RIGHT] = NULL;

    /* Insert the node into the tree */
    bst->root = InsertHelper(bst->root, newNode);

    return SUCCESS;
}

int BstFindHeight(const bst_node_type* node) {
    int leftHeight = 0, rightHeight = 0;
    /* Base case: an empty tree has height 0 */
    if (node == NULL) {
        return 0;
    }

    /* Recursively find the height of the left and right subtrees */
    leftHeight = BstFindHeight(node->children[LEFT]);
    rightHeight = BstFindHeight(node->children[RIGHT]);

    /* The height of the current node is 1 plus the max of left/right subtree heights */
    return 1 + Max(leftHeight, rightHeight);
}




/*
Exercise 18: BstTraverse

Iterate through the Binary Search Tree nodes and call an action function for each node.


Requirements:
 Use the Inorder traversal (https://en.wikipedia.org/wiki/Binary_search_tree#Traversal).
Call the action callback for each node, passing the node as an argument.

Constraints:
The implementation should be based on recursion method.
No helper function is needed.
*/



void BstTraverse(const bst_node_type* node, bst_action_type action) {
    /* Base case: if node is NULL, return */
    if (node == NULL) {
        return;
    }
    
    /* Inorder traversal: left, node, right */
    BstTraverse(node->children[LEFT], action);   /* Process left subtree */
    action(node);                                /* Process current node */
    BstTraverse(node->children[RIGHT], action);  /* Process right subtree */
}