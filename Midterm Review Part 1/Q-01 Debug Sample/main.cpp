//! Q-01
//! Breakdown + Fix
class Foo
{
    short m_val = 10;  // Member variable m_val with a default value of 10

public:
    Foo(short val = 5)  // Constructor with a default value of 5 for parameter val
    {
        m_val = val;  // Assigning val to the member variable m_val
    }

   //  Foo& operator+(const Foo& other) const  // Overloading the + operator as a member function
    Foo operator+(const Foo& other) const  //! Solution
    {
        Foo result = *this;  // Creating a copy of the current object using the copy constructor
        result.m_val += other.m_val;  // Adding the value of other.m_val to result.m_val
        return result;  // Returning the result of the addition
    }

    ~Foo() { }  // Destructor
};

/*
Problem: Foo& operator+(const Foo& other) const
_ The implementation that it provided returns a reference to a local variable 'result'.
When you return result by reference, u are returning the local variable that will be destroyed 
once the function scope ends.
_ Returning a reference to a local variable leads to undefined behavior because the obj being 
referenced will no longer exist

Fix: Foo& --> Foo

*/