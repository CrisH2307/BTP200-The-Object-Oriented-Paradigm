/*
*****************************************************************************
                              Line.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

/*
Line: encapsulates a horizontal line on a screen with the label
(this concrete class draws a labelled line)
*/

#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include <iostream>
#include "LblShape.h"
namespace sdds
{
    class Line: public LblShape
    {
        //todo: Create a member variable called m_length to hold 
        // the length of the Line, i.e., number of characters in a line.
        int m_length;

    public:
        Line();
        Line(const char* label, int len);
        //~Line();

        void getSpecs(std::istream& is) override;
        void draw(std::ostream& o)const override;
    };

}
#endif


