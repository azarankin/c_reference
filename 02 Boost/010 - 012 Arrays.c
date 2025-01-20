/*
In this chapter, you will learn and practice how to deal with arrays of elements of specific types.

Study:
 Arrays
See also Arrays (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Arrays). (GNU C reference manual)

Emphasize:
Random Access
Array Subscripts (Index Operator (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Array-Subscripts))

Highlights:
What is the index of the first element?
*/


/*
Exercise 10: IndexOf
Implement a function that is given three parameters: an array of integers, the number of items and an integer value (the element) to search for in the array. The function should return the first index at which the given element is found in the array, or -1 if it is not present.
For example, the index of the element 56 in the array [12, 45, 32, 56, 27] is 3.
Study:
Note the const type qualifier (https://en.wikipedia.org/wiki/Type_qualifier) that is applied to the array parameter.
Why is it so important?
Learn about the size_t (https://www.google.com/search?q=c+size_t) type.
Which header file it is defined in?
*/

/*type qualifier: const , volatile , restrict and Atomic */
/*size t is unsigned int in 32bit system*/

#include <stddef.h>

size_t IndexOf(const int array[], size_t size, int element)
{
    size_t i = 0;
    
    for (i=0; i < size; ++i)
    {
        if (array[i] == element)
        {
            return i;
        }
    }
    return -1;
}


/*
Exercise 11: CalculateAverage
Implement a function that is given an array of integers and the number of items. It should return the rounded (to the nearest integer (https://en.wikipedia.org/wiki/Rounding#Rounding_to_the_nearest_integer)) average of the numbers.
*/


#include <stddef.h>
int CalculateAverage(const int array[], size_t size)
{
    
    int sum = 0;
    size_t i = 0;
    
    if (size == 0) return 0; 
    
    for(i=0;i<size;++i)
    {
    	sum += array[i];
    }
    
    return (int)((float)sum / (float)size + 0.5f);
}



/*
Exercise 12: MoveElements
Given an array of integers: Implement a function that moves the initial segment of consecutive array elements to the end of the array. The elements that follow the segment should all be moved to the left.
For example: Given the array 3, 7, 2, 8, 5, 9, 1, 4: The result of moving the initial segment that includes 3 elements (i.e., [3, 7, 2]) is 8, 5, 9, 1, 4, 3, 7, 2.
The function is given the following arguments:
An array of integers (array)
The number of elements in the array (size)
The number of elements in the segment (count)
Constraints:
The array's elements should be moved in place
Do not use an auxiliary array
You can only use a single temporary int variable
*/

#include <stddef.h>

void ShiftLeft(int array[], size_t size)
{
    int j;
    for (j = 0; j < size - 1; ++j) {
        array[j] = array[j + 1];
    }
}

void MoveElements(int array[], size_t size, size_t count)
{
	int i = 0, temp;
    if(count >= size || count == 0) return;
    
    for (i = 0; i < count; ++i) {
        temp = array[0];

		ShiftLeft(array, size);

        array[size - 1] = temp;
    }
}