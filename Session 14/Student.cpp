// Student.cpp
#include "Student.h"

using namespace std;

namespace sdds {
	void Student::copyName(const char* n) {
		strcpy(m_name, n);
	}
	Student::Student() : //Person(nullptr, Date{ 1950,0,0 } { // default constructor 
		//std::cout << "aaa";
		m_id = 0;
		m_name = nullptr; // 
		for (int i = 0; i < NS; i++)
			m_marks[i] = -1.0f;
		m_numMarks = -1;
	}



	Student::Student(int id, const char* name, Date date, const float* marks, int nsc) {// non-default; custom; parameterized constructor
		//std::cout << "bbb";
		if (id > 0 && name && marks && nsc > 0) {
			m_id = id;
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_dob = date;
			m_numMarks = nsc;
			for (int i = 0; i < m_numMarks; i++)
				m_marks[i] = marks[i];
		}
	}
	Student::Student(int id, const char* name): Person(nullptr, Date(0,0,0)) {// non-default; custom; parameterized constructor
		///std::cout << "ccc";
		if (id > 0 && name) {
			m_id = id;
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_dob = Date{ 0,0,0 };
			m_numMarks = 0;
			for (int i = 0; i < m_numMarks; i++)
				m_marks[i] = 0.0f;
		}
	}
	Student::~Student() {
		if (m_name)
			delete[] m_name;
	}
	std::ostream& Student::operator<<(std::ostream& os) const {
		if (m_id > 0 && m_name != nullptr) {
			os << "id: " << (*this).m_id << ", Name: " << setw(12)
				<< left << (*this).m_name;
			os << ", date-of-birth: "
				<< std::setfill('0')
				<< std::setw(4) << std::right << m_dob.m_year << "/"
				<< std::setw(2) << std::right << m_dob.m_month << "/"
				<< std::setw(2) << std::right << m_dob.m_day
				<< std::setfill(' ');
			os << ", Marks: ";
			if ((*this).m_numMarks > 0) {
				for (int i = 0; i < (*this).m_numMarks; i++)
					os << (*this).m_marks[i] << " ";
			}
			else {
				os << "None";
			}
		}
		else
			os << "invalid data";
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Student& st) {
		return st << os;
	}


	Person::Person()
	{
		m_name = nullptr;
		m_dob = Date{ 1950,0,0 };
	}

	Person::Person(const char* name, Date dob): Student(nullptr, Date(0,0,0))
	{
		if (name and dob.m_year > 1950 and dob.m_month > 0 and dob.m_month <= 12 and dob.m_day > 0 and dob.m_day <= 31)
		{
			this->m_name = new char[strlen(name) + 1];
			strcpy(this->m_name, name);
			this->m_dob = dob;
		}
		else
		{
			m_name = nullptr;
			m_dob = Date{ 1970,0,0 };
		}
	}

	void Person::copyName(const char* n)
	{
		strcpy(this->m_name, n);
	}

	Person::~Person()
	{
		delete[]this->m_name;
	}

	std::ostream& Person::operator<<(std::ostream& os) const   //! Member operator
	{
		if (m_name)
		{
			os << "Name: " << setw(12)
				<< left << (*this).m_name;
			os << "date - of - birth: "
				<< std::setfill('0')
				<< std::setw(4) << std::right << m_dob.m_year << "/"
				<< std::setw(2) << std::right << m_dob.m_month << "/"
				<< std::setw(2) << std::right << m_dob.m_day
				<< std::setfill(' ');
		}
		return os;
	}


}
