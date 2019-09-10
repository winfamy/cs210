/** lab12.c
* ===========================================================
* Name: Grady Phillips, 04 Sep, 2019
* Section: M1A
* Project: Lab12
* Purpose:
	Understand iteration using while loops
	Understand iteration using do while loops
	Understand the appropriate use of break and continue
	Understand common errors made when using while and do while loops
* ===========================================================
*/

#include "lab12.h"
#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c, e, f;
	printf("armstrong: \n");
	scanf("%d", &a);
	printf("%d is %san Armstrong number.\n", a, isArmstrong(a) ? "" : "not ");

	printf("findGCD: \n");
	scanf("%d %d", &b, &c);
	printf("GCD = %d\n", findGCD(b, c));

	printf("printRange: \n");
	scanf("%d %d", &e, &f);
	printRange(e, f);
    return 0;
}

int isArmstrong(int n) {
	int remainder, orig, sum = 0;
	orig = n;
	while(n > 0) {
		// isolates first digit
		remainder = n % 10;
		sum += pow(remainder, 3);
		// decay by 10^1
		n /= 10;
	}

	return orig == sum;
}

int findGCD(int a, int b) {
	int gcd;
	// iterate to smaller
	int min = (a < b) ? a : b;
	// iterator
	int i = 1;
	while (i <= min) {
		// test divisibility
		if (a % i == 0 && b % i == 0) {
			gcd = i;
		}

		i++;
	}

	return gcd;
}

void printRange(int a, int b) {
	int min = (a < b) ? a : b;
	int max = (a < b) ? b : a;
	int i = min;
	while (i <= max) {
		printf("%d\n", i);
		i++;
	}
}
