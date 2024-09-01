/***********************************************************************
// Final project Milestone 4
// Module: Perishable Test
// File: Perishable.h
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
#ifndef _SDDS_PERISHABLE_H
#define _SDDS_PERISHABLE_H
#include "Item.h"

#include "Date.h"
namespace sdds {
	class Perishable :public Item
	{
		Date exp_date;
		char* handling_instruction=nullptr;

	public:
		//
		//constructor
		Perishable();
		//
		//
		//RULE_OF_THREE
		// 
		//copy constructor
		Perishable(const Perishable& item);
		//copy assingment operator
		Perishable& operator=(const Perishable& item);
		//destructor
		~Perishable();
		//
		//
		//query
		const Date& expiry()const;
		//
		//virtual overrides
		//
		operator bool() const;
		//
		int readSku(std::istream& istr);
		//
		std::ofstream& save(std::ofstream& ofstr)const;
		// loads an perishable item from a file
		std::ifstream& load(std::ifstream& ifstr);
		// displays the perishable item on the screen
		std::ostream& display(std::ostream& ostr)const;
		//
		std::istream& read(std::istream& istr);


	};

}
#endif