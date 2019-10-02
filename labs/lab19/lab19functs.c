/** lab19main.c
* ===========================================================
* Name: Grady Phillips, 30 Sep, 2019
* Section: M1A
* Project: 
* Purpose: 
* ===========================================================
*/

#include "lab19functs.h"
#include <string.h>
#include <stdio.h>

void replStr(char str[], char aChar, char bChar) {
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == aChar) {
			str[i] = bChar;
		}
	}
}

void replMultiChar(char str[], char searchChars[], char rChar) {
	for (int i = 0; i < strlen(str); ++i) {
		for (int j = 0; j < strlen(searchChars); ++j) {
			if (str[i] == searchChars[j]) {
				str[i] = rChar;
			}
		}
	}
}

int findLocations(char str[], int locations[], char searchChar) {
	int count = 0;
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == searchChar) {
			locations[count] = i;
			count++;
		}
	}

	return count;
}

int countSeqStr(char str[], char searchStr[]) {
	char * lastMatch;
	int count = 0;
	while ((lastMatch = strstr(str, searchStr)) != NULL) {
		count++;
		str = lastMatch + 1;
	}

	return count;
}