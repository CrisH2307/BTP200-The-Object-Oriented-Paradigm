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
#include <iostream>
#include <cstdio>
#include "File.h"
#include "ShoppingList.h"
#include "ShoppingRec.h"
#include "Utils.h"

using namespace std;


namespace sdds
{
	FILE* g_sfptr = nullptr;


	bool openFileForRead()
	{
		g_sfptr = fopen(SHOPPING_DATA_FILE, "r");
		return g_sfptr != nullptr;
	}

	bool openFileForOverwrite()
	{
		g_sfptr = fopen(SHOPPING_DATA_FILE, "w");
		return g_sfptr != nullptr;
	}

	void closeFile()
	{
		if (g_sfptr)
		{
			fclose(g_sfptr);
			g_sfptr = nullptr;
		}
	}

	bool freadShoppingRec(ShoppingRec* rec)
	{
		int flag = 0;
		bool success = fscanf(g_sfptr, "%[^,],%d,%d\n", rec->m_title, &rec->m_quantity, &flag) == 3;
		rec->m_bought = !!flag;
		return success;
	}

	void fwriteShoppintRec(const ShoppingRec* rec)
	{
		fprintf(g_sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
	}
}