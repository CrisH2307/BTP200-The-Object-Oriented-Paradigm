// foo.h
#ifndef FOO_H
#define FOO_H  //! Solution

class Foo
{
    short m_val = 10;

public:
    void set(short val);
};

#endif


/*
Problem: Missing #define FOO_H
_ Redefinition of the class Foo beacuse the header guard is not completed
*/