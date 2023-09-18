/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 19 2023
***********************************************************************/
#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_

#include "LblShape.h"

namespace sdds
{
    class Rectangle : public LblShape
    {
        unsigned int m_width{ 0 };
        unsigned int m_height{ 0 };

    public:
        Rectangle() {}
        Rectangle(const char* label, int width, int height);
        
        virtual ~Rectangle() {}

        void getSpecs(std::istream& is);
        void draw(std::ostream& os) const;
    };
}
#endif
