/***********************************************************************
// Final project Milestone 4
// Module: Perishable Test
// File: Item.h
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
#ifndef _SDDS_ITEM_H
#define _SDDS_ITEM_H
#define MAX_SKU_LEN 10
#include <ostream>
#include "Status.h"
#include "iProduct.h"
namespace sdds {
	class Item :public iProduct
	{
	private:
		//members
		double price;
		int quantity_OnHand;
		int quantity_Needed;
		char* item_desc;
		bool linear_output;
		/*bool stateOfObj;*/




	protected:
		//mebers
		Status status;
		int sku;

		//
		//method
		bool linear() const;


	public:
		//constructor
		Item();
		//
		//
		//copy constructor and assingmnet opeartor and destructor
		Item(const Item& item);
		Item& operator=(const Item& item);
		~Item();
		//
		//
		//virtual queries...
		int qtyNeeded() const;
		int qty() const;
		operator double()const;
		operator bool() const;
		//
		// 
		// overloading
		//modifier
		int operator-=(int reduce_qty);
		int operator+=(int increase_qty);
		void linear(bool isLinear);
		//opeartor
		bool operator==(int sku)const;
		bool operator==(const char* description)const;

		//modifiers
		void clear();
		//
		//
		//virtual input/output method overrides
		std::ofstream& save(std::ofstream& ofstr) const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		int readSku(std::istream& istr);
		std::istream& read(std::istream& istr);


	};

}
#endif