/***********************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 28 2023
************************************************************/
#ifndef SDDS_PUBLICATION_H_
#define SDDS_PUBLICATION_H_

#include <iostream>
#include "Streamable.h"
#include "Date.h"

namespace sdds
{
	class Publication : public Streamable
	{
		char* m_title{};	// set to null by default
		char m_shelfID[5] = { '\0' };	// set to empty string by default
		int m_membership = 0;	// set to zero by default
		int m_libRef = -1;	// set to -1 by default
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

		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std:: istream& istr);
		operator bool() const;
	};

}
#endif // !SDDS_PUBLICATION_H_
