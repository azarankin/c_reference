/*
In this worksheet you will implement Binary Search Tree.

Study:
Binary Search Tree(https://en.wikipedia.org/wiki/Binary_search_tree).
*/


/*
Exercise 18: BstInsert
Insert a new element to the Binary Search Tree, based on a given key.
Please note: The BstConstruct function is already implemented for you, and the Binary Search Tree is initialized (the root pointer set to NULL).

Requirements:
Allocate memory for the new node.
Initialize the node with the key and the data, and set the children pointers to NULL.
Call the InsertHelper function to insert the node in the tree.
Handle memory allocation failures and return ERROR or SUCCESS accordingly.

Constraints:
Complete the implementation of the InsertHelper function.
This function should be used to recursively find the appropriate location for inserting the new node.
There is no need for balancing.
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
/* ### To be implemented later (for BstInsert using AVL) ###
static bst_node_type* RotateSubTree(bst_node_type* root, side_t side)
static bst_node_type* Rotate(bst_node_type* node, side_t side, int key)
static bst_node_type* Balance(bst_node_type* node, int key)
*/

/* Helper function to recursively insert a node into the BST */
/* ### non-static ### */ bst_node_type* InsertHelper(bst_node_type* node, bst_node_type* newNode) {
    side_t side;
    
    /* If current node is NULL, this is where we insert */
    if (node == NULL) {
        return newNode;
    }

    /* Determine which side to insert based on key comparison */
    side = (newNode->key < node->key) ? LEFT : RIGHT;
    
    /* Recursively insert into appropriate subtree */
    node->children[side] = InsertHelper(node->children[side], newNode);
    
    return node;
}

/* ### Write your code below this line ### */


status_type BstInsert(bst_type* bst, int key, int data) {
    bst_node_type* newNode = NULL;

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







int Max(int a, int b) {
    return (a > b) ? a : b;
}


int BstFindHeight(const bst_node_type* node)
{
    int leftHeight = 0, rightHeight = 0;
    /* Base case: an empty tree has height 0 */
    if (node == NULL)
    {
        return 0;
    }

    /* Recursively find the height of the left and right subtrees */
    leftHeight = BstFindHeight(node->children[LEFT]);
    rightHeight = BstFindHeight(node->children[RIGHT]);

    /* The height of the current node is 1 plus the max of left/right subtree heights */
    return 1 + Max(leftHeight, rightHeight);
}



