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

#include <cstdio>
#include <iostream>
#include "cstring.h"
using namespace std;
namespace sdds
{
	void strCpy(char* des, const char* src)
	{
		int i;
		for (i = 0; src[i] != '\0'; i++) 
		//Until the index of the src has a character, which mean it satifies the condition not equal to null terminator, the program will continue to run
		{
			des[i] = src[i];
		}
		des[i] = '\0';
	}

	void strnCpy(char* des, const char* src, int count)
	{
		int i;
		for (i = 0; i < count; i++)
		{
			des[i] = src[i];

			if (src[i] == '\0')
			{
				i = count;
			}
		}
		//The index of (i < 2) which mean , Until the index of the src has a character, which mean it satifies the condition not equal to null terminator, the program will continue to run. 
		//For ex: '@@@' has 3 indexs (0,1,2). src[i] will contain 3 indexs until it reaches NULL TERMINATOR, and then copy the rest of it (str1)
		//But when the user only takes count = 1, that means it's only taking 1 character and the rest of it will be ok
	}

	int strCmp(const char* s1, const char* s2)
	{
		int i;
		for (i = 0; s1[i] != '\0'; i++)
		{
			if (s1[i] != s2[i])
			{
				return s1[i] - s2[i];
			}
		}	
		return 0;
	}

	int strnCmp(const char* s1, const char* s2, int count)
	{
		int i;
		for (i = 0; i < count; i++)
		{
			if (s1[i] != s2[i])
			{
				return s1[i] - s2[i];
			}
			// If one of the strings reaches the null terminator, stop comparing
			if (s1[i] == '\0' || s2[i] == '\0') 
			{
				break;
			}
		}

		return 0;
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

	const char* strStr(const char* haystack, const char* needle)
	{
		int i, j;
		if (*needle == '\0')
		{
			//returns nullptr if no match is found
			return haystack;
		}
		int haystackLen = strLen(haystack);
		int needleLen = strLen(needle);
		
		for (i = 0; i < (haystackLen - needleLen + 1); i++)
		// For loop, we will reach the number when the length of str1(haystack) - str2(needle)
		/* 
		If we use i < haystackLen - needleLen instead not adding 1
		it would only iterate until the second-to-last position of the haystack string
		which might cause us to miss the last position where the needle could potentially match
		By using i < (haystackLen - needleLen + 1) ,we include the last position in the iteration
		allowing us to check if the needle matches at the end of the haystack.
		*/
		{
			for (j = 0; j < needleLen; j++) // The loop will run until we out of number needle
			{
				if (haystack[i + j] != needle[j])
				/* 
				haystack[i + j] refers to the character in the haystack string at index (i + j)
				needle[j]       refers to the character in the needle string at index j.

				To check if the current character being compared in the haystack and needle strings is different
				If they are not equal, it indicates a mismatch between the characters
				and we can conclude that the current position in the haystack is not the start of the desired substring match.
				*/
					break; // The condition will break when we out of the character
			}
			if (j == needleLen)
			{
				return &haystack[i];
			}
			/* Determine if the entire needle string has been successfully matched within the haystack string.*/
		}
		return nullptr;
	}

	void strCat(char* dest, const char* src)
	{
		int i = 0;
		int j = 0;
		while (dest[i] != '\0')
		{
			i++;
		}

		while (src[j] != '\0')
		{
			dest[i] = src[j];
			i++;
			j++;
		}
		dest[i] = '\0';
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
