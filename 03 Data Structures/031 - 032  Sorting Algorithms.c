/*
In this worksheet you will implement several sorting algorithms.

Study:
Sorting Algorithm (https://en.wikipedia.org/wiki/Sorting_algorithm).
*/


/*
Exercise 18: BubbleSort

Requirements:
Implement the Bubble sort (https://en.wikipedia.org/wiki/Bubble_sort) algorithm.
Use the provided Swap function to swap the values of two elements, as needed.
*/


//API sort.h
#pragma once

#include <stddef.h>

void Sort(int* array, size_t size);


//function
#include "sort.h"

/* ### Please do not edit this function !!! ### */
/* non-static */ void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ### Write your code below this line ### */

/* Bubble sort */
void Sort(int* array, size_t size)
{
    size_t i, j;

    for (i = 0; i < size - 1; ++i)
    {
        for (j = 0; j < size - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                Swap(&array[j], &array[j + 1]);
            }
        }
    }
}



/*
Exercise 18: SelectionSort

Requirements:
Implement the Selection sort (https://en.wikipedia.org/wiki/Selection_sort) algorithm.
Use the provided Swap function to swap the values of two elements, as needed.
*/

/* Selection */
void Sort(int* array, size_t size)
{
    size_t i, j;

    for (i = 0; i < size - 1; i++)
    {
        size_t min_idx = i;

        for (j = i + 1; j < size; j++)
        { 
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        Swap(&array[min_idx], &array[i]);
    }
}
