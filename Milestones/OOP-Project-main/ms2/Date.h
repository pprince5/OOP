/***********************************************************************
// Final project Milestone 1
// Module: Utils
// File: Utils.h
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Prince           Date 02-Nov-2023           Reason
***********************************************************************/
// ID: 145685228
// Mail: pprince5@myseneca.ca
// Section: ZDD
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
		int year;
		int month;
		int day;
		Status status;
		bool format;
		// private functions
		bool validate();
		int uniqueValue() const;
	public:
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