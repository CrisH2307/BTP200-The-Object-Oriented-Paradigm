/*
*****************************************************************************
							  ShoppingList.h
Full Name  : Xuan Khang Huynh (Cris Huynh)
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_SHOPPINGLIST_H // replace with relevant names, each header should have it's own header guard
#define SDDS_SHOPPINGLIST_H

// Your header file content goes here
namespace sdds
{
	const int MAX_NO_OF_RECS = 15;

	bool loadList();

	void displayList();

	void removeBoughtItems();

	void removeItem(int index);

	bool saveList();

	void clearList();

	void toggleBought();

	void addItemToList();

	void removeItemfromList();

	bool listIsEmpty();

}
#endif