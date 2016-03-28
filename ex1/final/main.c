#include <stdio.h>
#include "MathIsFun.h"

#define POWER_CALC 1
#define PRIME_CHECK 2
#define PALI_CHECK 3

void handleChecker(int choice) {
	int n;
	bool res;

	printf("Please enter an integer: \n");
	scanf("%d", &n);

	switch (choice) {
	case PRIME_CHECK:
		res = funPrimeCheck(n);
		break;

	case PALI_CHECK:
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

	switch(op_number) {
	case POWER_CALC:	// power calculation
		printf("Please enter three space separated numbers: \n");
		scanf("%d %d %d", &x, &n, &d);
		printf("res = %d\n", funPow(x, n, d));
		break;

	case PRIME_CHECK: // prime check
		handleChecker(PRIME_CHECK);
		break;

	case PALI_CHECK: // palindrome check
		handleChecker(PALI_CHECK);
		break;

	default:
		break;
	}

	return 0;
}

