
/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 13 2023
***********************************************************************/

// creates a dynamic array of Labels to the size of noOfLabels

#include <iostream>
#include "LabelMaker.h"
#include "cstring.h"

using namespace std;

namespace sdds {

		// creates a dynamic array of Labels to the size of noOfLabels
		LabelMaker::LabelMaker(int noOfLabels) {

			if (noOfLabels > 0) {
				totalLabels = noOfLabels;
				labelList = new Label[noOfLabels];
			}
			else {
				cout << "Input more than zero" << endl;
				noOfLabels = 0;
			}
		}

		// Gets the contents of the Labels
		void LabelMaker::readLabels() {
			if (totalLabels > 0) {
				cout << "Enter " << totalLabels << " labels:" << endl;

				for (int i = 0; i < totalLabels; i++) {
					cout << "Enter label number " << i + 1 << endl;
					labelList[i].readLabels();
				}
			}
		}


		// Prints the Labels 
		void LabelMaker::printLabels() {
			for (int i = 0; i < totalLabels; i++) {
				labelList[i].printLabel();
				cout << endl;
			}
		}

		// Deallocates the memory when LabelMaker goes out of scope
		LabelMaker::~LabelMaker() {
			delete[] labelList;
			labelList = nullptr;
		}
	};
