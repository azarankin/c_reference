/*
In this chapter, you will learn and practice additional statements. This time, about statements that involve loops.

Study:
 Loop Statements
See also: The for (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#The-for-Statement), while(https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#The-while-Statement) and do(https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#The-do-Statement) statements.

Emphasize:
Counter-controlled loop
Infinite loop
*/


/*
Exercise 7: RangeSum
Implement a function that is given 2 integers representing the start and the end of a range of (positive) integers. It should return the sum of the odd numbers (https://en.wikipedia.org/wiki/Parity_(mathematics)) within the range.
For example, the expected result for the range 8..17 is 65 (9+11+13+15+17).
Constraints:
Not mandatory: Can you provide a solution without using the if statement?
Study:
Read about the Modulo (https://en.wikipedia.org/wiki/Modulo) Operator.
*/

int RangeSum(int start, int end)
{
    int i, sum = 0;

    i = start;

    while(i%2 == 0)
    {
        ++i;
    }
    
	for(;i<=end;i=i+2)
    {
       sum += i;
    }
    
    return sum;
}



int RangeSum_suggested(int start, int end)
{
    int i, sum = 0;

    /*!(start % 2) is 0 or 1*/
    for (i = start + !(start % 2); i <= end; i += 2)
    {
        sum += i;
    }

    return sum;
}
