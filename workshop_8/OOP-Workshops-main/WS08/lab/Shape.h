/***********************************************************************
// OOP244 Workshop #8 lab (part 1): tester program
//
// File  Shape.h
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

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>


using namespace std;
namespace sdds {
	class Shape {

	public:
		virtual void draw(std::ostream& os)const = 0;
		virtual void getspecs(std::istream& is) = 0;
		//
		//virtual destructor
		virtual ~Shape() = 0;
	};
	std::ostream& operator<<(std::ostream& os, const Shape& shape);
	
	std::istream& operator>>(std::istream& is, Shape& shape);
	




}

#endif