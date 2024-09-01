/***********************************************************************
// OOP244 Workshop #8 lab (part 1): tester program
//
// File  Rectangle.h
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
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H


#include "LblShape.h"

namespace sdds {

	class Rectangle : public Lblshape
	{
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* string,const int width,const int height);
		/*~Rectangle();*/
		//
		void getspecs(std::istream& is);
		void draw(std::ostream& os) const;


	};
}
#endif