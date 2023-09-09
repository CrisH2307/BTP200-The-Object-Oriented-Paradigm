//! Reading From a file
 // readFile.cpp

#include <iostream>
#include <fstream>

int main() {
    int i;

    std::ifstream f("input.txt");
    if (f.is_open()) {
        while (f) {
            f >> i;
            if (f)
                std::cout << i << ' ';
            else
                std::cout << "\n**Bad input**\n";
        }
    }
}