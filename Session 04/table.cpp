#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "table.h"
#include <cstring>

using namespace std;
namespace lectures
{
	void Table:: display()const
	{
		// The collection of data that defines the current condition or attributes of an object or program at a given moment
		if (isEmpty())
		{
			// Object is not good, nothing to print
			cout << "Invalid Object" << endl;
		}
		else
		{
			cout << "A table make of    [" << m_material << "]" << endl;
			cout << "It has a length of [" << m_length * 100 << "] cm." << endl;

		}

	}

	Table& Table::set(const char* material) // 1st Parameter: Table's address, 2nd Parameter: Material
		// Stores into the object of type table the material
		// <param name="theTbl" >< param name
	{
		// Check if the parameter is good
		if (material == nullptr || material[0] == '\0')
		{
			// Bad parameter, set the object into an empty state
			cout << "Invalid Object" << endl;
		}
		else
		{
			strcpy(m_material, material);
		}
		return *this;
	}


	Table& Table::set(double length)
	{
		// Check if the parameter is good
		if (0.5 < length && length < 3)
		{
			// Good parameter
			m_length = length;
		}
		else
		{
			// Bad data

			// Signal to any other fucntion that the object is ERROR mode --> Emply State
			setEmpty();
			/* Empty state refers to a specific condition 
			where an object or data structure does not contain any meaningful or valid data
			It represents a state where the object has not been initialized or has been
			explicitly set to a state where it has no relevant values */
		}
		return *this;
	}

	bool Table::isEmpty() const
	{
		return m_length == -1 && m_material[0] == '\0';
	}
	void Table::setEmpty()
	{
		m_length = -1;
		m_material[0] = '\0';
	}
}