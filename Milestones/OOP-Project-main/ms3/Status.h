/***********************************************************************
// Final project Milestone 3
// Module: iProduct and Item
// File: Status.h
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name prince            Date 24/11/2023            Reason
***********************************************************************/
// Id: 145685228
// Mail: pprince5@myseneca.ca
// section: zdd
#ifndef _SDDS_STATUS_H
#define _SDDS_STATUS_H
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
	class Status
	{
		char* description{};
		int code;
	public:
		//constructors
		Status();
		//
		Status(const char* refDescription);
		//
		//copy Constructor
		Status(const Status& obj);
		//
		//
		//destructor
		~Status();
		//
		Status& clear();
		//Overloading
		Status& operator=(const char* description);
		Status& operator=(int code);
		//
		//casting
		operator int() const;
		operator bool() const;
		operator const char* () const;
		//Helper functions
		std::ostream& printStatus(std::ostream& obj) const;



	};
	//helper
	std::ostream& operator << (std::ostream& os, const Status& obj);
}
#endif