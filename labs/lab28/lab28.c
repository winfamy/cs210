/** lab28.c
* ===========================================================
* Name: FIRST LAST, DATE
* Section: SECTION
* Project: Progamming Assessment 3 Practice
* Documentation: DOC STATEMENT
* ===========================================================  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct EmployeeBD {
    char firstName[64];
    char lastName[64];
    char birthMonth[64];
    int birthDate;
} EmployeeBD;

int main(void)
{
//    PROBLEM 1 - STRING MANIPULATION
//          a.) Define a function called numVowels that takes in a character array and outputs
//          an integer.  The function itself finds the number of vowels within the provided character
//          array. The character array may contain spaces and punctuation.

    //      b.) Define a function called sortString that expects an array of characters array and
    //      and returns a pointer to an array of characters.  The function sorts the characters
    //      in the string in alphabetic order, stores them in this order, and returns a pointer to
    //      this sorted array of characters.
    //      The character array may contain spaces and punctuation. When sorting, spaces and punctuation
    //      should be ignored and all alphabetic characters should be changed to lowercase for
    //      sorting and output.
    //      NOTE: In order to return a pointer to an array of characters that has scope outside a
    //          function call, the memory used to store the sorted array must by dynamically
    //          allocated.

    // PROBLEM 2 - Manipulate Employee Data
    //      You are tasked to create a program that will pull employee records from a simple
    //      text file that contains name and birthdate.  The ultimate goal is to allow a user
    //      to input a month that will result in output to the screen displaying all of the
    //      employees with birthdays for the specified month.  This will assist the squadron
    //      commander with ensuring that all employee birthdays are recognized at the
    //      monthly staff meeting.

    //      a.) Define a structure type, named EmployeeBD, with appropriate members
    //      to store data from the Employee_Recs.txt file. Use the fields names:
    //      FirstName, lastName, birthMonth, and birthDate.

    //      b.) Use the getNumLines function provided to capture the number of records to be read from
    //      from the Employee_Recs.txt file, then dynamically allocate memory to store the employee data
    //      from the text file.

    //      c.) Create a user-defined function called readFile, which requires the filename,
    //      memory passed by reference, and the number of records to be passed as parameters
    //      (in that order).  This function returns the integer value corresponding to the number
    //      of records successfully read.

    //      d.) Create a user-defined function called IDEmpBDMonth to print the employee records
    //      for all employees born in a specified month.  This function accepts three parameters
    //      being the stored records passed by reference, the number of records, and the specified
    //      month for record printing (in that order).  It returns the number of records with the
    //      specified month.
    //      NOTE:  In main, ask the user to provide an integer from 1 - 12 that corresponds with the
    //          birth month they would like to query.
    //      Format the output to the screen as follows:
    //          Example if the user enters 10:
    //              Requested Birthdays are:
    //              Lastname	Firstname	Birthday
    //              *********************************************
    //              Smith		Brian		October 13

    return 0;
}

int getNumLines(char filename[])
{
    char c;
    int count = 0;
    // Open the file
    FILE* fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }

    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;

    // Close the file
    fclose(fp);
    //printf("The file %s has %d lines\n ", filename, count);

    return count;
}
int numVowels(char string[]) {
    int vowelsc = 0;
    int length = strlen(string);
    char vowels[] = {
            'A', 'E', 'I', 'O', 'U',
            'a', 'e', 'i', 'o', 'u', '\0'
    };

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < strlen(vowels); ++j) {
            if (string[i] == vowels[j]) {
                vowelsc++;
            }
        }
    }

    return vowelsc;
}

int sort(const void * elem1, const void * elem2) {
    int a = *((int*)elem1);
    int b = *((int*)elem2);
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}

char * sortString(char string[]) {
    char * newString = malloc(sizeof(char) * strlen(string));
    int counter = 0;
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] >= 65 && string[i] <= 90) {
            string[i] = (char)((int)string[i] + 32);
        }

        if (string[i] >= 65 && string[i] <= 122) {
            newString[counter] = string[i];
            counter++;
        }
    }

    qsort(newString, counter, sizeof(char), sort);
    return newString;
}

int readFile(char file[], EmployeeBD * records, int lines) {
    FILE * fp = fopen(file, "r");
    if (fp == NULL) {
        printf("dummy\n");
        exit(1);
    } else {
        for (int i = 0; i < lines; ++i) {
            fscanf(fp, "%s %s %s %d", records[i].firstName, records[i].lastName, records[i].birthMonth, &records[i].birthDate);
        }
    }

    return lines;
}

int IDEmpBDMonth(EmployeeBD * records, int rows, char month[]) {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        if (!strcmp(records[i].birthMonth, month)) {
            count++;
        }
    }

    return count;
}