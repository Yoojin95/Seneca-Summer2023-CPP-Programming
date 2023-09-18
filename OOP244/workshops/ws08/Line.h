/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 19 2023
***********************************************************************/
#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include "LblShape.h"

namespace sdds
{
    class Line : public LblShape
    {
        unsigned int m_length{ 0 };

    public:
        Line() {}
        Line(const char* label, int length);
        virtual ~Line() {}

        void getSpecs(std::istream& is);

        void draw(std::ostream& os) const;
    };
}
#endif