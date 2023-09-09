//! Inherited Constructors
 // inheritCtors.cpp

#include <iostream>
#include "Student.h"

int main() {
    Instructor john("John");
    Person jane("Jane");
    float gh[] = { 89.4f, 67.8f, 45.5f };
    Student harry("Harry", 1234, gh, 3);
    john.display(std::cout);
    std::cout << std::endl;
    harry.display(std::cout);
    jane.display(std::cout);
}