

#include "lab20functs.h"

double fToC(double degF) {
	return (degF - 32) * ( 5.0 / 9.0 );
}

double cToK(double degC) {
	return degC + 273.15;
}

void printTable(double degFlow, double degFhigh, double degFstep) {
	fprintf(stdout, "\n\n|-----------------------------|\n");
	fprintf(stdout, "|                             |\n");
	fprintf(stdout, "|   Temperature Conversions   |\n");
	fprintf(stdout, "|                             |\n");
	fprintf(stdout, "|-----------------------------|\n");
	fprintf(stdout, "|Farenheit| Celsius | Kelvin  |\n");
	fprintf(stdout, "|-----------------------------|\n");
	for (double i = degFlow; i <= degFhigh; i += degFstep) {
		fprintf(stdout, "|%9.2lf|%9.2lf|%9.2lf|\n", i, fToC(i), cToK(fToC(i)));
	}

	fprintf(stdout, "|-----------------------------|\n");
}

double getInput(double * min, double * max, double * stepSize) {
	int minGood = 0;
	int maxGood = 0;
	int stepSizeGood = 0;
	while (minGood == 0) {
		fprintf(stdout, "Minimum Farenheit temperature:  ");
		fscanf(stdin, "%lf", min);
		if (*min < -459 || *min > 10705) {
			fprintf(stdout, "Your input is outside of the range %.2lf to %.2lf.\n", -459.67, 10706.0);
			fprintf(stdout, "Please re-enter.\n");
		} else {
			minGood = 1;
		}
	}

	while (maxGood == 0) {
		fprintf(stdout, "Maximum Farenheit temperature: ");
		fscanf(stdin, "%lf", max);
		if (*max <= *min || *max > 10705) {
			fprintf(stdout, "Your input is outside of the range %.2lf to %.2lf.\n", *min, 10706.0);
			fprintf(stdout, "Please re-enter.\n");
		} else {
			maxGood = 1;
		}
	}

	while (stepSizeGood == 0) {
		fprintf(stdout, "What step size: ");
		fscanf(stdin, "%lf", stepSize);
		if (*stepSize < 1 || *stepSize > (*max - *min) / 2.0) {
			fprintf(stdout, "Your input is outside of the range %.2lf to %.2lf.\n", 0.0, (*max - *min) / 2.0);
			fprintf(stdout, "Please re-enter.\n");
		} else {
			stepSizeGood = 1;
		}
	}
	return 0;
}

bool again() {
	char c;
	printf("Would you like to do this again? ");
	fscanf(stdin, " %c", &c);
	if (c == 'y' || c == 'Y') {
		return true;
	}


	return false;
}
