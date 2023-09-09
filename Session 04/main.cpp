#define _CRT_SECURE_NO_WARNINGS

// Encapsulation: Construction and Destruction
// We make data, we will create logic
#include "cstring"
#include "table.h"

using namespace std;
using namespace lectures;
int main()
{
	Table aTbl;

	aTbl.set("Wood and Steel");
	aTbl.set(-1.55);
	/*
	aTbl.m_length = -1.55;
	strcpy(aTbl.m_material, "Wood and steel");
	*/

	aTbl.display();  // This function will not be changed --> void display() const ;


	return 0;
}