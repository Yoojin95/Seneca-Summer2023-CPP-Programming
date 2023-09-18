/***********************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 30 2023
************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include "Streamable.h"

using namespace std;

namespace sdds
{
	/*
		Overload the insertion operator so a constant object of type Streamable can be written on an ostream object
		only if the Streamable object is in a valid state. Otherwise, the function will quietly ignore the insertion action.
	*/
	ostream& operator<<(ostream& os, const Streamable& stream)
	{
		return stream.write(os);
	}

	/*
		Overload the extraction operator so an object of type Streamable can be read from an istream object.
	*/
	istream& operator>>(istream& is, Streamable& stream)
	{
		return stream.read(is);
	}
}