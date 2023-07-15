
/*
Final Project Milestone 1
Filename: Menu.h
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
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
....
07/03: Beginning the MS1
07/05: Debugging Error
07/08: I'm confused whether create the default construcor or just need to create custom constructor
07/09: Segmentation Fault (Solved by Professor Jeevan Pant)
07/12: Menu Debugging Error, the problem is viewMenu and viewTitle, I separated them out because
it was easy to call the ostream helper function (Helper: Sean Muniz and Sukhman Hara)
07/13: Date Debugging Error, read and write function. cin failed didn't even print out.
I tried many times until I put os << displayTitle(os); (Initial I didnt put os) (Helper: Sean Muniz)
07/13: Small display error, and finished the MS1
-----------------------------------------------------------*/
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>

namespace sdds
{
	//! The MenuItem Class
	// todo: Create a class called MenuItem.
	// This class holds only one Cstring of characters for the content of the menu item dynamically.
	// The length of the content is unknown.This class should be fully private (no public members; even constructor is private!)

	static const unsigned int MAX_MENU_ITEMS = 20;
	class MenuItem
	{
		char* m_menuItem;
		// Make the “Menu” class a friend of this class (which makes MenuItem class only accessible by the Menu class).
		friend class Menu;
		MenuItem(const char* menu = nullptr);

		//! Rule of three
		MenuItem(const MenuItem& that) = delete;
		MenuItem& operator=(const MenuItem& that) = delete;
		~MenuItem();

		operator bool() const;
		operator const char* ()const;
		std::ostream& displayMenuItem(std::ostream& o)const;
	};

	class Menu
	{
		//todo: Attributes
		// This class has a minimum of three attributes.
		// A MenuItem to possibly hold the title of the Menu.
		// An array of MenuItem pointers.The size of this array is set by a constant unsigned integer defined in the Menu header file; called MAX_MENU_ITEMS.
		// Have the MAX_MENU_ITEMS integer initialized to 20. This array will keep potential MenuItems added to the Menu.
		// Each individual element of this array will hold the address of a dynamically allocated MenuItem as they are added to the Menu. (See insertion operator overload for Menu)
		// Initialize this array of pointers to nullptrs.
		// An integer to keep track of how many MenuItem pointers are pointing to dynamic MenuItem objects. (obviously, the value of this variable is always between 0 and MAX_MENU_ITEMS).
		MenuItem m_title;
		MenuItem* m_item[MAX_MENU_ITEMS];
		unsigned int m_track;
	public:
		Menu(const char* title = nullptr);

		//! Rule of three
		Menu(const Menu& that) = delete;
		Menu& operator=(const Menu& that) = delete;
		~Menu();

		std::ostream& viewTitle(std::ostream& os)const;
		std::ostream& viewMenu(std::ostream& os)const;
		unsigned int run();
		unsigned int operator~(); 
		Menu& operator<<(const char* menuItemContent);
		operator int()const;
		operator unsigned int()const;
		operator bool()const;
		friend std::ostream& operator<<(std::ostream& o, const Menu& menu);
		const char* operator[](unsigned index) const;
	};
	std::ostream& operator<<(std::ostream& o, const Menu& menu);
	
}

#endif