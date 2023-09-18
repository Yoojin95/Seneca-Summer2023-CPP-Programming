/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 19 2023
***********************************************************************/
#include <iostream>
#include "Line.h"

using namespace std;

namespace sdds
{
    /*
        Receives a Cstring and a value for the length of the line. Passes the Cstring to the constructor of the base class 
        and sets the m_length member variable to the value of the second argument.
    */
    Line::Line(const char* label, int length) : LblShape(label)
    {
        if (length > 0)
            m_length = length;
    }

    /*
        Reads comma-separated specs of the Line from istream.
        This function overrides the getSpecs function of the base class as follows.
        First, it will call the getSpecs function of the base class then it will read the value of the m_length attribute from the istream argument, 
        and then it will ignore The rest of the characters up to and including the newline character '\n'.
    */
    void Line::getSpecs(std::istream& is)
    {
        int length;
        bool flag = false;

        do 
        {
            LblShape::getSpecs(is);

            is >> length;

            if (!is) 
            {
                is.clear();
                is.ignore(32767, '\n');
            }
            else 
            {
                is.ignore();
                m_length = length;
                flag = true;
            }
        } while (!flag);
    }

    /*
        This function overrides the draw function of the base class.
        If the m_length member variable is greater than zero and the label() is not null, this function will first print the label() and then go to the new line. Afterwards it keeps printing the '=' (assignment character) to the value of the m_length member variable.
        Otherwise, it will take no action.

        Separator
        ========================================
    */
    void Line::draw(std::ostream& os) const
    {
        if (m_length > 0 && LblShape::label()) 
        {
            os << LblShape::label() << endl;
            os.width(m_length);
            os.fill('=');
            os << '=';
        }
    }
}