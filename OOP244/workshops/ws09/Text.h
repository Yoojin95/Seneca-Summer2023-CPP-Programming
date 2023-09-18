/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 27 2023
***********************************************************************/
#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

#include <iostream>

namespace sdds {
    class Text {
        char* m_filename;
        int getFileLength() const;
    protected:
        char* m_content;
        const char& operator[](int index) const;
    public:
        Text(const char* filename = nullptr);
        // Rule of three
        Text(const Text& other); // Copy constructor
        Text& operator=(const Text& other); // Copy assignment operator
        ~Text(); // Destructor

        void read();
        virtual void write(std::ostream& os) const;
    };

    std::ostream& operator<<(std::ostream& os, const Text& text);
}

#endif // SDDS_TEXT_H
