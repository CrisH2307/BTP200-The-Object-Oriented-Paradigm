/*
Final Project Milestone 4
Filename: Book.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Streamable.h"
#include "Publication.h"
#include "Book.h"
#include "Date.h"
#include "Lib.h"

using namespace std;
namespace sdds
{
    Book::Book() : m_author(nullptr)
    {
        //todo: A book is created empty by default, in a safe empty state.
         // Set other attributes using base class's set method
    }
    
	//! Rule of Three
    Book::~Book()
    {
         delete[]this->m_author;
    }

    Book::Book(const Book& that) : Publication(that)
    {
        this->m_author = nullptr;
        *this = that;
    }

    Book& Book::operator=(const Book& that)
    {
        if (this != &that)
        {
            Publication::operator=(that);
            delete[]this->m_author;
            
            if (that.m_author)
            {
                this->m_author = new char [strlen(that.m_author) + 1];
                strcpy(this->m_author, that.m_author);
            }
            else
            {
                this->m_author = nullptr;
            }
        } 
        return *this;
    }

	//! Methods
	char Book::type()const
    {
        //todo: Returns the character "B".
        return 'B';
    }

	std::ostream& Book::write(std::ostream& os) const
    {
        //todo:
        /*
        First, it will invoke the write of its Base class.
        If the incoming argument is a console IO object.
        writes a single space
        writes the author's name in SDDS_AUTHOR_WIDTH spaces. If the author's name is longer than the SDDS_AUTHOR_WIDTH value, it will cut it short and writes exactly SDDS_AUTHOR_WIDTH characters. Note that this should not modify the author's name.
        writes " |"
        If the incoming argument is not a console IO object
        writes a tab character '\t'
        writes the author's name
        returns the incoming ostream.
        */
        Publication::write(os);
        if (conIO(os)) 
        {
            os << ' ';
            if (m_author and strlen(m_author) > SDDS_AUTHOR_WIDTH) 
            {
                os.write(m_author, SDDS_AUTHOR_WIDTH);
            } 
            else 
            {
                os.width(SDDS_AUTHOR_WIDTH);
                os.setf(ios::left);
                os << this->m_author;
                os.unsetf(ios::left);
            }
            os << " |";
        } 
        else 
        {
            os << '\t';
            os << this->m_author;
        }
        return os;
    }

	std::istream& Book::read(std::istream& is)
    {
        //todo: Read the author name in local variables before setting the attribute to any value. (to make it easier lets assume the author's name can not be more than 256 characters)
        /*
        First, invoke the read of the Base class.
        Free the memory held for the author's name
        If the incoming argument is a console IO object
        ignore one character (skip the '\n')
        prompt "Author: "
        read the author's name
        If the incoming argument is not a console IO object
        ignore the tab character
        read the author's name
        Then if the incoming istream object is not in a fail state, dynamically hold the author's name in the char pointer attribute of the book class.
        At the end return the incoming istream object.
        
        */
        Publication::read(is);
        delete[] m_author;
        m_author = nullptr;
        // Read author's name
        char that_author[257]{};
        if (conIO(is))
        {
            is.ignore(3000,'\n');
            cout << "Author: ";
            is.getline(that_author, 257, '\n');
        }
        else
        {
            is.ignore();
            is.get(that_author, 257, '\n');
        }
        this->m_author = new char[strlen(that_author) + 1];
        strcpy(this->m_author, that_author);
        return is;
    }

	void Book::set(int member_id) 
    {
        //todo: invoke the set of the base class to set the member id, reset the date to the current date.
        Publication::set(member_id);
        resetDate();
    }

	Book::operator bool() const
    {
        //todo: return true if the author's name exists and is not empty and the base class's operator bool() has returned true.
        return ((m_author && m_author[0] != '\0' and Publication::operator bool()));
    }
}
