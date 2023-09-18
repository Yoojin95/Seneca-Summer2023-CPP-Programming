/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, May 24 2023
*******************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
	FILE* fptr;

	// Opens the data file for reading
	bool openFile(const char filename[]) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}

	// Returns an integer which is the number of records in the file
	int noOfRecords() {
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1) {
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}

	// Close the data file
	void closeFile() {
		if (fptr) fclose(fptr);
	}

	// TODO: read functions go here
	// 1. Reads employee name | accepts as a parameter the address of an array of character
	bool read(char* empName)	// char* empName -> name is an array or pointer to a character string
	{
		return fscanf(fptr, "%[^\n]\n", empName) == 1;	// no need &
	}

	// 2. Reads employee number | Accepts as a parameter a reference to an integer
	bool read(int& empNumber)
	{
		return fscanf(fptr, "%d,", &empNumber) == 1;
	}
	/*
		return fscanf(fptr, "%d,", &empNumber) == 1;
		: if the read operation was successfully read, fscanf returns 1
		  otherwise, it will return 0 which is false
	*/

	// Reads the employee salary | Acceptes as a parameter a reference to an floating point number
	bool read(double& empSalary)
	{
		return fscanf(fptr, "%lf,", &empSalary) == 1;
	}
}
