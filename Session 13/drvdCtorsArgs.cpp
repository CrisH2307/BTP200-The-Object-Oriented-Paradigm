//! Derived Class Constructors with Arguments
 // drvdCtorsArgs.cpp

#include <iostream>
#include "Student.h"

int main() {
    Person jane("Jane");
    float gh[] = { 89.4f, 67.8f, 45.5f };
    Student harry("Harry", 1234, gh, 3);

    harry.display(std::cout);
    jane.display(std::cout);
}