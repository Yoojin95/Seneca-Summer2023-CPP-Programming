// Final Project Milestone 2 
// LibApp Module
// File	LibApp.cpp
// : building a mockup application
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
/***********************************************************
 Yoojin Lee, ylee237@myseneca.ca, 188162218, July 21 2023
************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>

#include "LibApp.h"
#include "Menu.h"

using namespace std;

namespace sdds 
{
	// instantiates a Menu with the message and populates it with "Yes" menu item, and returns true if run method
	// returns 1, and false otherwise
	bool LibApp::confirm(const char* message) 
	{
		Menu temp(message);
		temp << "Yes";
		int select = temp.run();
		return(select == 1);
	}

	// prints the loading message
	void LibApp::load()
	{
		cout << "Loading Data" << endl;
	}

	// prints the saving message
	void LibApp::save()
	{
		cout << "Saving Data" << endl;
	}

	// prints the searching message
	void LibApp::search()
	{
		cout << "Searching for publication" << endl;
	}

	// prints messages accordingly, sets m_changed to true
	void LibApp::returnPub()
	{
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
	}

	// adds new publication to library, only prints messages in current version
	/*
		prints "Adding new publication to library"+newline
		calls the confirm method with "Add this publication to library?"
		if confrim returns true, it will set m_changed to true and prints "Publication added" + newline
	*/
	void LibApp::newPublication()
	{
		cout << "Adding new publication to library" << endl;
		bool isTrue = confirm("Add this publication to library?");
		
		if(isTrue) // if(confirm("Add this publication to library?")) //shorten this code?
		{
			m_changed = true;
			cout << "Publication added" << endl;
		}
	}

	// removes publication from library, only prints messages in current version
	/*
		prints "Removing publication from library"+newline
		calls the search method
		calls the confirm method with "Remove this publication from the library?"
		if confrim returns true, it will set m_changed to true and prints "Publication removed" + newline
	*/
	void LibApp::removePublication()
	{
		cout << "Removing publication from library" << endl;
		search();
		bool isTrue = confirm("Remove this publication from the library?");
		if (isTrue)
		{
			m_changed = true;
			cout << "Publication removed" << endl;
		}
	}

	// checks out publication, only prints messages in current version
	void LibApp::checkOutPub()
	{
		search();
		bool isTrue = confirm("Check out publication?");
		if (isTrue)
		{
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
	}

	// constructor of LibApp that initializes m_mainMenu and m_exitMenu pointers to provided values
	LibApp::LibApp()
	{
		/*
			m_mainMenu
			 This menu will be used as the main menu of the application and should be initialized with the following title
			 : "Seneca Libray Application"

			 and then populated with the following menu items
			 : "Add New Publication"
			   "Remove Publication"
		       "Checkout publication from library"
		       "Return publication to library"
		*/
		m_mainMenu = new Menu("Seneca Library Application");
		*m_mainMenu << "Add New Publication" << "Remove Publication"
			<< "Checkout publication from library" << "Return publication to library";

		/*
			m_exitMenu
			 This menu will be used when exiting the program if any changes are made to the data. 
			 This menu should be initialized with the following title
			 : "Changes have been made to the data, what would you like to do?"

			 and then populated with the following menu items
		  	 : "Save changes and exit"
			   "Cancel and go back to the main menu"
		*/
		m_exitMenu = new Menu("Changes have been made to the data, what would you like to do?");
		*m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		
		load();
	}

	// runs the application for user to select an option, and executes accordingly
	/*
		suggested pseudo code:
		loop until done
			display menu
			if first option  new publication otherwise
			if second option remove publication otherwise
			if third option checkout otherwise
			if fourth option return publication otherwise 
				if changed
				   Warning menu and choices
				   if save selected save and its done otherwise
				   if discard selected 
					  final confirmation for exit 
					  if exit selected 
						 its done (no saving)   
					  end if
				   end if
				otherwise (no change)
				   it is done          
				end if
			end if
		end loop        
		goodbye message
	*/
	void LibApp::run()
	{
		int flag = 1;

		/*
		 displays the main menu and based on the user's selection calls the corresponding private method 
		 and repeats the above until the user chooses to exit
		*/
		while (flag)
		{
			int selection = m_mainMenu->run();

			if (selection == 1)
			{
				newPublication();
			}
			else if (selection == 2)
			{
				removePublication();
			}
			else if (selection == 3)
			{
				checkOutPub();
			}
			else if (selection == 4)
			{
				returnPub();
			}
			else
			{
				if (!m_changed)
					flag = 0;
				else
				{
					int value = m_exitMenu->run();
					if (value == 1)
					{
						save();
						flag = 0;
					}
					if (value == 0)
					{
						int confirmation = confirm("This will discard all the changes are you sure?");
						if (confirmation)
						{
							flag = 0;
						}
					}
				}
			}
			cout << endl;

		}
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}

	// destructor of LibApp that deallocates memories allocated by m_mainMenu and m_exitMenu
	LibApp::~LibApp()
	{
		delete m_mainMenu;	// delete[] -> occurred memory leak (m_mainMenu is a single object!)
		delete m_exitMenu;
	}
}
