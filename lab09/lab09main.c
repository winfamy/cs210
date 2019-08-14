/*** @file lab09main.c
 *    @author Grady Phillips
 *    @brief Main function for lab09
 */
#include "lab09functs.h"
#include <stdio.h>

int main () {
    double r, h;
    double l, w, bh;
    double d;

    printf("Enter cylinder radius followed by height:\n");
    scanf("%lf", &r);
    scanf("%lf", &h);
    printf("The volume is %.6lf.\n", volumeCylinder(r, h));
    printf("Enter box width followed by height followed by depth: \n");
    scanf("%lf", &l);
    scanf("%lf", &w);
    scanf("%lf", &bh);
    printf("The volume is %.6lf.\n", volumeBox(l, w, bh));
    printf("Enter degrees:\n");
    scanf("%lf", &d);
    printf("%.6lf degrees is %.6lf radians.\n", d, degToRad(d));
}