/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 1 Part 2
// Version 1.0
// Description
// professor's tester program
//
// Revision History
/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, May 23 2023
*******************************************************************/
//
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "cstring.h"
using namespace sdds;
using namespace std;

int main() {
	char str1[80] = "abcdefghijklmnopqrstuvwxyz";
	char str2[80];
	const char* fadd;
	strCpy(str2, str1);			// abcdefghijklmnopqrstuvwxyz	
	cout << str2 << endl;		
	strnCpy(str2, "@@@", 2);	// @@cdefghijklmnopqrstuvwxyz
	cout << str2 << endl;		
	strnCpy(str2, "@@@", 3);	// @@@defghijklmnopqrstuvwxyz
	cout << str2 << endl;		
	strnCpy(str2, "@@@", 4);	// @@@
	cout << str2 << endl;		 
	cout << strCmp("aab", "aaa") << endl;		// 1
	//cout << strCmp("aaa", "aab") << endl;
	//cout << strCmp("aaa", "aaa") << endl;
	cout << strnCmp("aab", "aaa", 2) << endl;	// 0
	cout << strnCmp("aab", "aaa", 3) << endl;	// 1
	cout << strLen("") << endl;					// 0
	cout << strLen(str1) << endl;				// 26
	fadd = strStr(str1, "jkl");					
	cout << fadd << endl;						// jklmnopqrstuvwxyz
	fadd = strStr(str1, "bbb");	
	if (!fadd) cout << "Not found" << endl;		// Not found
	strCpy(str2, "John ");
	strCat(str2, "Doe");
	cout << str2 << endl;						// John Doe
	return 0;
}