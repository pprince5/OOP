/***********************************************************************
// OOP244 Workshop #8 lab (part 1): tester program
//
// File  Line.cpp.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Prince   Date 19-11-2023
// I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
// Email: pprince5@myseneca.ca 
// Student ID 145685228
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Line.h"

using namespace std;
namespace sdds
{
	//
	//constructors
	Line::Line() :Lblshape()
	{
		m_length = 0;

	};
	Line::Line(const char* string, const int length) :Lblshape(string)
	{
		m_length = length;
	};
	//destructors:: no destructor

	//
	//overriding
	void Line::getspecs(std::istream& is)
	{
		Lblshape::getspecs(is);
		is >> m_length;
		is.ignore();
	};
	//
	void Line::draw(std::ostream& os) const
	{
		if (m_length > 0 && label() != nullptr)
		{
			os << label() << endl;
			for (int i = 0; i < m_length; i++)
			{
				os << "=";
			}
		}
	};


}
