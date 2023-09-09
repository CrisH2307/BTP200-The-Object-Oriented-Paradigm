//! Shadowing
// shadowing.cpp


#include <iostream>
#include "Student.h"

int main() {
    Person jane;
    jane.set("Jane Doe");
    float gh[] = { 89.4f, 67.8f, 45.5f };
    Student harry(1234, gh, 3);
    harry.set("Harry");           // inherited
    harry.display(std::cout);     // not inherited
    jane.display(std::cout);
    std::cout << std::endl;
}
