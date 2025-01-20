
/*
Please note: One major fundamental concept on which this 💥 tutorial is based, is providing solutions to exercises through the use of C functions. Please read the Functions link below carefully. In addition, when you're ready to begin the exercises, go through the Syntax Tour Guide by clicking the C Guidance button under the Exercise tab.

In this chapter, you will learn about and practice data types, variables, expressions and functions.

Study:
Data types and Variables
See also: integer (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Integer-Types) and real number (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Real-Number-Types) types.
Operators and Expressions
See also: assignment (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Assignment-Operators) and arithmetic (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Arithmetic-Operators) operators.
Functions
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
Exercise 1: Add
A simple one to start with, implement a function that is given 2 integers and returns the sum of the numbers.
*/



/* The next line is the function prototype:
 * Name: Add, Arguments type: int, Return type: int
 */
int Add(int num1, int num2)
{
    int sum = 0;
    
    sum = num1 + num2;

    return sum;
}



/*
Exercise 2: BoxVolume
C Guidance
Yet another simple task, the function BoxVolume is given 3 positive integers representing the length, width and height of a three-dimensional box and your task is to have the function return the volume of the box.

For example, the volume of a box of 8cm length, 5cm width and 12cm height = 480 cm3.
*/

int BoxVolume(int length, int width, int height)
{
    int box_value = length * width * height;
    
    return box_value;
}


/*
Exercise 3: ThirdAngle
C Guidance
A bit more difficult, implement a function that is given 2 positive integers representing, in degrees, 2 angles of a triangle and returns the third angle.

For example, the third angle in a triangle that has one angle of 62° and the second of 37°, is 81°
*/

int ThirdAngle(int angle1, int angle2)
{
    return 180 - angle1 - angle2;
}

/*
Exercise 4: CirclePerimeter
C Guidance
Implement a function that is given the radius of a circle and returns the perimeter of the circle.

Please note: the constant π is already defined, use i
*/

/* ### The following variable defines the constant PI ### */
const float PI = 3.14;

float CirclePerimeter(float radius)
{
    return  2 * radius * PI;
}