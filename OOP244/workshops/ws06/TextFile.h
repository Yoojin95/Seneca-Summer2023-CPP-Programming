/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 6 2023
***********************************************************************/

#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds {
    class Line {
        char* m_value{ nullptr };
        
        operator const char* ()const; // conversion operator?
        Line() {}
        Line& operator=(const char*);
        ~Line();
        
        friend class TextFile;
        // copy and copy assignment prevention goes here
        
    };

    class TextFile {
        // private memeber variables
        Line* m_textLines = nullptr;
        char* m_filename = nullptr;
        unsigned m_noOfLines; // unsigned: only positive value is allowed
        unsigned m_pageSize;

        // private memeber function
        void setFilename(const char* fname, bool isCopy = false);
        void setNoOfLines();
        void loadText();
        void saveAs(const char* fileName)const;
        void setEmpty();

    public:
        // public memeber function
        // Constructors
        TextFile(unsigned pageSize = 15);
        TextFile(const char* filename, unsigned pageSize = 15);
        
        // Copy Constructor
        TextFile(const TextFile &src);
        // Copy Assignment
        TextFile& operator=(const TextFile &src);
        // Destructor
        ~TextFile();

        std::ostream& view(std::ostream& ostr)const;
        std::istream& getFile(std::istream& istr);
        operator bool()const;
        unsigned lines()const;
        const char* name()const;
        const char* operator[](unsigned index)const;
    };

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
    std::istream& operator>>(std::istream& istr, TextFile& text);

}
#endif // !SDDS_TEXTFILE_H__