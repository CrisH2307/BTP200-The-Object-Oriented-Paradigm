//! Connect to a File for Writing
 // connectFileWriting.cpp

#include <fstream>

int main() {
    std::ofstream fout;      // create a file object named fout 
    std::ofstream fout("output.txt"); // connects fout to output.txt for writing 
    // ...
}