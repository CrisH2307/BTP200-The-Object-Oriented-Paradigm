//! Helper Function

/*
Free Helpers:
A global function that supports a class
A free or loosely coupled helper function that obtains all of its information from the
public member functions og the class that is supports. A free helper function doesn't
require access to the private members of its class. The coupling between a free helper 
function and its class is minimal, which is an ideal design solution
    
The Cost of Upgrading Freedom:
Free helper functions use public queries to access information that is otherwise inacessible
If we add data members to the class, we may also need to add a query to access its value
As we add data members, the class definition grows with new queries. AKA: Class bloat

Friendship:
Grants helper functions access to the private members of a class. By granting friendship status
a class lets a helper function access to any of its private members: data members for member function
It minimize class bloat
       friend Type identifier (type [,type,...]);

The cost of Friendship
A class definition that grants friendship to a helper function to alter the values of its
private data members. Granting friendship pierces encapsulation
We grant friendship judiciously only to helper functions that require both read and write 
access to the private data members. Where read-only access is all that a helper function 
needs, using queries is probably more advisable
It is the strongest relationship that a class can grant an external entity

Friendly Classes:
One class can grant another class access to its private members. 
        friend class Identifier;

Friendship is neither reciprocal, transitive nor exclusive. One calss is a friend of another class
doesnt mean that the latter is a friend of the formet. A class is a friend of another class
and that other class is a friend of yet another class doesnt mean that the latter class is
a friend of either of them. A friend of one class may be a friend of any other class
*/

#include <iostream>
using namespace std;
#include "main.h"

Student::Student() 
{
    no = 0;
    ng = 0;
}

Student::Student(int n) 
{
    *this = Student(n, nullptr, 0);
}

Student::Student(int sn, const float* g, int ng_) 
{
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

void Student::display() const 
{
    if (no > 0) {
        cout << no << ":\n";
        cout.setf(ios::fixed);
        cout.precision(2);
        for (int i = 0; i < ng; i++) {
            cout.width(6);
            cout << grade[i] << endl;
        }
        cout.unsetf(ios::fixed);
        cout.precision(6);
    }
    else {
        cout << "no data available" << endl;
    }
}

bool areIdentical(const Student& lhs, const Student& rhs) 
{
    bool same = lhs.getStudentNo() == rhs.getStudentNo() && lhs.getNoGrades() == rhs.getNoGrades();

    for (int i = 0; i < lhs.getNoGrades() && same; i++)
    {
        same = lhs.getGrade(i) == rhs.getGrade(i);
    }
    return same;
}
