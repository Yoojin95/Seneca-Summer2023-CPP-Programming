/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 6 2023
***********************************************************************/

#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_
namespace sdds {
	void strCpy(char* des, const char* src);
	int strLen(const char* s);
	void strCat(char* des, const char* src);
}
#endif // !SDDS_CSTRING_H_