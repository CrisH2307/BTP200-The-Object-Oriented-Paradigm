 //! Q-02
 //! 
class Foo
{
    short m_val = 10;

public:
    Foo& operator++()
    {
        ++m_val;
        return *this; //! Returns current instance by a reference --> OK 
    }
    Foo& operator++(int data)
    {
        Foo oldVal = *this;
        ++(*this);
        return oldVal;
    }
};

/*
Problem: Foo& operator++(int data)
_ Postfix perator implementation returns the global obj by a reference.
In the post increment operator, you need to return a copy of the original obj,
not a reference.

Fix: Foo& --> Foo
*/