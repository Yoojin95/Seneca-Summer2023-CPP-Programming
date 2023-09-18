// Final Project
// Name               Date                 Reason
// Yoojin Lee         August 4, 2023
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>

using namespace std;
#include "Menu.h"

namespace sdds
{
	MenuItem::MenuItem()
	{
		setEmpty();
	}

	MenuItem::MenuItem(const char* name)
	{
		if (name != nullptr && name[0] != '\0')
			allocateName(name);
		else
		{
			delete[] m_name;
			setEmpty();
		}
	}

	void MenuItem::allocateName(const char* name)
	{
		delete[] m_name;
		int size = strlen(name) + 1;
		m_name = new char[size];
		strcpy(m_name, name);
	}

	void MenuItem::setEmpty()
	{
		m_name = nullptr;
	}

	MenuItem::~MenuItem()
	{
		delete[] m_name;
		m_name = nullptr;
	}

	MenuItem::operator bool() const
	{
		return (m_name != nullptr && m_name[0] != '\0');
	}

	MenuItem::operator const char* ()
	{
		return m_name;
	}

	ostream& MenuItem::display(ostream& os) const
	{
		if (*this)
			os << m_name;
		return os;
	}

	Menu::Menu()
	{
		setEmpty();
	}

	Menu::Menu(const char* name)
	{
		if (name[0] != '\0')
		{
			menu.allocateName(name);
			numOfMenu = 0;
		}
		else
		{
			delete[] menu.m_name;
			setEmpty();
		}
	}

	void Menu::setEmpty()
	{
		menu.m_name = nullptr;
		numOfMenu = 0;
	}

	Menu::~Menu()
	{
		int i;
		for (i = 0; i < numOfMenu; i++)
		{
			delete menuArray[i];
		}
	}

	ostream& Menu::displayName(ostream& os) const
	{
		if (menu)
			os << menu.m_name;
		else
			os << "";
		return os;
	}

	ostream& Menu::displayMenu(ostream& os) const
	{
		int i;
		if (menu)
		{
			displayName();
			os << endl;
		}
		for (i = 0; i < numOfMenu; i++)
		{
			os.width(2);
			os << right;
			os.fill(' ');
			os << i + 1 << "- ";
			os.unsetf(ios::right);
			menuArray[i]->display();
			os << endl;
		}
		os << " 0- Exit" << endl << "> ";
		return os;
	}

	unsigned int Menu::operator~()
	{
		int selection = run();
		return selection;
	}

	unsigned int Menu::run(istream& is) const
	{
		int selection;
		int flag = 1;
		displayMenu();
		while (flag)
		{
			if (!(is >> selection) || selection > numOfMenu
				|| selection < 0)
			{
				is.clear();
				is.ignore(200, '\n');
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

	Menu& Menu::operator<<(const char* menuitemContent)
	{
		if (numOfMenu < (int)MAX_MENU_ITEMS)
		{
			menuArray[numOfMenu] = new MenuItem(menuitemContent);
			numOfMenu++;
		}
		return *this;
	}

	Menu::operator int() const
	{
		return numOfMenu;
	}

	Menu::operator unsigned int() const
	{
		return numOfMenu;
	}

	Menu::operator bool() const
	{
		return (numOfMenu >= 1);
	}

	ostream& operator<<(ostream& os, const Menu& aMenu)
	{
		return aMenu.displayName(os);
	}

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