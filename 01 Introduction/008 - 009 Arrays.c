/*
In this chapter, you will learn and practice how to deal with arrays of elements of specific types.

Study:
 Arrays
See also Arrays (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Arrays). (GNU C reference manual)

Emphasize:
Random Access
Array Subscripts (Index Operator (https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html#Array-Subscripts))

Highlights:
What is the index of the first element?
*/


/*
Exercise 8: SetAnnualRainfall
Note: This is the first of two related exercises.
In this exercise you will be asked to store a value into the array annual_rainfalls, which has already been defined for you. The array can store up to 100 items. Your function will be called several times, and you must store one value for each one.
Your task is to implement a function that is given 2 integer numbers: The first parameter is a specific year, 1970 and later. The second parameter is the annual rainfall in millimeters (in a certain area) during that year. The function should store a single item in the array, at the index relative to 1970, with the value provided in the second parameter.
For example, for year 2003 the index is 33 (2003 - 1970), and the rainfall for that year could be 753 mm
*/

/* ### Please do not edit the following line !!! ### */
int annual_rainfalls[100];


void SetAnnualRainfall(int year, int rainfall_in_mm)
{
    annual_rainfalls[year-1970] = rainfall_in_mm;
}


/*
Exercise 9: RainfallAverage
Note: This is a follow-up to the previous exercise.
The function SetAnnualRainfall is already implemented here, and it will be called to set a continuous bunch of values to the array annual_rainfalls, starting at year 1970 (index zero).
Your task is to implement the function RainfallAverage that is given the actual number of items in the array (less than or equal 100), starting at index zero, and it should return the average of those items' values (the average annual rainfalls).
*/


/* ### Please do not edit the following line !!! ### */
int annual_rainfalls[100];

/* The following function is a complete implementation for the previous exercise */
/* ### Please do not edit this function !!! ### */
void SetAnnualRainfall(int year, int rainfall_in_mm)
{
    annual_rainfalls[year - 1970] = rainfall_in_mm;
}


int RainfallAverage(int num_years)
{
    int i, sum = 0;

    for (i = 0; i < num_years; ++i) 
    {
        sum += annual_rainfalls[i];
    }

    if (num_years == 0) 
    {
        return 0; 
    }

    return sum / num_years; 
}
