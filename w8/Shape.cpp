/*
*****************************************************************************
                              Shape.cpp
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
    // void Shape::draw(std::ostream& o) const
    // {
    //     //todo: Does not return anything and receives a reference to ostream as an argument. 
    //     // This pure virtual function can not modify the current object.
    // }

    // void Shape::getSpecs(std::istream& i)
    // {
    //     //todo: Does not return anything and receives a reference to istream as an argument.
    // }

    Shape::~Shape()
    {
        //todo: Create a virtual empty destructor for the shape interface.
        // this guarantees that any dynamically allocated derived class from the shape interface 
        // pointed by a base class pointer will be removed properly from memory when deleted.
    }

    std::ostream& operator<<(std::ostream& os, const Shape& that)
    {
        that.draw(os);
        return os;
    }

    std::istream& operator>>(std::istream& is, Shape& that)
    {
        that.getSpecs(is);
        return is;
    }
}
