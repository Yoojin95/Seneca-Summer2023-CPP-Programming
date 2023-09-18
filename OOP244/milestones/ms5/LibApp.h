// Final Project
// Name               Date                 Reason
// Yoojin Lee         August 4, 2023
/////////////////////////////////////////////////////////////////
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Lib.h"
#include "Publication.h"
#include "Book.h"
#include "PublicationSelector.h"
namespace sdds
{
	class LibApp
	{
		bool m_changed = false;
		Menu* m_mainMenu;
		Menu* m_exitMenu;
		char m_fileName[SDDS_MAXIMUM_CHARS]{};
		Publication* m_ppa[SDDS_LIBRARY_CAPACITY];
		int m_nolp = 0;
		int m_llrn;
		Menu* m_selectMenu;


		bool confirm(const char* message);
		void load();
		void save();
		int search(int);
		void returnPub();
		void newPublication();
		void removePublication();
		void checkOutPub();
		bool searchHelper(Publication&, int, char);
		Publication* getPub(int libRef);


	public:
		LibApp(const char* filename);
		void run();
		~LibApp();
	};
}
#endif


