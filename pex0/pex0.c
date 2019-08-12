/*** @file lab06p3.c
 *   @author your name
 *   @brief The template for CS210 lab 6 part 3.
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void drawTree(void);
void drawCat(void);
double coursePercentage(double, double, double);

int main() {
    drawTree();
    drawCat();

    int h;
    int m;
    int f;
    printf("Homework (x / 80): ");
    scanf("%d", &h);
    printf("Midterm (x / 40): ");
    scanf("%d", &m);
    printf("Final (x / 70): ");
    scanf("%d", &f);
    printf("Total percentage: %.2lf%%", coursePercentage(h/80.0, m/40.0, f/70.0));
}

void drawTree() {
    printf("   *   \n");
    printf("  ***  \n");
    printf(" ***** \n");
    printf("*******\n");
    printf("  ***  \n\n");
}

void drawCat() {
    printf("/\\   /\\\n");
    printf("  o o\n");
    printf(" =   =\n");
    printf("  ---\n\n");
}

double coursePercentage(double h, double m, double f) {
    return (h * .2 + m * .3 + f * .5) * 100;
}