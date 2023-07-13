/*
*****************************************************************************
                              Truck.cpp
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
#include <cstring>
#include "MotorVehicle.h"
#include "Truck.h"
using namespace std;
namespace sdds
{
    Truck::Truck(const char* license, int year, double capacity, const char* address)
     :
    MotorVehicle(license, year)
    {
        //Todo:
        /*
        A custom constructor that receives the license plate number, the year when the truck was built, 
        the capacity of the truck and the current address, as 1st, 2nd, 3rd, and 4th parameters, respectively. 
        Passes license number and year into the base class constructor invocation. Sets the current cargo to 0, 
        capacity to the corresponding received argument, and calls the base class moveTo function to set 
        current address to the received address.
        */
        // Initialize member variables
        this->m_capacity = capacity;
        this->m_cargo = 0.0;

        // Set current address using base class function
        moveTo(address);

    }
    bool Truck::addCargo(double cargo)
    {
        //Todo:
        /*
        a mutator to adds the received cargo load. If there is space for extra cargo load, i.e., 
        current cargo load is less than the capacity, adds the received cargo load and the current cargo load. 
        Then the current cargo load is set to the load resulting from the addition or the Truck's capacity, 
        whichever is smaller. Ensures that the cargo load Does not exceed the capacity! If the current load has been changed, 
        returns true, otherwise returns false.
        */
        
        bool ok = false;
        double newCargoLoad = this->m_cargo + cargo; 
        double newTotalLoad = min(newCargoLoad, m_capacity); 

        if (newTotalLoad != this->m_cargo) 
        {
            this->m_cargo = newTotalLoad; 
            ok = true; 
        }

        return ok;
    }
    bool Truck::unloadCargo()
    {
        //Todo: A mutator that unloads the current cargo by setting the attribute to 0. If the current load has been changed, returns true, otherwise, returns false.

        bool fml = false;

        if (this->m_cargo > 0.0)
        {
            this->m_cargo = 0.0;
            fml = true;
        }
        return fml;       
    }
    ostream& Truck::write(ostream& os) const
    {
        // TODO: A query that inserts into os the object's data in the format:
        //       | [YEAR] | [PLATE] | [ADDRESS] | [CURRENT_CARGO] / [CAPACITY]
        // Note: call the Base-class version of write function to display base-class data (year, plate, address).

        MotorVehicle::write(os);
        os << " | " << this->m_cargo << "/" << this->m_capacity;

        return os;
    }
    istream& Truck::read(istream& in) 
    {
        // TODO: a mutator that reads from the stream in the data for the current object
        /*
        Built year: [USER TYPES HERE]
        License plate: [USER TYPES HERE]
        Current location: [USER TYPES HERE]
        Capacity: [USER TYPES HERE]
        Cargo: [USER TYPES HERE]
        */
        // Note: call Base-class version of read function to read year, place and address.

        MotorVehicle::read(in);

        cout << "Capacity: ";
        in >> m_capacity;
        cout << "Cargo: ";
        in >> m_cargo;

        return in;
    }

    //! Helper Function
    // Helper Functions
    // Overload the insertion and extraction operators to insert a Truck into a stream and extract a Truck from a stream.
    // These operators should call the write / read member functions in the class Truck.

    std::ostream& operator<<(std::ostream& o, const Truck& t)
    {
        // TODO: insert return statement here
        t.write(o);
        return o;
    }
    std::istream& operator>>(std::istream& i, Truck& t)
    {
        // TODO: insert return statement here
        t.read(i);
        return i;
    }
}

