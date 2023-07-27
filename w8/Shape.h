/*
*****************************************************************************
                              LblShape.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


/*
Shape: encapsulates a shape that can be drawn on the screen
(An interface, that is an abstract base class with only pure virtual functions)
*/

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>

namespace sdds
{
    class Shape
    {
    public:
        virtual void draw(std::ostream& o)const = 0;
        virtual void getSpecs(std::istream& i) = 0;
        virtual ~Shape();
    };
    std::ostream& operator<<(std::ostream& os, const Shape& that);
    std::istream& operator>>(std::istream& is, Shape& that);
}
#endif



