// Final Project
// Name               Date                 Reason
// Yoojin Lee         August 4, 2023
/////////////////////////////////////////////////////////////////
#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>

namespace sdds
{
	const unsigned int MAX_MENU_ITEMS = 20;
	class Menu;

	class MenuItem
	{
		char* m_name{};

		MenuItem();
		MenuItem(const char*);
		void allocateName(const char*);
		void setEmpty();

		MenuItem(const MenuItem& source) = delete;
		MenuItem& operator=(const MenuItem& source) = delete;

		~MenuItem();
		operator bool() const;
		operator const char* ();
		std::ostream& display(std::ostream& os = std::cout) const;
		friend class Menu;
	};

	class Menu
	{
		MenuItem menu;
		MenuItem* menuArray[MAX_MENU_ITEMS]{};
		int numOfMenu;

		// copy constructor and copy assignment of Menu are disabled
		Menu(const Menu& source) = delete;
		Menu& operator=(const Menu& source) = delete;

	public:
		Menu();
		Menu(const char*);
		~Menu();
		void setEmpty();
		std::ostream& displayMenu(std::ostream& os = std::cout) const;
		std::ostream& displayName(std::ostream& os = std::cout) const;
		unsigned int run(std::istream& is = std::cin) const;
		unsigned int operator~();
		Menu& operator<<(const char* menuitemContent);
		operator int() const;
		operator unsigned int() const;
		operator bool() const;

		const char* operator[](int) const;

		friend class LibApp;
	};
	std::ostream& operator<<(std::ostream& os, const Menu&);
}

#endif