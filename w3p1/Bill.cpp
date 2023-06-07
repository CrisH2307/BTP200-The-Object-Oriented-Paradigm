/*
*****************************************************************************
							  Bill.cpp
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
#include "Bill.h"
using namespace std;
namespace sdds
{

	double Bill::getTotalTax()const
	{
		double TotalTax = 0.0;
		for (int i = 0; i < m_cntItems; i++)
		{
			TotalTax += m_items[i].getTax();
		}
		return TotalTax;
	}
	double Bill::getTotalPrice()const
	{
		double TotalPrice = 0.0;
		for (int i = 0; i < m_cntItems; i++)
		{
			TotalPrice += m_items[i].getPrice();
		}
		return TotalPrice;
	}

	void Bill::displayHeader()const
	{
		
		char curFill = cout.fill();

		cout << "+----------------------------------------------------+" << endl;
		cout << "| ";
		cout.width(WIDTH_NAME + WIDTH_PRICE + WIDTH_TAX + 6);
		cout.setf(ios::left);
		cout.fill(' ');

		if (isValid())
		{
			cout << m_title;
			
		}
		else
		{
			cout << "Invalid Bill";
		}

		cout << " |" << endl;
		cout << "+----------------------------------+----------+------+" << endl;

		cout << "| ";
		cout.width(WIDTH_NAME);
		cout << "Item Name";

		cout << " | ";
		cout.width(WIDTH_PRICE);
		cout.unsetf(ios::left);
		cout.setf(ios::right);
		cout << "Price";

		cout << " | ";
		cout.width(WIDTH_TAX);
		cout << "Tax";


		cout << " |" << endl;
		cout << "+----------------------------------+----------+------+" << endl;

		cout.fill(curFill);
		cout.unsetf(ios::right);

	}
	
	void Bill::displayFooter()const
	{
		if (!isValid())
		{
			cout << "+----------------------------------+----------+------+" << endl;
			return;
		}

		char currentFill = cout.fill();
		int precision = cout.precision();

		double priceBeforeTax = getTotalPrice();
		double tax = getTotalTax();
		double priceAfterTax = priceBeforeTax + tax;

		cout << "+----------------------------------+----------+------+" << endl;
		cout << "|                        Price Before Tax : ";
		cout.width(WIDTH_PRICE);
		cout.setf(ios::right);
		cout.setf(ios::fixed);
		cout.fill(' ');
		cout.precision(2);
		cout << priceBeforeTax << " |" << endl;

		cout << "|                                     Tax : ";
		cout.width(WIDTH_PRICE);
		cout  << tax << " |" << endl;

		cout << "|                         Price After Tax : ";
		cout.width(WIDTH_PRICE);
		cout  << priceAfterTax << " |" << endl;

		cout << "+----------------------------------------------------+" << endl;

		cout.fill(currentFill);
		cout.precision(precision);
		cout.unsetf(ios::right);
		cout.unsetf(ios::fixed);
	}

	bool Bill::isValid()const
	{

		int RedFlag = 0;

		for (int i = 0; i < m_capacity; i++)
		{
			if (m_items[i].isEmpty())
				RedFlag = 1;
		}
	
		if (m_items != nullptr && m_title[0] != '\0' && RedFlag != 1)
		{
			return true;
		}
		else
		{
			return false;
		}
			
	}

	void Bill::init(const char* title, int capacity)
	{
		if (title != nullptr and title[0] != '\0' and capacity > 0) //((title != nullptr || title[0] == '\0') && capacity > 0)
		{
			strncpy(m_title, title, WIDTH_NAME);
			m_capacity = capacity;

			m_items = new Item[capacity];

			// Initialize each item in the array
			for (int i = 0; i < capacity; i++)
			{
				m_items[i].init();
			}

			m_cntItems = 0;
		}
		else {
			m_title[0] = '\0';
			m_capacity = 0;
			// delete[] this->m_items;
			m_items = nullptr;
			m_cntItems = 0;
		}
	}

	bool Bill::add(const char* item_name, double item_price, bool isTaxed)
	{
		bool ok = false;
		if (m_cntItems < m_capacity)
		{
			m_items[m_cntItems].set(item_name, item_price, isTaxed);
			m_cntItems++;
			ok = true;
		}
		return ok;
	}

	void Bill::display()const
	{
		displayHeader();

		for (int i = 0; i < m_capacity; i++)
		{
			m_items[i].display();
		}

		displayFooter();
	}

	void Bill::cleanup()
	{
		delete[] m_items; // Deallocate the dynamic array

		// Reset attributes to default values
		m_items = nullptr;
		m_title[0] = '\0';
		m_capacity = 0;
		m_cntItems = 0;
	}
}