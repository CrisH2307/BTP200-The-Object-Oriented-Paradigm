/*
*****************************************************************************
							  File.cpp
Full Name  : Xuan Khang Huynh (Cris Huynh)
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
// This prevents VS compiler from issuing warnings/errors related to utilization
//   of unsafe string functions.  Has no effect in g++.
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"
using namespace std;
namespace sdds
{

	FILE* g_fptr = nullptr;

	bool openFile(const char* filename)
	{
		bool allGood = false;
		if (g_fptr == nullptr)
		{
			g_fptr = fopen(filename, "r");
			allGood = g_fptr != nullptr;

		}
		return allGood;
	}

	int noOfRecordsInFile()
	{
		int noOfRecs = -1;
		if (g_fptr != nullptr)
		{
			// we have a file open; start counting from "0"
			noOfRecs = 0;

			// get current position in the file.
			auto currentPosition = std::ftell(g_fptr);

			// go to the begining of the file
			fseek(g_fptr, 0, SEEK_SET);

			// read from file a character at a time, and count '\n'
			char ch{};

			while (fscanf(g_fptr, "%c", &ch) == 1)
			{
				noOfRecs += (ch == '\n');
			}

			// done counting, reposition the cursor to the original location
			fseek(g_fptr, currentPosition, SEEK_SET);
		}

		// if no file was open, the counter will have "-1",
		//  otherwise will contain the number of lines
		return noOfRecs;
	}

	void closeFile()
	{
		if (g_fptr != nullptr)
		{
			fclose(g_fptr);
			g_fptr = nullptr;
		}
	}

	bool read(char* str)
	{
		// Assuming g_fptr is a global file pointer representing the open file

		// Read the name of the employee from the file using fscanf
		if (fscanf(g_fptr, "%3s,", str) == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool read(int& val)
	{
		// Assuming g_fptr is a global file pointer representing the open file

		// Read the integer from the file using fscanf
		if (fscanf(g_fptr, "%d\n", &val) == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}