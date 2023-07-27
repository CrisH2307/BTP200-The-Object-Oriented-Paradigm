/*
*****************************************************************************
							  HtmlText.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds 
{
   class HtmlText :  public Text 
   {
      char* m_title;

   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      HtmlText(const HtmlText& that);
		HtmlText& operator=(const HtmlText& that);
		~HtmlText();
      virtual void write(std::ostream& os)const override;
   };
}
#endif // !SDDS_HTMLTEXT_H__
