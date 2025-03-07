#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>      /* printf */

char myName[32];

int x, y;

int main()
{
	while (1)
	{
		puts("Set the position:");
		scanf("%d %d", &x, &y);
		printf("The position set at (%d, %d)\n", x, y);

		//puts("Hello, what is your name?");
		//scanf("%s ", myName);
		// //cin >> myName;
		//printf("Your name is %s\n\n", myName);
		// //cout << "Your name is " << myName << "\n";
	}

	return 0;
}
