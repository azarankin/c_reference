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
Exercise 5: AbsoluteValue
Implement a function that is given one (signed) integer, and it should return its absolute value.
For example, the absolute value of -17 is 17, while the absolute value of 97 is 97.
*/

int AbsoluteValue(int value)
{
    return (value < 0) ? (-1 * value) : value;
}

int AbsoluteValue_suggested(int a)
{
    if (a < 0)
    {
        /* Note: here we modify the parameter a, which is a *COPY* of the argument
         * given to this function. The variable of the calling function remains unchanged.
         */
        a = -a;
    }

    return a;
}


/*
Exercise 6: AddVat
In the country of Lilliput, customers are required to pay VAT on their purchases. All products are classified into categories, and the VAT for each category is shown in the table below.
The function AddVat is given two parameters: the product's price and category. Your task is to have the function calculate and return the total price, including VAT.
Constraints:
Please use switch / case in your implementatio
*/

float AddVat(float price, int category)
{
    float total_price = 0;


    switch (category)
    {
        case 1:
            total_price = price * 1.2;
            break;
        case 2:
            total_price = price * 1.2;
            break;
        case 3:
            total_price = price * 1.2;
            break;
        case 4:
            total_price = price * 1.15;
            break;
        case 5:
            total_price = price * 1.08;
            break;
        case 6:
            total_price = price;
            break;

        /* ### Add more cases here ### */
        /* case ?: */

        default:
            total_price = price;
            /* ... */
    }

    return total_price;
}




#include <assert.h>

float AddVat_suggested(float price, int category)
{
    /* ### Please keep in mind that arguments in C are passed by value, so the
     * 'price' parameter is a *COPY* of the argument supplied by the caller function.
     * As a result, we can change 'price' without concern. ### */
    
    switch (category)
    {
        case 1:
        case 2:
        case 3:
            price *= 1.2;
            break;

        case 4:
            price *= 1.15;
            break;

        case 5:
            price *= 1.08;
            break;

        case 6:
            break;

        default:
            /* ### Display error message if 'category' is not valid ### */
            assert(0 && "Unknown category!");
    }

    return price;
}
