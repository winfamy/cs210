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

    double h;
    double m;
    double f;
    printf("Homework (x / 80): ");
    scanf("%lf", &h);
    printf("Midterm (x / 40): ");
    scanf("%lf", &m);
    printf("Final (x / 70): ");
    scanf("%lf", &f);
    printf("Total percentage: %.2lf%%", coursePercentage(h, m, f));
}

void drawTree() {
    printf("   *\n");
    printf("  ***\n");
    printf(" *****\n");
    printf("*******\n");
    printf("  ***\n\n");
}

void drawCat() {
    printf("/\\   /\\\n");
    printf("  o o\n");
    printf(" =   =\n");
    printf("  ---\n\n");
}

double coursePercentage(double h, double m, double f) {
    return (h/80*.2 + m/40*.3 + f/70*.5)*100;
}