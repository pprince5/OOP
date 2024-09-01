/***********************************************************************
// OOP244 Workshop #7 lab (part 1): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name prince        Date 13-11-2023           Reason
***********************************************************************/
//student ID: 145685228
// Mail: pprince5@myseneca.ca
// Section: zdd
#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include "Container.h"
using namespace sdds;
namespace sdds
{

	class Pack : public Container

	{

	private:
		int unitSize;
		int Size;
		int numUnits;

	public:
		//constructor
		Pack(const char* content, int size, int unit_Size = 330, int no_of_units = 0);
		//
		//
		//
		int operator+=(int);
		int operator-=(int);
		//
		//
		int unit();
		int noOfUnits();
		int size();
		//
		//
		void clear(int, int, const char*);
		//
		//
		ostream& print(ostream&);
		istream& read(istream&);
	

	};
	//
	//
	ostream& operator << (ostream& os, Pack& obj);
	istream& operator >> (istream& is, Pack& obj);
}
#endif
