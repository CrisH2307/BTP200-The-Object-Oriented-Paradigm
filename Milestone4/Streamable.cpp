/*
Final Project Milestone 4
Filename: Streamable.cpp
Author:	Cris Huynh
Revision History
-----------------------------------------------------------
Date        Reason
2023/07/02  Preliminary release
2023/?/?    Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
-----------------------------------------------------------
07/21: Started MS3
07/22: Debug errors (Segmentation Fault)
07/24: I was stuck with copy assignment and copy constructor(Helper: Sean Muniz, Kabir Nalula)
07/25: Stuck with write and read function (Helper: Preet Patel, Nand Patel, Sukhman Hara)
07/28: Fix some format error and fill char, finished
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Streamable.h"	
#include "Date.h"
#include "Lib.h"

using namespace std;
namespace sdds
{

	Streamable::~Streamable()
	{
		// todo: Add an empty virtual destructor to this interface to guaranty that the 
		// descendants of the Streamable are removed from memory with no leak.
	}

	std::ostream& operator<<(std::ostream& o, const Streamable& that)
	{
		// TODO: Add an empty virtual destructor to this interface to guaranty
		// that the descendants of the Streamable are removed from memory with no leak.
		if (that)
		{
			that.write(o);
		}
		return o;
	}

	std::istream& operator>>(std::istream& i, Streamable& that)
	{
		// TODO: Overload the extraction operator so an object of type Streamable can be read from an istream object.

			that.read(i);	
		return i;
	}
}
