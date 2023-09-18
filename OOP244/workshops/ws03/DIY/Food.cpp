/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 6 2023
*******************************************************************/
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Food.h"

using namespace std;
namespace sdds {
	// why do we need to set the name variable?
	void Food::setName(const char* name) {
		strnCpy(m_foodName, name, 30);
	}

	void Food::setEmpty() {
		*m_foodName = '\0';
		m_calNum = 0;
		m_timeCons = 0;
	}

	void Food::set(const char* name, int cal, int time) { // set the value of Food
		if (name != nullptr && cal > 0 && cal <= 3000
			&& time > 0 && time < 5)
		{
			setName(name);
			m_calNum = cal;
			m_timeCons = time;
		}
	}

	bool Food::isValid() const {
		bool result = false;
		if (*m_foodName != '\0' && m_calNum > 0 && m_calNum <= 3000
			&& m_timeCons > 0 && m_timeCons < 5)
		{
			result = true;
		}
		return result;
	}

	int Food::calorie() const {
		return m_calNum;
	}

	void Food::display() const {
		if (!isValid()) {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
		else {
			// | Cheerios Cereal with 2 % milk.. | 170 | Breakfast |
			cout << "| " << setfill('.') << setw(30) << left << m_foodName;
			cout << " |" << setfill(' ') << setw(5) << right << m_calNum;
			cout << " | " << setfill(' ') << setw(11) << left;
			switch (m_timeCons) {
			case 1:
				cout << "Breakfast" << "|" << endl;
				break;
			case 2:
				cout << "Lunch" << "|" << endl;
				break;
			case 3:
				cout << "Dinner" << "|" << endl;
				break;
			case 4:
				cout << "Snack" << "|" << endl;
				break;
			}
		}
	}
}