//width(int) - sets the field width to the integer received
//fill(char) - sets the padding character to the character received
//setf(...) - sets a formatting flag to the flag received
//unsetf(...) - unsets a formatting flag for the flag received
//precision(int) - sets the decimal precision to the integer received


//! Contruction and Destruction
//#include "main.h"
//#include <iostream>
//
//using namespace std;
//
//
//void Student::copyFrom(const Student& src) 
//// specify the class name followed by the scope resolution operator :: to 
//// indicate that the function belongs to that specific class.
//	
//	// class Name/Identifier::function(type Class& param)
//
//{
//	//! obj = param.obj --> copy data
//	no = src.no; // copy data from one obj to another  (no is an obj)
//	ng = src.ng;
//
//	for (int i = 0; i < NG; i++)
//	{
//		grade[i] = src.grade[i];
//	}
//}
////void Student::set(int studentNo, const float* grades, int numOfGrades)
////{
////	no = studentNo;
////	ng = numOfGrades;
////
////	for (int i = 0; i < numOfGrades; i++)
////	{
////		grade[i] = grades[i];
////	}
////}
//
//void Student::set(int sn, const float* g, int ng_) 
//{
//	bool valid = sn > 0 && g != nullptr && ng_ >= 0;
//	if (valid)
//		for (int i = 0; i < ng_ && valid; i++)
//			valid = g[i] >= 0.0f && g[i] <= 100.0f;
//
//	if (valid) {
//		// accept the client's data
//		no = sn;
//		ng = ng_ < NG ? ng_ : NG;
//		for (int i = 0; i < ng; i++)
//			grade[i] = g[i];
//	}
//	else {
//		no = 0;
//		ng = 0;
//	}
//}
//
//void Student::display() const
//{
//	if (no > 0)
//	{
//		cout << no << ":\n"; // Print the student number if it is valid
//		cout.setf(ios::fixed);
//		cout.precision(2); // Fixed to 2 decimals
//		/*
//		cout.setf(ios::fixed) is a C++ statement that modifies 
//		the behavior of the output stream cout by setting the fixed flag
//		of the stream's format control. This statement is typically used 
//		to control the formatting of floating-point numbers when they are 
//		printed to the standard output.
//		By using cout.setf(ios::fixed), the floating - point numbers will be
//		displayed with a fixed number of decimal places.This means that the numbers
//		will always be printed with the same number of digits after the decimal point, 
//		regardless of their actual precision
//		*/
//
//		for (int i = 0; i < ng; i++)
//		{
//			cout.width(6);
//			cout << grade[i] << endl;
//		}
//		cout.unsetf(ios::fixed);
//		cout.precision(6);
//	}
//	else
//	{
//		cout << "Unvalid" << endl;
//	}
//}
//
//int main ()
//{
//	Student cris;
//	cris.display();
//	float grade[] = { 78.9f, 67.5f, 45.5f, 64.35f };
//
//	cris.set(975, grade, 4);
//	cris.display();
//
//	// different date for each obj - same logic
//
//	//cris.display(); // Display the data stored in cris
//	//cout << endl;
//
//	return 0;
//}



//! Destructor
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//
//class String {
//private:
//    char* buffer;
//
//public:
//    String(const char* text) {
//        size_t length = std::strlen(text);
//        buffer = new char[length + 1];
//        std::strcpy(buffer, text);
//        std::cout << "Constructor called: " << buffer << std::endl;
//    }
//
//    ~String() {
//        std::cout << "Destructor called: " << buffer << std::endl;
//        delete[] buffer;
//    }
//
//    const char* getData() const {
//        return buffer;
//    }
//};
//
//int main() {
//    String str1("Hello");
//    String str2("World");
//
//    std::cout << "str1: " << str1.getData() << std::endl;
//    std::cout << "str2: " << str2.getData() << std::endl;
//
//    // Other code...
//
//    return 0;
//}  // Objects str1 and str2 go out of scope, destructors called


//! Constructors and Destructors
// destructors.cpp

//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//using namespace std;
//const int NG = 20;
//
//class Student {
//    int no;
//    float grade[NG];
//    int ng;
//public:
//    Student();
//    ~Student();
//    void set(int, const float*, int);
//    void display() const;
//};
//
//Student::Student() {
//    cout << "In constructor" << endl;
//    no = 0;
//    ng = 0;
//}
//
//// executed before object goes out of scope 
////
//Student::~Student() {
//    cout << "In destructor for " << no
//        << endl;
//}
//
//void Student::set(int sn, const float* g, int ng_) {
//    bool valid = sn > 0 && g != nullptr && ng_ >= 0;
//    if (valid)
//        for (int i = 0; i < ng_ && valid; i++)
//            valid = g[i] >= 0.0f && g[i] <= 100.0f;
//
//    if (valid) {
//        // accept the client's data
//        no = sn;
//        ng = ng_ < NG ? ng_ : NG;
//        for (int i = 0; i < ng; i++)
//            grade[i] = g[i];
//    }
//    else {
//        no = 0;
//        ng = 0;
//    }
//}
//
//void Student::display() const {
//    if (no > 0) {
//        cout << no << ":\n";
//        cout.setf(ios::fixed);
//        cout.precision(2);
//        for (int i = 0; i < ng; i++) {
//            cout.width(6);
//            cout << grade[i] << endl;
//        }
//        cout.unsetf(ios::fixed);
//        cout.precision(6);
//    }
//    else {
//        cout << "no data available" << endl;
//    }
//}
//
//int main() {
//    Student harry, josee;
//    float gh[] = { 89.4f, 67.8f, 45.5f };
//    float gj[] = { 83.4f, 77.8f, 55.5f };
//    harry.set(1234, gh, 3);
//    josee.set(1235, gj, 3);
//    harry.display();
//    josee.display();
//}

//! Constructors, Destructors and Arrays
// ctorsDtorsArrays.cpp
#include <iostream>
#include <cstring>
using namespace std;
const int NG = 20;

class Student {
    int no;
    float grade[NG];
    int ng;
public:
    Student(); 
    // Student(int g, float t) 
    //! --> This is overloaded Contructor, special member method, can be overloaded, 
    //! invoked during creation, same name as class, useful for
    ~Student();
    void set(int, const float*, int); 
    void display() const;    //Member Function
};

Student::Student() {
    cout << "In constructor" << endl;
    no = 0;
    ng = 0;
}

Student::~Student() {
    //! Destructor:
    //! + Special member method
    //! + Same name as the class proceeded with the tilde (~)
    //! + Invoked automatically when an obj is destroyed
    //! + No return type and no param
    //! + Only 1 destructor is allow per class 
    //! + Can't be overloaded 
    //! + Useful to release memory and resoures
    cout << "In destructor for " << no
        << endl;
}

void Student::set(int sn, const float* g, int ng_) {
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

int main() {
    Student a[3];
    float g0[] = { 89.4f, 67.8f, 45.5f };
    float g1[] = { 83.4f, 77.8f, 55.5f };
    float g2[] = { 77.8f, 83.4f, 55.5f };
    a[0].set(1234, g0, 3);
    a[1].set(1235, g1, 3);
    a[2].set(1236, g2, 3);
    for (int i = 0; i < 3; i++)
        a[i].display();
}