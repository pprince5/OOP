/***********************************************************************
// OOP244 Workshop #8 lab (part 1): tester program
//
// File  Line.h
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
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"

using namespace std;
namespace sdds {

	class Line : public Lblshape
	{
		int m_length;
	public:
		//
		// 
		//constructors
		Line();
		Line(const char* string,const int length);
		//destructor : no destructor
		void getspecs(std::istream& is);
		void draw(std::ostream& os)const;


	};




}
#endif
