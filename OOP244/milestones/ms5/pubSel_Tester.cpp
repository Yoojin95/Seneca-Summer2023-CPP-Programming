// Final Project 
// PublicationSelector Usage demonstration
// File	pubSel_Tester.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Yoojin Lee         August 4, 2023
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Publication.h"
#include "Book.h"
#include "PublicationSelector.h"

using namespace std;
using namespace sdds;

void prnPub(Publication* p[], int size, int ref) {
    int i;
    for (i = 0; i < size; i++) {
        if (ref == p[i]->getRef()) {
            cout << *p[i] << endl;
            i = size; 
        }
    }
}
int main() {
    ifstream infile("LibRecs.txt");
    Publication* p[1000]{};
    PublicationSelector ps("Publications with Harry and MoneySencse", 5);
    char type{};
    int i;
    for (i = 0; infile; i++) {
        infile >> type;
        infile.ignore();
        if (infile) {
            if (type == 'P')
                p[i] = new Publication;
            else if (type == 'B')
                p[i] = new Book;
            if (p[i]) {
                infile >> *p[i];
                if (strstr(*p[i], "Harry") || strstr(*p[i], "MoneySense"))
                    ps << p[i]; 
            }
        }
    }
    if (ps) {
        ps.sort(); 
        int ref = ps.run();
        if (ref) {
            cout << "Selected Library Reference Number: " << ref << endl;
            prnPub(p, 100, ref);
        }
        else {
            cout << "Aborted by user!";
        }
    }
    else {
        cout << "No matches to \"Harry\" and \"MoneySense\" found" << endl;
    }
    for (i = 0; p[i]; i++) {
        delete p[i];
    }
    return 0;
}