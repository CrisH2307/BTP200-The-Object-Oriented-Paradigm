//! DYNAMIC MEMORY SAMPLES
//! 
//! Sample 1
//! 
#include <iostream>

// Book.h
namespace culture
{
	class Book
	{
		char m_title[128]; // title
		int m_year;       // publication year,   Error 2: Never use auto inside the declaration

	public:
		Book();
		Book(const char* title);
		~Book();
	};
}