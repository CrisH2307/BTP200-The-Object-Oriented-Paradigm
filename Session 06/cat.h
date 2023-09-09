#ifndef LECTURES_CAT_H
#define LECTURES_CAT_H


namespace lectures
{
	class Cat
	{
		char* m_name;
		int m_age;

	public:
		Cat(); // Default Contructor
		// Same name as the class
		// Dont return anything
		// Purpose: Initialize all attributes
		// NEVER CALL CONSTRUCTOR, IT WILL AUTOMATICALLY CALL FOR USER, CHANGE CURRENT INSTANCE
		~Cat();
		// Destructor
		// Purpose: Release any resource used by current instance
		void display()const;
		void set(const char* name, int age);
	};
}

#endif
