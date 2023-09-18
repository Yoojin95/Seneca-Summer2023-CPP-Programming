/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 20 2023
***********************************************************************/

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

#include <iostream>

namespace sdds {
	
	class Mark {
		int m_mark;

	public:
		Mark();
		Mark(const int input);
		~Mark(){};

		operator int() const;
		operator char() const;
		operator double() const;

		Mark &operator+=(const int input);
		Mark &operator=(const int input);
	};

	int operator+=(int &value, const Mark &add);
}

#endif // !SDDS_MARK_H_

