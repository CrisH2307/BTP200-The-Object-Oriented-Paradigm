//! Q-15
//! 
// main.cpp
#include <iostream>

int main()
{
    int size = 5;
    //double arr[size];
    double* arr = new double[size];         //! Solution
    for (auto i = 0; i < size; ++i)
        arr[i] = (i + 2.0) / 10 + i + 1;

    std::cout << arr[0];
    for (auto i = 0; i < size; ++i)
        std::cout << ", " << arr[i];
    std::cout << std::endl;

    return 0;
}

/*
Problem: Memory is not allocated. The size of a statically alloated arrays
must be known at compile-time --> size is a variable

Fix: Allocate size
*/