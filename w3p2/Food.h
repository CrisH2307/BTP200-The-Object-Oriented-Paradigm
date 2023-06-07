/*
*****************************************************************************
							  Food.h
Full Name  : Xuan Khang Huynh (Cris Huynh)
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

namespace sdds
{
	const int FOOD_NAME = 30;

	const int CALORIES = 4;

	const int WHEN = 10;

	class Food
	{
		char m_name[FOOD_NAME + 1];
		int m_calo;
		int m_when;

	public:
		const char* when(int m_when)const;

		void init();

		bool set(const char* name, int calo, int when);

		void display()const;

		bool isEmpty()const;

		double getCalo()const;

		void setEmpty();
	};
}


#endif
