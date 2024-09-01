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

#include <iostream>
#include "Shape.h"

using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	};

	std::istream& operator>>(std::istream& is, Shape& shape) {
		shape.getspecs(is);
		return is;
	};

	Shape::~Shape() {
	};
}