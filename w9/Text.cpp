/*
*****************************************************************************
							  Text.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Text.h"
#include "cstring.h"
using namespace std;
namespace sdds 
{ 
    //==============PRIVATE====================//
   int Text::getFileLength() const 
   {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) 
      {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   //===============PROTECTED==================//
   const char& Text::operator[](int index)const
   {
   //todo:
   /*
   This index operator provides read-only (unmodifiable reference) access to the index-indexed element of the dynamic array, 
   pointed to by m_content. This operator should be accessible from the classes derived from Text, but not from the client code or main function.
   The behavior of the operator is not defined if the index goes out of bounds.
   */
        return this->m_content[index];

   }

   //================PUBLIC====================//
    
   Text::Text(const char* filename)
   {
      if (filename)
      {
         this->m_filename = new char[strLen(filename) + 1];
         strCpy(m_filename, filename);
         this->m_content = nullptr;
         read();
      }
      else
      {
         this->m_content = nullptr;
         this->m_filename = nullptr;
      }
   }

   Text::Text(const Text& that)   : Text(that.m_filename)
   {
        *this = that;
   }

	Text& Text::operator=(const Text& that)
   {
      if (this != &that)
      {
         delete[] this->m_filename;
         this->m_filename = nullptr;

         delete[] this->m_content;
         this->m_content = nullptr;

         if (that.m_filename)
         {
            this->m_filename = new char[strLen(that.m_filename) + 1];
            strCpy(this->m_filename, that.m_filename);
         }

         if (that.m_content)
         {
            this->m_content = new char[strLen(that.m_content) + 1];
            strCpy(this->m_content, that.m_content);
         }
      }

   return *this;
   }

   Text::~Text()
   {
      delete[] this->m_filename;
      this->m_filename = nullptr;

      delete[] this->m_content;
      this->m_content = nullptr;

   }

   void Text::read()
   {
      //todo:
      /*
      First, reads the file length (total characters in the file) by calling getFileLength() function and allocates
      memory to hold the total characters in the file plus extra null character for null termination of the string.
      Then it opens the file and reads its contents character-by-character into the newly allocated memory (character array) 
      and terminates the array with the null character.
      */
     int len = getFileLength();

     if (len == 0)
     {
         this->m_content = nullptr;
         return;
     }

     this->m_content = new char[len + 1];

     ifstream f(this->m_filename);

     if (f.is_open())
     {
         char c;
         int i = 0;

         while (f.get(c))
         {
            this->m_content[i] = c;
            i++;
         }
         this->m_content[i] = '\0';
         f.close();
     }
     
     else
     {
      delete[] this->m_content;
      this->m_content = nullptr;
     }
   }
   
   void Text::write(std::ostream& os)const
   {
      //todo: This virtual function will insert the content of the Text class into the ostream if m_content is not nullptr.
      if (this->m_content != nullptr)
      {
         os << this->m_content;
      }
   }

    //===============HELPERFUNC===============//
   ostream& operator<<(ostream& o, const Text& that)
   {
      that.write(o);
      return o;
   }
}