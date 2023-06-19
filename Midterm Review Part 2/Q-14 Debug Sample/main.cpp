//! Q-14

// main.cpp
#include <iostream>

// inserts "item" into the array at the end;
// resize the array and returns the address of the new array
double* insert(double* arr, int& size, double item)
{
    double* tmp = new double[size + 1];

    for (auto i = 0; i < size; ++i)
        tmp[i] = arr[i];
    tmp[size] = item;

    arr = tmp;
    ++size;

    delete[] tmp; //! Solution: Deallocate tmp

    return tmp;
}

int main()
{
    int size = 5;
    double* arr = new double[size];
    for (auto i = 0; i < size; ++i)
        arr[i] = (i + 2.0) / 10 + i + 1;

    arr = insert(arr, size, 6.7);

    for (auto i = 0; i < size; ++i)
        std::cout << arr[i] << ", ";

    delete[] arr;

    return 0;
}

/*
Problem: Memory leak in main()

Fix: Deallocate insert()
*/