//! Q-07
// foo.cpp
#include <cstring>
#include "foo.h"
#include "foo.h"


bool Foo::setStr(const char* name)
{
	if (name[0] != '\0' && name != nullptr)
	{
		std::strncpy(m_str, name, 32);
		m_str[31] = '\0';
		return true;
	}
	else
		return false;
}

/*
Problem: 'name' if conditions are wrong order. If the param is null
there is a crash on dereferencing the ptr
*/