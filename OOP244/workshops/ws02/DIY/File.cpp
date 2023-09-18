/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, May 30 2023
*******************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

// File format: postalcode,population

namespace sdds {
    FILE* fptr;

    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    // Make two 'read' functions for postal code and populations?
   
    // 1) Reads postal code
    bool read(char* p_code) 
    {
        return fscanf(fptr, "%[^,],", p_code) == 1;
    }

    // 2) Reads populations
    bool read(int& population)
    {
        return fscanf(fptr, "%d\n", &population) == 1;
    }

}