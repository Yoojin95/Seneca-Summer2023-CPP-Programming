/***********************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 30 2023
************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Book.h"

using namespace std;


namespace sdds
{
	/*
		Rule of Three
		1. Destructor
		 - 동적으로 할당된 객체의 메모리를 해제

		2. Copy Constructor
		- 동일한 클래스의 다른 객체를 복사하여 새로운 객체 생성
		- 동적으로 할당된 자원의 깊은복사를 수행해야하며, 원본과 복사본이 서로 독립적이여야 함

		3. Copy Assignment Operator
		- 한 객체를 다른 객체와의 '값'으로 대입
		- 자원의 깊은 복사를 수행하여 객체 간 자원을 공유하지 않도록 해야 함

		->  클래스가 동적으로 할당된 자원을 사용하고 위 함수 중 하나를 명시적으로 정의한 경우
			일관된 동작을 보장하기 위해 반드시 세 함수를 모두 정의해야 함
	*/

	// empty by default, in a safe empty state.
	// default constructor of class Book that sets all data members to safe empty state
	Book::Book() :Publication() {
		m_name = nullptr;
	}

	// copy constructor of class Book that performs deep copying
	Book::Book(const Book& book) :Publication(book) {
		if (book.m_name) {
			m_name = new char[strlen(book.m_name) + 1];
			strcpy(m_name, book.m_name);
		}
		else m_name = nullptr;
	}

	// copy assignment operator overload that performs deep copying
	Book& Book::operator=(const Book& book) {
		(Publication&)*this = book;
		delete[] m_name;
		m_name = nullptr;
		if (book.m_name) {
			m_name = new char[strlen(book.m_name) + 1];
			strcpy(m_name, book.m_name);
		}
		else m_name = nullptr;
		return *this;
	}

	// destructor of class Book that releases memory pointed by m_author
	Book::~Book() {
		delete[] m_name;
		m_name = nullptr;
	}



	// returns the character "B"
	char Book::type()const {
		return 'B';
	}
	// if the current object is valid, prints the details of Book in a specific format depending on its IO status
	/*
		First, it will invoke the write of its Base class.
		If the incoming argument is a console IO object.
			writes a single space.
			writes the author's name in SDDS_AUTHOR_WIDTH spaces.
			If the author's name is longer than the SDDS_AUTHOR_WIDTH value,
			it will cut it short and writes exactly SDDS_AUTHOR_WIDTH characters.

		writes " |"

		If the incoming argument is not a console IO object
			writes a tab character '\t'
			writes the author's name
			returns the incoming ostream.
	*/
	std::ostream& Book::write(std::ostream& os) const {
		Publication::write(os);
		if (Publication::conIO(os)) {
			os << " ";
			if (strlen(m_name) > SDDS_AUTHOR_WIDTH) {
				for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++)
					os << m_name[i];
			}
			else {
				os.setf(ios::left);
				os.width(SDDS_AUTHOR_WIDTH);
				os.fill(' ');
				os << m_name;
				os.unsetf(ios::left);
			}
			os << " |";
		}
		else {
			os << '\t';
			os << m_name;
		}
		return os;
	}

	/*
			First, invoke the read of the Base class.
			Free the memory held for the author's name
			If the incoming argument is a console IO object
				ignore one character (skip the '\n')
				prompt "Author: "
				read the author's name
			If the incoming argument is not a console IO object
				ignore the tab character
				read the author's name
			Then if the incoming istream object is not in a fail state, dynamically hold the author's name in the char pointer attribute of the book class.

			At the end return the incoming istream object.
		*/
	std::istream& Book::read(std::istream& istr) {
		char* name = new char[256];
		Publication::read(istr);
		if (Publication::conIO(istr)) {
			istr.ignore(1000, '\n');
			cout << "Author: ";
			istr.get(name, 256, '\n');
		}
		else {
			istr.ignore(1000, '\t');
			istr.get(name, 256, '\n');
		}
		if (istr) {
			delete[] m_name;
			m_name = nullptr;
			if (name) {
				m_name = new char[strlen(name) + 1];
				strcpy(m_name, name);
			}
		}
		delete[] name;
		return istr;
	}
	// sets m_membership value to the argument member_id and sets the Date to current date
	void Book::set(int member_id) {
		Publication::set(member_id);
		Publication::resetDate();
	}

	// returns true if Book object is valid, or false otherwise
	Book::operator bool() const {
		return m_name != nullptr && Publication::operator bool();
	}
}