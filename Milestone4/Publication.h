/*
Final Project Milestone 4
Filename: Publication.h
Author:	Cris Huynh
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/02  Preliminary release
2023/?/?    Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
07/25: Started declare and implement the function
07/31: Finished the implementation, but memory leaks and segmentation fault
08/01: Debug the error, the memory leaks on Publication and Book, also
istream error that didnt print 220 lines of book (Helper: Sean Muniz)
08/01: Finised MS4
-----------------------------------------------------------
*/
#ifndef _SDDS_PUBLICATION_H_
#define _SDDS_PUBLICATION_H_
#include <iostream>
#include "Date.h"
#include "Streamable.h"
namespace sdds
{
	class Publication: public Streamable
	{
		// m_title is a c - string to hold a dynamic title for the publication.
		// To ease the implementation, let's assume this dynamic array can not be more than 255 characters long.
		// This attribute is null by default.
		char* m_title{};

		// Hold the location of the publication in the library. m_shelfId is a c-string that is exactly 4 characters long.
		// This attribute is an empty string by default.
		char m_shelfld[5]{};

		// This attribute is an integer to hold a 5 digit membership number of members of the library.
		// In this class, if the membership number is '0', it means the publication is available and is not checked out by any members.
		// If the membership number is a five - digit number, it means the publication is checked out by the member holding that membership number.
		// This attribute is zero by default.
		int m_membership{};

		// This serial number is used internally to uniquely identify each publication in the system.
		// This attribute is - 1 by default.
		int m_libRef{};

		// A Date object
		// In periodical publications, this date is used for the publish date of the item.
		// In Books, this date is used to keep the date on which the book was borrowed by the member.
		// The Date, by default, is set to the current date.
		Date m_date{};

	public:
		Publication();

		//! Methods
		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the **libRef** attribute value
		void resetDate();
		// Sets the date to the current date of the system.

		//! Queries
		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute.


		//! Streamable pure virtual function implementations
		virtual bool conIO(std::ios& io)const override;
		virtual std::ostream& write(std::ostream& os) const override;
		virtual std::istream& read(std::istream& is) override;
		virtual operator bool() const override;

		//! The Rule of three
		// Make sure this object complies with the guidelines of the Rule of three so the 
		// copying and assignment and destruction are done safely and without any memory leak.
		Publication(const Publication& that);
		Publication& operator=(const Publication& that);
		~Publication();
	};

		

}
#endif // !_SDDS_PUBLICATION_H_

