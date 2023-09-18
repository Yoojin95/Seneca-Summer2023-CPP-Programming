/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 19 2023
***********************************************************************/
#include <iostream>
#include "Shape.h"

namespace sdds
{
    std::ostream& operator<<(std::ostream& os, const Shape& src)
    {
        src.draw(os);
        return os;
    }
    std::istream& operator>>(std::istream& is, Shape& src)
    {
        src.getSpecs(is);
        return is;
    }
}