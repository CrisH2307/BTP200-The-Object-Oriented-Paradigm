// Student.h
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_W8_EX1
#define SDDS_W8_EX1
#include<iostream>
#include<iomanip>
#include<cstring>

namespace sdds {
	const int NS = 32;

	struct Date {
		int m_year;
		int m_month;
		int m_day;
	};

	//! Base class
	class Student {
	protected:
		//char* m_name; // will point to a dynamic array 
		//Date m_dob; // date of birth
	private:
		int m_id;
		char* m_name; // will point to a dynamic array 

		Date m_dob; // date of birth
		float m_marks[NS]; // added for Week-04 exercise; static array
		int m_numMarks; // added for Week-04 exercise
		void copyName(const char* n);
	public:
		Student();
		Student(int id, const char* name, Date date, const float* marks, int nsc);
		Student(int id, const char* name);
		~Student();
		std::ostream& operator<<(std::ostream&) const;
	};
	std::ostream& operator<<(std::ostream& os, const Student& st);



	//! Derived class
	class Person: public Person {
	private:
		int m_id;
		char* m_name; // will point to a dynamic array 
		Date m_dob; // date of birth
		float m_marks[NS]; // added for Week-04 exercise; static array
		int m_numMarks; // added for Week-04 exercise
		void copyName(const char* n);

	public:
		Person();
		Person(int id, const char* name, Date date, const float* marks, int nsc);
		Person(int id, const char* name);
		Person(const char* name, Date dob);

		~Person();
		std::ostream& operator<<(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const Person& st);

}
#endif 

