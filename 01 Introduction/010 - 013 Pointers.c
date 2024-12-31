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
Exercise 10: Divide
Implement a function that is given 4 parameters: 2 integers - numerator and denominator, and 2 pointers to integers. The function should compute the value numerator / denominator, and set the integers, pointed to by the pointers, to the resulting quotient and the remainder, respectively.
A valid result must satisfy the equation: quotient * denominator + remainder = numerator.
Please note: The function should return 0 if the result is valid, otherwise it should return -1.
Study:
Please read the Pointers page on the Research tab and take a look at the interactive C Guidance in this tab.
In the following code snippet, what is the value of x after the code is executed?
int x;
int* i_ptr = &x;
*i_ptr = 17;
*/


int Divide(int numerator, int denominator, int* quotient, int* remainder)
{

    if (denominator == 0) {
        return -1;
    }



    /* ### Write your code below this line ### */

    *quotient = numerator / denominator;
    *remainder = numerator % denominator;


    
    return 0;
}






/*
Exercise 11: FindMinMax
In this exercise you will be required to manipulate an array that is passed as an argument to the function. Please carefully read the page Pointers, with close attention to the paragraph titled Passing Array to Function.
Implement the function FindMinMax, which is given four parameters: an array of integers, the array's size and two pointers to integers. The function should find the minimum and the maximum values in the array and store them in the variables pointed to by the pointers, respectively.
*/



void FindMinMax(const int array[], int size, int* min, int* max)
{
    /* ### Write your code below this line ### */
    int local_min=0, local_max=0, i=0;
	local_min = local_max = array[0];
    
    for(i=1;i<size;++i)
    {
    if(array[i]<local_min) local_min=array[i];
    if(array[i]>local_max) local_max=array[i];
    }
    
    *min = local_min;
    *max = local_max;
}



/*
Exercise 12: CopySelected
In this exercise the function is given three parameters: an array of integers, the array's size and a second, not initialized, array of the same size as the first one.
The function should find all the odd numbers and sequentially store them in the second array, while maintaining their order. The function should also return the total number of odd numbers found.
*/


int CopySelected(const int array[], int size, int odd_numbers[])
{
    /* ### Write your code below this line ### */
	int odd_number_counter = 0, i = 0;

    for(i=0;i<size;++i)
    {
        if(array[i]%2!=0)
        {
			odd_numbers[odd_number_counter] = array[i];
            ++odd_number_counter;
        }
    }
    
    return odd_number_counter;
}





/*
In this assignment the function is a given a sorted array of integers, where each number may appear more than once. The array's size and a pointer to an integer are also provided to the function.

The function needs to accomplish the following:

Find the (first) longest sequence of numbers of the same value.
Store the number from that sequence in the variable that the pointer is pointing at.
Return the length of the sequence.
For instance: if the array is initialized with the values [1, 1, 1, 3, 5, 5, 7, 7, 7, 7, 7, 9, 9, 9], the function should store the value 7 in the variable pointed by the pointer and return 5, which is the length of the 7's sequence.
*/

int MaxInstances(const int array[], int size, int* number) {
 int repeated_number;
 int number_counter;
 int max_counter;
 int most_repeated_number;
 int i;

 if (size == 0) {
  return 0;
 }

/*begin from the firt element and count it once*/
 repeated_number = array[0];
 number_counter = 1;
 /*store the biggest counter value and the number*/
 max_counter = 1;
 most_repeated_number = array[0];

/*iterate over the array and check how much the number repeated*/
 for (i = 1; i < size; ++i) {
  if (array[i] == repeated_number) 
  {
   ++number_counter;
  } 
  else /*another nomber appear over itteration*/
  {
   /*between sequences*/
   if (number_counter > max_counter) 
   {
    max_counter = number_counter;
    most_repeated_number = repeated_number;
   }
   repeated_number = array[i];
   number_counter = 1;
  }
 }

/*check the last sequence of the array*/
 if (number_counter > max_counter) 
 {
  max_counter = number_counter;
  most_repeated_number = repeated_number;
 }

 *number = most_repeated_number;
 return max_counter;
}





/*suggestet*/

int MaxInstances_suggested(const int array[], int size, int* number)
{
 int i = 0,  i_0 = 0, curr_num = 0, curr_count = 0, max_num = 0, max_count = 0;

 max_count = 0;
 curr_count = 1;

 /* The outer loop is executed as many as the number of 'sequences' in the array */
 for ( i = 1, i_0 = 0; i < size;  i = i_0)
 {
  /* The inner loop counts the number of instances in the current 'sequence' */
  for (curr_num = array[i_0]; i < size && curr_num == array[i]; ++i)
  {/*if(curr_num == array[i]) continue;*/}

  curr_count = i - i_0;

  if (curr_count > max_count)
  {
   max_num = curr_num;
   max_count = curr_count;
  }
 }

 *number = max_num;

 return max_count;
}
