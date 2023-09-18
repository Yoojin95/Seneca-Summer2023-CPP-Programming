// CalorieList Module: dynamically hold series of Food items and display them in a report
#include <iostream>
#include <iomanip>
/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 6 2023
*******************************************************************/
#include "CalorieList.h"
#include "Food.h"
#include "cstring.h"

using namespace std;

namespace sdds {
	bool CalorieList::isValid()const {
		bool result = true;
		//bool flag = true;

		for (int i = 0; i < m_noOfFood; i++) {
			if (!m_food[i].isValid()) {
				result = false;
				//flag = false;
			}
		}
		return result;
	}

	int  CalorieList::totalCal()const {
		int result = 0;
		for (int i = 0; i < m_noOfFood; i++) {
			result += m_food[i].calorie();
		}
		return result;
	}
	
	void  CalorieList::Title()const {
		cout << "+----------------------------------------------------+" << endl;
		// cout << "| " << setw(36) << left << m_title << " |" << endl;
		if (isValid()) {
			cout << "|  " << setw(47) << left << "Daily Calorie Consumption" << "   |" << endl;
		}
		else {
			cout << "| " << setw(50) << left << "Invalid Calorie Consumption list" << " |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}
	
	/*
	+--------------------------------+------+------------+
	|    Total Calories for today:     1717 |            |
	+----------------------------------------------------+
	*/
	void  CalorieList::Footer()const {
		//cout << "+--------------------------------+------+------------+" << endl;
		if (isValid()) {
			cout << "+--------------------------------+------+------------+" << endl;
			cout << "|" << setw(29) << right << "Total Calories for today:";
			cout << setw(9) << right << totalCal();
			cout <<" |            |" << endl;
			cout << "+----------------------------------------------------+" << endl;
		}
		else {
			cout << "+--------------------------------+------+------------+" << endl;
			cout << "|    Invalid Calorie Consumption list                |" << endl;
			cout << "+----------------------------------------------------+" << endl;
		}
	}

	// sets the CalorieList to accept the "size" number of Food Items. 
	// This function is called to prepare the CalorieList for accepting food items
	// ex. CL.init(5);
	/*
	    char m_foodName[31];
		int m_calNum;
		int m_timeCons;
	*/
	void CalorieList::setEmpty() {
		m_noOfFood = '\0';
		m_food = nullptr;
	}

	void CalorieList::init(int size) {
		if (size < 0) {
			setEmpty();	// invalid
		}
		else {
			m_noOfFood = size;
			m_addedCnt = 0;
			//strnCpy()
			m_food = new Food[size];
			for (int i = 0; i < size; i++) {
				m_food[i].setEmpty();
			}
		}
	}

		// Adds Food Items using their Name, Calorie count and time of consumption up to the number set in the init() function, returns true if successful.
	bool CalorieList::add(const char* item_name, int calories, int when) 
	{
		bool result = false;

		if (m_addedCnt < m_noOfFood) {
			m_food[m_addedCnt].set(item_name, calories, when);
			m_addedCnt++;
			result = true;
		}
		return result;
	}


		// Displays the report with food information and the total calorie consumed in the day as shown in the report sample
		void CalorieList::display()const {
			Title();
			for (int i = 0; i < m_noOfFood; i++) {
				m_food[i].display();
			}
			Footer();
		}


		// Releases all the memory used. After this function init() can be called for another report;
		void CalorieList::deallocate() {
			delete[] m_food;
			m_food = nullptr;
		}
	}