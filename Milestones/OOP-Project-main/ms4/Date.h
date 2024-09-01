/***********************************************************************
// Final project Milestone 4
// Module: Perishable Test
// File: Date.h
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
#ifndef _SDDS_DATE_H
#define _SDDS_DATE_H
#include <iostream>
#include <cstring>
#include <sstream>
#include"Status.h"
using namespace std;
namespace sdds {
	const int MAXIMUM_YEAR = 2030;
	class Date
	{
	public:
		int year;
		int month;
		int day;
		Status status;
		bool format;
		// private functions
		bool validate();
		int uniqueValue() const;
	
		//constructors
		Date();
		Date(int year, int month, int date);
		//
		// 
		//overloading
		bool operator==(const Date& object) const;
		bool operator!=(const Date& object) const;
		bool operator<(const Date& object) const;
		bool operator>(const Date& object) const;
		bool operator>=(const Date& object) const;
		bool operator<=(const Date& object) const;
		//
		//
		const Status& state();
		//
		Date& formatted(bool isDateFormatted);
		//Casting
		operator bool() const;
		//
		//
		// 
		std::ostream& write(std::ostream& object) const;
		std::istream& read(std::istream& object);

	};
	//Helper functions
	std::ostream& operator<<(std::ostream& os, const Date& date);
	//
	std::istream& operator>>(std::istream& is, Date& date);

}
#endif