/** lab19main.c
* ===========================================================
* Name: Grady Phillips, 30 Sep, 2019
* Section: M1A
* Project: 
* Purpose: 
* ===========================================================
*/

#include "lab19functs.h"
#include <stdio.h>
#include <string.h>

int main() {
	// Function - 1
	// Enter a string (<= 80 chars): This is a test string.
	// Enter a search character followed by replace character: i *
	// New string (between arrows): -->Th*s *s a test str*ng.<--

	char str1[MAX_STR_LEN];
	char s1, r1;
	printf("Function - 1\n");
	printf("Enter a string (<= 80 chars): ");
	scanf("%s", str1);
	printf("Enter a search character followed by replace character: ");
	scanf(" %c %c", &s1, &r1);
	printf("%c %c\n", s1, r1);
	replStr(str1, s1, r1);
	printf("New string (between arrows): -->%s<--\n\n", str1);

	// Function - 2
	// Enter a string (<= 80 chars): This is also a test string.
	// Enter a search string (<= 80 chars): isa
	// Enter a replace character: *
	// New string (between arrows): -->Th** ** *l*o * te*t *tr*ng.<--
	char str2[MAX_STR_LEN];
	char s2[MAX_STR_LEN];
	char r2;
	printf("Function - 2\n");
	printf("Enter a string (<= 80 chars): ");
	scanf("%s", str2);
	printf("Enter a search string (<= 80 chars): ");
	scanf("%s", s2);
	printf("Enter a replace character: ");
	scanf(" %c", &r2);
	replMultiChar(str2, s2, r2);
	printf("New string (between arrows): -->%s<--\n\n", str2);

	// Function - 3
	// Enter a string (<= 80 chars): This is yet another test string.
	// Enter a character whose locations you wish to find: t
	// There are 5 occurrences of t.
	// t found at location 10.
	// t found at location 15.
	// t found at location 20.
	// t found at location 23.
	// t found at location 26.
	char str3[MAX_STR_LEN];
	char s3;
	int locations[MAX_STR_LEN] = {[0 ... MAX_STR_LEN - 1] = -1};
	printf("Function - 3\n");
	printf("Enter a string (<= 80 chars): ");
	scanf("%s", str3);
	printf("Enter a character whose locations you wish to find: ");
	scanf(" %c", &s3);
	printf("There are %d occurrences of %c\n", findLocations(str3, locations, s3), s3);
	for (int i = 0; i < MAX_STR_LEN; ++i) {
		if (locations[i] == -1)
			break;

		printf("%c found at location %d.\n", s3, locations[i] + 1);
	}
	printf("\n");


	// Function - Challenge
	// Enter a string (<= 80 chars): This one is xxx difficult. xxxxxxxx.
	// Enter a search string (<= 80 chars): xxx
	// There are 7 occurrences of xxx.
	char str4[MAX_STR_LEN];
	char str5[MAX_STR_LEN];
	printf("Function - Challenge\n");
	printf("Enter a string (<= 80 chars): ");
	scanf("%s", str4);
	printf("Enter a search string (<= 80 chars): ");
	scanf("%s", str5);
	printf("There are %d occurrences of %s\n", countSeqStr(str4, str5), str5);
}