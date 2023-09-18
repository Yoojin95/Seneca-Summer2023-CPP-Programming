/******************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, June 6 2023
*******************************************************************/
#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
// item
namespace sdds {
	class Food {
		// Food name (up to 30 characters)
		char m_foodName[30];
		// Calorie number (valid between 0 and 3000)
		int m_calNum;
		// Time of consumption(1, 2, 3, or 4)
		int m_timeCons;
		void setName(const char* name);

	public:
		void setEmpty(); // safe empty state
		void set(const char* name, int cal, int time); //sets the value of Food
		bool isValid() const;
		int calorie() const;
		void display() const; // display the item info
	};
}
#endif // !SDDS_FOOD_H_

