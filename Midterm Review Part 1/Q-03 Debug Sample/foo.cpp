 //! Q-03
// foo.cpp
 #include "foo.h"
 #include "foo.h"
 
void Foo::set(short val = 100)
{
    if (val < 0)
        val *= -1;
    this->m_val += val;
}

/*
Problem: void Foo::set(short val = 100)
_ In header file, the set function has already defined the default param val = 100
In the implementation file, we dont need to redefined.
_ Default parameter are specified in the function declaration (header file) and
SHOULD NOT be repeated in the implementation file

Fix: void Foo::set(short val = 100) --> void Foo::set
*/