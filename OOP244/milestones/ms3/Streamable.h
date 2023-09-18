/***********************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 28 2023
************************************************************/
#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_

#include <iostream>

namespace sdds
{
	class Streamable
	{
	public:
		virtual std::ostream& write(std::ostream&)const = 0;
		virtual std::istream& read(std::istream&) = 0;

		virtual bool conIO(std::ios&)const = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable() {};
	};
	std::ostream& operator<<(std::ostream&, const Streamable&);
	std::istream& operator>>(std::istream&, Streamable&);
}
#endif // !SDDS_STREAMABLE_H_
