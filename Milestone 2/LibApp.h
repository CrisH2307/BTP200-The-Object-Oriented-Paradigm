/*
Final Project Milestone 2
Filename: LibApp.h
ID: 105444228
Author:	Cris Huynh
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/02  Preliminary release
2023/?/?    Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
......
07/10: Start working on MS2, set attributes and implement LibApp.cpp
07/13: Start debugging on MS2, i didnt know how to implement the confirm when i need to
add Yes. Until my friend help me for using the attribute << "Yes". (Helper: Preet Patel)
07/14: Run function's errors because my loop was infinite until I saw that the issue
that I got is i made a wrong bool value when inside the loop (true ==> false, Helper: Mandhav and Preet Patel)
07/14: Finished
-----------------------------------------------------------
*/


#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
namespace sdds 
{
	class LibApp 
	{
		// A flag to keep track of changes made to the application data. This flag is initially set to false. 
		// If any change is made to the data of the application, this flag is set to true.
		// Doing so, when exiting the program, 
		// we can warn the user and ask if they like the changes to be saved or discarded.
		bool m_changed;

		//This menu will be used as the main menu of the application and should be initialized with the following title:
		//! "Seneca Libray Application"
		Menu m_mainMenu;

		// This menu will be used when exiting the program if any changes are made to the data. 
		// This menu should be initialized with the following title:
		//! "Changes have been made to the data, what would you like to do?"
		Menu m_exitMenu;

		//! Private Methods
		bool confirm(const char* message);
		void load();  // prints: "Loading Data"<NEWLINE>
		void save();  // prints: "Saving Data"<NEWLINE>
		void search();  // prints: "Searching for publication"<NEWLINE>

		void returnPub();  /*  Calls the search() method.
							   prints "Returning publication"<NEWLINE>
							   prints "Publication returned"<NEWLINE>
							   sets m_changed to true;
						   */

		//! Methods with confirmation
		void newPublication();
		void removePublication();
		void checkOutPub();

	public:
		//! Constructor
		LibApp();

		//! The run method
		void run();
	};
}
#endif // !SDDS_LIBAPP_H

