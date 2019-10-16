/** lab25.h
* ===========================================================
* Name: Grady Phillips, 15 Oct, 2019
* Section: M1A
* Project: 
* Purpose: 
* ===========================================================
*/

#ifndef C_LAB25_H
#define C_LAB25_H

typedef struct Point {
	double x;
	double y;
} Point;

typedef struct USAFBaseData {
	char baseName[50];
	int bldgsOwned;
	int structsOwned;
	char city[50];
	char state[30];
} USAFBaseData;

void getPoints(Point *, Point *);
double getDistance(Point, Point);
int getNumLines(char filename[]);
void readFile(char filename[], USAFBaseData** baseStruct, int lines);
void printData(USAFBaseData** bases, int numBases);

#endif //C_LAB25_H
