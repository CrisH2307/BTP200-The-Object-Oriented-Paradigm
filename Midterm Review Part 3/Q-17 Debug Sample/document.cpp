// document.cpp
#include <iostream>
#include <cstring>
#include "document.h"
using namespace std;

namespace cpp
{
    Document::Document(const char* title, const char* author)
    {
        delete[] m_title;           
        if (title != nullptr && author != nullptr)
        {
            m_title = new char[strlen(title) + 1];

            strcpy(m_title, title);
            strcpy(m_author, author);
        }
        else
        {
            m_title = nullptr;
            *m_author = '\0';
        }
    }

    Document::~Document()
    {
        delete[] m_title;
        m_author[0] = '\0';         //! Solution: Deallocate author
    }
}