/*
*****************************************************************************
                              Line.cpp
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
    Line::Line() : LblShape()
    {
        //todo: Sets the m_length member variable to zero, and invokes the default constructor of the base class.
        this->m_length = 0;
    }

    Line::Line(const char* label, int len) : LblShape(label), m_length(len)
    {
        //todo: Receives a C-style null-terminated string and a value for the length of the line 
        // (number of characters to be printed as line). Passes the string to the constructor of the
        // base class and sets the m_length member variable to the value received through second param
        if (len < 0)
        {
            this->m_length = len;
        }
    }

    //Line::~Line()
    //{
    //    // This class has no destructor implemented.
    //}

    void Line::getSpecs(std::istream& is)
    {
        //todo: Reads comma-separated specs of the Line from istream.
        /*
        This function overrides the getSpecs function of the base class as follows.
        First, it will call the getSpecs function of the base class to read the string,
        then it will read the value of the m_length attribute from the istream argument,
        and then it will ignore the rest of the characters up to and including the newline character '\n'.
        */
        LblShape::getSpecs(is);
        is >> this->m_length;
        is.ignore(10000, '\n');
    }

    void Line::draw(std::ostream& o) const
    {
        //todo: This function overrides the draw function of the base class.

        /*
        If the m_length member
        variable is greater than zero and the label() is not nullptr, this function will
        first print the label() and then go to the new line. Afterwards it keeps printing the '='
        (assignment character) for the number of times equal to value carried by m_length.
        Otherwise, it will take no action.

        For example, if the C-style string returned by the label query is "Separator" and the length is 40,
        the draw function should insert the following into ostream:

        Separator
        ========================================
        */
        if (this->m_length > 0 and label() != nullptr)
        {
            o << label() << endl;

            for (int i = 0; i < this->m_length; ++i)
            {
                o << "=";
            }
        }
    }
}
