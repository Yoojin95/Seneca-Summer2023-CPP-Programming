/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 6 2023
***********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;

namespace sdds {
	const char m_prefix[3] = "C_";
	class Text;
	// Line Class
	Line::operator const char* () const {
		return (const char*)m_value;
	}

	Line& Line::operator=(const char* lineValue) {
		delete[] m_value;
		m_value = new char[strLen(lineValue) + 1];
		strCpy(m_value, lineValue);
		return *this;
	}

	Line::~Line() {
		delete[] m_value;
	}

	// TextFile Class
	//***** private memeber function ***** 

	void TextFile::setEmpty()
	{
		// deletes the m_textLines dynamic array and sets is to nullptr
		if (m_textLines != nullptr)
		{
			delete[] m_textLines;
			m_textLines = nullptr;
		}

		// deletes the m_filename dynamic Cstring and sets is to nullptr
		if (m_filename != nullptr)
		{
			delete[] m_filename;
			m_filename = nullptr;
		}

		// sets m_noOfLines attribute to zero
		m_noOfLines = 0;
	}


	void TextFile::setFilename(const char* fname, bool isCopy)
	{
		// If the isCopy argument is true, dynamically allocates a Cstring in m_filename and copies the content of the fname argument with a prefix of "C_" attached to it.
		// if isCopy is false, dynamically allocates a Cstring in m_filename and copies the content of the fname argument into it
		delete[] m_filename;
		if (!isCopy)
		{
			m_filename = new char[strLen(fname) + 1];
			strCpy(m_filename, fname);
		}
		else
		{
			m_filename = new char[strLen(m_prefix) + strLen(fname) + 1];
			strCpy(m_filename, m_prefix);
			strCat(m_filename, fname);
		}
	}

	// Counts the number of lines in the file
	void TextFile::setNoOfLines()
	{
		// Creates a local ifstream object to open the file with the name held in m_filename. 
		ifstream readFile;
		readFile.open(m_filename);
		char ch;

		// Then it will read the file, character by character
		if (readFile.is_open())
		{
			while (readFile)
			{
				readFile.get(ch);
				// accumulates the number of newlines in the m_noOfLines attribute.
				if (ch == '\n')
					m_noOfLines++;
			}
			// increase by one in case the last line does not have a new line at the end
			m_noOfLines++;
		}
		// If the number of lines is zero, it will delete the m_filename and set it to nullptr. 
		// (Setting the TextFile to a safe empty state)
		else
		{
			delete[] m_filename;
			m_filename = nullptr;
		}
	}


	void TextFile::loadText()
	{
		// if the m_filename is null, this function does nothing
		// If the m_filename is not null (TextFile is not in a safe empty state )
		// dynamically allocate an array of Lines pointed by m_textLines with the size kept in m_noOfLines.
		delete[] m_textLines;
		if (m_filename == nullptr)
			return;
		m_textLines = new Line[m_noOfLines];
	

		// Create a local instance of ifstream using the file name m_filename to read the lines of the text file
		ifstream readFile;
		readFile.open(m_filename);
		

		if (readFile.is_open())
		{
			string line;
			for (int i = 0; i < (int)m_noOfLines; i++)
			{
				getline(readFile, line);
				m_textLines[i] = line.c_str();
			}
		}
		readFile.close();
	}

	void TextFile::saveAs(const char* fileName)const
	{
		// open a new file using the name kept in the argument filename
		ofstream outfile;
		outfile.open(m_filename);

		// write them in the opened file adding a new line to the end of each line.
		if (outfile.is_open())
		{
			for (int i = 0; i < (int)m_noOfLines; i++)
			{
				outfile << m_textLines[i] << '\n';
			}
		}
		outfile.close();
	}


	//***** public memeber function ***** 
	// empty TextFile and initializes the m_pageSize attribute using the pageSize argument
	TextFile::TextFile(unsigned pageSize)
	{
		setEmpty();
		m_pageSize = pageSize;
	}

	TextFile::TextFile(const char* filename, unsigned pageSize)
	{
		// all the other attributes to nullptr and zero
		setEmpty();
		// Initializes the m_pageSize attribute using the pageSize argument
		m_pageSize = pageSize;

		//  if the filename is not null, it will set the filename, set the number of Lines and load the Text (using the corresponding private methods.)
		if (filename != nullptr)
		{
			setFilename(filename);
			setNoOfLines();
			loadText();
		}
	}

	// Copy Constructor
	TextFile::TextFile(const TextFile& src)
	{
		setEmpty();
		this->m_pageSize = src.m_pageSize;

		if (this != &src)
		{
			if (src.m_textLines && src.m_noOfLines > 0)
			{
				setFilename(src.m_filename, true);
				this->m_noOfLines = src.m_noOfLines;
				m_textLines = new Line[m_noOfLines];

				unsigned i = 0;
				while (i < m_noOfLines)
				{
					m_textLines[i].m_value = new char[strLen(src.m_textLines[i].m_value) + 1];
					strCpy(m_textLines[i].m_value, src.m_textLines[i].m_value);
					i++;
				}
				saveAs(m_filename);
			}
		}
	}

	// Copy Assignment
	TextFile& TextFile::operator=(const TextFile& src)
	{
		if (this != &src)
		{
			// deallocate the dynamic array of Text and sets the pointer to null
			if (m_textLines != nullptr)
			{
				delete[] m_textLines;
				m_textLines = nullptr;
			}
			// Saves the content of the incoming TextFile under the current filename
			if (src.m_textLines && src.m_noOfLines > 0)
			{
				this->m_noOfLines = src.m_noOfLines;
				m_textLines = new Line[m_noOfLines];

				unsigned i = 0;
				while (i < m_noOfLines)
				{
					m_textLines[i].m_value = new char[strLen(src.m_textLines[i].m_value) + 1];
					strCpy(m_textLines[i].m_value, src.m_textLines[i].m_value);
					i++;
				}
				saveAs(m_filename);
			}
		}
		return *this;
	}

	TextFile::~TextFile()
	{
		if (m_textLines != nullptr) {
			delete[] m_textLines;
			m_textLines = nullptr;
		}

		if (m_filename != nullptr) {
			delete[] m_filename;
			m_filename = nullptr;
		}
	}

	std::ostream& TextFile::view(std::ostream& ostr)const
	{
		if (m_filename != nullptr && m_filename[0] != '\0') 
		{
			ostr << m_filename << endl;

			ostr.fill('=');
			ostr.width(strLen(m_filename));
			ostr << '=' << endl;

			unsigned i = 0;

			// loops through the lines and print them one by line
			while (i < m_noOfLines && i < m_pageSize) 
			{
				ostr << m_textLines[i] << endl;
				i++;
			}
			if (i < m_noOfLines) {
				do {
					ostr << "Hit ENTER to continue...";
					char x;
					cin.get(x);

					for (unsigned j = 0; j < m_pageSize && i < m_noOfLines; j++) {
						ostr << m_textLines[i] << endl;
						i++;
					}
				} while (i < m_noOfLines);
			}
		}

		return ostr;
	}

	// Receives a filename from istr to set the file name of the TextFile. Then sets the number of lines and loads the Text. When done it will return the istr;
	std::istream& TextFile::getFile(std::istream& istr)
	{
		string input;
		istr >> input;
		
		while (getchar() != '\n');
		setFilename(input.c_str());
		setNoOfLines();
		loadText();
		return istr;

	}

	TextFile::operator bool()const
	{
		bool result = false;

		if (m_textLines != nullptr)
			result = true;

		return result;
	}

	unsigned TextFile::lines()const
	{
		return m_noOfLines;
	}

	const char* TextFile::name()const
	{
		return m_filename;
	}

	const char* TextFile::operator[](unsigned index)const
	{
		if (m_textLines != nullptr)
		{
			return m_textLines[index % m_noOfLines];
		}
		return nullptr;
	}

	std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
	{
		text.view(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, TextFile& text)
	{
		text.getFile(istr);
		return istr;
	}
}
