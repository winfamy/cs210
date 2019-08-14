//
// Created by Grady Phillips on 2019-08-13.
//
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "lab09functs.h"

int main() {
    printf("Testing started\n");

    assert(volumeBox(1, 1, 1) == 1);
    assert(volumeCylinder(10.5, 10.5) == volumeCylinder(10.5, 10.5));
    assert(degToRad(360) == 2*M_PI);

    printf("Testing completed\n");

    return 0;
}