/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 13 2023
***********************************************************************/

#ifndef SDDS_LABELMAKER_H_
#define SDDS_LABELMAKER_H_
#include <iostream>
#include "Label.h"

namespace sdds {

	class LabelMaker {

		int totalLabels;
		Label* labelList; 
		

	public:
		LabelMaker(int noOfLabels);
		~LabelMaker();
		void readLabels();
		void printLabels();
	};
}

#endif // !SDDS_LABELMAKER_H_
