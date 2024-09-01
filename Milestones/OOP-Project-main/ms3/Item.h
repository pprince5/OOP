/***********************************************************************
// Final project Milestone 3
// Module: iProduct and Item
// File: Item.h
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