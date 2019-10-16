/** lab23functs.c
* ===========================================================
* Name: Grady Phillips, 08 Oct, 2019
* Section: M1A
* Project: 
* Purpose: 
* ===========================================================
*/

#include "lab23functs.h"
#include <string.h>
#include <stdio.h>

/** ----------------------------------------------------------
 * Reads the number of records from the data file
 * @param dataFile is a string that indicates the path to and filename of the datafile
 * @return number of records in the file or -1 on error
 * ----------------------------------------------------------
 */
int getNumRecs(char dataFile[]) {
	int numCadets;
	FILE * in = fopen(dataFile, "r");
	if (in == NULL) {
		printf("Error opening file.\n");
		return -1;
	}

	fscanf(in, "%d", &numCadets);
	return numCadets;
}

/** ----------------------------------------------------------
 * Reads CadetInfoStructType  records from a text file
 * @param cadetRecords is the array of cadet records
 * @param numRecs is the number of records in the file
 * @param dataFile is a string that indicates the path to and filename of the datafile
 * ----------------------------------------------------------
 */
void getDataText(CadetInfoStructType cadets[], int numRecs, char dataFile[]) {
	FILE * in = fopen(dataFile, "r");
	if (in == NULL) {
		printf("Error opening file.\n");
		return;
	}

	char firstName[50];
	char lastName[50];
	fgets(firstName, 100, in); // ignores first line in file
	for (int i = 0; i < numRecs; ++i) {
		fscanf(in, "%s %s %d %d %d", lastName, firstName, &cadets[i].age, &cadets[i].squad, &cadets[i].year);

		// concats firstName + " " + lastName
		sprintf(cadets[i].name, "%s %s", firstName, lastName);
	}
}