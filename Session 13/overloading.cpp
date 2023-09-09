// Overloading and Shadowing
 // overloading.cpp

#include <iostream>
#include "Student.h"

int main() {
    Person jane;
    float gh[] = { 89.4f, 67.8f, 45.5f };
    Student harry(1234, gh, 3);

    harry.set("Harry");
    harry.display(std::cout);
    harry.display(std::cout, "Name is ");
    std::cout << std::endl;
    jane.set("Jane Doe");
    jane.display(std::cout);
    std::cout << std::endl;
}