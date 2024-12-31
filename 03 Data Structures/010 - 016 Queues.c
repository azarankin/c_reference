/*
In this worksheet you will implement a Queue.

Study:
Queue (https://en.wikipedia.org/wiki/Queue_(abstract_data_type)).
*/


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


/* ### Write your code below this line ### */

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