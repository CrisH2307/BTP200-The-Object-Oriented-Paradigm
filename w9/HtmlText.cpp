/*
*****************************************************************************
							  HtmlText.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "Text.h"
#include "cstring.h"
#include "HtmlText.h"
namespace sdds 
{
    HtmlText::HtmlText(const char* filename, const char* title) : Text(filename)
    {
        this->m_title = nullptr;
        if (title != nullptr)
        {
            this->m_title = new char[strLen(title) + 1];
            strCpy(this->m_title, title);
        }
    }

    HtmlText::HtmlText(const HtmlText& that) : HtmlText(that.m_title)
    {
        *this = that;
    }

	HtmlText& HtmlText::operator=(const HtmlText& that)
    {
        if (this != &that)
        {
            if (that.m_title)
            {
                Text::operator=(that);
                delete[]this->m_title;
                this->m_title = nullptr;
                this->m_title = new char[strLen(that.m_title) + 1];
                strCpy(this->m_title, that.m_title);
            }
        }
        return *this;
    }
	HtmlText::~HtmlText()
    {
        delete[]this->m_title;
        this->m_title = nullptr;

    }
    void HtmlText::write(std::ostream& os)const
    {
        bool those = false;
        int these = 0;
        os << "<html><head><title>";

        if (this->m_title != nullptr)
            os << this->m_title;
        else
            os << "No Title";

        os << "</title></head>\n<body>\n";

        if (this->m_title != nullptr)
            os << "<h1>" << this->m_title << "</h1>\n";

        
        while ((*this)[these] != '\0')
        {
            char c = (*this)[these];
            switch (c)
            {
            case ' ':
                if (those)
                    os << "&nbsp;";
                else
                {
                    those = true;
                    os << ' ';
                }
                break;
            case '<':
                os << "&lt;";
                those = false;
                break;
            case '>':
                os << "&gt;";
                those = false;
                break;
            case '\n':
                os << "<br />\n";
                those = false;
                break;
            default:
                those = false;
                os << c;
            }
            these++;
        }

        os << "</body>\n</html>";
    }

}
