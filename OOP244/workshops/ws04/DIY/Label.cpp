/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 13 2023
***********************************************************************/

#include <iostream>
#include "Label.h"
#include "cstring.h"

/* LabelMaker class creates a dynamic array of Labels
	and gets their content from the user one by one and prints them all at once */

namespace sdds {

	// create an empty label and defaults the frame to "+-+|+-+|"
	Label::Label() {
		
		// set the frame to defaultFrame
		strCpy(symbol, defaultFrame);

		// set to empty label
		pName = nullptr;
	}

	// an empty label and sets the frame to the frameArg argument
	Label::Label(const char* frameArg) {
		
		// set the frame to framArg
		strCpy(symbol, frameArg);
		
		// set to empty label
		pName = nullptr;

	}

	// Creates a Label with the frame set to frameArg and the content of the Label set to the corresponding argument
	// keep the content dynamically even though it should never be more than 70 characters
	Label::Label(const char* frameArg, const char* content) {
		
		strCpy(symbol, frameArg);

		if (strLen(content) < 71) {
			pName = new char[strLen(content) + 1];
			strCpy(pName, content);
		}
	}

	// Reads the label from console up to 70 characters and stores it in the Label
	void Label::readLabels() {
		char content[71];
		
		if (pName != nullptr) {
			delete[] pName;
			pName = nullptr;
		}

		cout << "> ";

		cin.get(content, 71);

		// clean buffer
		cin.ignore(10000, '\n');

		pName = new char[strLen(content) + 1];
		strCpy(pName, content);
	}

	// Makes sure there is no memory leak when the label goes out of scope
	Label::~Label() {
		if (pName) {
			delete[] pName;
			//oneLineText = nullptr;
		}
	}
	// Prints the label by drawing the frame around the content
	// no newline is printed after the last line and cout is returned at the end
	
	/*
	/-------------------------\	
	|                         |	
	| The Label Maker Program |
	|                         |
	\-------------------------/
	*/
	
	std::ostream& Label::printLabel()const {
		// if oneLineText has a value
		if (pName != nullptr) {
			int middle = strLen(pName);
			
			cout << symbol[0];		// +
			cout.fill(symbol[1]);	// -
			cout.width(middle + 3);
			cout << symbol[2] << endl;
			
			cout << symbol[3];
			cout.fill(' ');
			cout.width(middle + 3);
			cout << symbol[7] << endl;
	
			cout << symbol[3];
			cout.width(middle + 1);
			cout << pName;
			cout << " " << symbol[7] << endl;

			cout << symbol[7];
			cout.fill(' ');
			cout.width(middle + 3);
			cout << symbol[3] << endl;

			cout << symbol[6];		
			cout.fill(symbol[5]);	
			cout.width(middle + 3);
			cout << symbol[4];
		}

		return cout;
	}
}