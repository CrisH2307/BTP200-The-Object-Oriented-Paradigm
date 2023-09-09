//! Current Object
//! 
//! 
/*
'*this' is a special pointer that refers to the current object instance
within a member function. It is an implicit pointer to the object on which
the member function is called. It allows you to access the members of the
current object inside the member function. When a member function is 
called on an object, the this pointer is automatically set to point to that object.
The *this expression is used to dereference the this pointer and access the object itself.
*/


/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
const int NG = 20;

class Student {
    int no;
    float grade[NG];
    int ng;
public:
    Student(int s, const float* g, int n);
    ~Student();
    void set(int, const float*, int);
    void display() const;
};

Student::Student(int s, const float* g, int n) {
    cout << "Entering 3-arg constructor\n";
    set(s, g, n);
}
Student::~Student() {
    cout << "In destructor for " << no
        << endl;
}


void Student::set(int s, const float* g, int n) {
    no = s;
    ng = n;
    for (int i = 0; i < n; i++) {
        grade[i] = g[i];
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
    float gh[] = { 89.4f, 67.8f, 45.5f };
    float gj[] = { 83.4f, 77.8f, 55.5f };
    Student harry(1234, gh, 3),
        josee(1235, gj, 3);
    harry.display();
    josee.display();
    return 0;
}
*/
//#include <iostream>
//
//class MyClass {
//private:
//    int value;
//
//public:
//    void setValue(int val) {
//        value = val;
//    }
//
//    void printValue() {
//        std::cout << "Value: " << value << std::endl;
//        std::cout << "Address of current object: " << this << std::endl;
//    }
//
//    void printAddress() {
//        std::cout << "Address of this pointer: " << this << std::endl;
//    }
//};
//
//int main() {
//    MyClass obj1;
//    obj1.setValue(42);
//    obj1.printValue();
//
//    MyClass obj2;
//    obj2.setValue(78);
//    obj2.printValue();
//
//    obj1.printAddress();
//    obj2.printAddress();
//
//    return 0;
//}
#include <iostream>
#include "cat.h"
using namespace std;
using namespace lectures;

void defaultFormatOptions()
{
    // change the name column size to 20
    cout.width(20);   // Applied the next insertion only
    cout.setf(ios::left);  // Applied until removed, align left
    char oldFill = cout.fill('.');         // Fill the space with character


    cout << "Cr"; // Fill '.'
    cout.unsetf(ios::left);
    cout.width(4);
    cout.fill(oldFill);
    cout << 18 << ' ' << 2004 << '/' << 7 << '/' << 23 << endl;
              // Width(4)

    cout << 32 << ' ';
    cout.width(4);
    oldFill = cout.fill ('0');
    cout << 1992 << '/';
    cout.width(2);
    cout << 5 << '/';
    cout.width(2);
    cout << 12 << endl;

    
    cout.fill(oldFill);

    /*
    The width() function takes an integer argument and sets the minimum number of 
    characters to be used for the next output operation. If the actual output value
    requires fewer characters, it will be padded with spaces or other
    specified fill characters.*/

    cout.width(20);
    cout << "Cris Huynh" << 18 << " " << 2004 << '/' << 4 << '/' << 12 << endl;
}
//class Foo
//{
//    int data;
//public: 
//    void display() const      // (const Foo* this)  -> will receive 'this' as a first param
//    {
//
//    }
//};

int main()
{
    Cat aCat;

    aCat.set("James", 23);
    aCat.display();

    aCat.set("Sean", 69);
    aCat.display();

    return 0;
}