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
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
#include<iostream>
using namespace std;
namespace sdds
{
	class Container
	{
		char Description[50];
		int Capacity;
		int contentVolume;
		bool isContainerValid;
	protected:
		void setEmpty();
		int capacity();
		int volume();
	public:
		//constructor
		Container(const char* Content, int capacity, int volume = 0);
		//
		//
		int operator+=(int);
		int operator-=(int);
		//
		bool validity();
		void clear(int, const char*);
		//
		ostream& print(ostream&);
		istream& read(istream&);
	};
	ostream& operator<<(ostream& os, Container& obj);
	istream& operator>>(istream& is, Container& obj);
}
#endif