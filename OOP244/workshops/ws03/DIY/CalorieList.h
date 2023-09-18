/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 6 2023
*******************************************************************/
#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_
#include "Food.h"

//Bill
namespace sdds {
	class CalorieList {
		int m_noOfFood;
		int m_addedCnt;
		Food* m_food;
		
		bool isValid()const;
		int totalCal()const;
		void Title()const;
		void Footer()const;
		
	public:
		//CalorieList();
		//~CaloireList();
		void init(int size);
		void setEmpty();
		bool add(const char* item_name, int calories, int when);
		void display()const;
		void deallocate();
		

	};
}
#endif // !SDDS_CALORIELIST_H_
