/*
*****************************************************************************
							  Item.h
Full Name  : Xuan Khang Huynh (Cris Huynh)
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

namespace sdds
{

	/// <summary>
	/// An integer representing the number of characters
	///   of the `NAME` column (used in printing to screen).
	/// </summary>
	const int WIDTH_NAME = 32;

	/// <summary>
	/// An integer representing the number of characters
	///   of the `PRICE` column (used in printing to screen).
	/// </summary>
	const int WIDTH_PRICE = 8;

	/// <summary>
	/// An integer representing the number of characters
	///   of the `TAX` column (used in printing to screen).
	/// </summary>
	const int WIDTH_TAX = 4;

	/// <summary>
	/// The name of the item.
	/// </summary>
	// TODO: declare the `m_name` attribute; a statically-allocated
	///        array with `WIDTH_NAME` characters (not counting the
	///        null terminator).

	/// <summary>
	/// The price of the item, not including tax.
	/// </summary>
	// TODO: declare the `m_price` attribute as a floating-point
	//         number in double precision.

	/// <summary>
	/// `true` is the tax should be applied to this item when
	///   calculating the total price.
	/// </summary>
	// TODO: declare the `m_isTaxed` attribute as a boolean flag.


	/// <summary>
	/// Sets ALL object's attribute to a default value.
	/// </summary>

	class Item
	{
		char m_name[WIDTH_NAME + 1];
		double m_price;
		bool m_isTaxed;

	public:
		void init();



		/* TODO: define the `init` MODIFIER
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* init()
		*
		* - set the name to empty string (this will be the empty state)
		* - set the price to 0
		* - the item should be taxed
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/


		/// <summary>
		/// If the parameters are valid, stores the values in
		///   the attributes, otherwise sets the `Item`s attributes
		///   to their default values.
		/// </summary>
		/// <param name="name">The name of the item.
		/// 
		///   **Valid name**: any C-string that is not null and not empty.
		/// </param>
		/// <param name="price">The price of the item.
		/// 
		///   **Valid price**: any number bigger than 0.
		/// </param>
		/// <param name="isTaxed">`true` if this item should be taxed.</param>
		/// <returns>`true` if the parameters are valid and were accepted,
		///   `false` otherwise.</returns>
		bool set(const char* name, double price, bool isTaxed);
			/* TODO: define the `set` MODIFIER
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			*
			* set(name, price, isTaxed)
			*
			* - if ALL parameters are valid store them in the attributes and return `true`
			* - it at least one parameter is not valid, call the `init` function,
			*     and return `false`.
			*
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			*/



			/// <summary>
			/// Prints to screen the content of the `Item`.
			/// </summary>
		
		void display()const;
			/* TODO: define the `display` QUERY
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			*
			* display()
			*
			* - save in local variables the current filling character and the precision
			* - if the object is not in an empty state (the `m_name` attribute is not
			*     an empty string), print:
			*     "| NAME | PRICE | TAX? |<newline>"
			*     where:
			*     - `NAME` is a field of `WIDTH_NAME` characters, aligned to the left,
			*         and using '.' as a filling character.
			*     - `PRICE` is field of `WIDTH_PRICE` characters, aligned to the right,
			*         using a space as a filling character, and having exactly two
			*         digits after the period.
			*     - `TAX?` is field of `WIDTH_TAX` characters, aligned to the right,
			*         and using space as a filling character.
			* - if the object is in an empty state, print:
			*     "| xxx | xxx | xxx |<newline>"
			*     - use the same formatting options as described above.
			* - remove the formatting options that were set by this function
			*   - the filling character and the precision
			*   - anything set by "setf()" must be removed with "unsetf()"
			*
			* Look in the sample output for hints regarding the formatting.
			*
			* Note that the borders are separated from the column content by a space.
			*
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			*/


			/// <summary>
			/// Checks if the object is in empty state or not.
			/// </summary>
			/// <returns>`true` if the object is in empty state, `false` otherwise.</returns>
		bool isEmpty()const;
			/* TODO: define the `isEmpty` QUERY
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			*
			* isEmpty()
			*
			* - the object is in empty state if the `m_name` attribute is an empty string.
			*
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			*/


			/// <summary>
			/// Return to the client the price of the item before tax.
			/// </summary>
			/// <returns>the price of the item.</returns>
		double getPrice()const;
			/* TODO: define the `getPrice` QUERY
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			*
			* getPrice()
			*
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			*/


			/// <summary>
			/// Returns to the client the tax that must be paid for the item.
			/// </summary>
			/// <returns>the tax for the item.</returns>
		double getTax()const;
			/* TODO: define the `getTax` QUERY
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			*
			* getTax()
			*
			* - if the item is not taxable, the tax is `0`
			* - if the item is taxable, the tax is 13% of the price.
			*
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			*/
	};
}

#endif