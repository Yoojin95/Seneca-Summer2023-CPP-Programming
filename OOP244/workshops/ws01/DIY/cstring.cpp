/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, May 23 2023
*******************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
using namespace std;

namespace sdds {
	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src) {
		int i;
		for (i = 0; src[i] != 0; i++) {
			des[i] = src[i];
		}
		des[i] = '\0';
	}

	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len) {
		int i, j;
		for (i = 0; i < len; i++) {
			des[i] = src[i];
		} // i = 2
		for (j = 0; des[i + j] != 0; j++) { // 2+0=2  2+1=3  3+1=4
			des[i + j] = des[i + j];
		}
		des[i + j] = '\0';
		// @@cdefghijklmnopqrstuvwxyz
	}


	// Compares two C-strings 
	// returns 0 if they are the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2) {
		if (s1 > s2) {
			return 1;
		}
		else if (s1 < s2) {
			return -1;
		}
		else return 0;
		// strCmp("aab", "aaa") returns 1
	}

	int strnCmp(const char* s1, const char* s2, int len) {
		int i = 0; 
		int result = 0;
	
		for (i = 0; i < len; i++) {
			if (s1[i] > s2[i]) {
				result = 1;
			}
			else if (s1[i] < s2[i]) {
				result = -1;
			}
			else result = 0;
		}
		return result;
	}


	// returns the lenght of the C-string in characters
	int strLen(const char* s) {
		int length = 0;
		for (int i = 0; s[i] != 0; ++i) {
			length++;
		}
		return length;
	}


	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2) {
		int i = 0;
		const char* result = nullptr;
		bool flag = false;

		while (str1[i] && strLen(str1) > strLen(str2) && !flag) {
			if (strnCmp(&str1[i], str2, strLen(str2)) == 0) {
				result = &str1[i];
				flag = true;
			}
			i++;
		}
		return result;
	}


	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src) {
		int i, j;
		for (i = 0; des[i] != 0; i++) {
		}
		
		for (j = 0; src[j] != 0; j++) {
			des[i] = src[j];
			i++;
		}
		des[i] = '\0';
	}
}
