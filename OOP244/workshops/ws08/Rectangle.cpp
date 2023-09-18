/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 19 2023
***********************************************************************/
#include <iostream>
#include <cstring>
#include "Rectangle.h"
using namespace std;

namespace sdds
{
    Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label)
    {
        int widthComp = strlen(LblShape::label()) + 2;

        if (width > widthComp && height > 3) 
        {
            m_width = width;
            m_height = height;
        }
    }

    /*
        Reads comma-separated specs of the Rectangle from istream.
        This function overrides the getSpecs function of the base class as follows.
        First, it will call the getSpecs function of the base class, then it will read two comma-separated values from istream for m_width and m_length 
        and then ignores the rest of the characters up to and including the newline character ('\n').
    */
    void Rectangle::getSpecs(std::istream& is)
    {
        int width;
        int height;
        char comma;
        bool flag = false;

        do 
        {
            LblShape::getSpecs(is);

            is >> width >> comma >> height;

            if (!is) 
            {
                is.clear();
                is.ignore(32767, '\n');
            }
            else 
            {
                is.ignore();
                m_width = width;
                m_height = height;
                flag = true;
            }
        } while (!flag);
    }

    /*
        This function overrides the draw function of the base class.
        If the Rectangle is not in an empty state, this function will draw a rectangle with a label inside as follows, otherwise, it will do nothing:

        First line:
        prints '+', then prints the '-' character (m_width - 2) times and then prints '+' and goes to newline.

        Second line:
        prints '|', then in (m_width-2) spaces it prints the label() left justified and then prints '|' and goes to new line.

        In next (m_height - 3) lines:
        prints '|', (m_width-2) spaces then prints '|' and goes to new line.

        Last line: exactly like first line.

        For example, if the Cstring returned by the label query is "Container", the width is 30 and the height is 5, this function should insert the following into ostream:

        +----------------------------+
        |Container                   |
        |                            |
        |                            |
        +----------------------------+ 
    */
    void Rectangle::draw(std::ostream& os) const
    {
        if (m_width > 0 && m_height >> 0) 
        {
            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os << '-';
            os << '+' << endl;

            os << '|';
            os.width(m_width - 2);
            os.fill(' ');
            os << left << LblShape::label();
            os << '|' << endl;

            for (unsigned int i = 0; i < (m_height - 3); i++) 
            {
                os << '|';
                os.width(m_width - 2);
                os.fill(' ');
                os << ' ';
                os << '|' << endl;
            }

            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os << '-';
            os << '+';
        }
    }
}