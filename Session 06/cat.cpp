#define _CRT_SECURE_NO_WARNINGS
#include "cat.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace lectures
{
	Cat::Cat() // Function constructor, Initialize EVERYTHING
	{

		this->m_age = -1;
		this->m_name = nullptr;
	}
	void Cat::display()const
	{
		cout << "Name [" << this->m_name << "]" << endl;
		cout << " Age [" << this->m_age << "]" << endl;
	}
	void Cat::set(const char* name, int age)
	{
		 delete[] this->m_name; // Deallocate memory

		if (age > 0 and name != nullptr and name[0] != '\0')
		{
			//params are good
			m_name = new char[strlen(name) + 1]; // Deallocate memory and create new name
			strcpy(this->m_name, name);			 // Allocate memory and copy name
			m_age = age;
		}
		else
		{
			// bad params
			m_name = nullptr;
			m_age = -1;
		}


	}
}

//! WALKTHROUGH
/*

START: 1   --> ! is false , false + false = true
--------------
A1: 6      --> It's passing the address with ptr, 5 + 1 = 6
A2: 7       --> We use the post-fix increment, print the current value and future value in the next line
A3: 10      --> We use the pre-fix increment, print the updated value
----------------
X1: 5       --> It expect the address, so its not changing the value
X2: 8       --> Print the result after post-fix increment
X3: 9     --> Pass by value, wont change
----------------
B1: 3       --> Since its a reference, it will change value, 7/2 = 3
B2: 2        --> Since its a value, it wont change but its happening inside funtion
----------------
A1: 8
A2: 5        --> Whenever u see (*) in the function, u have to pass the variable that has the actual (&)
A3: 1            Whenever u see (&) in the function, u can just pass variable by itself
----------------
T1: -11        --> a = -10, int reference r = a, when r = -11; so do a
T2: 1        --> True or 1 (Cuz -11 = -11)
----------------
C: 10            --> We are printing 3 current instances, x,y and Foo, we didnt give the value, but the default value (n = 10)
C: 20        --> Constructor
C: 100            --> Enter the new scope Foo(100), create construction
D: 100            --> D: Destructor, destroy the opposite orders of the constructor, we are done with this scope, not for the outside scope
----------------
D: 20            --> After dashes, the destructor will run the outside scope, cuz we still have the scope existance
D: 10

*/