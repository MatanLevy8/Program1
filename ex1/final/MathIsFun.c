#include "MathIsFun.h"

int funPowWithPossitiveX(int x, int n, int d){
	int inner_x;

	if (n == 0)
		return 1;

	if (n % 2 == 0) //n is even
	{
		inner_x = funPow(x, n / 2, d);
		return (inner_x * inner_x) % d;
	}
	// n is odd
	inner_x = funPow(x, (n - 1) / 2, d);
	return (inner_x * (x % d) * inner_x) % d;
}

/*
 * Calculates the largest integer less or equal than the square root of x.
 * funSqrt(10) = 3
 * funSqrt(16) = 4
 * @param x - An integer for which the function applies
 * @return the value of |_sqrt(x)_|, if x is negative then the function
 * returns -1.
 */
int funSqrt(int x); // ==> Declaration is always in the beginning of the file.

int funPow(int x, int n, int d) {
	// check if x is negative right at the beginning in order
	// to take care of the issue that % operator in C
	// on negative numbers returns also negative answer
	if (x < 0)
		x = (x % d) + d;

	return funPowWithPossitiveX(x, n, d);
}

int funSqrt(int x) {
	int start = 0, end = x, middle, result, cand;

	while (start <= end)
	{
		middle = (start + end) / 2;
		result = middle * middle;

		if (result == x) // if the sqrt is an integer, we return it
		{
			return middle;
		}

		else if (result < x)
		{
			cand = middle;	// save potential candidate
			start = middle + 1;
		}

		else
		{
			end = middle - 1;
		}
	}

	return cand;
}

bool funPrimeCheck(int x) {
	int i;

	//by definition, a prime number is greater than 1
	if (x <2 )
		return false;

	for (i = 2; i < funSqrt(x) + 1; i++)
		if (x % i == 0)	// check if x is divided by is
			return false;

	return true;
}

bool funPalindromeCheck(int x) {
	int num_of_digits = 0, reversed = 0, original = x, i;

	if (x < 0)
		return false;

	// calculating the number of digits and saving the number with the
	// same digits in reversed order
	while (x > 0)
	{
		num_of_digits++;
		reversed *= 10;
		reversed += x % 10;
		x /= 10;
	}

	x = original;

	// checking if x and the integer in reversed order have the same digits

	for (i = 0; i < num_of_digits / 2; i++)
	{
		if (x % 10 != reversed % 10)
			return false;

		x /= 10;
		reversed /= 10;
	}

	return true;
}

