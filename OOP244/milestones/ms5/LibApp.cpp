// Final Project
// Name               Date                 Reason
// Yoojin Lee         August 4, 2023
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "LibApp.h"

using namespace std;
namespace sdds
{
	bool LibApp::confirm(const char* message)
	{
		Menu temp(message);
		temp << "Yes";
		int selection = temp.run();
		return (selection == 1);
	}

	void LibApp::load()
	{
		ifstream infile(m_fileName);
		char type{};
		int i;
		cout << "Loading Data" << endl;
		for (i = 0; infile && m_nolp < SDDS_LIBRARY_CAPACITY; i++)
		{
			infile >> type;
			infile.ignore();
			if (infile)
			{
				if (type == 'P')
				{
					m_ppa[i] = new Publication;
				}
				else if (type == 'B')
				{
					m_ppa[i] = new Book;
				}
				infile >> *m_ppa[i];
				m_nolp++;
			}
		}
		m_llrn = m_ppa[m_nolp - 1]->getRef();
	}

	void LibApp::save()
	{
		cout << "Saving Data" << endl;
		ofstream overwrite(m_fileName);
		int i;
		for (i = 0; i < m_nolp; i++)
		{
			if (m_ppa[i]->getRef())
			{
				overwrite << *m_ppa[i];
				overwrite << endl;
			}
		}
	}

	int LibApp::search(int mode)
	{
		int i, ref = 0;
		char type{};
		char title[SDDS_MAXIMUM_CHARS];
		PublicationSelector pubSel("Select one of the following found matches:");
		int selection = m_selectMenu->run();
		if (selection == 1)
			type = 'B';
		else if (selection == 2)
			type = 'P';
		if (selection)
		{
			cout << "Publication Title: ";
			cin.getline(title, SDDS_MAXIMUM_CHARS);
			for (i = 0; i < m_nolp; i++)
			{
				if (m_ppa[i]->getRef() && searchHelper(*m_ppa[i], mode, type) && strstr(*m_ppa[i], title))
					pubSel << *m_ppa[i];
			}
			if (pubSel)
			{
				pubSel.sort();
				ref = pubSel.run();
				if (!ref)
				{
					cout << "Aborted!" << endl;
				}
			}
			else
			{
				cout << "No matches found!" << endl;
			}
		}
		else
		{
			cout << "Aborted!" << endl;
		}
		return ref;
	}

	bool LibApp::searchHelper(Publication& pub, int mode, char type)
	{
		if (mode == 1)		// search case when looking through all publications/books
		{
			return (pub.type() == type);
		}
		else if (mode == 2)			// search case when looking through those on loan
		{
			return (pub.type() == type && pub.onLoan());
		}
		else		// search case when looking through those that are available
		{
			return (pub.type() == type && !pub.onLoan());
		}
	}

	Publication* LibApp::getPub(int libRef)
	{
		int i;
		Publication* p{};
		for (i = 0; i < m_nolp; i++)
		{
			if (m_ppa[i]->getRef() == libRef)
			{
				p = m_ppa[i];
				i = m_nolp;
			}
		}
		return p;
	}

	void LibApp::returnPub()
	{
		Date currentDay;
		double penalty = 0.0;
		int ref, noDaysLate;
		cout << "Return publication to the library" << endl;
		ref = search(2);
		if (ref)
		{
			cout << *getPub(ref) << endl;
			bool istrue = confirm("Return Publication?");
			if (istrue)
			{
				noDaysLate = currentDay - getPub(ref)->checkoutDate();
				if (noDaysLate > SDDS_MAX_LOAN_DAYS)
				{
					penalty = (double(noDaysLate) - SDDS_MAX_LOAN_DAYS) * 0.5;
					cout << "Please pay $" << fixed << setprecision(2) << penalty << " penalty for being " << noDaysLate - SDDS_MAX_LOAN_DAYS << " days late!" << endl;
				}
				getPub(ref)->set(0);
				m_changed = true;
				cout << "Publication returned" << endl;
			}
		}
	}

	void LibApp::newPublication()
	{
		Publication* temp{};
		if (m_nolp >= SDDS_LIBRARY_CAPACITY)
		{
			cout << "Library is at its maximum capacity!";
			cout << endl;
		}
		else
		{
			cout << "Adding new publication to the library" << endl;
			int selection = m_selectMenu->run();
			if (selection == 0)
			{
				cout << "Aborted!" << endl;
			}
			else
			{
				if (selection == 1)
				{
					temp = new Book;
				}
				else if (selection == 2)
				{
					temp = new Publication;
				}
				cin >> *temp;
				if (!cin)
				{
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Aborted!";
				}
				else
				{
					bool istrue = confirm("Add this publication to the library?");
					if (!istrue)
					{
						cout << "Aborted!";
					}
					else
					{
						if (temp)
						{
							temp->setRef(++m_llrn);
							m_ppa[m_nolp] = temp;
							m_nolp++;
							m_changed = true;
							cout << "Publication added" << endl;
						}
						else
						{
							cout << "Failed to add publication!";
							delete temp;
						}
					}
				}
			}
		}
	}

	void LibApp::removePublication()
	{
		int ref;
		cout << "Removing publication from the library" << endl;
		ref = search(1);
		if (ref)
		{
			cout << *getPub(ref) << endl;
			bool istrue = confirm("Remove this publication from the library?");
			if (istrue)
			{
				getPub(ref)->setRef(0);
				m_changed = true;
				cout << "Publication removed" << endl;
			}
		}
	}

	void LibApp::checkOutPub()
	{
		int ref, memberID = 0;
		cout << "Checkout publication from the library" << endl;
		ref = search(3);
		if (ref)
		{
			cout << *getPub(ref) << endl;
			bool istrue = confirm("Check out publication?");
			if (istrue)
			{
				cout << "Enter Membership number: ";
				cin >> memberID;
				while (memberID < 10000 || memberID > 99999)
				{
					cout << "Invalid membership number, try again: ";
					cin >> memberID;
				}
				getPub(ref)->set(memberID);
				m_changed = true;
				cout << "Publication checked out" << endl;
			}
		}
	}

	LibApp::LibApp(const char* filename)
	{
		m_mainMenu = new Menu("Seneca Library Application");
		*m_mainMenu << "Add New Publication" << "Remove Publication"
			<< "Checkout publication from library"
			<< "Return publication to library";
		m_exitMenu = new Menu("Changes have been made to the data, what would you like to do?");
		*m_exitMenu << "Save changes and exit"
			<< "Cancel and go back to the main menu";
		m_selectMenu = new Menu("Choose the type of publication:");
		*m_selectMenu << "Book" << "Publication";
		strncpy(m_fileName, filename, strlen(filename));
		m_fileName[strlen(filename)] = '\0';
		load();
	}

	void LibApp::run()
	{
		int flag = 1;
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

	LibApp::~LibApp()
	{
		delete m_mainMenu;
		delete m_exitMenu;
		delete m_selectMenu;
		int i;
		for (i = 0; i < m_nolp; i++)
			delete m_ppa[i];
	}
}