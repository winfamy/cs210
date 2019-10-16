/** lab25.c
* ===========================================================
* Name: Grady Phillips, 15 Oct, 2019
* Section: M1A
* Project: 
* Purpose: 
* ===========================================================
*/

#include "lab25.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define FILENAME "../labs/lab25/lab25Data.csv"
#define FILENAME "lab25Data.csv"

int main() {
	Point * pt1 = malloc(sizeof(Point));
	Point * pt2 = malloc(sizeof(Point));;
	getPoints(pt1, pt2);
	printf("Distance: %lf\n", getDistance(*pt1, *pt2));

	int numLines = getNumLines(FILENAME);
	USAFBaseData ** ptrs = malloc(sizeof(USAFBaseData *) * numLines);
	for (int i = 0; i < numLines; ++i) {
		ptrs[i] = malloc(sizeof(USAFBaseData));
	}

	readFile(FILENAME, ptrs, numLines);
	printData(ptrs, numLines);
}

void getPoints(Point * pt1, Point * pt2) {
	printf("Enter coordinates of point a: ");
	scanf("%lf %lf", &pt1->x, &pt1->y);
	printf("Enter coordinates of point b: ");
	scanf("%lf %lf", &pt2->x, &pt2->y);
}

double getDistance(Point pt1, Point pt2) {
	double xDist = pt1.x - pt2.x;
	double yDist = pt1.y - pt2.y;
	return pow(xDist*xDist + yDist*yDist, .5);
}

void printData(USAFBaseData** bases, int numBases) {
	for (int i = 0; i < numBases; ++i) {
		printf("%s, ", bases[i]->baseName);
		printf("%d, ", bases[i]->bldgsOwned);
		printf("%d, ", bases[i]->structsOwned);
		printf("%s, ", bases[i]->city);
		printf("%s\n", bases[i]->state);
	}
}

void readFile(char filename[], USAFBaseData** baseStruct, int lines) {
	FILE * fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Could not open file %s.\n", filename);
		exit(1);
	}

	char t[100]; //throwaway
	fgets(t, 1000, fp); // ignore first line
	for (int i = 0; i < lines; ++i) {
		//	char baseName[50];
		//	int bldgsOwned;
		//	int structsOwned;
		//	char city[50];
		//	char state[30];
		fscanf(fp, "%[^\n,],", baseStruct[i]->baseName);
		fscanf(fp, "%d,", &baseStruct[i]->bldgsOwned);
		fscanf(fp, "%d,", &baseStruct[i]->structsOwned);
		fscanf(fp, "%[^\n,],", baseStruct[i]->city);
		fscanf(fp, "%[^\n,],", baseStruct[i]->state);
		fgets(t, 1000, fp); // reset to new line
	}
}

int getNumLines(char filename[]) {
	char c;
	int count = 0;
	FILE* fp = fopen(filename, "r");

	// Check if file exists
	if (fp == NULL) {
		printf("Could not open file %s", filename);
		return 0;
	}

	for (c = getc(fp); c != EOF; c = getc(fp)) {
		if (c == '\n') {
			count = count + 1;
		}
	}

	// Close the file
	fclose(fp);

	return count;
}