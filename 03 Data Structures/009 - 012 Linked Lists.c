/*
In this chapter you will learn about and implement a Doubly Linked List data structure.

Study:
💥 Linked List

Emphasize:
Intrusive Linked List (https://www.google.com/search?q=intrusive+linked+list)
Doubly linked list

Highlights:
Node (https://en.wikipedia.org/wiki/Node_(computer_science))
Singly Linked List
List Traverse
Callback Function (https://en.wikipedia.org/wiki/Callback_(computer_programming))
*/




/*
Exercise 9: ListConstruct
Please note that the implementation of the ListIsEmpty function is already provided.
Requirements:
Initialize the control struct of the Linked List.
An initialized list is represented as an empty list.
Study:
Look into the implementation of ListIsEmpty and determine what values the head node's pointers should have when the list is empty.
*/



//API list.h


#pragma once

/* single node */
typedef struct ListNode list_node_type;

struct ListNode
{
	list_node_type* next;
	list_node_type* prev;
};

/* List control struct */
typedef struct List
{
    /* A standalone (dummy) node; doesn't have data */
    list_node_type head;
} list_type;

/* Match function signature. Used in ListFind API. */
typedef int(*list_isequal_type)(const list_node_type*,const void*);

/*
 * This is an example of a client Linked List element (intrusive):
 *
 * struct myData
 * {
 *     list_node_type link;  <-- the address of which is given to Insert/Remove
 *     int data;
 *     float more_data;
 * };
 */

/* Initialize a given list_type struct. */
void ListConstruct(list_type* list);

/* Insert a new node after a given node position.*/
void ListInsert(list_node_type* position, list_node_type* node);

/* Remove a given node from the list. */
void ListRemove(list_node_type* node);

/* Return 1 (true) or 0 (false), if the list is empty or not, respectively. */
int ListIsEmpty(const list_type* list);

/* Find and return a node which has data that matches the given data parameter.
 * The match is determined by calling the 'isequal' function. */
list_node_type* ListFind(const list_type* list, list_isequal_type isequal, const void* data);




// function


#include "list.h"
#include <stddef.h>
/* ### Write your code below this line ### */


/* Initialize a given list_type struct. */
void ListConstruct(list_type* list)
{

    list->head.next = &list->head;
    list->head.prev = &list->head;
}






/* ### ------------------------------- ### */
int ListIsEmpty(const list_type* list)
{
    return (list->head.next == &list->head && list->head.prev == &list->head);
}




/*
Exercise 10: ListInsert
Requirements:
Insert a node (the second argument) after position (the first argument).
*/


/* Insert a new node after a given node position. */
void ListInsert(list_node_type* position, list_node_type* node)
{
    list_node_type* next = position->next;

    position->next = node;
    node->prev = position;
    next->prev = node;
    node->next = next;
}



/*
Exercise 11: ListFind
Requirements:
Search for a specific node in the Linked List using the given match function and data (see the API file for the match function signature).
Return pointer to the node if the data is found; otherwise, return NULL.
Constraints:
The match function compares two data elements - one contained in a node and the other pointed to by a pointer - and returns 1 (true) if they are equal; otherwise, it returns 0 (false).
The concrete signature definition can be found in the API tab.
*/

/* Find and return a node which has data that matches the given data parameter. */
list_node_type* ListFind(const list_type* list, list_isequal_type isequal, const void* data)
{
    list_node_type* current = list->head.next;

    while (current != &list->head)
    {
        if (isequal(current, data))
        {
            return current;
        }
        current = current->next;
    }

    return NULL;
}




/*
Exercise 12: ListRemove

Requirements:
Remove a node from the Linked List.

Study:
What might happen if the client tries to remove the head node?
is there a way to detect such a case?
What can you do to help the client detect an unintentional attempt to remove a node again?
*/


/* Remove a given node from the list. */
void ListRemove(list_node_type* node)
{
    if (node->next == NULL || node->prev == NULL) {
        return;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;
    
    /* A segmentation violation will be raised when attempting to remove the node again. */

    node->next = NULL;
    node->prev = NULL;
}






/*
Exercise 14: QueueEnqueue
Push a new element to the end of the Queue.
Requirements:
Allocate memory for the new node and initialize it with the given data.
Insert the node into the Queue's Linked List.
Handle memory allocation failures and return ERROR or SUCCESS accordingly.
*/



status_type QueueEnqueue(queue_type* queue, int data) {
    /* Allocate memory for the new node */
    queue_node_type* new_node = (queue_node_type*)malloc(sizeof(queue_node_type));
    
    /* Check if memory allocation failed */
    if (new_node == NULL) {
        return ERROR;
    }
    
    /* Initialize data */
    new_node->data = data;
    
    /* Insert the node into the list before the head node
     * This adds it to the end of the queue */
    ListInsert(&queue->list.head, &new_node->link);
    
    return SUCCESS;
}


/*
Exercise 15: QueueDequeue
Pop the element from the front of the Queue and return its data.

Requirements:
Remove the last node from the Queue's Linked List.
Free the memory allocated to the node.
Return the node's data.
*/



int QueueDequeue(queue_type* queue) {
    /* Get the node at the front of the queue (last node before head) */
    list_node_type* node_to_remove = queue->list.head.prev;
    
    /* Get the queue_node_type pointer using the list_node_type address */
    queue_node_type* queue_node = (queue_node_type*)node_to_remove;
    
    /* Store the data before we free the node */
    int data = queue_node->data;
    
    /* Remove the node from the list */
    ListRemove(node_to_remove);
    
    /* Free the memory */
    free(queue_node);
    
    return data;
}



/*
Exercise 16: QueueDestruct

Requirements:
Empty the Queue by removing all the elements from the list.
Free the memory allocated to the nodes.

Constraints:
For testing purpose, please remove the nodes from first to last.
*/

void QueueDestruct(queue_type* queue)
{
    list_node_type* iter = NULL;

    for (iter = queue->list.head.next; !ListIsEmpty(&queue->list); iter = queue->list.head.next)
    {
        ListRemove(iter);
        free(iter);
    }
}
