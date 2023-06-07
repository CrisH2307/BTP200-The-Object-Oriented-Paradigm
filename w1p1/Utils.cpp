/*
*****************************************************************************
							  Utils.cpp
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

namespace sdds {

	void flushkeys()
	{
		while (cin.get() != '\n');
	}


	bool validYesResponse(char ch)
	{
		return ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n';
	}

	bool yes()
	{
		char ch = 0;
		do
		{
			cin >> ch;
			flushkeys();
		} while (!validYesResponse(ch) && cout << "Only (Y/y) or (N/n) is acceptable: ");

		return ch == 'y' || ch == 'Y';
	}

	void readCstr(char cstr[], int len)
	{
		char buf[1024]{};
		int i;
		cin.getline(buf, 1024);
		for (i = 0; i < len - 1 && buf[i]; i++)
			cstr[i] = buf[i];
		cstr[i] = '\0';
	}

	int readInt(int min, int max)
	{
		int value = 0;
		bool done = false;
		while (!done)
		{
			cin >> value;
			if (!cin)
			{
				cin.clear();
				cout << "Bad integer, try again: ";
			}
			else
			{
				if (value >= min && value <= max)
					done = true;
				else
					cout << "Value out of range (" << min << "<=value<=" << max << "): ";
			}
			flushkeys();
		}
		return value;
	}
}