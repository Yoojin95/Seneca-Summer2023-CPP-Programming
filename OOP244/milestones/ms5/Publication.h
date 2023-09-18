// Final Project
// Name               Date                 Reason
// Yoojin Lee         August 4, 2023
/////////////////////////////////////////////////////////////////
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H
#include <iostream>
#include "Streamable.h"
#include "Date.h"

namespace sdds
{
	class Publication :public Streamable
	{
		char* m_title{};				//set to nullptr by default
		char m_shelfID[5] = { '\0' };	//set to empty string by default
		int m_membership = 0;			//set to 0 by default
		int m_libRef = -1;				//set to -1 by default
		Date m_date;

	public:
		Publication();

		Publication(const Publication&);
		Publication& operator=(const Publication&);
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

		virtual bool conIO(std::ios& io) const;
		virtual std::ostream& write(std::ostream& os) const;
		virtual std::istream& read(std::istream& is);
		virtual operator bool() const;

	};
}

#endif