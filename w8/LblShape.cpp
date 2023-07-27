/*
*****************************************************************************
                              LblShape.cpp
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
#include <string>
#include "Rectangle.h"
#include "LblShape.h"
#include "Shape.h"
#include "Line.h"

using namespace std;
namespace sdds
{
    const char* LblShape::label() const
    {
        //todo: Add a query called label that returns the unmodifiable value of m_label member variable.
        return this->m_label; // Return the unmodifiable value of m_label
    }

    LblShape::LblShape()//: m_label(nullptr)   // Constructor initializes m_label to nullptr
    {
        //todo: Sets the label pointer to nullptr. (You don't need to do this if the m_label is
        //      already initialized to nullptr in its declaration in the class definition)

        this->m_label = nullptr;
    }


    LblShape::LblShape(const char* label) :m_label(nullptr)
    {
        //todo: Receives C-style null-terminated string as unmodifiable parameter, allocates memory 
        //      large enough to hold the received string and makes m_label point to it. 
        //      Finally, copies the received string to the allocated memory.

        if (label != nullptr and label[0] != '\0')
        {
            this->m_label = new char[strlen(label) + 1];
            strcpy(this->m_label, label);
        }
    }

    LblShape::~LblShape()
    {
        //todo: Deletes the memory pointed to by m_label member variable.
        delete[]this->m_label;
    }

    void LblShape::getSpecs(std::istream& is)
    {
        //todo: Reads a comma-delimited C-style null-terminated string form istream:
        /*
        Override the Shape::getSpecs pure virtual function to receive a C-style string (a label)
        from istream up to the ',' character (and then extract and ignore the comma). Afterward,
        follow the same logic as was done in the one argument constructor; allocate memory large
        enough to hold the string and copy the string into the allocated memory.
        */

        if (this->m_label != nullptr and this->m_label[0] != 0)
        {
            delete[]m_label;
            m_label = nullptr;
        }
        string Specs;

        getline(is, Specs, ',');

        this->m_label = new char[Specs.length() + 1]; // Allocate memeory
        strcpy(this->m_label, Specs.c_str());


    }
}
