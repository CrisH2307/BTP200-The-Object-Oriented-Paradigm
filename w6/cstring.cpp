/*
*****************************************************************************
							  cstring.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "cstring.h"
namespace sdds 
{
	void strCpy(char* des, const char* src)
	{
		if (des != nullptr and src != nullptr)
		{
			int i;
			for (i = 0; src[i] != '\0'; i++)
				//Until the index of the src has a character, which mean it satifies the condition not equal to null terminator, the program will continue to run
			{
				des[i] = src[i];
			}
			des[i] = '\0';
		}
	}


	int strLen(const char* s)
	{
		int len = 0;
	
			// Loop through each character of the user input and stop when a null character is found
			while (s[len] != '\0')
			{
				// Increment the string length by 1 each time a non-null character is found
				len++;
			}
			return len;
		
	}


	void strCat(char* des, const char* src)
	{
		if (des != nullptr and src != nullptr)
		{
			int i = 0;
			int j = 0;
			while (des[i] != '\0')
			{
				i++;
			}

			while (src[j] != '\0')
			{
				des[i] = src[j];
				i++;
				j++;
			}
			des[i] = '\0';
			/*
			The code uses an index i to traverse the dest array until it reaches the null terminator `'\0'
			which signifies the end of the string.
			Then, using another index j, the code copies the characters from the src array to the dest array
			starting from the position where the null terminator of dest was found.
			The copying continues until the null terminator '\0' of the src array is encountered.
			Finally, a null terminator '\0' is placed at the end of the concatenated string in the dest array to ensure proper termination
			*/
		}
	}
}