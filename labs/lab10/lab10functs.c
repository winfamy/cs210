//
// Created by Grady Phillips on 8/30/19.
//

#define MAGIC_CHAR '@'
#include <stdbool.h>

bool isFirstHalfAlpha(char c) {
	return ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'));
}

int typeOfChar(char c) {
	if (c >= 'A' && c <= 'z') {
		switch(c) {
			case 'A':
			case 'a':
			case 'E':
			case 'e':
			case 'I':
			case 'i':
			case 'O':
			case 'o':
			case 'U':
			case 'u':
				return 0;
			default:
				return 1;
		}
	}

	return -1;
}

bool isMagicChar(char c) {
	return c == MAGIC_CHAR;
}
