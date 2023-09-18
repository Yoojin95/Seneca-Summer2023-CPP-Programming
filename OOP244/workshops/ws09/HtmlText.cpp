/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 27 2023
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "HtmlText.h"
#include <cstring>
#include <fstream>

using namespace std;

namespace sdds {
    HtmlText::HtmlText(const char* filename, const char* title)
        : Text(filename), m_title(nullptr) {
        if (title != nullptr) {
            // Allocate memory and copy the title
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
        }
    }

    // Copy constructor
    HtmlText::HtmlText(const HtmlText& other) : Text(other), m_title(nullptr) {
        if (other.m_title != nullptr) {
            // Allocate memory and copy the title
            m_title = new char[strlen(other.m_title) + 1];
            strcpy(m_title, other.m_title);
        }
    }

    // Copy assignment operator
    HtmlText& HtmlText::operator=(const HtmlText& other) {
        if (this != &other) {
            // Call the base class assignment operator
            Text::operator=(other);

            // Free existing memory
            delete[] m_title;

            m_title = nullptr;
            if (other.m_title != nullptr) {
                // Allocate memory and copy the title
                m_title = new char[strlen(other.m_title) + 1];
                strcpy(m_title, other.m_title);
            }
        }
        return *this;
    }

    // Destructor
    HtmlText::~HtmlText() {
        delete[] m_title;
    }

    void HtmlText::write(ostream& os) const {
        // Implementation of the virtual write() function for HtmlText
        // This function converts the text file to a simple HTML file as described in the requirements.
        os << "<html><head><title>";
        os << (m_title ? m_title : "No Title");
        os << "</title></head>\n<body>\n";

        if (m_title != nullptr && strlen(m_title) > 0) {
            os << "<h1>" << m_title << "</h1>\n";
        }

        if (m_content != nullptr) {
            bool mSpaces = false;
            for (size_t i = 0; m_content[i] != '\0'; i++) {
                char ch = m_content[i];
                switch (ch) {
                case ' ':
                    if (mSpaces) {
                        os << "&nbsp;";
                    }
                    else {
                        os << ' ';
                        mSpaces = true;
                    }
                    break;
                case '<':
                    os << "&lt;";
                    mSpaces = false;
                    break;
                case '>':
                    os << "&gt;";
                    mSpaces = false;
                    break;
                case '\n':
                    os << "<br />\n";
                    mSpaces = false;
                    break;
                default:
                    os << ch;
                    mSpaces = false;
                    break;
                }
            }
        }

        os << "</body>\n</html>";
    }
  }

