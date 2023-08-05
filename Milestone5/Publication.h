/*
Final Project Milestone 5
Filename: Publication.h
ID: 105444228
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
MILESTONE JOURNAL:

MS1:
07/03: Beginning the MS1
07/05: Debugging Error
07/08: I'm confused whether create the default construcor or just need to create custom constructor
07/09: Segmentation Fault (Solved by Professor Jeevan Pant)
07/12: Menu Debugging Error, the problem is viewMenu and viewTitle, I separated them out because
it was easy to call the ostream helper function (Helper: Sean Muniz and Sukhman Hara)
07/13: Date Debugging Error, read and write function. cin failed didn't even print out.
I tried many times until I put os << displayTitle(os); (Initial I didnt put os) (Helper: Sean Muniz)
07/13: Small display error, and finished the MS1

MS2:
07/10: Start working on MS2, set attributes and implement LibApp.cpp
07/13: Start debugging on MS2, i didnt know how to implement the confirm when i need to
add Yes. Until my friend help me for using the attribute << "Yes". (Helper: Preet Patel)
07/14: Run function's errors because my loop was infinite until I saw that the issue
that I got is i made a wrong bool value when inside the loop (true ==> false, Helper: Mandhav and Preet Patel)
07/14: Finished

MS3:
07/21: Started MS3
07/22: Debug errors (Segmentation Fault)
07/24: I was stuck with copy assignment and copy constructor(Helper: Sean Muniz, Kabir Nalula)
07/25: Stuck with write and read function (Helper: Preet Patel, Nand Patel, Sukhman Hara)
07/28: Fix some format error and fill char, finished


MS4:
07/25: Started declare and implement the function
07/31: Finished the implementation, but memory leaks and segmentation fault
08/01: Debug the error, the memory leaks on Publication and Book, also
istream error that didnt print 220 lines of book (Helper: Sean Muniz)
08/01: Finised MS4


MS5:
07/19: Started MS5
07/20: Working on method, attributes and functions 
07/23: Implement the cpp file, add PublicSelector modules
07/28: Fixing compiler errors from publication because the format error
07/31: Fixing logic error from the menu, LibApp for the publication selector
08/01: Finished fixing Publication and Menu. Debug error starts with leaks segmentation fault
08/02: Adding Python auto input files, finished the compilation but logic error
08/03: Debug Problem 1: New Publication function, Load function
+ When I tried to input the publication, it didnt ignore the new line and kept me a blank space, 
I was helped my Sean Muniz and Madhav Rajpall for get rid of cin.lcear and cin.ignore() on Publication
beacuse I had already called the ignore on LilApp, and I need to delete one on Publication
+ Load and save function gave me memory leaks, Sean Muniz helped me fixing by passing the dereference instead of
local variable
08/03: Debug Problem 2: Remove and Search function
+ Remove Publication gave me too much ignore line, I decided to get rid of the getline and ignore on the LibApp function
+ Search is the most difficult fuction that I have done for MS5. I couldn't understand what should I return the function(int or void).
Sean Muniz and Sukhman Hara gave me advices and fix the return function so that when I call search for Publication fucntions, I can
call the argument and then it will return the number that it can pass the logic on every Publication function.
08/04: Debug Problem 3: Memory leaks
+ Today, I haven't even test any milestone test beacuse it gave me too much memory leaks.
+ Sean Muniz and Madhav Rajpall helped me to fix the leak by making Destructor, the instruction didnt say anything about it.
Also I just got rid of Default Constructor because the tester calls with argument, so I just needed to create only one 
constructor with a parameter.
08/05: Tested, compilation and endl
+ I just got some formatting error, I forgot endl, forgot to unsetf
+ However the all program was successful
+ Finished MS5 with 6 tests

Milestone form 1 to 5 Helper:
+ Sean Muniz
+ Preet Patel
+ Madhav Rajpall
+ Kabir Narula
+ Nand Patel
+ Joseph Chu
+ Sukhman Hara

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

