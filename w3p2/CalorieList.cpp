/*
*****************************************************************************
							  CalorieList.cpp
Full Name  : Xuan Khang Huynh (Cris Huynh)
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include "Food.h"
#include "CalorieList.h"
using namespace std;
namespace sdds
{

	int CalorieList::getTotalCalo()const
	{
		int TotalCalo = 0;
		for (int i = 0; i < m_cntItems; i++)
		{
			TotalCalo += m_items[i].getCalo();
		}
		return TotalCalo;
	}

	void CalorieList::displayHeader()const
	{
		char curFill = cout.fill();

		cout << "+----------------------------------------------------+" << endl;
		cout << "| ";
		cout.width(FOOD_NAME + CALORIES + WHEN+ 6);
		cout.setf(ios::left);
		cout.fill(' ');

		if (isValid())
		{
			cout << " Daily Calorie Consumption";

		}
		else
		{
			cout << "Invalid Calorie Consumption list";
		}
		cout << " |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;

		cout << "| ";
		cout.width(FOOD_NAME);
		cout.setf(ios::left);
		cout << "Food name";

		cout << " | ";
		cout.width(CALORIES);
		cout.unsetf(ios::left);
		cout.setf(ios::right);
		cout << "Cals";

		cout << " | ";
		cout.width(WHEN);
		cout.unsetf(ios::right);
		cout.setf(ios::left);
		cout << "When";

		cout << " |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;

		cout.fill(curFill);
		cout.unsetf(ios::left);
	}

	void CalorieList::displayFooter()const
	{
		int TotalCal = getTotalCalo();
		char currentFill = cout.fill();

		
		if (isValid())
		{

			cout << "+--------------------------------+------+------------+" << endl;
			cout << "|    Total Calories for today:     ";
			cout.width(FOOD_NAME);
			cout.setf(ios::right);
			cout.fill(' ');
			cout.width(CALORIES);
			cout << TotalCal << " |  ";

			cout.width(WHEN);
			cout << " |" << endl;


			cout << "+----------------------------------------------------+" << endl;

			cout.fill(currentFill);
			cout.unsetf(ios::right);
			cout.unsetf(ios::fixed);
		}

		else
		{
			cout << "+--------------------------------+------+------------+" << endl;
			cout << "|    Invalid Calorie Consumption list                |" << endl;
			cout << "+----------------------------------------------------+" << endl;
			return;
		}
	}

	bool CalorieList::isValid()const
	{
		int RedFlag = 0;

		for (int i = 0; i < m_capacity; i++)
		{
			if (m_items[i].isEmpty())
				RedFlag = 1;
		}

		if (m_items != nullptr && RedFlag != 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	void CalorieList::init(int capacity)
	{
	
		if (capacity > 0)
		{
			// Allocate memory for the items array
			m_items = new Food[capacity];

			// Set the capacity and number of items
			m_capacity = capacity;

			for (int i = 0; i < capacity; i++)
			{
				m_items[i].init();
			}
			m_cntItems = 0;
		}
		else
		{
			reset();
		}
	}
	
	bool CalorieList::add(const char* food_name, int calories, int when)
	{
		bool ok = false;
		if (m_cntItems < m_capacity)
		{
			m_items[m_cntItems].set(food_name, calories, when);
			m_cntItems++;
			ok = true;
		}
		return ok;
	}
	void CalorieList::display()const
	{
		displayHeader();

		for (int i = 0; i < m_capacity; i++)
		{
			m_items[i].display();
		}

		displayFooter();
	}
	void CalorieList::reset()
	{
		delete[] m_items; // Deallocate the dynamic array

		// Reset attributes to default values
		m_items = nullptr;
		m_capacity = 0;
		m_cntItems = 0;
	}
}
