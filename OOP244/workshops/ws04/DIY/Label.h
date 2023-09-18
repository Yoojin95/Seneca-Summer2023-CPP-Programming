/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 13 2023
***********************************************************************/

#ifndef SDDS_LABEL_H_
#define SDDS_LABEL_H_
#include <iostream>

using namespace std;

namespace sdds {
	const char defaultFrame[9] = "+-+|+-+|";
	
	class Label {

		char symbol[9];
		char* pName;

	public:
		Label(); 
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label(); // destructor


		void readLabels();	
		std::ostream& printLabel()const; 
	};

}


#endif // !SDDS_LABEL_H_

