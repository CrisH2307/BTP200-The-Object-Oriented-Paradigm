//! Q-04
// foo.cpp
#include "foo.h"
#include "foo.h"

void Foo::set(short val)
{
	 if (val < 0)
		this->m_val -= val;
	 else
		this->m_val += val;
}