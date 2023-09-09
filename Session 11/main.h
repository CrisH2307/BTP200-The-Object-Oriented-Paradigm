// Student.h

#include <iostream>     //! for std::ostream, std::istream
const int NG = 20;

class Student 
{
    int no;
    float grade[NG];
    int ng;
    std::string comment;    //! Store a comment using string obj
public:
    Student();
    Student(int);
    Student(int, const float*, int, const std::string&);
    void read(std::istream&);
    void display(std::ostream& os) const;
};
std::istream& operator>>(std::istream& is, Student& s);
std::ostream& operator<<(std::ostream& os, const Student& s);