/** lab28.h
* ===========================================================
* Name: Grady Phillips
* Section: M1
* Project: Programming Assessment 3 Practice
* Documentation: None
* ===========================================================  */

//    PROBLEM 1 - STRING MANIPULATION
//          a.) Define a function called numVowels that takes in a character array and outputs
//          an integer.  The function itself finds the number of vowels within the provided character
//          array. The character array may contain spaces and punctuation.

int numVowels(char []);

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

char * sortString(char []);
int comp(const void * elem1, const void * elem2);

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
int getNumLines(char *);
//      c.) Create a user-defined function called readFile, which requires the filename,
//      memory passed by reference, and the number of records to be passed as parameters
//      (in that order).  This function returns the integer value corresponding to the number
//      of records successfully read.
int readFile(char file[], EmployeeBD * records, int lines);
//      d.) Create a user-defined function called IDEmpBDMonth to print the employee records
//      for all employees born in a specified month.  This function accepts three parameters
//      being the stored records passed by reference, the number of records, and the specified
//      month for record printing (in that order).  It returns the number of records with the
//      specified month.
int IDEmpBDMonth(EmployeeBD *, int, char []);
//      NOTE:  In main, ask the user to provide an integer from 1 - 12 that corresponds with the
//          birth month they would like to query.
//      Format the output to the screen as follows:
//          Example if the user enters 10:
//              Requested Birthdays are:
//              Lastname	Firstname	Birthday
//              *********************************************
//              Smith		Brian		October 13

#ifndef MYEXE_LAB28_H
#define MYEXE_LAB28_H


#endif //MYEXE_LAB28_H
