// Final Project
// Name               Date                 Reason
// Yoojin Lee         August 4, 2023
/////////////////////////////////////////////////////////////////
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include "Publication.h"


namespace sdds
{
	class Book : public Publication
	{
		char* m_author{};

	public:
		Book();

		Book(const Book&);
		Book& operator=(const Book&);
		~Book();

		virtual char type()const;
		virtual void set(int);
		virtual std::ostream& write(std::ostream& os) const;
		virtual std::istream& read(std::istream& is);
		virtual operator bool() const;

	};
}

#endif


