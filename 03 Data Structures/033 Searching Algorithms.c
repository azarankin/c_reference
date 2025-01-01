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

/*non-static*/ status_type SearchHelper(const int* array, size_t first, size_t last, int data, size_t* index)
{
    /* ... */
}

/* ### Write your code below this line ### */


//TODO