/*
*****************************************************************************
                              searchNlist.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H
#include <iostream>
#include "Collection.h"

using namespace std;
namespace sdds
{
       // Search function template implementation
    template <typename CollectionType, typename KeyType>
    bool search(Collection<CollectionType>& collection, const CollectionType* array, size_t size, const KeyType& key)
    {
        bool that = false;

        for (size_t i = 0; i < size; ++i)
        {
            if (array[i] == key)
            {
                collection.add(array[i]);
                that = true;
            }
        }

        return that;
    }

    // listArrayElements function template implementation
    template <typename ElementType>
    void listArrayElements(const char* title, const ElementType* array, size_t size)
    {
        cout << title << endl;
        for (size_t i = 0; i < size; ++i)
        {
            cout << i + 1;
            cout << ": ";
            cout << array[i];
            cout << endl;
        }
    }
} // namespace sdds
#endif