#include <string.h>	/*cstring*/
#include <stdio.h>      /* printf */
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h>       /* sqrt */



//https://cplusplus.com/reference/ctime/
int frequency_of_primes(int n);

//#define CLOCKS_PER_MSEC ( CLOCKS_PER_SEC / 1000 )
const time_t CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 1000;

void DelayMSec(int msec)
{
	time_t startTime = clock();

	/*Validate an input*/
	if (msec < 0)
		msec = 0;

	/*Delay a moment ...*/
	while ((clock() - startTime) < (msec * CLOCKS_PER_MSEC));
}


int main_time()
{
	clock_t currentTime, startTime, endTime;

	while (1) /*for (;;)*/
	{
		startTime = clock();
		// puts("Tick... 3 2 1 ...");
		// /*delay a moment*/ while ((clock() - startTime) < (3 * CLOCKS_PER_SEC));
		puts("Tick... 250ms");
		while ((clock() - startTime) < (250 * CLOCKS_PER_MSEC));
	}


	clock_t t;
	int f;

	t = clock();
	puts("Calculating...");
	f = frequency_of_primes(99999);
	//printf ("The number of primes lower than 100,000 is: %d\n",f);

	t = clock() - t;


	printf("It took me %d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);
	return 0;
}


int frequency_of_primes(int n) {
	int i, j;
	int freq = n - 1;
	for (i = 2; i <= n; ++i) for (j = sqrt(i);j > 1;--j) if (i % j == 0) { --freq; break; }
	return freq;
}