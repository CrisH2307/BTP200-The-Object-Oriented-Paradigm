/*
*****************************************************************************
							  Utils.h
Full Name  : Xuan Khang Huynh (Cris Huynh)
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_UTILS_H // replace with relevant names, each header should have it's own header guard
#define SDDS_UTILS_H
// Your header file content goes here
namespace sdds
{

	void flushkeys();

	bool validYesResponse(char ch);

	bool yes();

	void readCstr(char cstr[], int len);

	int readInt(int min, int max);

}
#endif