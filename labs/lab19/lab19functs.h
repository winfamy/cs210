/** lab19main.h
* ===========================================================
* Name: Grady Phillips, 30 Sep, 2019
* Section: M1A
* Project: 
* Purpose: 
* ===========================================================
*/

#ifndef C_LAB19FUNCTS_H
#define C_LAB19FUNCTS_H
#define MAX_STR_LEN 81

void replStr(char str[], char aChar, char bChar);
void replMultiChar(char str[], char searchChars[], char rChar);
int findLocations(char str[], int locations[], char searchChar);
int countSeqStr(char str[], char searchStr[]);

#endif //C_LAB19FUNCTS_H
