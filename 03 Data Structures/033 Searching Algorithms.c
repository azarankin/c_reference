/*
In this worksheet you will implement several searching algorithms.

Study:
Search Algorithm(https://en.wikipedia.org/wiki/Search_algorithm).

Emphasize:
Binary search algorithm
*/



/*
Exercise 18: BinarySearch

Requirements:
Implement the Binary Search (https://en.wikipedia.org/wiki/Binary_search) algorithm.
Implement the helper functions listed below.

Constraints:
SearchHelper: Recursively looks for the data and stores the index of the data found in the variable pointed to by the pointer.
*/




//API search.h

#pragma once

#include <stddef.h>

#include "status.h"

status_type Search(const int* array, size_t size, int data, size_t* index);



//function
#include <stddef.h>

#include "status.h"
#include "search.h"




/**
* Helper function that performs binary search recursively
*
* @param array The sorted array to search in
* @param first The starting index of current search range
* @param last The ending index of current search range
* @param data The target value to find
* @param index Pointer to store found index
* @return SUCCESS if found, ERROR if not found
*/
/*non-static*/ status_type SearchHelper(const int* array, size_t first, size_t last, int data, size_t* index)
{
   size_t middle;
   /* Calculate middle point of current range */
   middle = (first + last) / 2;

   /* Check if middle element is the target */
   if (array[middle] == data)
   {
       *index = middle;
       return SUCCESS;
   }

   /* If middle element is smaller than target and we can go right */
   if (array[middle] < data && middle < last)
       return SearchHelper(array, middle + 1, last, data, index);

   /* If middle element is larger than target and we can go left */
   if (array[middle] > data && middle > 0)
       return SearchHelper(array, first, middle - 1, data, index);

   /* Target not found in the valid range */
   return ERROR;
}

/**
* Main search function that initiates binary search
*
* @param array The sorted array to search in
* @param size Size of the array
* @param data The target value to find
* @param index Pointer to store found index
* @return SUCCESS if found, ERROR if not found
*/
status_type Search(const int* array, size_t size, int data, size_t* index)
{
   return SearchHelper(array, 0, size, data, index);
}