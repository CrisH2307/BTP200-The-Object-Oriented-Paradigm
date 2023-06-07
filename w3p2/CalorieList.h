/*
*****************************************************************************
							  CalorieList.h
Full Name  : Xuan Khang Huynh (Cris Huynh)
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H

#include "Food.h"
namespace sdds
{

	class CalorieList
	{
		// char m_title[50];

		Food* m_items;
		/// <summary>
		/// The collection of items.
		/// </summary>
		//TODO: declare the `m_items` attribute; this attribute will store
		//        the address of a dynamically-allocated array of objects
		//        of type `Item`.

		int m_capacity;
		/// <summary>
		/// The maximum number of items this bill can accommodate.
		/// </summary>
		//TODO: declare the `m_capacity` attribute as an integer.


		int m_cntItems;
		/// <summary>
		/// The number of items in this bill. Cannot be bigger than capacity.
		/// </summary>
		//TODO: declare the `m_cntItems` attribute as an integer.

		int getTotalCalo() const;

		void displayHeader()const;

		void displayFooter()const;

		bool isValid()const;

	public:

		/// <summary>
	/// Initializes the list to be able to store `capacity` objects of type `Food`.
	/// </summary>
	/// <param name="capacity">An integer representing the maximum number of
	///   items this list can accommodate.
	/// 
	///   **Valid capacity**: any number bigger than 0.</param>
		void init(int capacity);

		/*void set(const char* title, int noOfItems);*/


		/// <summary>
		/// Add a new food to the list, if there is capacity.
		/// </summary>
		/// <param name="food_name">A C-string containing the name of the food item.</param>
		/// <param name="calories">An integer storing how many calories the food has.</param>
		/// <param name="when">An integer representing when this food will be consumed.</param>
		/// <returns>`true` if the food has been added to the list, `false` otherwise.</returns>
		bool add(const char* food_name, int calories, int when);

		/// <summary>
		/// Prints to screen the content of the list.  Look in the sample output
		///   for hints about formatting.
		/// </summary>
		void display()const;

		/// <summary>
		/// Deallocates all dynamic memory used by this object and sets all attributes to
		///   a default value.
		/// </summary>
		void reset();

	};
}


#endif
