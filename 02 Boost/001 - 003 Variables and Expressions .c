/*
Please note: One major fundamental concept on which this 💥 tutorial is based, is providing solutions to exercises through the use of C functions. Please read the Functions link below carefully. In addition, when you're ready to begin the exercises, go through the Syntax Tour Guide by clicking the C Guidance button under the Exercise tab.

In this chapter, you will learn about and practice data types, variables, expressions and functions.

Study:
💥 Data types and Variables
See also: integer (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Integer-Types) and real number (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Real-Number-Types) types.
💥 Operators and Expressions
See also: assignment (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Assignment-Operators) and arithmetic (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Arithmetic-Operators) operators.
💥 Functions
See also: Functions (https://en.wikipedia.org/wiki/Function_(computer_programming))

Emphasize:
Variables
char, short, int and long data types
signed, unsigned
float and double data types
Assignment, compound assignment
Operators, operands
Operator precedence and associativity (https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B#Operator_precedence)
*/


/*
Exercise 1: BoxSurfaceArea
A simple one to start with, implement a function that is given 3 positive integers representing the length, width and height of a three-dimensional box and returns the surface area of the box.
For example, the surface area of a box with 8cm length, 5cm width and 12cm height = 392 cm2.
Study:
What is the value range (https://en.wikipedia.org/wiki/C_data_types#Main_types) of a 32-bit unsigned int type?
What is the value range of a 32-bit signed int type?
*/


/*
 * Click the 'C Guidance' button to get help on the structure of C functions
 */

/* The next line is the function prototype:
 * Name: BoxSurfaceArea
 * Arguments type: unsigned int
 * Return type: unsigned int
 */



unsigned BoxSurfaceArea(unsigned length, unsigned width, unsigned height)
{
    /* This is an 'unsigned int' type local variable, initialized to 0 */
    unsigned area = 0;

    /* ### Write your code below this line ### */
	unsigned l = length, w = width, h = height;
    area = (l*w + w*h + h*l) * 2;
    
    return area;
}



/*
Exercise 2: FahrenheitToCelsius
Yet another simple task, implement a function that converts Fahrenheit temperature to Celsius.

Study:
There are two categories of numeric data types: Integer and Floating Point (FP).
The C language provides numeric conversion from Integer to FP and vice versa.
What is the type of the numeric literal 7?
Explain the difference between the numeric literals 5 and 5.0
*/

float FahrenheitToCelsius(int fahrenheit)
{
    /* This is a float-type local variable, initialized to 0 */
    float celsius = 0.0f;
	celsius = ((float)fahrenheit - 32.0f) * (5.0f / 9.0f);

    return celsius;
}


/*
Exercise 3: ReverseNumber
A bit more difficult, the function ReverseNumber is given a number between 100 and 999, and your task is to have the function return the number in reverse. For example, for number 123 the function should return 321.

Constraints:
Please don't use loops in the solution of this exercise.

Study:
Modulo Operato (https://en.wikipedia.org/wiki/Modulo)
*/

unsigned ReverseNumber(unsigned number)
{
    unsigned ones_digit, tens_digit, hundreds_digit, result;

    /* ### Write your code below this line ### */
    hundreds_digit = number / 100;
    tens_digit = (number - hundreds_digit * 100 )/ 10; /*(number / 10) % 10*/
	ones_digit = number - hundreds_digit * 100 - tens_digit *10; /*number % 10*/
    result = ones_digit * 100 + tens_digit * 10 + hundreds_digit;
    
    
    result = ones_digit * 100 + tens_digit * 10 + hundreds_digit;

    return result;
}


unsigned ReverseNumber_suggested(unsigned number)
{
    unsigned ones_digit, tens_digit, hundreds_digit;

    ones_digit = number % 10;

    tens_digit = (number/ 10) % 10;

    hundreds_digit = number / 100;

    return ones_digit * 100 + tens_digit * 10 + hundreds_digit;
}