#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include "test.h"

using namespace std;
namespace project
{
	Team::Team()
	{
		m_name[0] = '\0';
		m_hour = 0.0;
		m_number = 0;
	}
	Team::Team(const char* name, double hour) : Team()
	{
		if (name != nullptr and name[0] != '\0' and hour > 0.0)
		{
			strcpy(this->m_name, name);
			this->m_hour = hour;
		}
	}
	double Team::avgHour()const
	{
		double avgHour = 0.0;
		for (int i = 0; i < m_number; ++i)
		{
			avgHour += this->m_hour;
		}
		return avgHour;
	}

	void Team::add(const char* name, double hour)
	{
		if (name != nullptr and name[0] != '\0')
		{
			//Check if the name is already in list
			for (int i = 0; i < m_number; ++i)
			{
				if (strcmp(m_name, name) == 0)
				{
					// Name already exists, no need to add
					return;
				}
			}
			//// Deallocate
			//delete[] m_name; //! Safeguard

			//// Allocate
			//m_name = new char[strlen(name) + 1];

			//Add newname
			strcpy(m_name, name);
			strcat(m_name, ";");
			m_number++;
		}
	}

	void Team::addHours(const char* name, double hours)
	{
		if (name != nullptr and name[0] != '\0')
		{
			//Check if the name is already in list
			for (int i = 0; i < m_number; ++i)
			{
				if (strcmp(m_name, name) == 0)
				{
					// Name already exists, add hours
					this->m_hour += hours;
				}
			}
		}
	}

	Team::operator int()const
	{
		return m_number;
	}

	Team::~Team()
	{
		delete[]m_name;
		m_name[0] = '\0';
		m_hour = 0.0;
		m_number = 0;
	}

	ostream& operator<<(ostream& os, const Team& mem)
	{
		for (int i = 0; i < mem.operator int(); ++i)
		{
			os << mem.avgHour() << " ";
		}
		return os;

	}
}