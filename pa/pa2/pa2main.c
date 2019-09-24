/** pa2main.c
* ===========================================================
* Name: Grady Phillips, 24 Sep, 2019
* Section: M1A
* Project: 
* Purpose: 
* ===========================================================
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "pa2functs.h"

int main() {
	int guess;
	printf("Enter num for guessNum (1-10): \n");
	scanf("%d", &guess);
	printf("Well guessed! The number was %d.\n", guessNum(guess));

	int numDoubles;
	printf("How many numbers will the user enter (max of 10)?\n");
	scanf("%d", &numDoubles);
	double doubles[numDoubles];
	for (int i = 0; i < numDoubles; ++i) {
		printf("Please enter a double value: \n");
		scanf("%lf", &doubles[i]);
	}

	char op;
	printf("What operation would you like to perform on the randomly generated numbers (enter the first letter)?\n");
	printf("Sum, Average, or Range.\n");
	scanf(" %c", &op);
	printf("The calculation returned %.2lf.\n", generateCalculate(numDoubles, doubles, op));

	char move[10];
	char moves[][10] = { "rock", "paper", "scissors" };
	scanf("%s", move);
	int aiMove = perfectAI(move);
	printf("%s!\n", moves[aiMove]);
	printf("perfectAI has won.\n");

	int min;
	int max;
	int pArr[1024] = {0};
	printf("Enter min (perfectNumbers): \n");
	scanf("%d", &min);
	printf("Enter max (perfectNumbers): \n");
	scanf("%d", &max);
	perfectNumbers(min, max, pArr);

	int arr[SIZE][SIZE];
	fill2D(arr);
	printf("The number of values in the array divisible by both 3 and 5 is %d.\n", count2D(arr));
}