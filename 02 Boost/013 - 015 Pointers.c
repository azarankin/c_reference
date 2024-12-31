/*
In this chapter, you will learn and practice how to deal with pointers in C.

Study:
💥 Pointers
See also: Declaring Pointers (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Declaring-Pointers),
and Initializing Pointers (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Initializing-Pointers).

Emphasize:
Address Operator
Pointer Dereferencing: '*' vs '[ ]'
Pointer Arithmetic
Null Pointer
*/


/*
Exercise 13: Divide
Implement a function that is given 4 parameters: 2 integers - numerator and denominator, and 2 pointers to integers. The function should compute the value numerator / denominator, and set the integers, pointed to by the pointers, to the resulting quotient, rounded towards zero (think of negative numbers) and the remainder, respectively.
A valid result must satisfy the equation: quotient * denominator + remainder = numerator.
Please note: The function should return 0 if the result is valid, otherwise it should return -1.
Study:
In the following code snippet, what is the value of x after the code is executed?
int x;
int* i_ptr = &x;
*i_ptr = 17;
*/


/* ### Write your code below this line ### */
int Divide(int numerator, int denominator, int* quotient, int* remainder)
{
    if(denominator == 0 || quotient == 0 || remainder == 0) return -1;
    
    *quotient = numerator / denominator;
    *remainder = numerator % denominator;
    
    
    return 0;
}




/*
Exercise 14: StringLength
Given a char pointer, the function should return the length of the string (https://en.wikipedia.org/wiki/C_string_handling#Definitions) pointed to by the pointer.
Constraints:
Do not use the Array Subscript Operator ('[ ]'), use the Dereference Operator ('*').
Do not use a numeric counter, use pointer arithmetic.
Use asser (https://en.wikipedia.org/wiki/Assert.h) to verify that the pointer is not NULL.
Study:
Note again the const qualifier that is applied to the pointer parameter.
What is the difference between the following definitions?
const char* str;
char* const str;
What is the type of each of the following definitions?
char* str1 = "Hello world";
char str2[] = "Hello world";
What is the value of each of the following expressions?
sizeof(str1);
sizeof(str2);
StringLength(str1);
StringLength(str2);
*/


/* ### Write your code below this line ### */
#include <assert.h>
#include <stddef.h>

size_t StringLength(const char* str)
{
    const char* ptr = NULL;
	assert(str != NULL);
    ptr = str; 
    while (*ptr != '\0') {
        ++ptr;
    }

    return ptr - str; 
    
}


/*
Exercise 15: StringCompare
Given 2 char pointers, the function should compare the strings pointed to by the pointers lexicographically (case sensitive). It should return a negative, 0 (zero), or positive integer value, if the first string is found to be, less than, equal to, or greater than the second string, respectively.
For example: The (first) string "Fan" is less than the (second) string "Fun", therefore the function should return a negative integer value in this case.
Please note: An uppercase letter is different from its lowercase letter ('A' != 'a').
Constraints:
Do not use the Array Subscript operator ('[ ]'), use the Dereference Operator ('*').
Use assert (https://en.wikipedia.org/wiki/Assert.h) to verify that the pointers are not NULL.
Study:
Learn about the ASCII (https://en.wikipedia.org/wiki/ASCII) t
*/


/* ### Write your code below this line ### */
#include <assert.h>
#include <stddef.h>
int StringCompare(const char* str1, const char* str2) {
    assert(str1 != NULL && str2 != NULL);
    while (*str1 != '\0' && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    return *str1 - *str2;
}



/*
Exercise 16: StringToInteger
Implement a function that converts a string to an integer. A detailed description of the requirements can be found in the man page (https://en.wikipedia.org/wiki/Man_page) of the function atoi (https://man7.org/linux/man-pages/man3/atoi.3.html) (ASCII to integer).
Constraints:
Do not use the Array Subscript Operator ('[ ]'), use the Dereference Operator ('*').
Use assert (https://en.wikipedia.org/wiki/Assert.h) to verify that the pointer is not NULL.
*/

/* ### Write your code below this line ### */

#include <assert.h>
#include <stddef.h>

int StringToInteger(const char* str)
{
    int total, digit, sign;
	assert(str != NULL);
    
    
    sign = 1;
        
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }


	total = 0;
    
    while(*str >= '0' && *str <= '9')
    {
    	digit = *str - '0';
        
        total = total * 10 + digit;
        ++str;
    }
    
    return sign * total;
}