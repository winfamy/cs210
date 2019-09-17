/** lab14functs.c
* ===========================================================
* Name: Grady Phillips, 10 Sep, 2019
* Section: M1A
* Project: 
* Purpose: 
* ===========================================================
*/

#include "lab14functs.h"

int findMaxIndex(int arr[], int size) {
	int maxI = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > arr[maxI]) {
			maxI = i;
		}
	}

	return maxI;
}

int numPlayerOverX(int * arr, int threshold, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > threshold) {
			count++;
		}
	}

	return count;
}

int getMaxYardsPerCarryIndex(int threshold, int * yds, int * att) {
	int index = 0;
	double max = 0.0;
	double ydsPerCarry;
	for (int i = 0; i < MAXPLAYERS; i++) {
		if (att[i] > threshold) {
			ydsPerCarry = (double)yds[i]/att[i];
			if (ydsPerCarry > max) {
				max = ydsPerCarry;
				index = i;
			}
		}
	}

	return index;
}

double getMaxYardsPerCarry(int * yds, int * att) {
	int i = getMaxYardsPerCarryIndex(10000, yds, att);
	return (double)yds[i]/att[i];
}