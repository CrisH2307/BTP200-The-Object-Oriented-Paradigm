/*
*****************************************************************************
							  Food.cpp
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
	// Create new function that returns the when, because the argument calls as the number
	const char* Food::when(int m_when)const
	{
		// Mealtime variable are int

		if		(m_when == 1)
			return "Breakfast";
		else if (m_when == 2)
			return "Lunch";
		else if (m_when == 3)
			return "Dinner";
		else if (m_when == 4)
			return "Snack";
		else
			return "NULL";
			
	}
	void Food::init()
	{
		m_name[0] = '\0';
		m_calo = 0.0;
		m_when = 0;
	}

	bool Food::set(const char* name, int calo, int when)
	{
		if (name != nullptr and name[0] != '\0' and calo > 0 and calo < 3000 and when != 0)
		{
			strncpy(m_name, name, FOOD_NAME);
			m_name[FOOD_NAME] = '\0';
			m_calo = calo;
			m_when = when;
			return true;
		}
		else
		{
			//params are bad
			init();
			return false;

		}

	}

	void Food::display()const
	{
		char curFill = cout.fill();
		const char* newwhen = when(m_when);


		if (isEmpty() == false)
		{
			cout << "| ";
			cout.width(FOOD_NAME);
			cout.setf(ios::left);
			cout.fill('.');
			cout << m_name;

			cout << " | ";
			cout.width(CALORIES);
			cout.unsetf(ios::left);
			cout.setf(ios::right);
			//cout.precision(2);
			cout.fill(' ');
			cout << m_calo;

			cout << " | ";
			cout.width(WHEN);
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout << newwhen;
			cout << " |";
		}
		else
		{
			cout << "| ";
			cout.width(FOOD_NAME);
			cout.setf(ios::left);
			cout.fill('x');

			cout << "xxx";

			cout << " | ";
			cout.width(CALORIES);
			cout.unsetf(ios::left);
			cout.setf(ios::right);
			cout << "xxx";


			cout << " | ";
			cout.width(WHEN);
			cout.unsetf(ios::right);
			//cout.unsetf(ios::fixed);
			cout << "xxx";

			cout << " |";
		}
		cout << endl;
		cout.unsetf(ios::left);
		cout.unsetf(ios::right);
		cout.fill(curFill);
	}

	bool Food::isEmpty()const
	{
		return (m_name[0] == '\0');
	}

	double Food::getCalo()const
	{
		return m_calo;
	}
	void Food::setEmpty()
	{
		m_name[0] = '\0';
		m_calo = 0;
		m_when = 0;
	}
}
