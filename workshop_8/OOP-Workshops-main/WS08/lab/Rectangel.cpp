/***********************************************************************
// OOP244 Workshop #8 lab (part 1): tester program
//
// File  Retangle.cpp
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
#include <iomanip>
#include <string.h>
#include "Line.h"
#include "Rectangle.h"
using namespace std;
namespace sdds {
	//
	//constructor
	Rectangle::Rectangle() :Lblshape()
	{
		m_width = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char* string,const int width,const int height) :Lblshape(string) 
	{
		int check = strlen(label()) + 2;
		if (height < 3 || width < check)
		{
			m_height = 0;
			m_width = 0;
		}
		else 
		{
			m_width = width;
			m_height = height;

		}
	}
	//destructor: no destructor
	/*Rectangle::~Rectangle() 
	{

	}*/
	void Rectangle::getspecs(std::istream& is) 
	{
		Lblshape::getspecs(is);
		is >> m_width;
		is.ignore(2000,',');
		is >> m_height;
		is.ignore(2000, '\n');
	}
	void Rectangle::draw(std::ostream& os) const 
	{
		if (m_height > 0 && m_width > 0)
		{

			os << "+";
			for (int i = 0; i < m_width - 2; i++) 
			{
				os << "-";
			}
			os << "+" << endl;
			os << "|";
			
			/*os.width(m_width - 2);
			os.left;
			os << label();*/
			os << setw((streamsize)m_width - 2) << setfill(' ') << left << label();
			os << "|" << std::endl;
			for (int i = 0; i < m_height - 3; i++) {
				os << "|" << setw((streamsize)m_width - 2) << " " << "|" << endl;
			}

			os << "+";
			for (int i = 0; i < m_width - 2; i++)
			{
				os << "-";
			}
			os << "+";

			


		}
	
	}
}
