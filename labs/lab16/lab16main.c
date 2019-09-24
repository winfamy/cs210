/** lab16main.c
* ===========================================================
* Name: Grady Phillips, 20 Sep, 2019
* Section: M1A
* Project: 
* Purpose: 
* ===========================================================
*/

#define NUM_RES 5
#include "lab16functs.h"
#include <stdio.h>

int main () {
	double resVals[NUM_RES] = {0};
	double circVolt = 12;
	double vDrop[NUM_RES] = {0};
	double currentVal;
	captureOhms(resVals);
	calculateCurrent(circVolt, resVals, &currentVal);
	voltageDrop(vDrop, resVals, currentVal);
	printDrop(vDrop);

	int surveyAnswer;
	printf("Survey response scale: 10 - Outstanding, 8-9 - Excellent, 6-7 - Good, 5 - Average, \n"
	       "3-4 - Below Average, 1-2 - Awful, 0 - Horrible.\n"
	       "Enter an integer value from 0-10 corresponding to your opinion of Cookies 'n Cream ice cream:\n");
	scanf("%d", &surveyAnswer);
	switch(surveyAnswer) {
		case 0:
			printf("Horrible\n");
			break;
		case 1:
		case 2:
			printf("Awful\n");
			break;
		case 3:
		case 4:
			printf("Below Average\n");
			break;
		case 5:
			printf("Average\n");
			break;
		case 6:
		case 7:
			printf("Good\n");
			break;
		case 8:
		case 9:
			printf("Excellent\n");
			break;
		case 10:
			printf("Outstanding\n");
			break;
		default:
			printf("You did not enter a value between 0 and 10.\n");
			break;
	}
}