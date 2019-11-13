/** lab32.c
* ===========================================================
* Name: FIRST LAST, DATE
* Section: SECTION
* Project: Lab 32
* Documentation: DOC STATEMENT
* ===========================================================  */

#include "lab32.h"
#include <assert.h>
#include <string.h>

int main() {

    // Exercise 1
    printf("\nExercise 1:\n\n");
    // The recursive function factorial() has been defined for you below. Review
    // the code and determine if it is tail recursive.
    //
    // For this exercise you will write a tail recursive version of factorial(),
    // called tail_factorial(), your function should take 2 integer parameters, the
    // first is the input value, the second is an accumulator.

    // Write your own code to test the base and recursive cases of tail_factorial()
    // to determine that it is working correctly.
	assert(tail_factorial(1, 1) == 1);
	assert(tail_factorial(6, 1) == 6*5*4*3*2*1);
	assert(tail_factorial(9, 1) == 9*8*7*6*5*4*3*2*1);

    // Exercise 2
    printf("\nExercise 2:\n\n");
    // The Collatz conjecture states that following a set of rules, you can reach 1
    // starting from any other number. While this conjecture has not been proven, you
    // will write a tail recursive function called collatz() that accepts two integer
    // input parameters (the first is the starting value, the second is the accumulator)
    // and returns the number of steps needed to reach 1 from the starting value.
    //
    // The rules of the Collatz conjecture are:
    //   if the current N is even, the next N = N/2
    //   if the current N is odd, the next N = 3*N + 1
    //
    // The first 10 values in the number of steps required to reach 1 are below (for testing)
    // this is the correct output for inputs of 1, 2, 3, ... 10
    //
    // 0, 1, 7, 2, 5, 8, 16, 3, 19, 6

    // Write your own code to test the base and recursive cases of collatz() to determine
    // that it is working correctly
    assert(collatz(1, 0) == 0);
	assert(collatz(3, 0) == 7);
	assert(collatz(5, 0) == 5);


    // Exercise 3
    printf("\nExercise 3:\n\n");
    // Download the password.zip file from zyBooks. Extract this file to a new password
    // directory under your Lab 32 folder. There is a password hidden inside these files,
    // write a function decode_password() which searches these files recursively to find
    // the password, starting with "_.txt".
    //
    // Your decode_password() function should accept a character array input and return void.
    // The input is the name of a text file, without the directory, so the first call would be
    // decode_password("_.txt"); Use the DIRNAME constant to add the directory to the file name
    // inside the decode_password() fuction. You might create a character array to hold the full
    // name then use sprintf() to put the directory and filename together, fullName is a character
    // array you create, DIRNAME is a directory constant, and fname is the name you pass into the
    // decode_password() function.
    // sprintf(fullName, "%s%s", DIRNAME, fname);
    //
    // Until you reach the end of the text file, read one line of the file, if the string on that
    // line is of length 1, print that character (it is part of the message), otherwise the
    // string you read is the name of another text file which you should now search.
    //
    // NOTE: a bunch of random underscore '_' characters got thrown in with the actual message
    // so don't print those out when you find them. If you use fscanf(), to read the text files
    // remember that each line ends with a new line character.


    // When you submit to the ZyBook comment out any calls to decode_password(), and change the
    // printf() call below to the password you read from the text files.
    printf("https://xkcd.com/710/\n");

    return 0;
}

/** ----------------------------------------------------------
 * @fn int factorial(int N)
 * @brief Recursively calculates the factorial of N
 * @param N, the input parameter
 * @return N!, the value of the factorial of N
 * ----------------------------------------------------------
 */
int factorial(int N) {

    if (N < 2) {
        return 1;
    }

    return N * factorial(N-1);
}

int tail_factorial(int N, int accum) {
	if (N < 2)
		return N == 0 ? 1 : accum * N;

	return tail_factorial(N - 1, accum * N);
}

int collatz(int N, int steps) {
	if (N == 1)
		return steps;

	return N % 2 == 0
		? collatz(N/2, ++steps)
		:  collatz(3 * N + 1, ++steps);
}

void decode_password(char * filename, char * msg) {
	char fullname[1024];
	char buf[1024];
	sprintf(fullname, "%s%s", DIRNAME, filename);
	FILE * fp = fopen(fullname, "r");
	if (fp == NULL)
		printf("Failed opening file %s!\n", fullname);

	fgets(buf, 1000, fp);
	while (!feof(fp)) {
		buf[strlen(buf) - 1] = '\0'; // removes trailing newline
		if (strlen(buf) == 1) {
			if (buf[0] != '_') {
				msg[strlen(msg)] = buf[0];
				msg[strlen(msg)] = '\0';
			}
		} else {
			decode_password(buf, msg);
		}

		fgets(buf, 1000, fp);
	}
}