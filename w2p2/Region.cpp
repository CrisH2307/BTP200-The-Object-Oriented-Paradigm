/*
*****************************************************************************
							  Region.cpp
Full Name  : Xuan Khang Huynh (Cris Huynh)
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include "File.h"
#include "Region.h"

using namespace std;

namespace sdds
{

	Region* r_postalarea = nullptr;

	int r_numofPostal = 0;

	void sort()
	{
		for (int i = r_numofPostal - 1; i > 0; --i)
			for (int j = 0; j < i; ++j)
				if (r_postalarea[j].m_pop > r_postalarea[j + 1].m_pop)
				{
					auto temp = r_postalarea[j];
					r_postalarea[j] = r_postalarea[j + 1];
					r_postalarea[j + 1] = temp;
				}
	}

	bool load(const char* filename)
	{

		bool ok = true;
		// int ArrayNameSize;

		if (openFile(filename))
		{
			int size = noOfRecordsInFile(); // Get the number of records in the file
			// int newSize = r_numofPostal + noOfRecords; // Calculate the size of the new array

			// Region* newArray = new Region[newSize]; // Create a new array of the new size
			r_postalarea = new Region[size];


			for (int i = 0; i < size; i++)
			{
				load(r_postalarea[i]);
			}



			//// Copy existing employees from old array to the new array
			//for (int i = 0; i < r_numofPostal; i++)
			//{
			//	newArray[i].m_pop = r_postalarea[i].m_pop;

			//	ArrayNameSize = strlen(r_postalarea[i].m_postal); // Get new size if the array

			//	newArray[i].m_postal = new char[ArrayNameSize + 1]; // Allocate memory for newArray names

			//	strcpy(newArray[i].m_postal, r_postalarea[i].m_postal); // Copy to new array into new array
			//}
			//for (int i = r_numofPostal; i < newSize; i++) // initialize new element
			//{
			//	load(newArray[i]);
			//}

			// cleanUp();

			//// Update ptr
			//r_postalarea = newArray;

			//// Update the variable that stores the size of the array
			//r_numofPostal = newSize;

			r_numofPostal = size; 
			closeFile();

		}
		else
		{
		cout << "Could not open data file: " << filename << endl;
		ok = false;
		}

	return ok;
	}

	bool load(Region& reg)
	{
		bool ok = false;

		if (read(reg.m_postal) && read(reg.m_pop) )
		{

			ok = true;

	/*	if (read(population) && read(name))
		{
			//Get stored in obj
			reg.m_pop = population;

			int size = strlen(name);

			//if all reads are successful, store the read data into the
			//parameter(don't forget to allocate memory
			//for the `m_name` attribute; allocate an extra character for `\0`).

			reg.m_postal = new char[size + 1]; // Allocates

			for (int i = 0; i < size; i++)
			{
				reg.m_postal[i] = name[i]; // copies characters into m_name
			}
			reg.m_postal[size] = '\0'; // Add \0

			ok = true;
			*/
		}
		return ok;
	}

	void display(const Region& region)
	{
		cout << region.m_postal << " -> " << region.m_pop << endl;
	}

	void display(const char* areaName, bool sorted)
	{


		cout << "#. Postal Code -> Population" << endl;
		cout << "------------------------------" << endl;
		int sumofPopulation = 0;


		if (sorted == true)
		{
			sort();
		}

		for (int i = 0; i < r_numofPostal; i++)
		{
			cout << i + 1 << ". ";
			display(r_postalarea[i]);
			sumofPopulation += r_postalarea[i].m_pop;
		}
		cout << "------------------------------" << endl;
		cout << "Population of " << areaName << ": " << sumofPopulation << endl;
	}



	void cleanUp() // Deallocate memory
	{

		delete[] r_postalarea;

		r_postalarea = NULL;

		r_numofPostal = 0;
	}
}