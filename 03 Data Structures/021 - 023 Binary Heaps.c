/*
In this worksheet you will implement Binary Heap.

Study:
Heap(https://en.wikipedia.org/wiki/Heap_(data_structure)).
*/


/*
Exercise 18: HeapPush
Push a new element to the max Heap.
Please note: The HeapConstruct function is already implemented for you, and the vector, which the Heap is based on, is initialized with sufficient capacity.

Requirements:
Resize by one the Heap's vector.
Provide the given data to the HeapifyUp function to place it in the right index.
Return SUCCESS if the vector has free space, or ERROR otherwise.

Constraints:
Complete the implementation of the HeapifyUp function.
This function will also be used in the next execise.
*/


//API heap.h
#pragma once

#include "status.h"
#include "vector.h"

typedef struct Heap
{
    vector_type vector;
} heap_type;

status_type HeapPush(heap_type* heap, int data);
status_type HeapPop(heap_type* heap, int* data);

/* Utility function: Converts int's array into a max heap */
void MakeHeap(int* array, size_t size);







//function



#include <stddef.h>

#include "heap.h"

static void HeapifyUp(int* array, size_t top, size_t hole, int data)
{
    size_t parent;

    /* Traverse up the tree to maintain heap property */
    for (parent = (hole - 1) / 2; 
         hole > top && array[parent] < data; 
         hole = parent, parent = (parent - 1) / 2)
    {
        /* Move the parent's value down to the current hole */
        array[hole] = array[parent];
    }

    /* Place the new value at its correct position */
    array[hole] = data;
}


/* ### To be implemented later (for HeapPop) ###
static void AdjustHeap(int* array, size_t size, size_t hole, int data)
*/



/* ### Write your code below this line ### */


status_type HeapPush(heap_type* heap, int data)
{
    size_t current_size = 0;
    int* array = NULL;

    /* Check if heap exists */
    if (heap == NULL)
    {
        return ERROR;
    }

    /* Get current size and array */
    current_size = heap->vector.size;
    array = heap->vector.array;

    /* Check if there is enough capacity in the heap */
    if (current_size >= heap->vector.capacity)
    {
        return ERROR;  /*Heap is full*/
    }

    /* Increase the size of the heap */
    heap->vector.size++;

    /* Insert the new element and restore the heap property */
    HeapifyUp(array, 0, current_size, data);

    return SUCCESS;
}



/*
Exercise 18: HeapPop
Pop and return the element with the highest value in the Heap.

Requirements:
Store the top item's data in the variable pointed to by the data pointer.
Call AdjustHeap to re-arrange the Heap, with the adjusted size.
Resize the vector by minus one.
Return ERROR if the vector is empty, or SUCCESS otherwise.

Constraints:
Implement the function AdjustHeap.
This function will also be used in the next execise.
*/




static void AdjustHeap(int* array, size_t size, size_t hole, int data)
{
    const size_t top = hole;
    size_t right = hole;

    for (right = hole; right < size / 2; hole = right)
    {
        right = 2 * (right + 1);
        if (array[right] < array[right - 1])
            right--;

        array[hole] = array[right];
    }

    if (right == (size - 1) / 2)
    {
        right = 2 * (right + 1);
        array[hole] = array[right - 1];
        hole = right - 1;
    }

    HeapifyUp(array, top, hole, data);
}

status_type HeapPop(heap_type* heap, int* data)
{
    size_t size = 0;

    if (heap->vector.size == 0)
        return ERROR;

    *data = heap->vector.array[0];
    size = heap->vector.size - 1;

    AdjustHeap(heap->vector.array, size, 0, heap->vector.array[size]);
    VectorResize(&heap->vector, -1);

    return SUCCESS;
}



/*
Exercise 18: MakeHeap
Convert an array into a max heap data structure.

Requirements:
Using a loop, iterate from (size - 2) / 2 down to 0.
Call AdjustHeap passing the array's item at the index of the loop.
*/



void MakeHeap(int* array, size_t size)
{
    size_t parent = 0;

    for (parent = (size - 2) / 2 + 1; parent > 0; )
    {
        parent--;

        AdjustHeap(array, size - 1, parent, array[parent]);
    }
}








