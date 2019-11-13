/** lab32.h
* ===========================================================
* Name: FIRST LAST, DATE
* Section: SECTION
* Project: Lab 33
* Documentation: DOC STATEMENT
* ===========================================================  */

#ifndef MYEXE_LAB32_H
#define MYEXE_LAB32_H

#include <stdio.h>
#define DIRNAME "./password/"

/** ----------------------------------------------------------
 * @fn int factorial(int N)
 * @brief Recursively calculates the factorial of N
 * @param N, the input parameter
 * @return N!, the value of the factorial of N
 * ----------------------------------------------------------
 */
int factorial(int N);
int tail_factorial(int, int);
int collatz(int, int);
void decode_password(char * filename, char * msg);

#endif //MYEXE_LAB32_H
