// Final Project
// Name               Date                 Reason
// Yoojin Lee         August 4, 2023
/////////////////////////////////////////////////////////////////
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
	Publication::Publication() : m_date()
	{
	}

	Publication::Publication(const Publication& pub)
	{
		if (pub)
		{
			m_title = nullptr;
			*this = pub;
		}
	}

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

	Publication::~Publication()
	{
		delete[] m_title;
		m_title = nullptr;
	}

	void Publication::set(int member_id)
	{
		if (member_id >= 10000 && member_id <= 99999)
			m_membership = member_id;
		else
			m_membership = 0;
	}

	void Publication::setRef(int value)
	{
		m_libRef = value;
	}

	void Publication::resetDate()
	{
		m_date = Date();
	}

	char Publication::type()const
	{
		return 'P';
	}

	bool Publication::onLoan()const
	{
		return (m_membership != 0);
	}

	Date Publication::checkoutDate()const
	{
		return m_date;
	}

	bool Publication::operator==(const char* title)const
	{
		return (strstr(m_title, title) != NULL);
	}

	Publication::operator const char* ()const
	{
		return m_title;
	}

	int Publication::getRef() const
	{
		return m_libRef;
	}

	bool Publication::conIO(ios& io) const
	{
		return (&io == &cin || &io == &cout);
	}

	ostream& Publication::write(ostream& os) const
	{
		if (*this)
		{
			bool isConsole = conIO(os);
			char temp_title[SDDS_TITLE_WIDTH + 1];
			strncpy(temp_title, m_title, SDDS_TITLE_WIDTH);
			temp_title[SDDS_TITLE_WIDTH] = '\0';
			if (isConsole)
			{
				os << "| "
					<< setw(SDDS_SHELF_ID_LEN) << left << m_shelfID << " | "
					<< setw(SDDS_TITLE_WIDTH) << setfill('.') << temp_title << " | "
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

	istream& Publication::read(istream& is)
	{
		delete[] m_title;
		m_title = nullptr;
		m_shelfID[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();

		char title[SDDS_MAXIMUM_CHARS];
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
			is.getline(title, SDDS_MAXIMUM_CHARS);
			cout << "Date: ";
			is >> date;
		}
		else
		{
			is >> libRef;
			is.ignore(100, '\t');
			is.getline(shelf, SDDS_SHELF_ID_LEN + 1, '\t');
			is.getline(title, SDDS_MAXIMUM_CHARS, '\t');
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

	Publication::operator bool() const
	{
		return (m_title != nullptr && m_shelfID[0] != '\0');
	}
}