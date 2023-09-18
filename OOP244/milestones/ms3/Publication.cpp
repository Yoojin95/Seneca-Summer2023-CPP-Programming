/***********************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 28 2023
************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Publication.h"
#include "Date.h"
#include "Lib.h"
using namespace std;

namespace sdds
{
	// default constructor of Publication that sets date attribute to current date
	Publication::Publication(): m_date()
	{
	}

	// copy constructor of Publication that does deep copying
	Publication::Publication(const Publication& pub)
	{
		if (pub)
		{
			m_title = nullptr;
			*this = pub;
		}
	}

	// copy assignment operator overload that does deep copying
	Publication& Publication::operator=(const Publication& pub)
	{
		if (this != &pub)
		{
			if (pub.m_title != nullptr && pub.m_shelfID[0] != '\0' && pub.m_title[0] != '\0')
			{
				delete[] m_title;
				int size = strlen(pub.m_title) + 1;
				m_title = new char[size];
				strcpy(m_title, pub.m_title);
				strcpy(m_shelfID, pub.m_shelfID);
				m_membership = pub.m_membership;
				m_libRef = pub.m_libRef;
				m_date = pub.m_date;
			}
			else
			{
				delete[] m_title;
				m_title = nullptr;
			}
		}
		return *this;
	}

	// destructor of Publication that releases memory pointed by m_title
	Publication::~Publication()
	{
		delete[] m_title;
		m_title = nullptr;
	}

	// sets m_membership to member_id if it is within range, or sets it to 0 if member_id is out of range
	void Publication::set(int member_id)
	{
		if (member_id >= 10000 && member_id <= 99999)
			m_membership = member_id;
		else
			m_membership = 0;
	}

	// sets m_libRef to argument value
	void Publication::setRef(int value)
	{
		m_libRef = value;
	}

	// sets the date to current date
	void Publication::resetDate()
	{
		m_date = Date();
	}

	// returns "P" to indicate current object is "Publication"
	char Publication::type()const
	{
		return 'P';
	}

	// returns true if m_membership value is not zero, or false otherwise
	bool Publication::onLoan()const
	{
		return (m_membership != 0);
	}

	// returns the date attribute
	Date Publication::checkoutDate()const
	{
		return m_date;
	}

	// returns true if the argument title exists within m_title, or false otherwise
	bool Publication::operator==(const char* title)const
	{
		return (strstr(m_title, title) != NULL);
	}

	// conversion operator overload that returns m_title
	Publication::operator const char* ()const
	{
		return m_title;
	}

	// returns the libRef attribute
	int Publication::getRef() const
	{
		return m_libRef;
	}

	// returns true if the address of io object is either the address of cin object or cout object
	bool Publication::conIO(ios& io) const
	{
		return (&io == &cin || &io == &cout);
	}

	// if the current object is valid, it prints the details of attributes in a specific format depending on its IO status
	ostream& Publication::write(ostream& os) const
	{
		if (*this)
		{
			bool isConsole = conIO(os);
			if (isConsole)
			{
				os << "| "
					<< setw(4) << left << m_shelfID << " | "
					<< setw(30) << setfill('.') << m_title << " | "
					<< setfill(' ');
				if (m_membership == 0)
				{
					os << " N/A ";
				}
				else
				{
					os << m_membership;
				}
				os << " | ";
				m_date.write(os);
				os << " |";
			}
			else
			{
				os << type() << '\t' << m_libRef << '\t'
					<< m_shelfID << '\t' << m_title << '\t'
					<< m_membership << '\t';
				m_date.write(os);
			}
		}
		return os;
	}

	// reads all values of data members from istream or from the data file
	istream& Publication::read(istream& is)
	{
		delete[] m_title;
		m_title = nullptr;
		m_shelfID[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();

		char title[256];
		char shelf[SDDS_SHELF_ID_LEN + 1];
		int membership = 0;
		int libRef = -1;
		Date date;

		if (conIO(is))
		{
			cout << "Shelf No: ";
			is.getline(shelf, SDDS_SHELF_ID_LEN + 1);
			if (strlen(shelf) != 4)
			{
				is.setstate(ios::failbit);
			}
			cout << "Title: ";
			is.getline(title, 256);
			cout << "Date: ";
			is >> date;
		}
		else
		{
			is >> libRef;
			is.ignore(100, '\t');
			is.getline(shelf, SDDS_SHELF_ID_LEN + 1, '\t');
			is.getline(title, 256, '\t');
			is >> membership;
			is.ignore(100, '\t');
			is >> date;
		}

		if (date.errCode())
		{
			is.setstate(ios::failbit);
		}

		if (is)
		{
			int size = strlen(title) + 1;
			m_title = new char[size];
			strcpy(m_title, title);
			strcpy(m_shelfID, shelf);
			m_membership = membership;
			m_date = date;
			m_libRef = libRef;
		}
		return is;
	}

	// returns true if Publication object is valid, meaning m_title is not nullptr, and m_shelfID is 
	//not an empty string
	Publication::operator bool() const
	{
		return (m_title != nullptr && m_shelfID[0] != '\0');
	}
}

