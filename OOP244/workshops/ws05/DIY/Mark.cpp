/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 20 2023
***********************************************************************/

#include <iostream>
#include "Mark.h"
using namespace std;

// Create a Module for a Mark to encapsulate a mark between 0 and 100

namespace sdds 
{
	
	// If this value is not provided, the value of the mark will be zero
	Mark::Mark()
	{
		m_mark = 0;
	}
	// Member Initializer List -> Mark::Mark() : m_mark(0) {}


	Mark::Mark(const int input) 
	{
		if (input >= 0 && input <= 100) 
		{
			m_mark = input;
		}
		else 
		{
			m_mark = -1;	// invalid
		}
	}

	// Mark can be casted to an integer (int type)
	// The result would be the value of the mark or zero if the mark is in an invalid state
	Mark::operator int() const
	{
		int result = 0;

		if (m_mark >= 0 && m_mark <= 100)
			result = m_mark;

		return result;
	}

	// Mark can be casted to a character (char type)
	// invalid mark will result in an 'X' value
	Mark::operator char() const 
	{
		char result = 'X';

		if (m_mark >= 0 && m_mark < 50) result = 'F';
		else if (m_mark >= 50 && m_mark < 60) result = 'D';
		else if (m_mark >= 60 && m_mark < 70) result = 'C';
		else if (m_mark >= 70 && m_mark < 80) result = 'B';
		else if (m_mark >= 80 && m_mark <= 100) result = 'A';
	
		return result;
	}

	// Mark can be casted to a double
	// the result would be the GPA equivalent of the integer value
	Mark::operator double() const 
	{
		double result = 0.0;

		if (m_mark >= 50 && m_mark < 60) result = 1.0;
		else if (m_mark >= 60 && m_mark < 70) result = 2.0;
		else if (m_mark >= 70 && m_mark < 80) result = 3.0;
		else if (m_mark >= 80 && m_mark <= 100) result = 4.0;

		return result;
	}

	// An integer can be added to the value of the mark using += operator
	// if the mark is invalid, the action is omitted
	// Reference of the mark is returned after the operation.
	Mark &Mark::operator+=(const int input) 
	{
		if (m_mark >= 0 && m_mark <= 100)
		{
			m_mark += input;
		}
		return *this;
	}


	Mark &Mark::operator=(const int input) 
	{
		m_mark = input;
		
		return *this;
	}


	// Mark can be added to an integer, returning the integer after the operation
	// Invalid marks will not add any value to the integer
	int operator+=(int &value, const Mark &add) 
	{
		int temp = int(add);

		if (temp >= 0 && temp <= 100) 
		{
			value += temp;
		}
		return value;
	}
}