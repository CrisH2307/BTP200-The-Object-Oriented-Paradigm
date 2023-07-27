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
Rectangle: encapsulates a rectangle on the screen that can be labelled
(this concrete class draws a rectangle with a label inside).
*/

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include <iostream>
#include "LblShape.h"
namespace sdds
{
    class Rectangle: public LblShape
    {
        int m_width;
        int m_height;

    public:
        Rectangle();
        Rectangle(const char* label, int width, int height);
        //~Rectangle();
        void getSpecs(std::istream& is) override;
        void draw(std::ostream& os)const override;
    };

}
#endif

