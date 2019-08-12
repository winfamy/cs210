/*** @file lab06p3.c
 *   @author your name
 *   @brief The template for CS210 lab 6 part 3.
 */
#include <stdio.h>
#include <math.h>

/***
 *  Function prototypes
 */
// TODO 3.2 - Exercise 3 - Pythagorean Theorem
double pythagorean(int, int);

int main() {

    // TODO 3.3 - Exercise 3 - Pythagorean Theorem
    int a, b;
    printf("Enter lengths of sides a and b: ");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("The length of the hypotenuse is %.6lf.", pythagorean(a, b));
    // Enter lengths of sides a and b: 3 4
    // The length of the hypotenuse is 5.000000.

    return 0;
}

// TODO 3.1 - Exercise 3 - Pythagorean Theorem
double pythagorean(int a, int b) {
    return sqrt(pow(a, 2) + pow(b, 2));
}