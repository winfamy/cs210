/** lab23functs.h
* ===========================================================
* Name: Grady Phillips, 08 Oct, 2019
* Section: M1A
* Project: 
* Purpose: 
* ===========================================================
*/

#ifndef C_LAB23FUNCTS_H
#define C_LAB23FUNCTS_H

typedef struct CadetInfoStruct {
	char name[50];
	int age;
	int squad;
	int year;
} CadetInfoStructType;

/** ----------------------------------------------------------
 * Reads the number of records from the data file
 * @param dataFile is a string that indicates the path to and filename of the datafile
 * @return number of records in the file or -1 on error
 * ----------------------------------------------------------
 */
int getNumRecs(char dataFile[]);

/** ----------------------------------------------------------
 * Reads CadetInfoStructType  records from a text file
 * @param cadetRecords is the array of cadet records
 * @param numRecs is the number of records in the file
 * @param dataFile is a string that indicates the path to and filename of the datafile
 * ----------------------------------------------------------
 */
void getDataText(CadetInfoStructType cadets[], int numRecs, char dataFile[]);



#endif //C_LAB23FUNCTS_H
