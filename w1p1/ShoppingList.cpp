/*
*****************************************************************************
							  ShoppingList.cpp
Full Name  : Xuan Khang Huynh (Cris Huynh)
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include <cstdio>
#include "File.h"
#include "ShoppingList.h"
#include "ShoppingRec.h"
#include "Utils.h"


using namespace std;

namespace sdds
{
	ShoppingRec g_recs[MAX_NO_OF_RECS]{};
	int g_noOfRecs = 0;

	bool loadList()
	{
		ShoppingRec shpr{};
		bool ok = false;
		if (openFileForRead())
		{
			ok = true;
			while (g_noOfRecs < MAX_NO_OF_RECS && freadShoppingRec(&shpr))
				g_recs[g_noOfRecs++] = shpr;
			closeFile();
		}
		return ok;
	}

	void displayList()
	{
		for (int i = 0; i < g_noOfRecs; i++)
		{
			cout << (i + 1) << "-";
			displayShoppingRec(&g_recs[i]);
		}
	}

	void removeBoughtItems()
	{
		if (!listIsEmpty())
		{
			cout << "Removing bought items, are you sure?" << endl;
			cout << "(Y)es/(N)o: ";
			if (yes())
			{
				for (int i = 0; i < g_noOfRecs; i++)
				{
					if (g_recs[i].m_bought)
						removeItem(i--);
				}
			}
			else
			{
				cout << "Cancelled!" << endl;
			}
		}
		else
		{
			cout << "List is empty!" << endl;
		}
	}

	void removeItem(int index)
	{
		if (index >= 0 && index < g_noOfRecs)
		{
			g_noOfRecs--;
			for (int i = index; i < g_noOfRecs; i++)
				g_recs[i] = g_recs[i + 1];
		}
	}

	bool saveList()
	{
		bool ok = false;
		if (openFileForOverwrite())
		{
			ok = true;
			for (int i = 0; i < g_noOfRecs; i++)
				fwriteShoppintRec(&g_recs[i]);
			closeFile();
		}
		return ok;
	}

	void clearList()
	{
		cout << "This will remove all the items from the list;" << endl
			<< "Are you sure? (Y)es/(N)o" << endl;
		if (yes())
			g_noOfRecs = 0;
		else
			cout << "Cancelled!" << endl;
	}

	void toggleBought()
	{
		cout << "Item number: ";
		toggleBoughtFlag(&g_recs[readInt(1, g_noOfRecs) - 1]);
	}

	void addItemToList()
	{
		if (g_noOfRecs < MAX_NO_OF_RECS)
		{
			g_recs[g_noOfRecs] = getShoppingRec();
			g_noOfRecs += !isShoppingRecEmpty(&g_recs[g_noOfRecs]);
		}
		else
		{
			cout << "Shopping List is full!" << endl;
		}
	}

	void removeItemfromList()
	{
		if (!listIsEmpty())
		{
			int value = 0;
			cout << "Item number to delete: ";
			value = readInt(1, g_noOfRecs);
			cout << "Deleting following item, are you sure?" << endl;
			displayShoppingRec(&g_recs[value - 1]);
			cout << "(Y)es/(N)o: ";
			if (yes())
				removeItem(value - 1);
			else
				cout << "Cancelled!" << endl;
		}
		else
		{
			cout << "List is empty!" << endl;
		}

	}

	bool listIsEmpty()
	{
		return g_noOfRecs == 0;
	}

}