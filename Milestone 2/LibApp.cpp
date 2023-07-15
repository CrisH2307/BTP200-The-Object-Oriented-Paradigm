
/*
Final Project Milestone 2
Filename: LibApp.cpp
Author:	Cris Huynh
ID: 105444228
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Menu.h"
#include "Utils.h"
#include "LibApp.h"
using namespace std;
namespace sdds 
{
	bool LibApp::confirm(const char* message)
	{
		// todo: Instantiate a Menu in this function and initialize it with the message argument.
		//		 Then add only a "yes" as a single menu item to the Menu.
		//		 Finally, run the menu and return true if the run method of Menu returns 1 and otherwise this function returns false.
		
		Menu that(message);
		
		that << "Yes";
		
		unsigned int those = that.run();

		return (those == 1);
	}

	void LibApp::load()
	{
		cout << "Loading Data" << endl;
	}

	void LibApp::save()
	{
		cout << "Saving Data" << endl;
	}

	void LibApp::search()
	{
		cout << "Searching for publication" << endl;
	}

	void LibApp::returnPub()
	{
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
		cout << endl;
	}

	void LibApp::newPublication()
	{
		//todo: Prints "Adding new publication to library"+newline
		//      calls the confirm method with "Add this publication to library?"
		//		if confrim returns true, it will set m_changed to true and prints "Publication added" + newline

		cout << "Adding new publication to library" << endl;

		if (confirm("Add this publication to library?"))
		{
			this->m_changed = true;
			cout << "Publication added" << endl;
		}
		cout << endl;

	}
	void LibApp::removePublication()
	{
		//todo: prints "Removing publication from library"+newline
		//		calls the search method
		//		calls the confirm method with "Remove this publication from the library?"
		//		if confrim returns true, it will set m_changed to true and prints "Publication removed" + newline

		cout << "Removing publication from library" << endl;
		search();
		
		if (confirm("Remove this publication from the library?"))
		{
			this->m_changed = true;
			cout << "Publication removed" << endl;
		}
		cout << endl;
	}
	void LibApp::checkOutPub()
	{
		//todo: calls the search method
		//		calls the confirm method with Check out publication ? "
		//		if confrim returns true, it will set m_changed to true and prints "Publication checked out" + newline

		search();
		if (confirm("Check out publication?"))
		{
			this->m_changed = true;
			cout << "Publication checked out" << endl;
		}
		cout << endl;
	}



	LibApp::LibApp() : m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
	{
		//todo: Constructor should initialize and set the attributes and load the publication records from database
		//      Initializes the attributes(see the attribute section)
		//		populates the Menu attributes
		//		calls the `load()`` method

		m_changed = false;

		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";

		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";
		
		
		// Load publication records from the database
		load();
	}

	void LibApp::run()
	{
		//todo:
		/*
		The run method is the main application driver.
		It displays the main menu and based on the user's selection calls the corresponding private method and repeats the above until the user chooses to exit.
		When the user selects exit, the value of m_changed is examined. If the value is false, then since the data of the application is not modified, the program terminates.
		If the value is true, the m_exitMenu is used by calling its run method. Doing so the user has the selection of saving and exiting, cancelling and going back to the main menu or exiting without saving.
		If the first one is selected, the save() method is called and the program terminates.
		If the second one is selected the program goes back to the main menu and execution continues.
		If the exit is selected, then the confirm menu will be called using the message: "This will discard all the changes are you sure?". If the user selects Yes, the program terminates. Otherwise, the program goes back to the main menu and execution resumes.
		When the program is terminated, the following message is printed:
		-------------------------------------------
		Thanks for using Seneca Library Application
		*/

		bool done = true;

		while (done)
		{
			// Display the main menu
			int choice = m_mainMenu.run();

			// Call the corresponding private method based on the user's selection
			switch (choice)
			{
			case 1:
				newPublication();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkOutPub();
				break;
			case 4:
				returnPub();
				break;
			case 0:
				// User selected exit, check if changes were made
				if (this->m_changed)
				{
					// Display exit menu
					unsigned int exitChoice = m_exitMenu.run();
					if (exitChoice == 1)
					{
						save();
						done = false;
					}
					else if (exitChoice == 2)
					{
						cout << endl;
					}
					else
					{
						int confirmed = confirm("This will discard all the changes are you sure?");
						if (confirmed == 1)
						{
							done = false;
						}
						else
						{
							cout << endl;
						}
					}
				}
				else
				{
					// No changes made, exit program
					done = false;
				}
				break;
			 default:
				cout << "Invalid selection. Please try agian." << endl;
				break;

			}
		}
		// Print termination message
		cout << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}
}