//
// Name               Date                 Reason
// Yoojin Lee         August 4, 2023
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Book.h"
#include "Lib.h"

using namespace std;
namespace sdds
{
	Book::Book() :Publication()
	{
	}

	Book::Book(const Book& book)
	{
		if (book)
		{
			m_author = nullptr;
			*this = book;
		}
	}

	Book& Book::operator=(const Book& book)
	{
		if (this != &book)
		{
			if (book.m_author && book.m_author[0])
			{
				Publication::operator=(book);
				delete[] m_author;
				int size = strlen(book.m_author) + 1;
				m_author = new char[size];
				strcpy(m_author, book.m_author);
			}
			else
			{
				delete[] m_author;
				m_author = nullptr;
			}
		}
		return *this;
	}

	Book::~Book()
	{
		delete[] m_author;
		m_author = nullptr;
	}

	char Book::type()const
	{
		return 'B';
	}

	ostream& Book::write(ostream& os) const
	{
		if (*this)
		{
			Publication::write(os);
			char temp_author[SDDS_AUTHOR_WIDTH + 1];
			strncpy(temp_author, m_author, SDDS_AUTHOR_WIDTH);
			temp_author[SDDS_AUTHOR_WIDTH] = '\0';
			if (conIO(os))
			{
				os << " ";
				os << setw(SDDS_AUTHOR_WIDTH) << temp_author;
				os << " |";
			}
			else
			{
				os << '\t';
				os << m_author;
			}
		}
		return os;
	}

	istream& Book::read(istream& is)
	{
		char temp_author[SDDS_MAXIMUM_CHARS];
		Publication::read(is);
		delete[] m_author;
		m_author = nullptr;
		if (conIO(is))
		{
			is.ignore();
			cout << "Author: ";
			is.getline(temp_author, SDDS_MAXIMUM_CHARS);
		}
		else
		{
			is.ignore(100, '\t');
			is.get(temp_author, SDDS_MAXIMUM_CHARS);
		}
		if (is)
		{
			int size = strlen(temp_author) + 1;
			m_author = new char[size];
			strcpy(m_author, temp_author);
		}
		return is;
	}

	void Book::set(int member_id)
	{
		Publication::set(member_id);
		Publication::resetDate();
	}

	Book::operator bool() const
	{
		bool isTrue = Publication::operator bool();
		return (m_author && m_author[0] && isTrue);
	}
}