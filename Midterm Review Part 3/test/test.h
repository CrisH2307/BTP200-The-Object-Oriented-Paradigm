#include <iostream>             //! for std::ostream, std::istream

using namespace std;

class Data
{
	char* m_title{};
	double m_price{};
public:

	//! Data validation
	//! 1
	bool checkString(const char* name);

	//! 7
	bool checkArray(int integer[]);

	//! Data Processing
	int wordCheck(const char* word, const char* word2);

	//! Dynamic Memory
	void resize(const char* text);		//1
	char* resizeBlank(const char* text);
	void bookResize( const char* name[], double price[]);

};
