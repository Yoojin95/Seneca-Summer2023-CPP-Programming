/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, May 30 2023
*******************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
using namespace std;

namespace sdds {
	void strCpy(char* des, const char* src) {
		int i;
		for (i = 0; src[i] != 0; i++) {
			des[i] = src[i];
		}
		des[i] = '\0';
	}

	void strnCpy(char* des, const char* src, int len) {
		int i, j;
		for (i = 0; i < len; i++) {
			des[i] = src[i];
		}
		for (j = 0; des[i + j] != 0; j++) { 
			des[i + j] = des[i + j];
		}
		des[i + j] = '\0';
	}

	int strCmp(const char* s1, const char* s2) {
		if (s1 > s2) {
			return 1;
		}
		else if (s1 < s2) {
			return -1;
		}
		else return 0;
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

	int strLen(const char* s) {
		int length = 0;
		for (int i = 0; s[i] != 0; ++i) {
			length++;
		}
		return length;
	}

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