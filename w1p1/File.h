/*
*****************************************************************************
                             File.h
Full Name  : Xuan Khang Huynh (Cris Huynh)
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_FILE_H // replace with relevant names, each header should have it's own header guard
#define SDDS_FILE_H

// Your header file content goes here
namespace sdds
{
    struct ShoppingRec;

    const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";

    bool openFileForRead(void);

    bool openFileForOverwrite(void);

    void closeFile(void);

    bool freadShoppingRec(ShoppingRec* rec);

    void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif