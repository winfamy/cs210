/** lab23main.c
* ===========================================================
* Name: Grady Phillips, 08 Oct, 2019
* Section: M1A
* Project: 
* Purpose: 
* ===========================================================
*/

#include "lab23functs.h"
#include <stdlib.h>
#include <stdio.h>


int main() {
	printf("Reading number of records in the data file.\n");
	int numCadets = getNumRecs("./lab23Data.txt");
	printf("%d records in the data file.\n", numCadets);
	CadetInfoStructType * cadets = (CadetInfoStructType *)calloc(numCadets, sizeof(CadetInfoStructType));
	getDataText(cadets, numCadets, "./lab23Data.txt");
	printf("The first cadet is:\n");
	printf("Cadet name = %s\n", cadets[0].name);
	printf("Cadet age = %d\n", cadets[0].age);
	printf("Cadet squad = %d\n", cadets[0].squad);
    printf("Cadet year = %d\n", cadets[0].year);
	printf("The last cadet is:\n");
	printf("Cadet name = %s\n", cadets[numCadets - 1].name);
	printf("Cadet age = %d\n", cadets[numCadets - 1].age);
	printf("Cadet squad = %d\n", cadets[numCadets - 1].squad);
	printf("Cadet year = %d\n", cadets[numCadets - 1].year);
	free(cadets);
}