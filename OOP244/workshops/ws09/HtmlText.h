/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 27 2023
***********************************************************************/
#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H

#include "Text.h"

namespace sdds {
    class HtmlText : public Text 
    {
        char* m_title;
    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr);
        // Rule of three
        HtmlText(const HtmlText& other); // Copy constructor
        HtmlText& operator=(const HtmlText& other); // Copy assignment operator
        ~HtmlText(); // Destructor

        virtual void write(std::ostream& os) const override;
    };
}

#endif // SDDS_HTMLTEXT_H
