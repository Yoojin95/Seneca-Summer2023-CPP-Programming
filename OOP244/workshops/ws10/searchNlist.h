// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Yoojin Lee      August 2 2023
/////////////////////////////////////////////////////////////////
#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H
#include <iostream>
#include "Collection.h"

using namespace std;

namespace sdds
{
	template<typename T1, typename T2>
	bool check(T1* array, int index, T2 key)
	{
		return array[index] == key;
	}

	template<typename T1, typename T2>
	bool search(T1* array, int number, T2 key, Collection<T1>& c)
	{
		bool index = false;
		for (int i = 0; i < number; i++)
		{
			if (check(array, i, key))
			{
				c.add(array[i]);
				index = true;
			}
		}
		return index;
	}

	template <typename T>
	void listArrayElements(const char* title, T* array, int number)
	{
		cout << title << endl;
		for (int i = 0; i < number; i++)
		{
			cout << i + 1 << ": " << array[i] << endl;
		}
	}

	template <typename T1>
	bool sizeCheck(Collection<T1>& c1, Collection<T1>& c2)
	{
		return c1.size() > c2.size();
	}
}
#endif // !SDDS_SEARCHNLIST_H

