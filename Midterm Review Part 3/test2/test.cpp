// Book.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include "test.h"

using namespace std;

namespace culture
{  
	// Solution: Default constructor
	Book::Book()
	{
		m_title[0] != '\0'; // Whenever the char attribute contains array size, we dont need to allocate memory and define the name is nullptr
	}

	Book::Book(const char* title)   // Error 1: From the header file, the parameter was const char, when we implement on the source file, we have to declare with the same type
	{
		for (int i = 0; i < strlen(title); ++i)
		{
			m_title[i] = title[i];
		}
			m_year = 2020;
	}

	Book::~Book() 
	{
		//m_title = nullptr;   // Error 3: Destructor is the special method that releasing the memory and resources held by the obj, not modifying the member variable.
		delete[] m_title;
	}
}