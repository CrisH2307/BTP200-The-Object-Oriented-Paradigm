//! Connect to a File for Reading
 // connectFileReading.cpp

#include <fstream>

int main() {
    std::ifstream fin;     // defines a file object named fin 
    fin.open("input.txt"); // connects input.txt to fin
    // ...
}