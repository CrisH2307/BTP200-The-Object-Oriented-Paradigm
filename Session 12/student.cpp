//! Functions in a Hierarchy

/*
Shadowing
A member function of a derived class shadows the base class member function with the same identifier
          Base::identifier(arguments);
Base identifies the class to which the shadowed function belongs

Exposing an Overload member function with the same identifier but a different signatue, we insert a 'using'
declaration into the definition of the derived class. 
A member function of a derived class shadows an identically named member function of a base class
        using Base::identifier;

Derived Contructors:
A derived class does not inherit a base class contructor by default. If we dont declare a constructor in 
our definition of the derived class, the compiler inserts an empty no-argument constructor by default
4 Steps to construct a instance (Construction Process)
1. Construct the base class portion of the complete obj
    + Allocate memory for the instance variables in the order of their declaration
    + Execute the base class constructor
2. Construct the derived class portion of the obj
    + Allocate memory for the instance variables in the order of their declaration
    + Execute the derived class constructor

Passing Arguments to a Base Class Contructor
Each contructor of a derived class, other than the no-argument constructor, receives in its params all
of the values passed by the client
        Derived(params) : Base (arguments)

Inheriting Base Class Constructors:
Where the derived class constructor doesnt execute any logic on the instace variables of the derived class and only passes
to the base class contructor values received from the client
        using Base::Base;


Derived Destructors:
Derived class doesnt inherit the destructor of its base class. Destructors execute in opposite order to the order of their obj's construction
Destruction Process
1. Execute derived class Destructor
2. Deallocate derived class memory
3. Execute base class destructor
4. Deallocate base class memory

Derived Helper Operators:
Helper functions support the classes identified by their parameter types. 
Each helper function is dedicated to the class that is supports
*/

// Student.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "student.h"

using namespace std;

Person::Person() {
    cout << "Person()" << endl;
    name[0] = '\0';
}


void Person::set(const char* n) {
    cout << "Person(const char*)" << endl;
    strncpy(name, n, NC);
    name[NC] = '\0';
}

Person::Person(const char* nm) {
    strncpy(name, nm, NC);
    name[NC] = '\0';
}



Person::~Person() {
    std::cout << "Leaving " << name << std::endl;
}


void Person::display(std::ostream& os) const {
    os << name << ' ';
}

void Person::display(ostream& os, const char* msg) const {
    os << msg << name << ' ';
}

istream& operator>>(istream& is, Person& p) {
    char name[NC + 1];
    cout << "Name: ";
    is.getline(name, NC + 1);
    p = Person(name);
    return is;
}

std::ostream& operator<<(ostream& os, const Person& p) {
    p.display(os);
    return os;
}

Student::Student() {
    no = 0;
    ng = 0;
}

Student::Student(int n) {
    cout << "Student()" << endl;
    float g[] = { 0.0f };
    *this = Student(n, g, 0);
}

Student::Student(int sn, const float* g, int ng_) {
    cout << "Student(int, const float*, int)" << endl;
    bool valid = sn > 0 && g != nullptr && ng_ >= 0;
    if (valid)
        for (int i = 0; i < ng_ && valid; i++)
            valid = g[i] >= 0.0f && g[i] <= 100.0f;

    if (valid) {
        // accept the client's data
        no = sn;
        ng = ng_ < NG ? ng_ : NG;
        for (int i = 0; i < ng; i++)
            grade[i] = g[i];
    }
    else {
        *this = Student();
    }
}

Student::Student(const char* nm, int sn, const float* g, int ng_) : Person(nm) {
    bool valid = sn > 0 && g != nullptr && ng_ >= 0;
    if (valid)
        for (int i = 0; i < ng_ && valid; i++)
            valid = g[i] >= 0.0f && g[i] <= 100.0f;

    if (valid) {
        // accept the client's data
        no = sn;
        ng = ng_ < NG ? ng_ : NG;
        for (int i = 0; i < ng; i++)
            grade[i] = g[i];
    }
    else {
        *this = Student();
    }
}

Student::~Student() {
    std::cout << "\nLeaving " << no << std::endl;
}

void Student::display(ostream& os) const {
    if (no > 0) {
        Person::display(os);
        os << no << ":\n";
        os.setf(ios::fixed);
        os.precision(2);
        for (int i = 0; i < ng; i++) {
            os.width(6);
            os << grade[i] << endl;
        }
        os.unsetf(ios::fixed);
        os.precision(6);
    }
    else {
        os << "no data available" << endl;
    }
}

void Student::read(istream& is) {
    char name[NC + 1]; // will hold the student's name
    int no;            // will hold the student's number
    int ng;            // will hold the number of grades
    float grade[NG];   // will hold the grades

    std::cout << "Name: ";
    is.getline(name, NC + 1);
    cout << "Student Number : ";
    is >> no;
    cout << "Number of Grades : ";
    is >> ng;
    if (ng > NG) ng = NG;
    for (int i = 0; i < ng; i++) {
        cout << "Grade " << i + 1 << " : ";
        is >> grade[i];
    }

    // construct a temporary Student
    Student temp(name, no, grade, ng);
    // if data is valid, the temporary object into the current object 
    if (temp.no != 0)
        *this = temp;
}

istream& operator>>(istream& is, Student& s) {
    s.read(is);
    return is;
}

ostream& operator<<(ostream& os, const Student& s) {
    s.display(os);
    return os;
}