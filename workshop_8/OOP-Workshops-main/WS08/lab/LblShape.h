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
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"

using namespace std;
namespace sdds {

	class Lblshape :public Shape 
	{
		char* m_label = nullptr;
	protected:
		const char* label() const;
	public:
		//
		virtual void draw(std::ostream& os)const = 0;
		//constructors
		Lblshape();
		Lblshape(const char* string);
		//destructor
		~Lblshape();
		void getspecs(std::istream& is);
		//
		//
		//deleted copy constructor and assignment operator
		Lblshape(Lblshape&) = delete;
		Lblshape& operator=(Lblshape&) = delete;
		//
		// virtual function overriding
		/*void Shape::getspecs(std::istream& is);*/
	};

}
#endif