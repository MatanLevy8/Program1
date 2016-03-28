#include <stdio.h>
#include <math.h>
#include "MathIsFun.h"


int mod(int a, int b)
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
	if (n<2)
		return false;
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


void callTest(char* name, void (*pointerToFunc)(void) ){
	printf("\nTest/%s started\n",name);
	(*pointerToFunc)();
	printf("Test/%s ended\n",name);
}


void tests()
{
	printf("Tests - start\n");
	callTest("Prime test", &primesTest);
	callTest("Power Modulo test", &testMod);
	callTest("Palndrome test", &palindromTest);
	callTest("Sqrt test", &sqrtTest);

	printf("Tests - end\n");
}
