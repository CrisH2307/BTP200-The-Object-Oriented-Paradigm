/*
*****************************************************************************
							  File.h
Full Name  : Xuan Khang Huynh (Cris Huynh)
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds
{
	bool openFile(const char* filename);

	void closeFile();

	int noOfRecordsInFile();

	bool read(char* str);

	bool read(int& val);

}
#endif // !SDDS_FILE_H