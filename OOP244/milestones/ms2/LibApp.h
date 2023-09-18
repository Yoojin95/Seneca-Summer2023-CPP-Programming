// Final Project Milestone 2 
// LibApp Module
// File	LibApp.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
/***********************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 21 2023
************************************************************/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"

namespace sdds 
{
	class LibApp 
	{
		/*
			A flag to keep track of changes made to the application data. 
			This flag is initially set to false. 
			If any change is made to the data of the application, this flag is set to true.
			Doing so, when exiting the program, we can warn the user and ask if they like the changes to be saved or discarded.
		*/
		bool m_changed = false;
		/*
			This menu will be used as the main menu of the application and should be initialized with title
			and then populated with the menu items:
		*/
		Menu* m_mainMenu;
		/*
			This menu will be used when exiting the program if any changes are made to the data.
			This menu should be initialized with the title
			and then populated with the  menu items
		*/
		Menu* m_exitMenu;

		bool confirm(const char* message);
		void load();
		void save();
		void search();
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();

	public:
		LibApp();
		void run();
		~LibApp();		
	};
}
#endif // !SDDS_LIBAPP_Hs