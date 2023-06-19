//! Q-12
// main.cpp
// inserts "item" into the array at the end;
// resize the array and returns the address of the new array


double* insert(double* arr, int& size, double item)
{
	double* tmp = new double[size + 1];

	for (auto i = 0; i < size; ++i)
		tmp[i] = arr[i];
	tmp[size] = item;

	delete[] arr;

	arr = tmp;
	++size;

	return arr;
}

int main()
{
    int size = 5;
    double* arr = new double[size] { 1.2, 2.3, 3.4, 4.5, 5.6 }; //! Solution

    arr = insert(arr, size, 6.7);		//! Solution

    delete[] arr;

    return 0;
}
/*
The insert function expects a dynamically allocated array as the first parameter,
but the client code passes a statically-allocated array double arr[5]. 
This causes a problem because the delete[] operator can only be used to deallocate memory
that was allocated with new[].
*/

