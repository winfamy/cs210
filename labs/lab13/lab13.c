/** lab13.c
* ===========================================================
* Name: Grady Phillips, 06 Sep, 2019
* Section: M1A
* Project: Lab 13
* Purpose:
	Define a pointer
	Understand how to declare pointer using address of operator
	Understand how to dereference a pointer using dereference operator
	Understand pass by value vs. pass by reference
* ===========================================================
*/

#include "lab13.h"
#include <stdio.h>

int main() {
    int classYear, favNum;
    printf("Please enter your class year:\n");
    scanf("%d", &classYear);
    printf("Please enter your favorite integer:\n");
	scanf("%d", &favNum);
    swapPassByValue(classYear, favNum);
    printf("aNum = %d, bNum = %d\n", classYear, favNum);

    swapPassByReference(&classYear, &favNum);
	printf("aNum = %d, bNum = %d\n", classYear, favNum);

	int a, b;
	scanf("%d %d", &a, &b);
	printf("The sum of %d and %d = %d\n", a, b, pointerSum(&a, &b));

	int fac;
	long ret;
	scanf("%d", &fac);
	findFactorial(fac, &ret);
	printf("The factorial of %d is %li\n", fac, ret);
    return 0;
}

void swapPassByValue(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

// swaps by switching pointer addys
// could also swap by setting *a = *b; etc
void swapPassByReference(int * a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int pointerSum(int * a, int * b) {
	return *a + *b;
}

void findFactorial(int a, long * l) {
	*l = 1;
	for (int i = 1; i <= a; ++i) {
		*l *= i;
	}
}