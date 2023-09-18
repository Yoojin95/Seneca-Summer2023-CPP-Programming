/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop  Part 2
// Version 1.0
// Description
// professor's tester program
//
// Revision History
/////////////////////////////////////////////////////////////////////////
 Yoojin Lee, ylee237@myseneca.ca, 188162218, May 24 2023
************************************************************************/
#include "Employee.h"
using namespace sdds;
int main() {
   if (load()) {
      display();
   }
   deallocateMemory();
   return 0;
}