#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "test.h"
using namespace std;

//! 1. Check if a string contains exactly two words. Each word starts with an upper case letter and contains only letters (the string represents the name of a person)
bool Data::checkString(const char* name)
{
	bool ok = false;
	int w_cnt = 0;
	int in = 0;
	int twowords = 0;

	for (int i = 0; name[i] != '\0'; ++i)
	{
		// Check if is a word
		if ((name[i] >= 'A' and name[i] <= 'Z') or
			(name[i] >= 'a' and name[i] <= 'z'))
		{
			ok = true;
		}
	} 

	if (name[0] >= 'A' and name[0] <= 'Z')
	{
		for (int i = 0; name[i] != '\0'; ++i)
		{
			if (name[i] == ' ')
			{
				w_cnt++;
				in = i;

				if (name[in + 1] >= 'A' and name[in + 1] <= 'Z')
				{
					twowords = 1;
				}
			}
		}
	}
	if (w_cnt > 1)
	{
		return 0;
	}
	else
		return twowords;

	return ok;
}

//! 7. Check if an array of integers contains duplicates.
bool Data::checkArray(int integer[])
{
	bool ok = false;

	const int size = sizeof(integer) / sizeof(integer[0]);

	for (int i = 0; i < size; ++i)  
	{
		for (int j = i + 1; j < size; ++j)
		{
			/*
			* This is the nested loop
			
			1   2   3   4   5

			i will start at integer[0] = 1
			j will start at integer[0+1] = 2

			The [j] loop will continue to run, after no more, it returns to [i] loop with next one
			i will start at integer[1] = 2
			.......


			and so on

			j loop first and i will loop later

			*/
			if (integer[i] == integer[j])
			{
				ok = true;
				break;
			}
		}
		if (ok)
		{
			break;
		}
	
	}
	return ok;
}



int Data::wordCheck(const char* word, const char* word2)
{
	int count = 0;

	int word2Len = strlen(word2);

	while (word2Len = strstr(word, word2) != nullptr)
	{
		count++;
	}
	return count;
}


/* DYNAMIC MEMORY */
//! 1. Resize an array of characters to remove all occurrences of letter a.
void Data::resize(const char* text)
{
	int oldSize = strlen(text);

	int newSize = 0;

	// Count the number of characters
	for (int i = 0; i < oldSize; ++i)
	{
		if (text[i] != 'a')
		{
			newSize++;
		}
	}

	char* newText = new char[newSize + 1];

	int newi = 0;
	// Copy the characs excluding a to the resized
	for (int i = 0; i < oldSize; ++i)
	{
		if (text[i] != 'a')
		{
			newText[newi] = text[i];
			newi++;

		}

		newText[newi] = '\0';

		cout << "Resized: " << newText << endl;

		delete[] text; // Deallocate the memory for the original text

		oldSize = 0;

	}
}

//! 3. Resize an array of characters to remove all blank characters from the beginning and end of a string.
char* Data::resizeBlank(const char* text)
{
	int oldSize = strlen(text);

	int blankSpace = 0;

	for (int i = 0; i < oldSize; ++i)
	{
		if (text[i] == ' ')
		{
			blankSpace++;
		}
	}

	int newSize = oldSize - blankSpace;

	char* newText = new char[newSize + 1];

	// Copy the non-blank characters to the new string
	// strncpy(newText, text + blankSpace, newSize);  --> Optional

	int j = 0;
	for (int i = 0; i < oldSize; ++i) 
	{
		newText[j] = text[i];
		j++;
		newText[newSize] = '\0';

	}
	return newText;
}

//! 11. From an array of Books, remove all books that don’t have a valid title (a valid title is a string with at least four characters) or the price is less than zero:
void Data::bookResize( const char* name[], double price[])
{
	int oldSize = sizeof(name) / sizeof(name[0]);

	int validBooks = 0;

	for (int i = 0; i < oldSize; ++i)
	{
		if (strlen(name[i]) >= 4 && price[i] >= 0.0)
		{
			validBooks++;
		}
	}

	const char** validNames = new const char* [validBooks];
	double* validPrices = new double[validBooks];

	int newIndex = 0;

	for (int i = 0; i < oldSize; ++i)
	{
		if (strlen(name[i]) >= 4 && price[i] >= 0.0)
		{
			validNames[newIndex] = name[i];
			validPrices[newIndex] = price[i];
			newIndex++;
		}
	}

	// Print the valid books for demonstration
	for (int i = 0; i < validBooks; ++i)
	{
		std::cout << "Book " << i + 1 << ": " << validNames[i] << ", Price: " << validPrices[i] << std::endl;
	}

	delete[] validNames;
	delete[] validPrices;
}



int main()
{
	//int myArray[] = { 1, 2, 3, 4, 5 };
	////const char* name2 = "ro";
	//Data data; // Create an instance of the Data class

	//if (data.checkArray(myArray))
	//{
	//	std::cout << "Array contains duplicates." << std::endl;
	//}
	//else {
	//	std::cout << "Array does not contain duplicates." << std::endl;
	//}

	const char* text[] = {"Ronaldo", "Messi", " ", "Yuno" ,"Yuki"};
	double price[] = { 69.0, 0.0 , 234.2, 200.2, 32 };
	Data data;
	
	data.bookResize(text, price);


	return 0;

	//bool ok = data.checkString(name); // Call the non-static member function using the object instance
	//cout << ok;
	//return 0;
}