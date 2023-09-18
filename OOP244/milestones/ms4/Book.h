/***********************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 30 2023
************************************************************/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Publication.h"
#include "Lib.h"

namespace sdds 
{
	class Book :public Publication 
	{
		char* m_name{};

	public:
		Book();

		Book(const Book& book);
		Book& operator=(const Book& book);
		~Book();

		char type()const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		void set(int member_id);
		operator bool() const;
	};
}

#endif // !SDDS_BOOK_H
