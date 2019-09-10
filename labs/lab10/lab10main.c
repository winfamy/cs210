//
// Created by Grady Phillips on 8/30/19.
//

#include <stdio.h>
#include "lab10functs.h"

int main() {
	char a, b, c;
	printf("Enter a single character to pass to isFirstHalfAlpha():\n");
	scanf(" %c", &a);
	if (isFirstHalfAlpha(a)) {
		printf("A %c is in the first half of the alphabet.\n", a);
	} else {
		printf("A %c is NOT in the first half of the alphabet.\n", a);
	}

	printf("Enter a single character to pass to typeOfChar():\n");
	scanf(" %c", &b);
	switch (typeOfChar(b)) {
		case -1:
			printf("A %c is neither a vowel nor a consonant.\n", b);
			break;
		case 0:
			printf("A %c is a vowel.\n", b);
			break;
		case 1:
			printf("A %c is a consonant.\n", b);
			break;
	}

	printf("Enter a single character to pass to isMagicChar():\n");
	scanf(" %c", &c);
	if (isMagicChar(c)) {
		printf("A %c is the magic character @.\n", c);
	} else {
		printf("A %c is NOT the magic character @.\n", c);
	}
}