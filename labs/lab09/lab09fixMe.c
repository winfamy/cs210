/** lab09.c
* ===========================================================
* Name: Name, Date
* Section:
* Project: Lab 9
* Purpose: Debugging
* ===========================================================
* Instructions:
 * Complete the tasks outlined in the lab writeup.
*/
#include <stdio.h>
double convertTemperature(double);

int findLargest(int n1, int n2, int n3) {
	if(n1 >= n2 && n1 >= n3)
		return n1; // printf("%.2lf is the largest number.", n1);

	else if (n2 >= n1 && n2 >= n3)
		return n2; // printf("%.2lf is the largest number.", n2);

	else
		return n3; // printf("%.2lf is the largest number.", n3);
}


int main() {
	// findLargest()
	int n1, n2, n3;

	printf("Enter three integer numbers: \n");
	scanf("%d %d %d", &n1, &n2, &n3);
	int largest = findLargest(n1, n2, n3);
	printf("%d\n", largest);

	// convertTemperature()
	double fahrenheit;
	printf("Please enter a temperature in fahrenheit: \n");
	scanf("%lf", &fahrenheit);
	double celsius = convertTemperature(fahrenheit);
	printf("%lf\n", celsius);
}

double convertTemperature(double fahrenheit) {
	double celsius = (5.0/9.0) * (fahrenheit - 32.0);
	return celsius;
}

