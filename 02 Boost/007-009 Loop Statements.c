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
Exercise 7: Fibonacci
Given an index (n), the function should return the value of the n-th element in the Fibonacci Sequence.
Please note: For the indexes 0, 1, 2, 3 - The Fibonacci values are 0, 1, 1, 2 respectively.

Constraints:
Please don't use the recursion method - Only use an iterative loop.
*/

unsigned Fibonacci(unsigned n)
{   
    unsigned current = 0;
    unsigned prev1 = 0;
    unsigned prev2 = 1;
    
    if (n <= 1) return n;
    
    while (n > 1)
    {
        current = prev1 + prev2;
        prev1= prev2;
        prev2 = current;
            
        --n;
    }
    
    
    return current;
}


unsigned Fibonacci2(unsigned n)
{   
    unsigned current;
    unsigned temp;
    unsigned prev;
    int i;
    
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    current = 1;
    prev = 0;
    
    for(i=2;i<=n;++i)
    {
        temp = prev + temp;
        prev = current;
        current = temp;
    }
    
    return current;
}



/*
Exercise 8: IsPrimeNumber
Given a non-negative number as a long integer, the function should return 1 (true) if the number is prime (https://en.wikipedia.org/wiki/Prime_number), otherwise it should return 0 (false).
Please note the two special numbers 0 (zero) and 1.
Tip: Use the Diagnosis button to review the performance data, after testing execution is complete.
Study:
Learn about the typedef statement (https://en.wikipedia.org/wiki/Typedef).
What are the advantages?
What are the limitations?
*/

typedef unsigned long ulong_t;
int IsPrimeNumber(ulong_t number) //1 is true 0 is false
{
    
    int i = 0;
    if (number <= 1) return 0;
    if (number == 2) return 1;
    if (number % 2 == 0) return 0;

    for (i = 3; i * i <= number; i += 2)
    {
        if (number % i == 0) return 0;
    }

    return 1;
}




/*
Exercise 9: SquareRoot
Implement a function called SquareRoot. The function is given a non-negative float number and should return the square root of the number without(https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Babylonian_method) using any library (https://en.wikipedia.org/wiki/C_standard_library) functions.
Click the Hint button to see a suggested pseudocode (https://en.wikipedia.org/wiki/Pseudocode) for the solution.
Study:
What is the difference between while and do-while loops?
*/