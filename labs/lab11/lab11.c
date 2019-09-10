/** lab11.c
* ===========================================================
* Name: Grady Phillips, 04 Sep, 2019
* Section: M1A
* Project: Lab 11
* Purpose:
* 	Understand iteration using for loops
* 	Understand the expressions in a for loop
* 	Understand common errors made when using for loops
* ===========================================================
*/

#include <stdio.h>
#include "lab11.h"

int main() {
	// input vars
	int a, b, c;
	printf("numFactorial: ");
	scanf("%d", &a);
	printf("The factorial of %d is %d.\n", a, numFactorial(a));

	printf("prime: ");
	scanf("%d", &b);
	printf("%d is %sa prime number.\n", b, isPrime(b) ? "" : "not ");

	printf("floyd: ");
	scanf("%d", &c);
	floydsTriangle(c);
}

int numFactorial(int a) {
	int fac = 1;
	for (int i = a; i > 0; --i) {
		fac *= i;
	}

	return fac;
}

int isPrime(int p) {
	for (int i = 1; i < p; ++i) {
		if (i == p || i == 1) {
			continue;
		}

		if (p % i == 0) {
			return 0;
		}
	}

	return 1;
}

void floydsTriangle(int f) {
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			if (i % 2 == 0) {
				printf((j % 2 == 0) ? "1": "0");
			} else {
				printf((j % 2 == 0) ? "0": "1");
			}
		}

		printf("\n");
	}
}

