/** lab35.c
* ===========================================================
* Name: FIRST LAST, DATE
* Section: SECTION
* Documentation: YOUR DOC STATEMENT
* ===========================================================  */

#include "lab35.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main() {
    // Exercise 1
    printf("\nExercise 1: sum_squares()\n\n");
	printf("2 %d\n", sum_squares(2));
	printf("4 %d\n", sum_squares(4));

    // Exercise 2
    printf("\nExercise 2: is_even()\n\n");
	printf("2 %d\n", is_even(2));
	printf("3 %d\n", is_even(3));
	printf("12351 %d\n", is_even(12351));

    // Exercise 3
    printf("\nExercise 3: power_two()\n\n");
	printf("2 %d\n", power_two(2));
	printf("3 %d\n", power_two(3));


    // Exercise 4
    printf("\nExercise 4: reverse_bytes()\n\n");
	printf("0x00183CFF 0x%04X\n", reverse_bytes(0x00183CFF));

    // Exercise 5
    printf("\nExercise 5: is_palindrome()\n\n");
    char a[] = "racecar";
	char b[] = "a  a";
	char c[] = "abc";
	printf("racecar %d\n", is_palindrome(a, strlen("racecar")));
	printf("a__a %d\n", is_palindrome(b, strlen("a  a")));
	printf("abc %d\n", is_palindrome(c, strlen("a  a")));
   
    return 0;
}

int sum_squares(int N) {
	if (N == 1)
		return 1;

	return N * N + sum_squares(N - 1);
}

int is_even(int x) {
	return 1 & ~x;
}

int power_two(int N) {
	return 1 << N;
}

int reverse_bytes(unsigned int val) {
	int numBytes = sizeof(val);
	unsigned int reversed = 0;
	for (int i = 0; i < numBytes; ++i) {
		unsigned int byteVal = (val & 255 << i * 8) >> i * 8;
		reversed |= byteVal << (numBytes - i - 1) * 8;
	}

	return (int)reversed;
}

int is_palindrome(char message[], int len) {
	printf("%s\n", message);
	if (len == 0 || len == 1) {
		printf("done processing\n");
		return 1;
	}

	if (message[0] == message[strlen(message) - 1]) {
		message[strlen(message) - 1] = '\0';
		return is_palindrome(message + 1, len - 2);
	}

	printf("not palindrome\n");
	return 0;
}

void print_bits(void* ptr, int num_bytes) {
	// Cast the pointer as an unsigned byte
	uint8_t* byte = ptr;

	// For each byte, (bytes are little endian ordered)
	for (int i = num_bytes - 1; i >= 0; --i) {

		// For each bit, (inside the byte, bits are big endian ordered)
		for (int j = 7; j >= 0; --j) {

			// Print a character 1 or 0, given the bit value
			printf("%c", (byte[i] >> j) & 1 ? '1' : '0');
		}

		// Separate bytes
		printf(" ");
	}

	// End with a new line
	printf("\n");
}