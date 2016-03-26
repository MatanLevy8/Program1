#include "MathIsFun.h"
#include <math.h>

int funPowWithPossitiveX(int x,int n,int d){
	int inner_x;
	if (n==0)
		return 1;
	if (n%2 == 0) //n is even
	{
		inner_x = funPow(x,n/2,d);
		return (inner_x*inner_x)%d;
	}
	else // n is odd
	{
		inner_x= funPow(x,(n-1)/2,d);
		return ((inner_x)*(x%d)*inner_x)%d;
	}
	return inner_x;
}

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

int main()
{
	int op_number, x, n, d;
	printf("Welcome to Math Is Fun - beta version\n");
	printf("Supported operations are:\n");
	printf("1 - Power Calculation\n");
	printf("2 - Prime Check\n");
	printf("3 - Palindrome test\n");
	printf("Please enter operation number (1/2/3): \n");

	scanf("%d", &op_number);
	switch(op_number) {
	case 1:
		printf("Please enter three space separated numbers: \n");
		scanf("%d %d %d", &x, &n, &d);
		printf("res = %d\n", funPow(x,n,d));
		break;
	case 2:
		printf("Please enter an integer: \n");
		scanf("%d", &n);
		if (funPrimeCheck(n))
			printf("res = true\n");
		else
			printf("res = false\n");
		break;
	case 3:
		printf("Please enter an integer: \n");
		scanf("%d", &n);
		if (funPalindromeCheck(n))
			printf("res = true\n");
		else
			printf("res = false\n");
		break;
	default:
		break;
	}

	return 0;
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
	if (x<0)
		x = x%d + d;
	return funPowWithPossitiveX(x,n,d);
}

int funSqrt(int x) {
	//Your implementation
	//Declaration + Variable initializing at the beginning of the function
	int middle ,start=0,end=x, result, cand;
	while (start<=end)
	{
		middle = (start+end)/2;
		result = middle * middle;
		if (result == x)
		{
			return middle;
		}
		else if (result < x)
		{
			cand = middle;
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
	for (i=2;i<funSqrt(x)+1;i++)
		if (x%i==0)
			return false;
	return true;
}

bool funPalindromeCheck(int x) {
	//Your implementation
	//Declaration + Variable initializing at the beginning of the function
	int num_of_digits=0, original=x,i,reversed=0;
	if (x<0)
		return false;
	while (x>0)
	{
		num_of_digits++;
		reversed *=10;
		reversed += (x%10);
		x/=10;
	}
	x = original;
	for (i=0;i<num_of_digits;i++)
	{
		if (x%10 != reversed%10)
			return false;
		x/=10;
		reversed/=10;
	}

	return true;
}
