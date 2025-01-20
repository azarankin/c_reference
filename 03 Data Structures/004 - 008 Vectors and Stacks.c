/*
In this chapter you will learn about and implement a resizable Vector data structure using a fixed sized array.

Study:
Explore the header file (under the API tab) and understand the vector_type struct and the API function declarations.
Array (https://en.wikipedia.org/wiki/Array_(data_structure))
Stack (https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
LIFO (as opposed to FIFO)

Emphasize:
Applications of stacks (https://en.wikipedia.org/wiki/Stack_(abstract_data_type)#Applications_of_stacks)

Highlights:
Capacity vs Size
What is the difference between a Vector and a Stack?
*/


/*
Exercise 4: VectorConstruct

Requirements:
Allocate capacity int elements for the Vector's array.
Initialize the Vector's control struct.
Handle memory allocation failures and return ERROR or SUCCESS according
*/


//*possibel staus.h
#pragma once

/* Enum for status return values */
typedef enum
{
    SUCCESS = 1, /* Indicates successful operation */
    ERROR = 0    /* Indicates a failure */
} status_type;

typedef int status_type;

#define SUCCESS 1
#define ERROR 0


// API vector.h

#pragma once

#include <stddef.h> /* size_t */

#include "status.h"

typedef struct
{
    size_t capacity; /* max number of elements in the array */
    size_t size;     /* number of "occupied" elements */
    int* array;      /* the dynamically allocated array */
} vector_type;

/* Initialize a given vector_type struct and allocate an int array of 'capacity' length. */
status_type VectorConstruct(vector_type* vector, size_t capacity);

/* Release the array allocated to this Vector. */
void VectorDestruct(vector_type* vector);

/* Increase/decrease the amount of "occupied" elements. */
void VectorResize(vector_type* vector, int addition);

/* Push an element to the top of the Vector. */
void VectorPush(vector_type* vector, int data);

/* Pop and return an element from the top of the Vector. */
int VectorPop(vector_type* vector);


#include <stddef.h>
#include <stdlib.h> /* malloc, free */
#include "vector.h"



/* Initialize a given vector_type struct and allocate an int array of 'capacity' length. */
status_type VectorConstruct(vector_type* vector, size_t capacity)
{
    /* Check if the vector pointer is NULL */
    if (vector == NULL)
    {
        return ERROR;
    }

    /* Allocate memory for the array */
    vector->array = (int*)malloc(capacity * sizeof(int));

    /* Check if memory allocation was successful */
    if (vector->array == NULL)
    {
        return ERROR;
    }

    /* Initialize the vector's control struct */
    vector->capacity = capacity;
    vector->size = 0;

    return SUCCESS;
}


/*

Exercise 5: VectorDestruct

Requirements:
Free the memory allocated for the Vector's array.
*/


/* Release the array allocated to this Vector. */
void VectorDestruct(vector_type* vector)
{

    if (vector->array != NULL) {
        free(vector->array);
        //vector->array = NULL;
    }

}



/*
Exercise 6: VectorResize
Requirements:
Update the count of occupied elements in the Vector.
Use assert to ensure that size does not exceed the Vector's capacity.
*/

/* Increase/decrease the amount of "occupied" elements. */
void VectorResize(vector_type* vector, int addition){
    assert(vector != NULL);
	assert(vector->capacity >= vector->size + addition);
    vector->size += addition;
}



/*
Exercise 7: VectorPush
Requirements:
Append the given element value to the end of the Vector's array.
Update the Vector's size.
Use assert to ensure that size does not exceed the Vector's capacity.
*/


/* Push an element to the top of the Vector. */
void VectorPush(vector_type* vector, int data){
    assert(vector->size < vector->capacity);
    vector->array[vector->size] = data;
	++vector->size;
}


/*
Exercise 8: VectorPop
Requirements:
Remove and return the last element in the Vector's array.
Update the Vector's size.
Use assert to ensure that size is greater than zero.
*/

/* Pop and return an element from the top of the Vector. */
int VectorPop(vector_type* vector){
    assert(vector != NULL);
    assert(vector->size > 0);

    --vector->size;

    return vector->array[vector->size];
}