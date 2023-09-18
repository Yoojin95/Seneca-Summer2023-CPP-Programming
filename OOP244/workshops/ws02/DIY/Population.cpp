/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, May 30 2023
*******************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;

namespace sdds 
{
    int n_pop;  // number of population
    PCpopulations* PCpop;

    // TODO: sort the data based on population
    void sort() 
    {
        int i, j;
        PCpopulations temp;
        for (i = n_pop - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (PCpop[j].population > PCpop[j + 1].population) {
                    temp = PCpop[j];
                    PCpop[j] = PCpop[j + 1];
                    PCpop[j + 1] = temp;
                }
            }
        }
    }


    // 3 mandatory functions: load, display, deallocateMemeory

    bool load(PCpopulations& PCpop) 
    {
        bool ok = false;
        char t_Pcode[50] = {}; // temporarily store a postal code.

        // Checks if reading the data is successful
        if (read(t_Pcode) && read(PCpop.population)) {
            int len = strLen(t_Pcode) + 1;  // dynamically allocates memory
            PCpop.p_code = new char[len];
            strCpy(PCpop.p_code, t_Pcode);
            ok = true;
        }
        return ok;
    }

    bool load(const char* filename) {
        bool ok = false;
        int count = 0;

        if (openFile(filename)) 
        {
            n_pop = noOfRecords();
            PCpop = new PCpopulations[n_pop];

            for (int i = 0; i < n_pop; i++) {
                if (load(PCpop[i])) count++;
            }

            if (count == n_pop) {
                ok = true;
            }
            else {
                cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << filename << endl;
        }
        return ok;
    }


    /*
    Postal Code: population
    -------------------------
    1- A0R:  2543
    2- A0M:  6200
        ...
    15- A0A:  46587
    -------------------------
    Population of Canada: 282439
    */

    // sum of population
    // fix later (put this function in display() function)
    void sumPopulation() 
    {
        int sum = 0;
        for (int i = 0; i < n_pop; i++) 
        {
            sum += PCpop[i].population;
        }
        cout << sum << endl;
    }

    void display(const PCpopulations& PCpop) 
    {
        cout << PCpop.p_code << ":  " << PCpop.population << endl;
    }

    void display() 
    {
        cout << "Postal Code: population\n"
            << "-------------------------"
            << endl;

        sort();

        for (int i = 0; i < n_pop; i++) {
            cout << i + 1 << "- ";
            display(PCpop[i]);
        }

        cout << "-------------------------" << endl;
        cout << "Population of Canada: ";

        sumPopulation();
    }

    void deallocateMemory() 
    {
        for (int i = 0; i < n_pop; i++) {
            delete[] PCpop[i].p_code;
        }
        delete[] PCpop;
    }
}