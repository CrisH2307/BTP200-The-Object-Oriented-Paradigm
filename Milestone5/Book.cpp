/*
Final Project Milestone 5
Filename: Book.cpp
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
        char author[256] = { 0 };
        Publication::read(is);
        if (m_author) {
            delete[] m_author;
            m_author = nullptr;
        }

        if (conIO(is)) {
            is.ignore();
            cout << "Author: ";
            is.get(author, 256);
        }
        else {
            is.ignore(1000, '\t');
            is.get(author, 256);
        }

        if (is) {
            m_author = new char[strlen(author) + 1];
            strcpy(m_author, author);
        }

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
