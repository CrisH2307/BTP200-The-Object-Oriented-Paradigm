/*
*****************************************************************************
                              MotorVehicle.cpp
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "cstring.h"
#include "MotorVehicle.h"
using namespace std;
namespace sdds
{
    MotorVehicle::MotorVehicle(const char* license, int year)
    {
        //todo: a custom constructor that receives as parameters the license plate number and the year when the vehicle was built. 
        //      Sets the location of the vehicle as Factory. 
        //      Assume that this constructor is always used with valid data.

        strnCpy(this->m_license, license, 8);
        this->m_license[8] = '\0';  // Ensure null-terminated string
        strCpy(this->m_address, "Factory");  // Set default location as "Factory"
        this->m_year = year;

    }
    void MotorVehicle::moveTo(const char* address)
    {
        
        //todo: Prints to the screen the MotorVehicle information in the following format:
        //       | [LICENSE_PLATE]| |[CURRENT_ADDRESS] --->[NEW_ADDRESS] | <ENDL>
        // where
        //  the license plate is a field of 8 characters, where the displayed content is aligned to the right
        //  current address is a field of 20 characters, where the displayed content is aligned to the right
        //  new address is a field of 20 characters, where the display content is aligned to the left 
        //  Then, the function moves the vehicle to the new address if the new address is different from the current address, 
        //  by copying the received address as the MotorVehicle's current address.

        const int LICENSE_PLATE = 8;
        const int CURRENT_ADDRESS = 20;
        const int NEW_ADDRESS = 20;

        cout << "|";
        cout.width(LICENSE_PLATE);
        cout.setf(ios::right);
        cout << m_license;

        cout << "| |";
        cout.width(CURRENT_ADDRESS);
        cout << m_address;

        cout << " ---> ";
        cout.width(NEW_ADDRESS);
        cout.unsetf(ios::right);
        cout.setf(ios::left);

        if (strcmp(m_address, address) != 0)
        {
            strncpy(m_address, address, CURRENT_ADDRESS - 1);
            m_address[CURRENT_ADDRESS - 1] = '\0';
            cout << m_address;
        }

        cout << "|";
        cout << endl;
        cout.unsetf(ios::left);

    }
    ostream& MotorVehicle::write(ostream& os) const
    {
        // TODO: a query that inserts into os the current object's data in the following format:
        // | [YEAR] | [PLATE] | [ADDRESS]

        os << "| " << this->m_year << " | " << this->m_license << " | " << this->m_address;
        return os;
    }
    istream& MotorVehicle::read(istream& in)
    {
        // TODO: a mutator that reads from the stream in the data for the current object
        //       Built year : [USER TYPES HERE]
        //       License plate : [USER TYPES HERE]
        //       Current location : [USER TYPES HERE]

        cout << "Built year: ";
        in >> m_year;
        in.ignore();
        cout << "License plate: ";
        in.getline(m_license, 9);
        cout << "Current location: ";
        in.getline(m_address, 64);

        return in;
    }

    //! Helper Function
    //  overload the insertion and extraction operators to insert a MotorVehicle into a stream and extract a MotorVehicle from a stream.
    //  These operators should call the write / read member functions in the class MotorVehicle.
    ostream& operator<<(ostream& o, const MotorVehicle& m)
    {
        // TODO: insert return statement here
        m.write(o);
        return o;

    }
    istream& operator>>(istream& i, MotorVehicle& m)
    {
        // TODO: insert return statement here
        m.read(i);
        return i;
    }
}
