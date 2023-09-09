#include <iostream>
#include "ArrayList.h"

using namespace std;
namespace lectures
{
	ArrayList:: ArrayList(int cnt)  //Validate the param and the function
	{
		if (cnt > 0)
		{
			m_cnt = cnt;
			m_data = new double[cnt];

			for (int i = 0; i < cnt; ++i)
			{
				m_data[i] = -5 + i;
			}
		}
	}

	void ArrayList::display()const
	{
		for (int i = 0; i < m_cnt; ++i)
		{
			cout << " " << m_data[i];
		}
		cout << endl;
	}

	ArrayList::~ArrayList()
	{
		delete[] m_data;
	}

	ArrayList& ArrayList::push_back(double val)    //! To resize the array
	{
		// 1. Create a new array of the require size
		double* tmp = new double[m_cnt + 1];

		// 2. Allocate new memory, copy from old array into new one
		for (int i = 0; i < m_cnt; ++i)
		{
			tmp[i] = m_data[i];
		}

		// 3. Put new element in the correct position
		tmp[m_cnt] = val;

		// 4. Clean up the old array
		delete[] m_data;

		// 5. Update new attribute to point to the new array
		m_data = tmp;
		++m_cnt;

		return *this;

	}

	ArrayList& ArrayList::operator+=(const ArrayList& other)
	{
		for (int i = 0; i < other.m_cnt; ++i)
		{
			this->push_back(other.m_data[i]);
		}

		return *this;
	}
	ArrayList& ArrayList::operator<<(const ArrayList& other)
	{
		*this += other;
		return *this; // Return current instance
	}

	ArrayList::operator bool()const
	{
		cout << "\t\tDebug: Conversion bool has been called";
		return m_cnt > 0;
	}
	ostream& operator<<(ostream& out, const ArrayList& al)
	{
		al.display();
	}


	ArrayList& ArrayList::operator++()
	{
		for (int i = 0; i < this->m_cnt; ++i)
			this->m_data[i] += 1;

		return *this;
	}


	ArrayList ArrayList::operator++(int)
	{
		// Make a copy of the current instance
		ArrayList copy = *this;
		++(*this);
		return copy;
	}

	ArrayList::ArrayList(const ArrayList & other) : ArrayList()
	{
		if (other.m_cnt > 0)
		{
			// do some shit
			this->m_cnt = other.m_cnt;
			this->m_data = new double[m_cnt];
			for (int i = 0; i < m_cnt; ++i)
			{
				this->m_data[i] = other.m_data[i];
			}
		}
		else
		{
			// Set to default
		}
	}

	ArrayList ArrayList::operator=(const ArrayList& other)
	{
		//1. check for self assignment and Nothing else
		if (this != &other)
		{
			// 2. Cleanup resources used by current instance
			delete[] this->m_data;

			// 3. Shallow copy: copy non-resource attributes
			this->m_cnt = other.m_cnt;

			// 4. Deep copy: Duplicate the resource
			if (m_cnt > 0)
			{
				// do some shit
				this->m_data = new double[m_cnt];
				for (int i = 0; i < m_cnt; ++i)
				{
					this->m_data[i] = other.m_data[i];
				}
			}
			else
			{
				// Set to default
				this->m_data = nullptr;
			}
		}
		return *this;
	}
}