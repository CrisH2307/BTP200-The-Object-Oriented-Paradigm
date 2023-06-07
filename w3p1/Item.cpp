/*
*****************************************************************************
							  Item.cpp
Full Name  : Xuan Khang Huynh (Cris Huynh)
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

// This prevents VS compiler from issuing warnings/errors related to utilization
//   of unsafe string functions.  Has no effect in g++.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include "Item.h"
using namespace std;
namespace sdds
{

	void Item::init() 
	{
		for (int i = 0; i < WIDTH_NAME; i++)
		{
			m_name[i] = '\0';
		}

		m_price = 0.0;
		m_isTaxed = true;
	}
	bool Item::set(const char* name, double price, bool isTaxed)
	{
	
		if (name != nullptr and name[0] != '\0' and price > 0.0)
		{
			strncpy(m_name, name, WIDTH_NAME);
			m_name[WIDTH_NAME] = '\0';
			m_price = price;
			m_isTaxed = isTaxed;
			return true;
		}
		else
		{
			//params are bad
			init();
			return false;

		}

	}
	void Item::display()const
	{
		int number = cout.precision();
		char curFill = cout.fill();



		if (isEmpty() == false)
		{
			cout << "| ";
			cout.width(WIDTH_NAME);
			cout.setf(ios::left);
			cout.fill('.');
			cout <<  m_name;

			cout << " | ";
			cout.width(WIDTH_PRICE);
			cout.unsetf(ios::left);
			cout.setf(ios::right | ios::fixed);
			cout.precision(2);
			cout.fill(' ');
			cout << m_price;

			cout << " | ";
			cout.width(WIDTH_TAX);

			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);

			if (m_isTaxed == true)
			{
				cout << "Yes";

			}
			else
			{
				cout << "No";

			}
			cout << " |";
		}
		else
		{
			cout << "| ";
			cout.width(WIDTH_NAME);
			cout.setf(ios::left);
			cout.fill('x');
			cout << "";

			cout << " | ";
			cout.width(WIDTH_PRICE);
			cout.unsetf(ios::left);
			cout.setf(ios::right | ios::fixed);
			cout << "";

			cout << " | ";
			cout.width(WIDTH_TAX);
			cout << "";
			cout << " |";

			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);
		}
		cout << endl;

		cout.precision(number);
		cout.fill(curFill); 
	}
	bool Item::isEmpty()const
	{
		return (m_name[0] == '\0');

	}
	double Item::getPrice()const
	{
		return m_price;
	}
	double Item::getTax()const
	{
		if (m_isTaxed)
		{
			return 13 * m_price / 100;
			// 13% tax on the price
		}
		else
		{
			return 0.0; // Not taxable, so no tax
		}
	}
}