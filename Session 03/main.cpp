// MEMBER FUNCTION AND PRIVACY

#include <iostream>
#include <string.h>

using namespace std;

/*

		Data member  ( C structure) ----> Data - State

		Member Function ( C Enhanchement)  -----> Logic - Member Function


queries: Also called accessor methods, report the state of the object
modifiers: Also called mutator methods, change the state of the object
special: Also called manager methods, create, assign and destroy and object

*/

// Adding a member function

const int NG = 20;

struct Student
{
	int no;
	float grade[NG];
	int ng;

	void display() const; // Member Function
	void displayNo() const;
}; 

void Student::displayNo() const // Accessing global function
{
	cout << no << ": \n";
	// cout << "Number...\n";
}
void Student::display() const
{
	/*
	displayNo();			// Calls the global display function
	harry.displayNo();		// Calls the member function on harry

	::displayNo();		// Calls the global function
	displayNo();			// Calls the member function
	*/

	int i;
	for (i = 0; i < ng; i++)
	{
		cout << grade[i] << endl;
	}

}

//int main()
//{
//	Student harry = { 975, 78.9f, 69.4f };
//	harry.display(); // ==> Client call to the number function
//
//	cout << endl;
//}