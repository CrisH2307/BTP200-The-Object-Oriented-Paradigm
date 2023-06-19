// main.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include "test.h"

using namespace culture;
using namespace std;

int main()
{
     culture::Book aBook;   //Missing default constructor
	 // aBook.m_year = 2010; --> Error 04: m_year is the private attribute that it cant be accessible
	 return 0;
}