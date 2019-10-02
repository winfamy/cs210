#include <stdio.h>
#include "lab20functs.h"

int main() {
    double minF=0.0, maxF=0.0, stepF=0.0;
    do {
		getInput(&minF, &maxF, &stepF);
	    printTable(minF, maxF, stepF);
    } while(again());
    return 0;
}