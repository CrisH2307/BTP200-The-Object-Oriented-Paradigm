#ifndef _MAIN_H
#define _MAIN_H


#include <iostream>

//class Money {
//    int dollars;
//    int cents;
//public: 
//    Money(int dollars, int cents);
//    Money(int total);
//
//    //----DO NOT MODIFY THE CODE ABOVE THIS LINE----
//    //----WRITE YOUR METHOD DECLARATIONS BELOW THIS LINE----
//    bool operator==(const Money& mny)const;
//    bool operator!=(const Money& mny)const;
//
//    //! Friend non-member function
//    friend Money operator+(const Money& left, const Money& right);
//
//    //----WRITE YOUR METHOD DECLARATIONS ABOVE THIS LINE----
//    //----DO NOT MODIFY THE CODE BELOW THIS LINE----
//};
const int NG = 20;
class Student {
    int no;
    float grade[NG];
    int ng;
    void set(int, const float*, int);
public:
    Student();
    Student(int, const float*, int);
    void display() const;
    Student& operator+=(float g);  // This is binary operator
    Student& operator++();         // This is pre-fix unary operator 
    Student operator++(int);       // This is post-fix unary operator
    operator bool() const;         // This is Bool conversion operator
    Student(int);                  // This is cast operator
    explicit Student(int);         // This is explicit
};

#endif //_MONEY_MONEY_H

