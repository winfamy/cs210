/** lab31.c
* ===========================================================
* Name: FIRST LAST, DATE
* Section: SECTION
* Project: Lab 31
* Documentation: DOC STATEMENT
* ===========================================================  */

#include "lab31.h"
#include <string.h>

int main() {

    // Exercise 1
    printf("\nExercise 1:\n\n");
    // Using recursion, implement the function powerN() which calculates the
    // value of a base number raised to the power of the exponent. The prototype
    // for the powerN() each function is provided in the lab31.h file.
    //
    // Fill in your answer to the questions below in each printf() statement

    // 1) Using the provided function parameter names: int powerN(int base, int exp)
    // Fill in the condition and return value for the base case.
    printf("When exp == 0 -> return 1;\n");

    // 2) Using the provided function parameter names: int powerN(int base, int exp)
    // Fill in the return value for the recursive case.
    printf("Otherwise -> return base * powerN(base, exp - 1);\n");

    // 3) Now you code up the powerN() function, use recursion, and do not use any
    // standard library functions.
    int base = 2;
    for (int i = 0; i <= 10; ++i) {
        printf("%d^%d = %d\n", base, i, powerN(base, i));
    }


    // Exercise 2
    printf("\nExercise 2:\n\n");
    // Using recursion, implement the function count_char(). This function counts the
    // occurrences of the provided character parameter c, in the character array parameter
    // str[].
    //
    // Before you start think through the appropriate base and recursive cases.
    char exampleStr[] = "banana banana banana banana banana";
    char searchChar = 'a';

    printf("There are %d occurrences of the character %c in the string:\n%s\n",
            count_char(exampleStr, searchChar), searchChar, exampleStr);


    // Exercise 3
    printf("\nExercise 3:\n\n");
    // Using recursion, implement the function count_num(). This function counts the
    // occurrences of the provided integer parameter x, in the integer array parameter
    // array[]. Note there is an extra integer parameter len, which is the number of
    // integer values in the array.
    //
    // Before you start think through the appropriate base and recursive cases.
    int arr[] = {1,2,3,4,5,6,7,1,1,1,1,1,4,3,1,31,1,2,3,1};
	printf("%d\n", count_num(arr, 1, 20));

    // Write your own code to test your count_num() function.



    // Exercise 4
    printf("\nExercise 4:\n\n");
    // Using recursion, implement the function reverse_print(). This function accepts a
    // character array parameter as input, and prints it in reverse.
    //
    // Before you start think through the appropriate base and recursive cases. Note
    // that the recursive call may not happen at the end of the function.
    char exampleText[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do "
                         "eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut "
                         "enim ad minim veniam, quis nostrud exercitation ullamco laboris "
                         "nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in "
                         "reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla "
                         "pariatur. Excepteur sint occaecat cupidatat non proident, sunt in "
                         "culpa qui officia deserunt mollit anim id est laborum.";
	reverse_print(exampleText);
    // Call reverse_print() with the exampleText character array to complete this exercise.


    // Exercise 5
    printf("\nExercise 5:\n\n");
    // Using recursion, implement a function, called fibonacci, which accepts one integer input
    // parameter N, and returns the Nth value of the fibonacci sequence. Note that the fibonacci
    // sequence is defined as: fib(0) = 0, fib(1) = 1, fib(N >= 2) = fib(N-1) + fib(N-2)
    //
    // Think through the base cases and the recursive case, before adding the function prototype to the
    // lab31.h header and defining your function in this file.
    //
    // Try calling your function with a few test cases to make sure it works.
	//printf("%d\n", fibonacci(44));


    return 0;
}

/** ----------------------------------------------------------
 * @fn int powerN(int base, int exp)
 * @brief Calculates the value of the base number raised to the exponent
 * @param base is the base number
 * @param exp is the exponent
 * @return the value of base^exponent
 * ----------------------------------------------------------
 */
int powerN(int base, int exp) {
	if (exp == 0)
		return 1;
	return base * powerN(base, exp - 1);
}

/** ----------------------------------------------------------
 * @fn int count_char(char str[], char c)
 * @brief Counts the number of characters in str[] that match c
 * @param str is the character array to search
 * @param c is the search character
 * @return the number of characters matching c in str[]
 * ----------------------------------------------------------
 */
int count_char(char str[], char c) {
	if (str[0] == '\0')
		return 0;

	return (int)(str[0] == c) + count_char(str + 1, c);
}

/** ----------------------------------------------------------
 * @fn int count_num(int array[], int x, int len)
 * @brief Counts the number of ints in array[] that match x
 * @param array is an array of integers to be searched
 * @param x is the int value to be searched for
 * @param len is the number of values in the array
 * @return the number of integers in array[] matching x
 * ----------------------------------------------------------
 */
int count_num(int array[], int x, int len) {
	if (len == 0) {
		return 0;
	}

	return (int)(array[0] == x) + count_num(array + 1, x, len - 1);
}

/** ----------------------------------------------------------
 * @fn void reverse_print(char str[])
 * @brief Prints the character array str[] in reverse
 * @param str is the character array
 * @return none, only prints the input parameter in reverse
 * ----------------------------------------------------------
 */
void reverse_print(char str[]) {
	if (str[0] == '\0') {
		return;
	}

	printf("%c", str[strlen(str) - 1]);
	str[strlen(str) - 1] = '\0';
	reverse_print(str);
}

int fibonacci(int x) {
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;

	return fibonacci(x - 1) + fibonacci(x - 2);
}