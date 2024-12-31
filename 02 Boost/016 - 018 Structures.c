/*
In this chapter, you will learn about and practice structures.

Study:
Structures (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Structures). Pay attention to the difference between:
Structure definition (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Defining-Structures).
Structure declaration.
Structure variables definition (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Declaring-Structure-Variables).

Emphasize:
User defined data types
Structure's members
Structure initialization
Pass by value
Pass by pointer
*/




/*
Exercise 17: Distance
Given 2 points on a coordinate plane (https://en.wikipedia.org/wiki/Cartesian_coordinate_system), the function should return the (float) distance between the 2 points (https://en.wikipedia.org/wiki/Cartesian_coordinate_system#Distance_between_two_points).
Constraints:
You might want to use C math functions.
*/


#include <math.h>

struct Point
{
    int x, y;
};

/* ### Write your code below this line ### */


float Distance(struct Point a, struct Point b)
{
	float x = 0, y = 0;
	x = b.x - a.x;
    y = b.y - a.y;
    
    return sqrt(pow(x,2) + pow(y,2));
}





/*
Exercise 18: IsLess
In this exercise you will practise using the indirect member access operator (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Member-Access-Expressions) (→).
This function is an example of a compare function, which can be used as a callback function (https://en.wikipedia.org/wiki/Callback_(computer_programming)) in algorithms such as sorting.
The function is given two const pointers to struct Person type variables. You already have the struct defined for you. If the first variable's ID number is lower than the second variable's ID number, the function should return 1 (true), otherwise it should return 0 (false).
*/


struct Person
{
    unsigned id_num;
    char name[32];
    char address[128];
    unsigned tel_num;
};

/* ### Write your code below this line ### */
int IsLess(const struct Person* p1, const struct Person* p2)
{
    return (p1 -> id_num < p2 -> id_num); /*? 1 : 0*/
}