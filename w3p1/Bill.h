/*
*****************************************************************************
							  Bill.h
Full Name  : Xuan Khang Huynh (Cris Huynh)
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_BILL_H
#define SDDS_BILL_H

#include "Item.h"

namespace sdds
{
	class Bill
	{
		char m_title[50];
		/// <summary>
		/// The title of the bill.
		/// </summary>
		// TODO: declare the `m_title` attribute; a statically-allocated
		///        array with `50` characters (not counting the
		///        null terminator).

		
		Item* m_items;
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


		/// <summary>
		/// Calculates the tax for all items in the bill.
		/// </summary>
		/// <returns>the total tax for all items.</returns>
		
		double getTotalTax()const ;
		/* TODO: define the `getTotalTax` QUERY
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* getTotalTax()
		*
		* - create a local variable (floating point number in double precision)
		*     to store the total tax
		* - iterate over the array of items and add the tax of each one
		*     to the local variable (use `Item::getTax()` function).
		* - return the total tax
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/


		/// <summary>
		/// Calculates the total price of the items in the bill (no tax included).
		/// </summary>
		/// <returns>the total price for all items.</returns>
		double getTotalPrice() const;
		/* TODO: define the `getTotalPrice` QUERY
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* getTotalPrice()
		*
		* - create a local variable (floating point number in double precision)
		*     to store the total price
		* - iterate over the array of items and add the price of each one
		*     to the local variable (use `Item::getPrice()` function).
		* - return the total price
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/


		/// <summary>
		/// Print to screen the header of the table for the bill content.
		/// </summary>
		void displayHeader()const;
		/* TODO: define the `displayHeader` QUERY
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* displayHeader()
		*
		* - save in a local variable the current filling character
		* - print to screen the header in the following format:
		*
		*     +----------------------------------------------------+
		*     | BILL_TITLE                                         |
		*     +----------------------------------+----------+------+
		*     | Item Name                        |    Price |  Tax |
		*     +----------------------------------+----------+------+
		*
		*     where:
		*     - `BILL_TITLE` is a field of `WIDTH_NAME + WIDTH_PRICE + WIDTH_TAX + 6`
		*         characters, aligned to the left, and using space as a filling
		*         character. If the object is invalid, the title is "Invalid Bill".
		* - restore the formatting options the were set by this function
		*   - the filling character
		*
		* See the sample output for hints about formatting options.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/


		/// <summary>
		/// Print to screen the footer of the table for the bill content.
		/// </summary>
		void displayFooter()const;
		/* TODO: define the `displayFooter` QUERY
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* displayFooter()
		*
		* - if the bill is not valid (use `Bill::isValid` to determine that), print to
		*     screen:
		*
		*     +----------------------------------+----------+------+
		*
		*     and exit the function.
		*
		* - if the bill is valid:
		*     - save in local variables the current filling character and the precision
		*     - calculate the price before tax (use `Bill::getTotalPrice`)
		*     - calculate the tax (use `Bill::getTotalTax`)
		*     - calculate the price after tax (as a sum of price before tax and tax).
		*     - print to screen the footer in the following format:
		*
		*       +----------------------------------+----------+------+
		*       |                        Price Before Tax :    NN.NN |
		*       |                                     Tax :    NN.NN |
		*       |                         Price After Tax :    NN.NN |
		*       +----------------------------------------------------+
		*
		*       where:
		*       - `NN.NN` is a field of `WIDTH_PRICE` characters, aligned to the right,
		*           using space as a filling character, and having exactly two
		*           digits after the period.
		*     - restore the formatting options the were set by this function
		*       - the filling character and the precision
		*       - anything set by "setf()" must be removed with "unsetf()"
		*
		* See the sample output for hints about formatting options.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/


		/// <summary>
		/// Checks if the object contains valid data.
		/// </summary>
		/// <returns>`true` if the object is valid, `false` otherwise.</returns>
		bool isValid()const;
		/* TODO: define the `isValid` QUERY
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* isValid()
		*
		* - return `true` if all the following conditions are met:
		*   - `m_items` is not null
		*   - `m_title` is not an empty string
		*   - ALL items in the array (up to `m_capacity`) are valid. Iterate over the
		*       array and use `Item::isEmpty` to check each item.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/

	public:
		/// <summary>
		/// Initializes the `Bill` object to the values received as parameters.
		///   If the parameters are invalid, set the object to a default state.
		/// </summary>
		/// <param name="title">A C-string representing the title for this bill.
		/// 
		///   **Valid title**: any array of characters that is not null and
		///                    not empty.</param>
		/// <param name="capacity">An integer representing the maximum number of
		///   items this bill can accommodate.
		/// 
		///   **Valid capacity**: any number bigger than 0.
		/// </param>
		void init(const char* title, int capacity);
		/* TODO: define the `init` MODIFIER
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* init(title, capacity)
		*
		* - if all parameters are valid
		*   - copy at most 50 characters from the parameter into the attribute.
		*   - copy the capacity parameter into the attribute.
		*   - dynamically allocate an array of `Item` objects (of size `capacity`).
		*       Store it's address into the `m_items` attribute.
		*   - iterate over the dynamic array, and for each item call the `Item::init()"
		*       function.
		*   - set the attribute `m_cntItems` to 0.
		* - if at least one parameter is not valid
		*   - set title to empty string
		*   - set capacity to 0
		*   - set the `m_items` pointer to null
		*   - set the `m_cntItems` to 0
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/


		/// <summary>
		/// Add a new item to the bill, if there is capacity.
		/// </summary>
		/// <param name="item_name">The new item's name.</param>
		/// <param name="item_price">The new item's price.</param>
		/// <param name="isTaxed">`true` if the new item should be taxed.</param>
		/// <returns>`true` if the item was successfully added.</returns>
		bool add(const char* item_name, double item_price, bool isTaxed);
		/* TODO: define the `add` MODIFIER
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* add(item_name, item_price, isTaxed)
		*
		* - if there is still capacity in the array (the number of items is
		*     smaller than the capacity)
		*     - call the `Item::set()` on the item at index `m_cntItems`, passing
		*         the parameters received.
		*     - increment `m_cntItems`
		*     - return the value returned by `Item::set()`
		* - if there is no capacity, return `false` and do nothing else.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/


		/// <summary>
		/// Prints to screen the content of the bill formatted like a table.
		/// </summary>
		void display()const;
		/* TODO: define the `display` QUERY
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* display()
		*
		* - display the table header
		* - iterate over the array of items, and call `Item::display()` on each one
		* - display the table footer
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/

		void cleanup();
		/// <summary>
		/// Deallocate all the dynamic memory used by the `Bill` object,
		///   and set all the attributes to their default values.
		/// </summary>
		/* TODO: define the `cleanup` MODIFIER
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* cleanup()
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/

	};
}

#endif