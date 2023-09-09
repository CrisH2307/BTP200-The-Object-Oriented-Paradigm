#ifndef LECTURES_TABLE_H
#define LECTURES_TABLE_H

namespace lectures
{

	class Table
	{
	private:  //Private, every member on the private will not change and access until the user change it
			  //todo This is INACCESSIBLE
		char m_material[100]{}; //Public attributes
		double m_length{};  // in meters
		// Checks if an object is in empty state
		
		// Return true if the object is in an empty state
		bool isEmpty() const;

		// Sets an object to the empty state
		void setEmpty();
		 
	public:  // Where you can access
		void display() const ;
		Table& set(const char* material);
		// Stores into the object of type table the material
		// <param name="theTbl" >< param name
		Table& set(double length);
	};
}

#endif