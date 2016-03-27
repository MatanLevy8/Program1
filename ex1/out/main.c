#include <stdio.h>
#include "MathIsFun.h"

void handleChecker(int choice) {
	int n;
	bool res;

	printf("Please enter an integer: \n");
	scanf("%d", &n);

	switch (choice) {
	case 2:
		res = funPrimeCheck(n);
		break;

	case 3:
		res = funPalindromeCheck(n);
		break;

	default:
		break;
	}

	if (res)
		printf("res = true\n");
	else
		printf("res = false\n");
}

int main()
{
	int op_number, x, n, d;

	printf("Welcome to Math Is Fun - beta version\n");
	printf("Supported operations are:\n");
	printf("1 - Power Calculation\n");
	printf("2 - Prime Check\n");
	printf("3 - Palindrome Check\n");
	printf("Please enter operation number (1/2/3): \n");

	scanf("%d", &op_number);

	// TODO: decide whether to save 1, 2, 3 as consts
	switch(op_number) {
	case 1:	// power calculation
		printf("Please enter three space separated numbers: \n");
		scanf("%d %d %d", &x, &n, &d);
		printf("res = %d\n", funPow(x, n, d));
		break;

	// TODO: decide which option is better
	case 2:
		handleChecker(2);
		break;

	case 3:
		handleChecker(3);
		break;

	/*case 2:	// prime check
		printf("Please enter an integer: \n");
		scanf("%d", &n);
		if (funPrimeCheck(n))
			printf("res = true\n");
		else
			printf("res = false\n");
		break;

	case 3:	// palindrome test
		printf("Please enter an integer: \n");
		scanf("%d", &n);
		if (funPalindromeCheck(n))
			printf("res = true\n");
		else
			printf("res = false\n");
		break;*/

	default:
		break;
	}

	return 0;
}

