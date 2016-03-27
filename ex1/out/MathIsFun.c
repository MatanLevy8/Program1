#include "MathIsFun.h"

/***************************************************
 * START OF TEST ZONE
 * *************************************************/
/*
#include <math.h>

int mod (int a, int b)
{
   if(b < 0) //you can check for b == 0 separately and do what you want
     return mod(-a, -b);
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}

void sqrtTest() {
	int x, ours, truth;
	for (x = 0; x < 40000; x++) {
		ours = funSqrt(x);
		truth = floor(sqrt(x));
		if (ours != truth) {
			printf("damn... x=%d\n ours = %d, truth=%d\n", x, ours, truth);
		}
	}
}

bool primeTest(int n){
	int i;
	 for(i=2;i<=n/2;++i)
	 {
	     if(n%i==0)
	      {
	          return false;
	      }
	  }
	 return true;
}

void primesTest() {
	int i;
	for (i = 1; i < 10000; i++) {
		if (funPrimeCheck(i) != primeTest(i))
			printf("We have a problem !!!!! %d\n", i);
	}
}

bool palindromCheck(int x){
	int i;
	char str[100];
	sprintf(str, "%d", x);
	int str_len = strlen(str);
	for (i = 0; i <= str_len/2; i++) {
		if (str[i] != str[str_len - i - 1])
			return false;
	}
	return true;
}

void palindromTest(){
	int i;
	for (i = 1; i < 10000; i++) {
		if (funPalindromeCheck(i) != palindromCheck(i))
			printf("Problem at --%d--:\n We say : %d, the truth (hopefully) is : %d\n", i,funPalindromeCheck(i),palindromCheck(i));
	}
	printf("palindrome test ended");

}

void testMod()
{
	int x,n,d;
	int ours,the_truth;
	for (n=2;n<7;n++)
	{
		for (x=-10;x<20;x++)
		{
			for (d = 2;d<80;d++)
			{
				ours = funPow(x,n,d);
				the_truth=(int)mod((int)ceil(pow(x,n)),d);
				if (the_truth != ours ){
					printf("problem in d=%d,x=%d,n=%d\n",d,x,n);
					printf("The truth is : %d\n",the_truth);
					printf("Our shitty code said : %d\n",ours );
				}
			}
		}
	}
	//printf("%d", -1%3);
}
*/
/***************************************************
 * END OF TEST ZONE
 * *************************************************/

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
	//Your implementation
	//Declaration + Variable initializing at the beginning of the function

	// check if x is negative right at the beginning in order
	// to take care of the issue that % operator in C
	// on negative numbers returns also negative answer
	if (x < 0)
		x = (x % d) + d;

	return funPowWithPossitiveX(x, n, d);
}

int funSqrt(int x) {
	//Your implementation
	//Declaration + Variable initializing at the beginning of the function
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
	//Your implementation
	//Declaration + Variable initializing at the beginning of the function
	int i;

	for (i = 2; i < funSqrt(x) + 1; i++)
		if (x % i == 0)	// check if x is divided by is
			return false;

	return true;
}

bool funPalindromeCheck(int x) {
	//Your implementation
	//Declaration + Variable initializing at the beginning of the function
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
	// TODO: it's probably enough to run till (num_of_digits / 2) + 1
	for (i = 0; i < num_of_digits; i++)
	{
		if (x % 10 != reversed % 10)
			return false;

		x /= 10;
		reversed /= 10;
	}

	return true;
}

