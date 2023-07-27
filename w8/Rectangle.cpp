/*
*****************************************************************************
                              Rectangle.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Rectangle.h"
#include "LblShape.h"
#include "Shape.h"
#include "Line.h"

using namespace std;
namespace sdds
{
    Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0)
    {
        //todo: Sets the width and height member variables to zero. It will also invoke the default constructor of the base class.
    }

    Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label)
    {
        //todo:Receives a C-style null-terminated string for the label, and two values for the width and height of the Rectangle through its arguments.
        /*
        Passes the the string to the constructor of the base class and sets the m_width and m_height member variables to the corresponding values received
        from the argument list. However if the m_height is less than 3 or m_width is less the length of the label() + 2 it will set the Rectangle object to
        an empty state.
        */
        this->m_height = height;
        this->m_width = width;
        int labelLen = strlen(LblShape::label());

        if (this->m_height < 3 and this->m_width < labelLen + 2)
        {
            this->m_width = 0;
            this->m_height = 0;
        }
    }

    //Rectangle::~Rectangle()
    //{
    //    // This class has no destructor implemented.
    //}

    void Rectangle::getSpecs(std::istream& is)
    {
        //todo: Reads comma-separated specs of the Rectangle from istream.
        /*
        This function overrides the getSpecs function of the base class as follows.
        First, it will call the getSpecs function of the base class, then it will read two
        comma-separated values from istream for m_width and m_length and then ignores the
        rest of the characters up to and including the newline character ('\n').
        */

        LblShape::getSpecs(is);
        char that;
        is >> this->m_width >> that >> this->m_height;

        is.ignore(20000, '\n');
    }

    void Rectangle::draw(std::ostream& os) const
    {
        //todo: This function overrides the draw function of the base class.
        /*
        If the Rectangle is not in an empty state, this function will draw a
        rectangle with a label inside as follows, otherwise, it will do nothing:

        First line:
        prints '+', then prints the '-' character (m_width - 2) times and then prints
        '+' and goes to newline.

        Second line:
        prints '|', then in (m_width-2) spaces it prints the label() left justified
        and then prints '|' and goes to new line.

        In next (m_height - 3) lines:
        prints '|', (m_width-2) spaces then prints '|' and goes to new line.

        Last line: exactly like first line.

        For example, if the string returned by the label query is "Container",
        the width is 30 and the height is 5, this function should insert the following into ostream:

        +----------------------------+
        |Container                   |
        |                            |
        |                            |
        +----------------------------+
        */
        if (this->LblShape::label() != nullptr && this->m_height != 0 and this->m_width != 0)
        {
            // First line
            os << "+";
            for (int i = 0; i < m_width - 2; ++i)
            {
                os << "-";
            }
            os << "+" << endl;

            // Second line
            os << "|";
            os.width(m_width - 2);
            os << left << label();
            os << "|" << endl;

            // Middle lines
            for (int i = 0; i < m_height - 3; ++i)
            {
                os << "|";
                os.width(m_width - 2);
                os << right << "";
                os << "|" << endl;
            }

            // Last line
            os << "+";
            for (int i = 0; i < m_width - 2; ++i)
            {
                os << "-";
            }
            os << "+";

        }

    }
}
