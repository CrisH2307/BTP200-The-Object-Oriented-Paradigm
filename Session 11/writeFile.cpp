//! Writing to a File
 // writeFile.cpp

#include <iostream>
#include <fstream>

    int main() {
        int i;

        std::ofstream f("output.txt");
        if (f.is_open()) {
            f << "Line 1" << std::endl;   // record 1
            f << "Line 2" << std::endl;   // record 2
            f << "Line 3" << std::endl;   // record 3
        }
    }
}