//
// Created by Grady Phillips on 2019-08-12.
//

#include "lab09functs.h"
#include <math.h>

double volumeCylinder(double r, double h) {
    return M_PI * pow(r, 2) * h;
}

double volumeBox(double l, double w, double h) {
    return l * w * h;
}

double degToRad(double d) {
	return d/180.0 * M_PI;
}