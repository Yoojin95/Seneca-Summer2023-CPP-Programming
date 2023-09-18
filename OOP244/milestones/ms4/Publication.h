/***********************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 30 2023
************************************************************/
#ifndef SDDS_PUBLICATION_H_
#define SDDS_PUBLICATION_H_

#include <iostream>
#include "Streamable.h"
#include "Date.h"

namespace sdds
{
	class Publication :public Streamable {
		char* m_title;
		char m_shelfId[SDDS_SHELF_ID_LEN + 1];
		int m_membership;
		int m_libRef;
		Date m_date;
		void setDefault();
	public:
		Publication();
		Publication(const Publication& pub);
		Publication& operator=(const Publication& pub);
		~Publication();
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();

		virtual char type()const;
		bool onLoan()const;
		Date checkoutDate()const;
		bool operator==(const char* title)const;
		operator const char* ()const;
		int getRef()const;

		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
		operator bool() const;

	};
}
#endif // !SDDS_PUBLICATION_H_

