/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 6 2023
***********************************************************************/

#include "cstring.h"
namespace sdds {
	
	void strCpy(char* des, const char* src) 
	{
		int i = 0;
		while (src[i])
		{
			des[i] = src[i];
			i++;
		}
		des[i] = '\0';	
	}

	int strLen(const char* s)
	{
		int len = 0;
		while (s[len])
		{
			len++;
		}
		return len;
	}

	void strCat(char* des, const char* src)
	{
		int des_len = strLen(des);
		int cnt = 0;

		while (src[cnt])
		{
			des[des_len] = src[cnt];
			des_len++;
			cnt++;
		}
		des[des_len] = '\0';
	}

}