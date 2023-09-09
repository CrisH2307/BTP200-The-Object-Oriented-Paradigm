#ifndef _MAIN_H
#define _MAIN_H

const int NG = 20;

class Student
{
	int no;
	double grade[NG];
	int ng;

public:
    Student();
    Student(int);
    Student(int, const float*, int);
    void display() const;
    void set(int sn, const float* g, int ng_);
    int getStudentNo() const { return no; }
    int getNoGrades() const { return ng; }
    float getGrade(int i) const { return i < ng ? grade[i] : 0.0f; }
};

bool areIdentical(const Student&, const Student&);


#endif // !_MAIN_H

