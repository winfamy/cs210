
#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include "lab26.h"

//#define FILENAME "../labs/lab26/lab26Data.csv"
#define FILENAME "lab26Data.csv"

int main(void) {
   // With the functions provided in the Vector ADT,
   //   create a correctly sized vector to read-in all
   //   data from the lab26Data.csv file
   int lines = getNumLines(FILENAME);
   vector v;
   vector_create(&v, lines);
   
   // Utilize your readFile() function from Lab 25
   //   to populate the vector -- you will need to make changes
   //   for this function to perform correctly
   readFile(FILENAME, &v, lines);

   // With the functions provided in the Vector ADT,
   //   print the number of vector elements
	printf("%d\n", vector_size(&v));
    
   // With the functions provided in the Vector ADT,
   //   insert a 12 at index 139
   vector_insert(&v, 139, 12);

   // With the functions provided in the Vector ADT,
   //   print the number of vector elements
   printf("%d\n", vector_size(&v));
    
   // With the functions provided in the Vector ADT,
   //   print the element at index 999
   printf("%d\n", *vector_at(&v, 999));
    
   // With the functions provided in the Vector ADT,
   //   erase the element at index 999
   vector_erase(&v, 999);

   // With the functions provided in the Vector ADT,
   //   print the element at index 999
	printf("%d\n", *vector_at(&v, 999));
    

   // With the functions provided in the Vector ADT,
   //   print the number of vector elements
	printf("%d\n", vector_size(&v));
    

    // Using the Vector ADT provided function
    //   vector_push_back to insert the integer 222
	vector_push_back(&v, 222);
   

   // With the functions provided in the Vector ADT,
   //   print the number of vector elements
	printf("%d", vector_size(&v));
    

   // With the functions provided in the Vector ADT,
   //   destroy the vector
	vector_destroy(&v);
}

void readFile(char filename[], vector* v, int lines) {
	FILE * fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Could not open file %s.\n", filename);
		exit(1);
	}

	int d;
	for (int i = 0; i < lines; ++i) {
		fscanf(fp, "%d,", &d);
		*vector_at(v, i) = d;
	}
}

int getNumLines(char filename[]) {
	char c;
	int count = 0;
	FILE* fp = fopen(filename, "r");

	// Check if file exists
	if (fp == NULL) {
		printf("Could not open file %s", filename);
		return 0;
	}

	for (c = getc(fp); c != EOF; c = getc(fp)) {
		if (c == '\n') {
			count = count + 1;
		}
	}

	// Close the file
	fclose(fp);

	return count;
}