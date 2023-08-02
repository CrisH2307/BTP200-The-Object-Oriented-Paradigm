/*
Final Project Milestone 4
Filename: Streamable.h
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
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------
*/
#ifndef _SDDS_STREAMABLE_H_
#define _SDDS_STREAMABLE_H_
#include <iostream>
namespace sdds
{
	class Streamable
	{
	public:
		virtual std::ostream& write(std::ostream& os) const = 0;
		virtual std::istream& read(std::istream& is) = 0;		
		virtual bool conIO(std::ios& ios) const = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable();
		friend std::ostream& operator<<(std::ostream& o, const Streamable& that);
		friend std::istream& operator>>(std::istream& i, Streamable& that);
	};


}
#endif // _SDDS_STREAMABLE_H_






