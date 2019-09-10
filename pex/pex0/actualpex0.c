/** PEX0.c
* ==============================================================
* Name: Grady Phillips, Aug 16th
* Section: M1
* Project: PEX 0 - ASCII Art
* Purpose: Understand how to use C standard library functions,
*          and user-defined functions.
* Documentation Statement: None
* ==============================================================
* Instructions:
 * Complete and submit PEX0 as outlined in the writeup.
*/

#include <stdio.h>
#include <math.h>

/**   ----------------------------------------------------------  
* Outputs a flower to stdout
* @param    void
* @return   void
*/ 
void drawFlower();

/**   ----------------------------------------------------------
* Outputs a dog to stdout
* @param    void
* @return   void
*/
void drawDog();

/**   ----------------------------------------------------------
* Outputs an arrow to stdout
* @param    void
* @return   void
*/
void drawArrow();

/**   ----------------------------------------------------------
* Calculates a right triangle's area given base width a,
* vertical height b, and hypotenuse length c. Returns -1
* if triangle is not a right triangle
* @param    a   Right triangle base width
* @param    b   Right triangle vertical height
* @param    c   Right triangle hypotenuse length
* @return   Returns right triangle area, or -1 if given dimensions
*           are not that of a right triangle.
*/
double triangleArea(double, double, double);


int main() {
    int choice;                // flower/dog/arrow
    double baseWidth;          // base width
    double baseHeight;         // base height
    double hypotenuseLength;   // hypotenuse length
    scanf("%d", &choice);
    scanf("%lf", &baseWidth);
    scanf("%lf", &baseHeight);
    scanf("%lf", &hypotenuseLength);


    switch (choice) {
        case 1:
            drawFlower();
            break;
        case 2:
            drawDog();
            break;
        case 3:
            drawArrow();
            break;
    }

    double ret = triangleArea(baseWidth, baseHeight, hypotenuseLength);
    if (ret == -1) {
        printf("Your inputs do not describe a right triangle!\n");
    } else {
        printf("The area of a right triangle with a base side of %.0lf inches, a height of %.0lf inches, and a hypotenuse of %.0lf inches is %.2lf square inches.", baseWidth, baseHeight, hypotenuseLength, ret);
    }

    return 0;
}

void drawFlower() {
    printf("    _ _\n");
    printf("   (_\\_)\n");
    printf("  (__<_{}\n");
    printf("   (_/_)\n");
    printf("  |\\ |\n");
    printf("   \\\\| /|\n");
    printf("    \\|//\n");
    printf("     |/\n");
    printf(",.,.,|.,.,.\n");
    printf("^`^`^`^`^`^  \n");
}

void drawDog() {
    printf("^..^      /\n");
    printf("/_/\\_____/\n");
    printf("   /\\   /\\\n");
    printf("  /  \\ /  \\\n");
}

void drawArrow() {
    printf("**\n");
    printf("**\n");
    printf("**\n");
    printf("**\n");
    printf("**\n");
    printf("****\n");
    printf("***\n");
    printf("**\n");
    printf("*\n");
}

double triangleArea(double a, double b, double c) {
    if (pow(a, 2) + pow(b, 2) != pow(c, 2)) {
        return -1;
    } else {
        return 0.5 * a * b;
    }
}