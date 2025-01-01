/*
In this chapter, you will learn and practice implementations using recursion.

Study:
Recursion(https://en.wikipedia.org/wiki/Recursion_(computer_science)).
*/


/*
Exercise 18: Fibonacci-R

Return the value of the n-th element in the Fibonacci Sequence.


Constraints:
The implementation should be based on recursion method.
*/

/* ### Write your code below this line ### */
unsigned Fibonacci(unsigned  index) {
    /* Base cases */
    if (index == 0) {
        return 0;
    }
    if (index == 1) {
        return 1;
    }
    
    /* Recursive case: Fib(n) = Fib(n-1) + Fib(n-2) */
    return Fibonacci(index - 1) + Fibonacci(index - 2);
}







