/** lab16functs.c
* ===========================================================
* Name: Grady Phillips, 20 Sep, 2019
* Section: M1A
* Project: 
* Purpose: 
* ===========================================================
*/

#include "lab16functs.h"
#include <stdio.h>

void captureOhms(double resVals[]) {
	scanf("%lf %lf %lf %lf %lf", &resVals[0], &resVals[1], &resVals[2], &resVals[3], &resVals[4]);
}

void calculateCurrent(double circVolt, double resVals[], double * currentVal) {
	double totalRes = 0;
	for (int i = 0; i < 5; ++i) {
		totalRes += resVals[i];
	}

	*currentVal = circVolt / totalRes;
}

void voltageDrop(double vDrop[], double resVals[], double currentVal) {
	for (int i = 0; i < 5; ++i) {
		vDrop[i] = currentVal * resVals[i];
	}
}

void printDrop(double vDrop[]) {
	for (int i = 0; i < 5; ++i) {
		printf("%d) %.1lf V\n", i + 1, vDrop[i]);
	}
}

int performOperation(char c, int a, int b) {
	switch (c) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			return a;
	}
}

void getMinMax(int a[], int i, int * p1, int * p2) {
	*p1 = a[0];
	*p2 = a[0];
	for (int j = 0; j < i; ++j) {
		if (a[j] < *p1) {
			*p1 = a[j];
		}

		if (a[j] > *p2) {
			*p2 = a[j];
		}
	}
}