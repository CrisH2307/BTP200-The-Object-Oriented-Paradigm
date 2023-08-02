/*
Final Project Milestone 4
Filename: Book.h
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

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include<iostream>
#include "Publication.h"
namespace sdds
{
	class Book: public Publication
	{
		char* m_author;

	public:
		Book();

		//! Rule of Three
        Book(const Book& that);
        Book& operator=(const Book& that);
        ~Book();

		//! Methods
		virtual char type() const override;
		virtual std::ostream& write(std::ostream& os = std::cout) const override;
		virtual std::istream& read(std::istream& is = std::cin) override;
		virtual void set(int member_id) override;
		virtual operator bool() const override;
	};
}
#endif 

