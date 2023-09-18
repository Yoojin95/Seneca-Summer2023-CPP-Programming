/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 19 2023
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;

namespace sdds
{
    const char* LblShape::label() const
    {
        return m_label;
    }

    /*
        Allocates memory large enough to hold the incoming Cstring argument pointed by the m_label member variable. 
        Then copies the Cstring argument to the newly allocated memory.
    */
    LblShape::LblShape(const char* label)
    {
        if (label && label[0] != '\0') {
            m_label = new char[strlen(label) + 1];
            strcpy(m_label, label);
        }
    }

    /*
        Deletes the memory pointed by m_label member variable.
    */
    LblShape::~LblShape()
    {
        if (m_label) {
            delete[] m_label;
            m_label = nullptr;
        }
    }

    /*
        Reads a comma-delimited Cstring form istream:
        Override the Shape::getSpecs pure virtual function to receive a Cstring (a label) from istream up to the ',' character 
        (and then extract and ignore the comma). Afterward, follow the same logic as was done in the one argument constructor; 
        allocate memory large enough to hold the Cstring and copy the Cstring into the newly allocated memory.
    */
    void LblShape::getSpecs(std::istream& is)
    {
        string label;

        // Reads a comma-delimited Cstring form istream
        getline(is, label, ',');

        // copy the Cstring into the newly allocated memory
        delete[] m_label;
        m_label = new char[strlen(label.c_str()) + 1];
        strcpy(m_label, label.c_str());
    }
}