#ifndef _LECTURES_ARRAYLIST_H
#define _LECTURES_ARRAYLIST_H

namespace lectures
{
	class ArrayList
	{
		double* m_data = nullptr;
		int m_cnt = 0;

	public:
		// Construcor
		ArrayList() = default;		// Create an empty list  (no data allocated)
		explicit ArrayList(int cnt);			// Create an array with cnt elements
		void display() const;		// Prints to screen the array in a formatted way
		ArrayList& push_back(double val);	// Add at the end of the collection one more element



		// Overload
		// Add to the current instance all the elements found in the parameter
		ArrayList& operator+=(const ArrayList& other);

		// Same as ArrayList& operator+=(const ArrayList& other) and also implementation
		ArrayList& operator<<(const ArrayList& other);


		// Casting operator, conversion to bool operator, returns true if current instant
		explicit operator bool()const;

		// add 1 to every element in the collection
		ArrayList& operator++(); //! Pre-fix


		// post fix, does the same shit as prefix
		ArrayList operator++(int); //! Post-fix

		//copy constructor
		ArrayList(const ArrayList& other);

		//Copy assignment
		ArrayList operator=(const ArrayList& other);

		std::ostream& operator<<(std::ostream& out, const ArrayList& al);

		// Destructor
		~ArrayList();				// Clean up any dynamic memory used by the current obj
	};
}

#endif // !_LECTURES_ARRAYLIST_H




