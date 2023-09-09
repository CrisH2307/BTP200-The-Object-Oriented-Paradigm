//! Input and Output Operators


//! A composition is a relationship in which one class has another class
//! A association is a relationship in which one class uses another class

/*
		Codes ---* Course o--- Grading Scheme
					|
					V
				Hybrid Course

In this diagram, assiciations appear as star and compisitions as filled circles
+ Codes uses the Calendar
+ While Course has Course Code Class


Stream Library Overview
_ Based input/output library that supports the core language overload two operators for extracting values
 from an input stream and inserting values into an output stream
  + << -> Extract from an input stream   (cout << )
  + >> -> Insert into an output stream   (cin  >> )

Standard I/O
_ The 'iostream' system header file contains the definitions for streaming from and to standard devices.
Ex: #include <iostream>

istream class: For processing input from the standard input device
	+ cin - standard input

ostream class: For processing output to the standard output device
	+ cout - standard output
	+ cerr - standard error
	+ clog - standard log

File I/O
_ The 'fstream' system header file contains the definitons for streaming from and to files
Ex: #include <fstream>

ifstream class: For processing input from a file stream
ofstream class: For processing out to a file stream
fstream  class: For processing input from and output to a file stream


Design Considerations:
_ In overloading the insertion and extraction for our class types, good design suggests
	+ Providing flexibility in the selection of stream objs
	+ Resolving scope on classes and objs defined in header files
	+ Enabling cascading as implemented for fundamental types

_ A header files may be included alongside other header files written by other developers.
Purpose: Avoid conflicts between the header files included in an implementation file
       + Include system header files before custom header files
       + Insert namespace directives after all header files
       + Resolve the scope of any identifier in a header file at the identifier itself


Cascading: Supports enables concatenation of operations where the leftmost operand serves as
the left operand for evert operation in a compound expression
       cout << x << y << z << endl;

Cascaded sub-expressions:
       cout << x;
       cout << y;
       cout << z;
       cour << endl;
Requires that we return a modifiable reference to the left operand
Returning a modifiable reference from a function lets the client code use the 
return value as the left operand for the operator on its right.


Standard I/O Operators
_ The prototypes for the overloaded insertion and extraction operators for standard input and output
on objs of our own classes take the form
       std::istream& operator>>(std::istream&, Type&);
       std::ostream& operator<<(std::ostream&, const Type&);


File I/O Operators
_ The stream library doesnt predefine any file objs as instances of the file stream classes


File Connections
_ We can connect a file obj to a file for reading, writing or both. The obj's destructor closes the connection

Input File Obj
_ We define an instance of the std::ifstream class, this class includes a no-argument constructor 
_ To connect a file to an existing file obj, we call the open() member function on the obj

Outpur File Obj
_ We define an instance of the std::ofsteeam class (no-argument constructor). 
_ To connect a file to an existing file obj, we call the open() member function on the obj

Confirming a File connection
_ The is_open() member function called on the file obj returns the current state of the obj's conenction to a file

Streaming Fundamental Types:
The standard input/output library overloads the extraction and insertion operator for each 
fundamental type for the file stream class with a file objs as left operand

Reading From a file
Reads from a file under format control using the extraction operator in the same way as the 
standard input obj (cin) reads using the extraction operator

Writing to a File:
Writes to a file under format control using the insertion operator in the same way as the standard output
obj (cout, cerr, and clog) write using the insertion operator

String Class:
The examples in these notes have been limited to input data that fits within pre-allocated memory. 
The user determines the number of characters to enter and pre-allocation of the required memory is not possible
Problem: 
We only know how much memory to allocate for the comment after receiving in complete text. 
We cant allocate that memory at compile-time or run-time before accepting the comment.

Solution:
Using helper function getline()
    std::istream& getline(std::istream&, std::string&, char);
The first param receives a modifiable reference to the std::istream obj
The second param receives a modifiable reference to the std::string obj
The third param receives the character delimiter for terminating extraction (newline by default)

std::string::length() - returns the number of characters in the string
std::string::c_str() - returns the address of the C-style null-terminated version of the string

C-Style Example
1. define a string object to accept the input
2. extract the input using the std::getline() helper function
3. query the string object for the memory required
4. allocate dynamic memory for the requisite C-style null-terminated string
5. copy the data from the string object to the allocated memory
6. deallocate the allocated memory


Summary:
+ We associate our own classes with the iostream classes by overloading the extraction and insertion operators as helpers to those classes
+ The first parameter in the declaration of each overloaded operator is a modifiable reference to the stream object
+ The return type of each overloaded operator is a modifiable reference to the stream object, which enables cascading
+ The standard library includes overloaded extraction and insertion operators for file objects as left operands and fundamental types as right operands
+ An input file object is an instance of an ifstream class
+ An output file object is an instance of an ofstream class
+ The string class of the standard library manages the memory requirements for storing a user-defined character string of any length


*/

// Student.cpp

#include <iostream>             //! for std::ostream, std::istream
#include <fstream>
#include "main.h"
using namespace std;

int main()
{
    std::ofstream fout("output.txt");  // connects output.txt to fout for output, 

    if (!fout.is_open())
    {
        std::cerr << "File is not open" << std::endl;   //! Confirming a File connection
    }
    else {
        // file is open
        // ...

    }
}

Student::Student()
{
    no = 0;
    ng = 0;
}

Student::Student(int n) 
{
    *this = Student(n, nullptr, 0);
}

Student::Student(int sn, const float* g, int ng_, const string& c) {
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
        comment = c;
    }
    else {
        *this = Student();
    }
}

void Student::read(std::istream& is) {
    int no;          // will hold the student number
    int ng;          // will hold the number of grades
    float grade[NG]; // will hold the grades
    string comment;  // will hold comments

    cout << "Student Number : ";
    is >> no;
    cout << "Number of Grades : ";
    is >> ng;
    if (ng > NG) ng = NG;
    for (int i = 0; i < ng; i++) {
        cout << "Grade " << i + 1 << " : ";
        is >> grade[i];
    }
    is.ignore(); // extract newline
    cout << "Comments : ";
    getline(is, comment, '\n');

    // construct a temporary Student
    Student temp(no, grade, ng, comment);
    // if data is valid, the temporary object into the current object 
    if (temp.no != 0)
        *this = temp;
}

void Student::display(std::ostream& os) const {
    if (no > 0) {
        os << no << ":\n";
        os.setf(ios::fixed);
        os.precision(2);
        for (int i = 0; i < ng; i++) {
            os.width(6);
            os << grade[i] << endl;
        }
        os.unsetf(ios::fixed);
        os.precision(6);
        os << "Comments:\n" << comment << endl;
    }
    else {
        os << "no data available" << endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Student& s) {
    s.display(os);
    return os;
}

std::istream& operator>>(std::istream& is, Student& s) {
    s.read(is);
    return is;
}


