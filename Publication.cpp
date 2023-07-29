/*
Final Project Milestone 3
Filename: Publication.cpp
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
07/21: Started MS3
07/22: Debug errors (Segmentation Fault)
07/24: I was stuck with copy assignment and copy constructor(Helper: Sean Muniz, Kabir Nalula)
07/25: Stuck with write and read function (Helper: Preet Patel, Nand Patel, Sukhman Hara)
07/28: Fix some format error and fill char, finished
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Publication.h"
#include "Streamable.h"
#include "Date.h"
#include "Lib.h"

using namespace std;
namespace sdds
{
	Publication::Publication() : m_date()
	{
		//todo: Sets all the attributes to their default values
		this->m_title = new char[1];
		this->m_title[0] = '\0';
		this->m_shelfld[0] = '\0';
		this->m_membership = 0;
		this->m_libRef = -1;
	}

	//////////////////////////////////////////////////////////////////////////
	//! Methods
	void Publication::set(int member_id)
	{
		if (member_id > 9999 and member_id < 100000)
		{
			this->m_membership = member_id;
		}
		else
		{
			this->m_membership = 0;
		}
	}

	void Publication::setRef(int value)
	{
		this->m_libRef = value;
	}

	void Publication::resetDate()
	{
		this->m_date = Date();
	}

	char Publication::type() const
	{
		return 'P';
	}

	bool Publication::onLoan() const
	{
		return (this->m_membership != 0);
	}

	Date Publication::checkoutDate() const
	{
		return this->m_date;
	}

	bool Publication::operator==(const char* title) const
	{
		return this->m_title and strstr(this->m_title, title);
	}

	Publication::operator const char* () const
	{
		return this->m_title;
	}

	int Publication::getRef() const
	{
		return this->m_libRef;
	}

	//////////////////////////////////////////////////////////////////////////
	//! Queries
	bool Publication::conIO(ios& io) const
	{
		return (&io == &cin or &io == &cout);
	}

	ostream& Publication::write(ostream& os) const
	{
		// TODO: If the os argument is a console IO object (use conIO()), print shelfId, title, membership 
		// and date attributes as the following format (title is left-justified padded with dots)
		/*
				 1         2         3         4         5         6         7
		1234567890123456789012345678901234567890123456789012345678901234567890
		| P001 | The Toronto Star.............. | 34037 | 2021/11/17 |
		| P007 | Macleans Magazine............. |  N/A  | 2021/11/11 |
		Otherwise:
		Print the type() and then libRef, shelfId, title, membership and date attributes in a
		tab-separated format.
		P	2001		P001		The Toronto Star		34037	2021/11/17
		No newline is printed afterwards either way.
		*/

		if (conIO(os))
		{
			char fc = os.fill(' ');
			os << "| ";
			os.width(SDDS_SHELF_ID_LEN);
			os << this->m_shelfld;

			os << " | ";
			os.width(SDDS_TITLE_WIDTH);
			os.setf(ios::left);
						os.fill('.');
						os << this->m_title; // Left-justify the title and pad with dots

						os.fill(fc);
						os.unsetf(ios::left);

			os << " | ";
		
			if (m_membership == 0)
			{
				cout << " N/A ";
			}
			else
			{
				os << this->m_membership;
			}
			
			os << " | ";
			os << this->m_date;
			os << " |";
		}
		else
		{
			os << type();
			os << "\t";
			os << this->m_libRef;
			os << "\t";
			os << this->m_shelfld;
			os << "\t";
			os << this->m_title;
			os << "\t";
			os << this->m_membership;
			os << "\t";
			os << this->m_date;			
		}	
		return os;
	}

	istream& Publication::read(istream& istr)   //! Helper: Sean Muniz, Sukhman Hara, Preet Patel
	{
		// todo: Read all the values in local variables before setting the attributes to any values.
		/*
		First, clear all the attributes by freeing the memory and setting everything to their default values.

		Then, if the istr argument is a console IO object (use conIO()) read the attributes as follows:

		prompt: "Shelf No: "
		read the shelf number up to its limit (see Lib.h).
		if the number is not exactly the length it is supposed to be, set the istr to a fail state manually.
		prompt: "Title: "
		read the title
		prompt: "Date: "
		read the date

		in this case the libRef value is left with its default value.

		Otherwise, assume reading begins with libRef attribute as if the type 'P' is not in the file.

		read the libRef number
		skip the tab
		read the shelf number
		skip the tab
		read the title
		skip the tab
		read the membership
		skip the tab
		read the date

		Either way if the date is in an invalid state set the istr to a fail state manually

		After the process of reading is done if istr is in a valid state:

		Dynamically store the title into the title attribute
		copy the shelf id into the shelfId attribute
		set the membership
		set the date
		set the libRef attribute

		At the end return the istr argument.	
		*/

		
		if (m_title != nullptr)
		{
			delete[] m_title;
		}
		m_title = nullptr;
		m_shelfld[0] = '\0';
		m_membership = 0;
		m_libRef = -1;

		char title[SDDS_TITLE_WIDTH + 1]{};
		char id[SDDS_SHELF_ID_LEN + 1]{};
		int memberShip = 0;
		int libRef = -1;
		Date date;

		if (conIO(istr)) {
			cout << "Shelf No: ";//prompt statment
			istr.getline(id, SDDS_SHELF_ID_LEN + 1, '\n');//read the shelf number up to its limit (see Lib.h).

			if (strlen(id) != SDDS_SHELF_ID_LEN)
			{
				istr.setstate(ios::failbit);
			}
			cout << "Title: ";
			istr.getline(title, SDDS_TITLE_WIDTH + 1);//read title

			cout << "Date: ";
			istr >> date;//read date

		}
		else {
			istr >> libRef;									// Read libRef from input, uisng tab
			istr.ignore();
			istr.getline(id, SDDS_SHELF_ID_LEN + 1, '\t');	// Read shelfId from input, using tab
			istr.getline(title, SDDS_TITLE_WIDTH + 1, '\t');	// Read title from input, using tab
			istr >> memberShip;								// Read membership from input, using tab
			istr.ignore();
			istr >> date;										// Read date from input
		}
		
		if (!date) 
		{			
			istr.setstate(std::ios::failbit);
		}
		if (istr) 
		{		
			delete[] m_title;
			m_title = new char[strlen(title) + 1];//Dynamically store the title into the title attribute
			strcpy(m_title, title);//copy title into m_title
			strcpy(m_shelfld, id);//copy the shelf id into the shelfId attribute
			set(memberShip);//set the membership
			m_date = date;
			setRef(libRef);//set the libRef attribute
		}
		return istr;
	}


	Publication::operator bool() const
	{
		//todo: Returns true if neither of the title or shelfId attributes is null or empty. Otherwise, it will return false.
		return (this->m_title != nullptr and this->m_shelfld[0] != '\0') ;
	} 

	//////////////////////////////////////////////////////////////////////////
	//! Rule of Three
	Publication::Publication(const Publication& that) : m_date(that.m_date)
	{
		m_title = nullptr; // Set m_title to nullptr to ensure it doesn't point to any allocated memory
		*this = that; // Use the copy assignment operator to perform a deep copy
	}

	Publication& Publication::operator=(const Publication& that)
	{
		if (this and that)
		{
			delete[] m_title; // Deallocate existing memory (if any) to avoid memory leaks
			m_title = nullptr; // Set m_title to nullptr to ensure it doesn't point to any allocated memory
			m_shelfld[0] = '\0';

			// Perform a deep copy of the attributes
			m_membership = that.m_membership;
			m_libRef = that.m_libRef;
			m_date = that.m_date;

			// Allocate memory for m_title and copy the contents
			if (that.m_title != nullptr)
			{
				m_title = new char[strlen(that.m_title) + 1];
				strcpy(m_title, that.m_title);
				strcpy(m_shelfld, that.m_shelfld);
			}

			strcpy(m_shelfld, that.m_shelfld);
		}
		return *this;
	}
 
	Publication::~Publication()
	{
		// todo: Make sure this object complies with the guidelines of the Rule of three so the 
		// copying and assignment and destruction are done safely and without any memory leak.
		//todo: Sets all the attributes to their default values.
		 delete[] m_title;
	}
}