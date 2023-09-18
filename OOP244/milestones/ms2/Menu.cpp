// Final Project Milestone 2 
// Menu Module
// File	Menu.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
/**********************************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 21 2023
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<iomanip>
#include <iostream> // provides functionality for formatted input/output operations
#include <cstring>

using namespace std;
#include "Menu.h"

namespace sdds
{
	//============= MenuItem class ==================
	// constructor of MenuItem that does not take an argument and sets the object to a safe empty state
	MenuItem::MenuItem()
	{
		m_name = nullptr;
	}

	// constructor of MenuItem that takes name and sets it to m_name if name is not nullptr or empty
	MenuItem::MenuItem(const char* name)
	{
		if (name != nullptr && name[0] != '\0') // check the validation
		{
			delete[] m_name; // deletes previously allocated memory for 'm_name' to prevent memory leaks

			// 왜 메모리 동적할당을 사용할까?
			/*
			메모리 동적 할당을 사용하면 메뉴 항목의 이름이 얼마든지 다양한 크기의 문자열로 지정될 수 있습니다. 예를 들어, "Omelet"은 6자이지만 "California Roll"은 15자입니다.
			정적 배열을 사용하면 가장 긴 이름을 고려하여 크기를 설정해야 하지만, 동적 할당을 사용하면 이름의 길이에 제한이 없습니다.
			-> 유연한 문자열 크기, 메모리 관리, 객체 간 독립성 ...
			*/
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
		else
		{
			// 기본생성자에서 m_name을 nullptr로 설정했는데, else문에서 왜 다시 설정하는걸까?
			/*
			*  to ensure that m_name is explicitly set to nullptr in case the default constructor is used explicitly or implicitly
			* safeguard against any potential future changes in the default initialization of m_name
			* helps to improve code clarity and maintain consistency.

			  즉, 코드의 명확성, 일관성, 그리고 미래 대비 기능을 제공
			*/
			delete[] m_name;
			m_name = nullptr; // indicating an empty state for the menu item
		}
	}

	/*
	// dynamically allocates m_name to assign to incoming name
	void MenuItem::allocateName(const char* name)
	{

	}

	// sets the object to empty state by setting m_name to nullptr
	void MenuItem::setEmpty()
	{
		m_name = nullptr;
	}
	*/

	// destructor of MenuItem that deallocates memory used by m_name
	MenuItem::~MenuItem()
	{
		delete[] m_name;
		m_name = nullptr;
	}

	// converts the MenuItem object to a bool value by checking if the 'm_name' is not null or empty
	MenuItem::operator bool() const
	{
		// returns true if m_name is not nullptr or empty (if the object is valid)
		return (m_name != nullptr && m_name[0] != '\0');
	}

	// a function returns a pointer to the memory location where the m_name character array is stored
	MenuItem::operator const char* ()
	{
		// returns the address of the content Cstring
		return m_name;
	}

	// prints m_name if object is valid <- foolproof?
	ostream& MenuItem::display(ostream& os)const
	{
		/*
		The condition if (*this) checks if the MenuItem object itself can be implicitly converted to bool.
		In this case, the conversion operator overload for the MenuItem class would be invoked.
		*/
		if (*this) // if(m_name)?
			os << m_name;
		return os;
	}


	//============= Menu class ==================
	// constructor of Menu that does not take arguments and initializes object to safe empty state
	Menu::Menu()
	{
		setEmpty();
	}

	// constructor of Menu that creates an empty object with the argument name as the title of the Menu
	/*
		Allocates and sets the content of the MenuItem to a Cstring value at the moment of instantiation (or initialization).
		If no value is provided for the description at the moment of creation, the MenuItem should be set to an empty state.
	*/
	Menu::Menu(const char* name)
	{
		if (name[0] != '\0')
		{
			delete[] menu.m_name;
			menu.m_name = new char[strlen(name) + 1];
			strcpy(menu.m_name, name);
			numOfMenu = 0;
		}
		else
		{
			delete[] menu.m_name;
			setEmpty();
		}
	}


	// sets the object Menu to an empty state by setting menu to nullptr, and numOfMenu to zero
	void Menu::setEmpty()
	{
		menu.m_name = nullptr;
		numOfMenu = 0;
	}

	// destructor of Menu by deallocating all MenuItem pointers in menuArray (looping)
	Menu::~Menu()
	{
		for (int i = 0; i < numOfMenu; ++i)
		{
			delete menuArray[i];
		}
	}

	// displays the title of the menu and returns ostream object
	ostream& Menu::displayName(ostream& os)const
	{
		if (menu)
			os << menu.m_name;
		else
			os << "";

		return os;
	}

	// displays the entire menu and returns ostream object
	ostream& Menu::displayMenu(ostream& os)const
	{
		if (menu)
		{
			displayName() << endl;
			//os << ":" << endl;
		}

		for (int i = 0; i < numOfMenu; ++i)
		{
			/*
			Lunch Menu
			 1- Omelet
			 0- Exit
			> 1
			*/
			os << " " << setw(1) << right << i + 1;
			os << "- ";
			menuArray[i]->display();
			os << endl;
		}
		os << " 0- Exit" << endl << "> ";

		return os;
	}

	// functionality identical to run
	unsigned int Menu::operator~()
	{
		int selection = run();
		return selection;
	}

	// displays the menu, gets user input for menu item selection, validates input, and returns the selected items index
	unsigned int Menu::run(istream& is) const
	{
		int selection;
		int flag = 1;	// true

		displayMenu();

		while (flag)
		{
			if (!(is >> selection) || selection > numOfMenu || selection < 0) // !(is >> selection) : 'is' is not an integer
			{
				is.clear(); // clears the error state of the input stream to allow for subsequent input
				is.ignore(200, '\n'); // clears any invalid characters from the stream
				cout << "Invalid Selection, try again: ";
			}
			else
			{
				is.ignore(200, '\n');
				flag = 0;
			}
		}
		return selection;
	}

	// dynamically creates a MenuItem to be added to the end of menuArray 
	Menu& Menu::operator<<(const char* menuitemContent)
	{
		if (numOfMenu < (int)MAX_MENU_ITEMS)
		{
			menuArray[numOfMenu] = new MenuItem(menuitemContent);
			numOfMenu++;
		}
		return *this;
	}

	// returns the number of menu items -1
	Menu::operator int() const
	{
		return numOfMenu;
	}

	// returns the number of menu items 5 0
	Menu::operator unsigned int() const
	{
		return numOfMenu;
	}

	// returns true if number of menu is greater than 1
	Menu::operator bool() const
	{
		return (numOfMenu >= 1);
	}

	// insertion operator overload to print the title of the Menu
	ostream& operator<<(ostream& os, const Menu& aMenu)
	{
		return aMenu.displayName(os);
	}

	// indexing operator overload to return the const char* of the corresponding MenuItem in the menuArray
	/*
	Overload the indexing operator to return the const char* cast of the corresponding MenuItem in the array of MenuItem pointers.
	If the index passes the number of MenuItems in the Menu, loop back to the beginning. (use modulus)
	Example:

	Menu M;
	M << "Omelet" << "Tuna Sandwich" << "California Rolls";
	cout << M[0] << endl;
	cout << M[1] << endl;
	cout << M[3] << endl; // << note that the last valid index is "2"
	*/
	const char* Menu::operator[](int num) const
	{
		if (num < numOfMenu)
		{
			return (const char*)(*menuArray[num]);
		}
		else
		{
			int mod = num % numOfMenu;
			return (const char*)(*menuArray[mod]);
		}
	}
}

