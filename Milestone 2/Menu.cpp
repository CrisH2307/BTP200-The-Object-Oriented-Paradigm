/*
Final Project Milestone 2
Filename: Menu.cpp
Author:	Cris Huynh
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/02  Preliminary release
2023/?/?    Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds
{

	//! MenuItem Class
	MenuItem::MenuItem(const char* menu)
	{
		//todo: Constructor
		// Allocates and sets the content of the MenuItem to a Cstring value at the moment of instantiation(or initialization).
		// If no value is provided for the description at the moment of creation, the MenuItem should be set to an empty state.

		if (menu != nullptr and menu[0] != '\0')
		{
			m_menuItem = new char[strlen(menu) + 1];
			strcpy(this->m_menuItem, menu);
		}
		else
		{
			m_menuItem = nullptr;
		}
	}


	MenuItem::~MenuItem()
	{
		delete[]m_menuItem;
	}


	MenuItem::operator bool() const
	{
		//todo: When a MenuItem is casted to “bool” it should return true, if it is not empty and it should return false if it is empty.
		return (this->m_menuItem != nullptr);
	}
	MenuItem::operator const char* () const
	{
		//todo: When a MenuItem is casted to “const char*” it should return the address of the content Cstring.
		return this->m_menuItem;
	}
	std::ostream& MenuItem::displayMenuItem(std::ostream& o) const
	{
		//todo: Create a method to display the content of the MenuItem on ostream. (No newline is printed after)
		//      Nothing is printed if MenuItem is empty.
		//      Remember that the MenuItem class is fully private.

		if (this->m_menuItem)
		{
			o << this->m_menuItem;
		}
		return o;

	}


	//! Menu Class

	Menu::Menu(const char* title) : m_title(title), m_track(0)
	{
		//! Constructors
		//todo: A Menu is always created empty; with no MenuItems, with or without a title.
		/*      Example:
				Menu A;
				Menu B("Lunch Menu");
		*/
	}


	//! Rule of Three 

	Menu::~Menu()
	{
		//! Destructor
		//todo: Looping through the MenuItems array of pointers, it deletes each pointer up to the number of menu items in the menu.
		for (unsigned i = 0; i < m_track; ++i)
		{
			delete m_item[i];
		}
	}



	std::ostream& Menu::viewTitle(std::ostream& os) const   //! Helped by Sean Muniz
	{
		if (this->m_title)
		{
			m_title.displayMenuItem(os);
		}
		return os;
	}

	ostream& Menu::viewMenu(ostream& os) const
	{
		//todo: 	Ccreate a function to display the title of the Menu on ostream if the title is not empty, otherwise, it does nothing.   
		/*
		Create a function to display the entire Menu on ostream:
		This function first displays the title (if it is not empty) followed by a ":" and a new-line, then it will display all the MenuItems one by one; adding a row number in front of each.
		The row numbers are printed in two spaces, right justified followed by a "dash" and a "space". After printing all the MenuItems it should print " 0- Exit" and new-line and "> ".
		For example if the title is "Lunch Menu" and the menu items are "Omelet", "Tuna Sandwich" and "California Rolls", the Menu object should be printed like this:

		Lunch Menu:
		1- Omelet
		2- Tuna Sandwich
		3- California Rolls
		0- Exit
		>
		*/

		if (this->m_title)
		{
			viewTitle(os);
			os << endl;

			for (unsigned int i = 0; i < this->m_track; i++)
			{
				os.width(2);
				os.setf(ios::right);
				os << i + 1 << "- ";
				(*this->m_item[i]).displayMenuItem(os); //must dereference pointer before calling member funciton.  
				os.unsetf(ios::right);
				os << endl;
			}
			cout << " 0- Exit" << endl;
			cout << "> ";
		}

		else
		{
			for (unsigned int i = 0; i < this->m_track; i++)
			{
				os.width(2);
				os.setf(ios::right);
				os << i + 1 << "- ";
				(*this->m_item[i]).displayMenuItem(os); //must dereference pointer before calling member funciton.  
				os.unsetf(ios::right);
				os << endl;
			}
			cout << " 0- Exit" << endl;
			cout << "> ";
		}
		return os;
	}

	unsigned int Menu::run()
	{
		//todo: Create a member function called run. This function displays the Menu and gets the user selection.
		/*
		(this function should be completely foolproof) The function receives nothing and returns an unsigned integer (That is the user’s selection).
		After displaying the menu, ask for an integer and make sure the value of the integer is between 0 and the number of the menu items. If the user enters anything incorrect, print:
		"Invalid Selection, try again: "
		and get the integer again until a valid selection is made.

		Nice to do:
		The action of a foolproof integer entry within limits, with a prompt and an error message is a good candidate for a separate function implementation in the Utils module
		*/

		unsigned int those;
		int that = 0;
		viewMenu(cout);

		do
		{
			if (cin >> those and those >= 0 and those <= this->m_track)
			{
				that = 1;
			}
			else
			{
				cout << "Invalid Selection, try again: ";
			}
			cin.clear();
			cin.ignore(2000, '\n');

		} while (that == 0);

		return those;
	}

	unsigned int Menu::operator~()
	{
		//todo: Overload operator~ to do exactly what the run function does (two different ways to run the menu)
		return run();

	}

	Menu& Menu::operator<<(const char* menuItemContent)
	{
		// TODO: Overload a member insertion operator (operator<<) to add a MenuItem to the Menu.
		/*
		This operator receives a C-style string containing the content of the MenuItem and returns the reference of the Menu object (*this).
		To accomplish this, check if the next spot for a MenuItem is available in the array of MenuItem pointers.
		If it is, dynamically create a MenuItem out of the content received through the operator argument and then store the address in the available
		spot and finally increase the number of allocated MenuItem pointers by one.
		If no spot is available, ( that is; if number of allocated MenuItem pointers is equal to MAX_MENU_ITEMS) this function silently ignores the action.
		At the end, return the reference of the Menu object.
		*/

		if (menuItemContent != nullptr and menuItemContent[0] != '\0')
		{
			if (this->m_track < MAX_MENU_ITEMS)
			{
				m_item[m_track] = new MenuItem(menuItemContent);

				// Store the address of the new MenuItem in the next available spot
				m_track++;
			}
		}


		return *this;

	}

	Menu::operator int() const
	{
		//todo: Overload two type conversions for int and unsigned int to return the number of MenuItems on the Menu.
		return this->m_track;
	}

	Menu::operator unsigned int() const
	{
		//todo: Overload two type conversions for int and unsigned int to return the number of MenuItems on the Menu
		return this->m_track;
	}

	Menu::operator bool() const
	{
		return (m_track > 0);
	}


	ostream& operator<<(ostream& o, const Menu& menu)
	{
		//todo: Overload the insertion operator to print the title of the Menu using cout.
		menu.viewTitle(o);
		return o;
	}

	const char* Menu::operator[](unsigned int index) const
	{
		/*
		Overload the indexing operator to return the const char* cast of the corresponding MenuItem in the array of MenuItem pointers.
		If the index passes the number of MenuItems in the Menu, loop back to the beginning. (use modulus)
		*/
		if (*this)
		{
			if (index > this->m_track)
			{
				return this->m_item[index % m_track] -> operator const char* ();
			}
			else
			{
				return this->m_item[index] -> operator const char* ();
			}
		}
		// Return a default value in case the above conditions are not met
		return nullptr;
	}
}