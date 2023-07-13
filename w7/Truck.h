
/*
*****************************************************************************
                              Truck.h
Full Name  : Cris Huynh
Student ID#: 105444228
Email      : xhuynh@myseneca.ca
Course     : BTP200 NAA

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/


#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__
#include <iostream>
#include "MotorVehicle.h"
namespace sdds
{
    class Truck : public MotorVehicle
    {
        double m_capacity;
        double m_cargo;

    public:
        Truck(const char* license, int year, double capacity, const char* address);
        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
    };
    std::ostream& operator<<(std::ostream& o, const Truck& t);
    std::istream& operator>>(std::istream& i, Truck& t);


}
#endif