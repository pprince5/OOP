/***********************************************************************
// Final project Milestone 4
// Module: Perishable Test
// File: Status.h
// Version 1.1
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
// Prince              28-11-4
***********************************************************************/
// ID: 145685228
// mail: pprince5@seneca.ca
// Section:: ZDD
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