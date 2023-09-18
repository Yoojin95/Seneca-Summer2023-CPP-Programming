/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 27 2023
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Text.h"
#include <cstring>
#include <fstream>

using namespace std;

namespace sdds 
{
    int Text::getFileLength() const {
        if (m_filename == nullptr)
            return 0;

        ifstream file(m_filename);
        if (!file.is_open())
            return 0;

        // Count the characters to get the file length
        int length = 0;
        char ch;
        while (file.get(ch)) {
            length++;
        }

        file.close();
        return length;
    }

    Text::Text(const char* filename) : m_filename(nullptr), m_content(nullptr) {
        if (filename != nullptr) {
            // Allocate memory and copy the filename
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            read();
        }
        else {
            // In case filename is nullptr, set the class to an empty state
            m_filename = nullptr;
            m_content = nullptr;
        }
    }

    // Copy constructor
    Text::Text(const Text& other) : m_filename(nullptr), m_content(nullptr) {
        if (other.m_filename != nullptr) {
            // Allocate memory and copy the filename
            m_filename = new char[strlen(other.m_filename) + 1];
            strcpy(m_filename, other.m_filename);
            // Copy content if available
            if (other.m_content != nullptr) {
                m_content = new char[strlen(other.m_content) + 1];
                strcpy(m_content, other.m_content);
            }
        }
    }

    // Copy assignment operator
    Text& Text::operator=(const Text& other) {
        if (this != &other) {
            // Free existing memory
            delete[] m_filename;
            delete[] m_content;

            m_filename = nullptr;
            m_content = nullptr;

            if (other.m_filename != nullptr) {
                // Allocate memory and copy the filename
                m_filename = new char[strlen(other.m_filename) + 1];
                strcpy(m_filename, other.m_filename);
                // Copy content if available
                if (other.m_content != nullptr) {
                    m_content = new char[strlen(other.m_content) + 1];
                    strcpy(m_content, other.m_content);
                }
            }
        }
        return *this;
    }

    // Destructor
    Text::~Text() {
        delete[] m_filename;
        delete[] m_content;
    }
    void Text::read() {
        // Clear existing content if any
        delete[] m_content;
        m_content = nullptr;

        // Check if the filename is null or if the file cannot be opened
        if (m_filename == nullptr) {
            return; // No file to read, set to empty state
        }

        ifstream file(m_filename);
        if (!file.is_open()) {
            return; // Failed to open file, set to empty state
        }

        // Read the file content character by character and count the number of characters
        int length = 0;
        char ch;
        while (file.get(ch)) {
            length++;
        }

        // Allocate memory to hold the file content and the null byte
        m_content = new char[length + 1];

        // Close and reopen the file to reset the file stream to the beginning
        file.close();
        file.open(m_filename);

        // Read the file content into the allocated memory
        for (int i = 0; i < length; i++) {
            file.get(m_content[i]);
        }

        // Terminate the content with a null byte
        m_content[length] = '\0';

        file.close();
    }

    void Text::write(ostream& os) const {
        // Implementation of the virtual write() function
        // This function inserts the content of the Text class into the ostream if m_content is not null.

        if (m_content != nullptr) {
            os << m_content;
        }
    }

    // Index operator provides read-only access to the content of the text
    const char& Text::operator[](int index) const {
        // Implementation of the index operator
        // Provides read-only access to the content of the text for the derived classes of Text.
        // The behavior of the operator is not defined if the index goes out of bounds.

        // For simplicity, assume the index is within bounds and return the character at the specified index.
        return m_content[index];
    }

    // Overload the insertion operator for a Text object into ostream
    ostream& operator<<(ostream& os, const Text& text) {
        text.write(os);
        return os;
    }
}