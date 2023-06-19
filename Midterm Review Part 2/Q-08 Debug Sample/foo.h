// foo.h
#ifndef FOO_H
#define FOO_H

 // structure that should store only numbers in the interval [0, 100]
struct Foo
{
	long m_data;
public:
	Foo() { m_data = 50; }
	Foo(long data)
	{
		if (0 <= data && data <= 100)
			m_data = data;
		else
			//*this = Foo();
			m_data = 50;		//! Solution: Assign the default value
	}
};
#endif