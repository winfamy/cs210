/** pa2functs.c
* ===========================================================
* Name: Grady Phillips, 24 Sep, 2019
* Section: M1A
* Project: 
* Purpose: 
* ===========================================================
*/

#include "pa2functs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int guessNum(int i) {
	int gen = (rand() % 10) + 1;
	while (i != gen) {
		gen = (rand() % 10) + 1;
	}

	return gen;
}

double generateCalculate(int size, double d[], char c) {
	double returnVal = 0; // so we dont have to init for (*)= operations
	double largestSmallest[2] = {0}; // init with 2 zeroes, for use in range
	switch (c) {
		case 'S':
		case 's':
			for (int i = 0; i < size; ++i) {
				returnVal += d[i];
			}

			return returnVal;
		case 'A':
		case 'a':
			for (int i = 0; i < size; ++i) {
				returnVal += d[i];
			}

			return returnVal / size;
		case 'R':
		case 'r':
			getLargestSmallest(d, largestSmallest, size);
			return largestSmallest[0] - largestSmallest[1];
	}

	return 0.0;
}

// puts largest into out[0], smallest into out[1]
void getLargestSmallest(double in[], double out[], int size) {
	double smallest = in[0];
	double largest = in[0];
	for (int i = 1; i < size; ++i) {
		if (in[i] < smallest) {
			smallest = in[i];
		}

		if (in[i] > largest) {
			largest = in[i];
		}
	}

	out[0] = largest;
	out[1] = smallest;
}

int checkPerfect(int num) {
	int sum = 0;
	for (int i = 1; i < num; ++i) {
		if (num % i == 0) {
			sum += i;
		}
	}

	return sum == num;
}

int perfectNumbers(int min, int max, int arr[]) {
	int currentCount = 0; // uses to make sure we have a known array length and index for storage
	for (int i = min; i <= max; ++i) {
		if ( checkPerfect(i) ) {
			arr[currentCount] = i;
			currentCount++;
			printf("%d\n", i);
		}
	}

	return currentCount;
}

int perfectAI(char c[]) {
	enum {ROCK, PAPER, SCISSORS};
	int rock = strcmp(c, "rock");
	int paper = strcmp(c, "paper");

	if (rock == 0) {
		return PAPER;
	} else if (paper == 0) {
		return SCISSORS;
	} else {
		return ROCK;
	}
}

void fill2D(int arr[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			arr[i][j] = (rand() % 1000) + 1;
		}
	}
}

int count2D(int arr[SIZE][SIZE]) {
	int count = 0;
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (arr[i][j] % 3 == 0 && arr[i][j] % 5 == 0) {
				count++;
			}
		}
	}

	return count;
}