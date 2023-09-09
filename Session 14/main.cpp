// main.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<iostream>
#include<iomanip>

#include "Student.h"

using namespace std;
using namespace sdds;
/* Activities
1. Base and derived class
2. Defining derived class
3. Access - private, protected, public
4. Shadowing -
5. Exposing base class member function
   (when it has different signature than the shadowing function): using Base::fName
6. Constructors
   - how do base and derived class constructors work together
   -
*/
int main()
{
	int id[] = { 1001,1002,1003,1004,1005,1006,1007,1008 };
	const char* name[] = { "Amy Jackson", "Oscar Banks", "Lucy Alcorn",
		"Daisy Crook", "James Edgar", "Jane ",
		"Osbert ", "Elton Hurst" };
	Date dobs[] = { Date{2001,1,1},Date{2002,2,3},Date{2000,1,5},
		Date{2003,3,3},Date{1999,2,3},Date{2002,3,5},Date{2001,5,8},Date{2003,11,12} };
	float marks[][32] = { {50.1, 55.1, 60.1, 65.1},
					  {51.2, 56.2, 61.2, 66.2, 71.2},
					  {52.3, 57.3, 62.3},
					  {53.4, 58.4, 63.4, 68.4,  73.4, 99.4},
					  {54.5, 59.5, 64.5},
					  {55.6, 60.6, 65.6, 70.6},
					  {56.7, 61.7, 66.7, 71.7, 76.7},
					  {57.8, 62.8, 67.8, 72.8, 77.8, 73.8, 78.8, 83.8}
	};
	int nsc[] = { 4, 5, 3, 6, 3, 4, 5, 8 };
	std::cout << std::endl;
	Student* s[20];
	for (int i = 0; i < 8; i++) {
		s[i] = new Student(id[i], name[i], dobs[i], marks[i], nsc[i]);
	}

	for (int i = 0; i < 8; i++) {
		std::cout << *s[i] << std::endl;
	}



	for (int i = 0; i < 8; i++) {
		delete s[i];
	}

	return 0;
}