/*
In this chapter, you will learn about and practice statements that involve comparison and logical operators.

Study:
💥 Conditional Execution
See also: The if Statement (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#The-if-Statement) and Conditional (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Conditional-Expressions) Expressions.
See also: Comparison (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Comparison-Operators) and Logical (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Logical-Operators) Operators.

Emphasize:
&& (and) operator
|| (or) operator
Flow control

Highlights:
The result of comparison and logical expressions is either 1 (for true) or 0 (for false).
The value of x in the expression x = (a > 3); will be 1 if a is greater than 3, and 0 otherwise.
Comparison and logical operators test the truth value of an expression:
An expression that evaluates to zero is considered false.
Any nonzero expression is considered true.
*/

/*
Exercise 4: TriangleType
Implement a function that is given 2 positive integers representing 2 angles of a triangle. If the triangle is right, isosceles, or both, the function should return 1, 2 or 3, respectively. Otherwise it shoud return 0.

Keep in mind that the parameter values may be invalid. How would you handle this?

Study:
What is the difference between the following statements?
if (x == 3) { ... }
if (x = 3) { ... }
What input values are considered to be an error in this exercise?
What are the conventional ways for error handling in C?
*/


/*
xercise 4: TriangleType
Implement a function that is given 2 positive integers representing 2 angles of a triangle. If the triangle is right, isosceles, or both, the function should return 1, 2 or 3, respectively. Otherwise it shoud return 0.
Keep in mind that the parameter values may be invalid. How would you handle this?
Study:
What is the difference between the following statements?
if (x == 3) { ... }
if (x = 3) { ... }
What input values are considered to be an error in this exercise?
What are the conventional ways for error handling in C?
*/

/* ### Write your code below this line ### */
int TriangleType(unsigned angle1, unsigned angle2) {
    unsigned angle3;
    int isRight;
    int isIsosceles;

    if (angle1 <= 0 || angle2 <= 0 || angle1 + angle2 >= 180) {
        return -1;
    }

    angle3 = 180 - (angle1 + angle2);
    if (angle3 <= 0) {
        return 0;
    }

    isRight = (angle1 == 90 || angle2 == 90 || angle3 == 90);
    isIsosceles = (angle1 == angle2 || angle1 == angle3 || angle2 == angle3);

    if (isRight && isIsosceles) return 3;
    if (isRight) return 1;
    if (isIsosceles) return 2;
    return 0;
}





/*
Exercise 5: Maximum
Implement a function that is given 2 integers. It should return the greater one. You are encouraged to use the Conditional Operator for this exercise.

Study:
What is wrong with the following expression?
(a < 5) ? { x = 1; y = 7; } : { x = 3; y = 9; }
What is the difference between the if-else statement and the conditional expression?
*/

/* ### Write your code below this line ### */
int Maximum(int number1, int number2)
{
    return number1 > number2 ? number1 : number2;
}




/*
Exercise 6: IsRightTriangle
Given the lengths of the 3 edges of a triangle, the function should return 1 (true) if the triangle is 'right-angled', otherwise it should return 0 (false).
Please note: The lengths of the edges can be given to the function in any order. You may want to implement some secondary helper functions.

Study:
Learn about Static (https://en.wikipedia.org/wiki/Static_(keyword)) Functions and Variables.
*/


/* ### Write your code below this line ### */
int IsRightTriangle(float edge1, float edge2, float edge3)
{
    float longest_edge, second_edge, third_edge;
    
    if(edge1 > edge2 && edge1 > edge3)
    {
    	longest_edge = edge1;
        second_edge = edge2;
        third_edge = edge3;
    }
    else if(edge2 > edge1 && edge2 > edge3)
    {
    	longest_edge = edge2;
        second_edge = edge1;
        third_edge = edge3;
    }
    else
    {
      	longest_edge = edge3;
        second_edge = edge1;
        third_edge = edge2;
    }
    

	return longest_edge*longest_edge ==  second_edge * second_edge + third_edge*third_edge;
}



/*suggested*/

static int IsRight(float a, float b, float c);
static int IsEqual(float a, float b);
static float Abs(float x);

int IsRightTriangle_suggested(float a, float b, float c)
{
    if (IsRight(a, b, c)) return 1;
    if (IsRight(a, c, b)) return 1;
    if (IsRight(b, c, a)) return 1;

    return 0;
}

static int IsRight(float a, float b, float c)
{
    return IsEqual(a * a + b * b, c * c);
}

static int IsEqual(float a, float b)
{
    #define EPSILON 0.01
    return (Abs(a - b) < EPSILON);
}

static float Abs(float x)
{
    return (x < 0) ? -x : x;
}


/*
*in C
*static functions helps encapsulate and not awailable the function on #include
*static functions is file level scope
*/