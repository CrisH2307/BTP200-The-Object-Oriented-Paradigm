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
LblShape: encapsulates a shape that can be labelled
(An abstract base class that represents a labelled shape)

Add a character pointer member variable called m_label and initialize it to nullptr. This member variable will be used to hold the 
dynamically allocated label for the Shape.
*/

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include <iostream>
#include "Shape.h"
namespace sdds
{
    class LblShape: public Shape
    {
        char* m_label; 

    protected:
        const char* label()const;

    public:
        LblShape();
        LblShape(const char* label);

        //! Rule of Three
        LblShape(const LblShape& that) = delete;
        LblShape& operator=(const LblShape& that) = delete;
        virtual ~LblShape();

        void getSpecs(std::istream& is) override;
    };

}
#endif

