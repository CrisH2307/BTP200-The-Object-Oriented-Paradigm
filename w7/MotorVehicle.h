
/*
*****************************************************************************
                              MotorVehicle.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#ifndef SDDS_MOTORVEHICLE_H__
#define SDDS_MOTORVEHICLE_H__
#include <iostream>
namespace sdds
{
    class MotorVehicle
    {
        char m_license[9];
        char m_address[64];
        int m_year;

    public:
        MotorVehicle(const char* license, int year);
        void moveTo(const char* address);
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
    };
    std::ostream& operator<<(std::ostream& o, const MotorVehicle& m);
    std::istream& operator>>(std::istream& i, MotorVehicle& m);

}
#endif