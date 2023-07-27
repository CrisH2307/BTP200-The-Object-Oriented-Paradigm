/*
*****************************************************************************
							  Text.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds 
{
   class Text 
   {
   private:
      char* m_filename ;
      char* m_content ;
      int getFileLength()const;    // Code provided in Text.cpp

   protected:
      const char& operator[](int index)const;

   public:
      Text(const char* filename=nullptr);

      //! The Rule of three
      // Implement the rule of three so the memory is managed properly in case of copying and assignment.		
      Text(const Text& that);
		Text& operator=(const Text& that);
		~Text();
      void read();
      virtual void write(std::ostream& os)const;
   };
    // prototype of insertion overload into ostream goes here
    std::ostream& operator<<(std::ostream& o, const Text& that);
}
#endif 

