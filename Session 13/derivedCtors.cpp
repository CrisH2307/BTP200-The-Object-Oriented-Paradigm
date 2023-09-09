//! Derived Class Constructors
 // derivedCtors.cpp

#include <iostream>
#include "Student.h"

int main() {
    Person jane;
    float gh[] = { 89.4f, 67.8f, 45.5f };
    Student harry(1234, gh, 3);

    harry.set("Harry");
    harry.display(std::cout);

    jane.set("Jane");
    jane.display(std::cout);
}