/*
In this worksheet you will implement a Queue.

Study:
Queue (https://en.wikipedia.org/wiki/Queue_(abstract_data_type)).
*/


#include "009 - 012 Linked Lists.c"



//API queue.h

#pragma once

#include "status.h"
#include "list.h"

typedef struct Queue
{
    list_type list;
} queue_type;

void QueueConstruct(queue_type* queue);
void QueueDestruct(queue_type* queue);
status_type QueueEnqueue(queue_type* queue, int data);
int QueueDequeue(queue_type* queue);





#include "queue.h"
#include "list.h"
#include <stdlib.h>
/* ### This struct will be used in QueueEnqueue */
typedef struct
{
    list_node_type link;
    int data;
} queue_node_type;


/*
Exercise 13: QueueConstruct

Requirements:
Initialize the Queue's control struct by initializing the Linked List contained within the Queue.
*/





void QueueConstruct(queue_type* queue) {
    ListConstruct(&queue->list);
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
