//! Q-10
// main.cpp
 #include <iostream>
 #include "foo.h"
 #include "foo.h"

int main()
{
	Foo theFoo;
	// Expected output: 50
	std::cout << theFoo.m_data << std::endl;

	Foo another(75);
	// Expected output: 75
	std::cout << another.m_data << std::endl;
}

/*
Problem: Ambiguity when creating the instance theFoo. Because of the default
value for the param

Fix:

*/