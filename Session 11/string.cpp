//! String Class example
 // string.cpp

#include <iostream>
#include <string>

int main() {
    char* s;
    std::string str;

    std::cout << "Enter a string : ";
    if (std::getline(std::cin, str)) {
        s = new char[str.length() + 1];
        std::strcpy(s, str.c_str());
        std::cout << "The string entered is : >" << s << '<' << std::endl;
        delete[] s;
    }
}
