//! Q-13

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
 
   // delete[] arr;     //! Solution: DELETE
 
   arr = tmp;
   ++size;

   delete[] tmp;
 
   return arr;
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
 Problem: insert() has 2 deallocate, which mean return is garbages
 In the insert function, after assigning tmp to arr and incrementing size,
 you should not delete arr again because it now points to the modified array.
 Instead, you should delete the tmp array, which was used to store the copied contents.
 The one you allocate, the allocate u have to
  */