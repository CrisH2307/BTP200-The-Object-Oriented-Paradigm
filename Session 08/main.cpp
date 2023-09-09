//! Member operator
/*
Operations:
The keyword operator identified an overloaded operation.
The signature of a member function that overloads an operator
consist of the keyword, the symbol and type of the right operand
within parentheses. Left operand is the current obj

Overload in 2 ways
Member operators: Part of the class definition with direct access to the class representation
Helper operators: Supporting the class, without direct access to its representation

Promotion or Narrowing of Argument
If the compiler cant find an exact match to an operation's signature
the compiler will attempt a rather complicated selection process to find 
an optimal fit, promoting or narrowing the operand value into a related type

Good design Practice:
Programmers expect an operator to perform its operation in a way similar if not
identical to the way that the operator performs its operation on any fundamental
type as definedby the core language
*/


#include "main.h"

//! Operator Overloading using member functions 
/*
Money::Money(int dollars, int cents) : dollars{ dollars }, cents{ cents } {}

Money::Money(int total) : dollars{ total / 100 }, cents{ total % 100 } {}


//----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//----WRITE YOUR METHOD DEFINITIONS BELOW THIS LINE----
bool operator==(const Money& mny)const
{
	bool ok = false;
	if (this->dollars == mny.dollars and this->cents == mny.cents)
	{
		ok = true;
	}
	return ok; 

	// or 
	return dollars == mny.dollars and cents == mny.cents;

}
bool operator!=(const Money& mny)const
{
	return !(mny == *this);
}

*/
//! Operator Overloading using member functions 
//Money operator+(const Money& left, const Money& right)
//{
//	int total;
//	total = (left.dollars + right.dollars) * 100;
//	total += left.cents + right.cents;
//
//	return total;
//}

// Overloading Operators
 // operators.cpp

#include <iostream>
using namespace std;


//class Student {
//    int no;
//    float grade[NG];
//    int ng;
//    void set(int, const float*, int);
//public:
//    Student();
//    Student(int, const float*, int);
//    void display() const;
//    Student& operator+=(float g);
//};

Student::Student() 
{

    no = 0;
    ng = 0;
}

Student::Student(int sn, const float* g, int ng_) 
{
    set(sn, g, ng_);
}

void Student::set(int sn, const float* g, int ng_) 
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
        no = 0;
        ng = 0;
    }
}

void Student::display() const {
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



/*
Binary Operator:
Consists of one operator(+=) and two operands (Student).
In a binary operator, the left operand is the current obj and
the member function takes one explicit parameter: The right side operand

    Declaration:
        return_type operator symbol (type [identifier])
        ex: Student& operator *=(double gpa);

--> return_type is the type of the evaluated expression
    operator identifies the function as an operation
    symbol specifies the kind of operation
    type is the type of the right operand
    identifier is the right operand's name 
*/
Student& Student::operator+=(float g)
{
    if (no != 0 && ng < NG && g >= 0.f && g <= 100.f)
        grade[ng++] = g;
    return *this;
}



/*
Unary Operator:
Consists of one operator and one operand.
The left operand of a unary member operator is the current obj.
The operator does not take any explicit parameters

    Declaration:
    return_type operator symbol()

--> return_type is the type of the evaluated expression.  
    operator identifies an operation
    symbol identifies the kind of operation.


Pre-fix operators:
Overload the pre-fix increment/decrement operators to increment/decrement
the current object and return a reference to its updated value.
     Type& operator++()  or  Type& operator--()

Post-fix operators:
Overload the post-fix operators to increment/decrement the currenct obj
after returning its value.
     return_type operator++(int)  or  Type operator--(int)

*/
Student& Student::operator++() // Pre-fix
{
    for (int i = 0; i < ng; i++)
        if (grade[i] < 99.0f) grade[i] += 1.f;
    return *this;
}

Student Student::operator++(int)  // Post-fix
{
    Student s = *this;      // Save the original
    ++(*this);              // Call the pre-fix operator
    return s;               // Return the original
}


/*
Conversion Operator: 
Define implicit conversions to different types, including fundamental types

Bool:
Returns true if the object has valid data and false if it's in a safe empty state
*/
Student::operator bool() const // Bool
{ 
    return no != 0; 
}



/*
Cast Operator:
Defines the casting operation for a class type in terms of a single-argument constructor.
This overloaded constructor defines the rule for casting a value of its param type 
to the class type, as well as constructing an object from an argument of the param type
*/
//Student::Student(int sn)
//{
//    float g[] = { 0.0f };
//    set(sn, g, 0);
//}

/*
Explicit:
Declaring several single-argument constructors raise the possibility of potential
ambiguites in automatic conversions from one type to another. Limiting the number 
of single-argument constructors in a class definition helps avoid such potential ambiguities
*/



/*
Temporary Objects:
Create temporary objects in a variety of situations. 
A temporary object has no name and is destroyed as the last step in evaluating
the expression that contains its creation point

int main () {
     Student harry(975), nancy;

     harry.display();      //-> 975:
     nancy = Student(428); // temporary Student object
     nancy.display();      //-> 428:
 }

*/


//int main() {
//    float gh[] = { 89.4f, 67.8f, 45.5f };
//    Student harry(1234, gh, 3);
//    harry.display();
//    harry += 78.23f;
//    harry.display();
//}
