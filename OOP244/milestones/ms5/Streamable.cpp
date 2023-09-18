// Final Project
// Name               Date                 Reason
// Yoojin Lee         August 4, 2023
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include "Streamable.h"

using namespace std;

namespace sdds
{
	ostream& operator<<(ostream& os, const Streamable& stream)
	{
		return stream.write(os);

	}

	istream& operator>>(istream& is, Streamable& stream)
	{
		return stream.read(is);

	}
}