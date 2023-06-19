//! Q-16
//! 
// main.cpp
 #include "foo.h"
 #include "foo.h"

int main()
{
	Foo theFoo(300);
}

/*
Problem: Undefined destructor ~Foo(). It calls destructor in an infinite loop
Fix:	 Delete the loop inside constructor
*/