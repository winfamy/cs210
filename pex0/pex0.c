/*** @file lab06p3.c
 *   @author your name
 *   @brief The template for CS210 lab 6 part 3.
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void drawTree(void);
void drawCat(void);

int main() {
    drawTree();
    drawCat();
}

void drawTree() {
    printf("   *   \n");
    printf("  ***  \n");
    printf(" ***** \n");
    printf("*******\n");
    printf("  ***  \n");
}

void drawCat() {
    printf("/\\   /\\\n");
    printf("  o o\n");
    printf(" =   =\n");
    printf("  ---\n");
}