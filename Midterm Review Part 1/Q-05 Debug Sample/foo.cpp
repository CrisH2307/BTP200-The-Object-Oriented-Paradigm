//! Q-05
// foo.cpp
#include <cstring>
#include "foo.h"
#include "foo.h"

bool Foo::setStr(const char* name)
{
	if (name != nullptr)
	{
		if (name[0] != '\0')
		{
			std::strncpy(m_str, name, 32);
			m_str[31] = '\0';
			return true;
		}
	}
	else
		return false;
}

/*
Problem: Unmatched parameter from the header to the implementation

Fix: 
foo.h
	bool setStr(const char* strStr); --> bool setStr(const char* name);

*/