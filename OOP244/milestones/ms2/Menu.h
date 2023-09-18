// Final Project Milestone 2 
// Menu Module
// File	Menu.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 21 2023
***********************************************************************/
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_

namespace sdds {

	// Forward declaration
	class Menu;
	const unsigned int MAX_MENU_ITEMS = 20;

	class MenuItem
	{
		// cstring of characters for the content of the menu item dynamically
		char* m_name{}; // omlet, tuna sandwich, california roll 

		// Constructor
		MenuItem();
		MenuItem(const char*);

		//void allocateName(const char*);
		void setEmpty();

		// Copy constructor and Copy assignment of MenuItem are deleted
		MenuItem(const MenuItem& src) = delete;
		MenuItem& operator=(const MenuItem& src) = delete;

		// Destructor
		~MenuItem();

		// bool type conversion
		operator bool() const;

		// const char* type conversion
		operator const char* ();

		// display the content of the MenuItem on ostream
		std::ostream& display(std::ostream& os = std::cout)const;

		friend class Menu;
	};


	class Menu
	{
		// 3 attributes
		MenuItem menu; // represents the title of menu items
		MenuItem* menuArray[MAX_MENU_ITEMS]{}; // stores the menu items
		int numOfMenu; // keeps track of the number of menu items

		Menu(const Menu& src) = delete;
		Menu& operator=(const Menu& src) = delete;

	public:
		Menu();
		Menu(const char*);
		~Menu();

		void setEmpty();

		// Display the title of the Menu on ostream
		std::ostream& displayName(std::ostream& os = std::cout)const;
		// Display the entire Menu on ostream
		std::ostream& displayMenu(std::ostream& os = std::cout)const;


		// foolproof function run (입력 유효성 검사)
		unsigned int run(std::istream& is = std::cin)const;
		unsigned int operator~();

		Menu& operator<<(const char* menuitemContent);

		operator int() const;
		operator unsigned int() const;

		operator bool() const;

		const char* operator[](int) const;
	};

	std::ostream& operator<<(std::ostream& os, const Menu&);
}

#endif // !SDDS_MENU_H_

