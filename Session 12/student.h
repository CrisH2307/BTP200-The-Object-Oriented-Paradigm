// Student.h

#include <iostream>
const int NC = 30;
const int NG = 20;

class Person {
    char name[NC + 1];
public:
    Person();                                           //! Construction of Derived Class
    void set(const char* n);
    Person(const char*);                                //! Passing arguments to a Base Class Constructor
    void display(std::ostream&) const;
    void display(std::ostream&, const char*) const;     //! Exposing an Overload member function
    ~Person();                                          //! Destruction of Derived Class
};  
//! Derived Helper Function
std::istream& operator>>(std::istream&, Person&);
std::ostream& operator<<(std::ostream&, const Person&);

class Student : public Person {
    int no;
    float grade[NG];
    int ng;
public:
    Student();
    Student(int);
    Student(int, const float*, int);
    Student(const char*, int, const float*, int);
    void read(std::istream&);
    void display(std::ostream&) const;
    using Person::display;
    ~Student();
};

class Instructor : public Person {
public:
    using Person::Person;
};
std::istream& operator>>(std::istream&, Student&);
std::ostream& operator<<(std::ostream&, const Student&);
