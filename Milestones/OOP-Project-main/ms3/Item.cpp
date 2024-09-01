/***********************************************************************
// Final project Milestone 3
// Module: iProduct and Item
// File: Item.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <limits>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Item.h"
#include "Utils.h"
using namespace std;
namespace sdds {

	//protected return the linear flag of the item
	bool Item::linear() const
	{
		return linear_output;

	}
	//
	//default constructor that sets all the attributes to zero, nullptr and false.
	Item::Item() :status()
	{
		price = 0;
		quantity_OnHand = 0;
		quantity_Needed = 0;
		item_desc = nullptr;
		linear_output = false;
		sku = 0;

		/*stateOfObj = false;*/

	}
	//
	//
	//rule of three
	//copy constructor
	Item::Item(const Item& item)
	{
		if (item.item_desc != nullptr)
		{
			item_desc = new char[strlen(item.item_desc) + 1];
			strcpy(this->item_desc, item.item_desc);
		}
		else {
			item_desc = nullptr;
		}

		price = item.price;
		quantity_OnHand = item.quantity_OnHand;
		quantity_Needed = item.quantity_Needed;
		sku = item.sku;
		linear_output = item.linear_output;
		status = item.status;
	}
	// copy assignment opearator
	Item& Item::operator=(const Item& item)
	{
		if (this != &item)
		{
			delete[] item_desc;
			if (item.item_desc != nullptr)
			{
				item_desc = new char[strlen(item.item_desc) + 1];
				strcpy(this->item_desc, item.item_desc);
			}
			else {
				item_desc = nullptr;
			}
			//
			price = item.price;
			quantity_OnHand = item.quantity_OnHand;
			quantity_Needed = item.quantity_Needed;
			sku = item.sku;
			linear_output = item.linear_output;
			status = item.status;
		}
		return*this;

	}
	//destructor
	Item::~Item()
	{
		delete[] item_desc;
	}
	//
	//
	// virtual public iproductn quesries overriding
	int Item::qtyNeeded() const
	{
		return quantity_Needed;
	}
	int Item::qty() const
	{
		return quantity_OnHand;
	}
	Item::operator double()const
	{
		return price;
	}
	Item::operator bool() const
	{
		return status;
	}
	//
	//
	//virtual public modifier iproduct overrides
	//reduces the on-hand quantity by the received value
	int Item::operator-=(int reduce_qty)
	{
		if (reduce_qty > 0)
		{
			quantity_OnHand -= reduce_qty;
		}
		return quantity_OnHand;
	}
	//increases the on-hand quantity by the received value
	int Item::operator+=(int increase_qty)
	{
		if (increase_qty > 0)
		{
			quantity_OnHand += increase_qty;
		}
		return quantity_OnHand;

	}
	//sets the linear flag attribute to true or false
	void Item::linear(bool isLinear)
	{
		linear_output = isLinear;
	}
	//
	//public modifier
	void Item::clear()
	{

		status.clear();
	}
	//
	//
	//virtual operator overrides
	bool Item::operator==(int sku)const
	{


		return sku == this->sku;
	}
	bool Item::operator==(const char* description)const
	{
		return strstr(item_desc, description) != nullptr;
	}
	//
	/*void Item::linear(bool isLinear)
	{
		linear_output = isLinear;
	}*/
	//
	//virtual input/output method overrides
	std::ofstream& Item::save(std::ofstream& ofstr) const
	{
		if (status)
		{
			ofstr << sku << "\t" << item_desc << "\t" << qty() << "\t" << qtyNeeded() << "\t";
			ofstr << std::fixed <<
				std::setprecision(2)
				<< price << "\t";
		}
		return ofstr;

	}
	std::ifstream& Item::load(std::ifstream& ifstr)
	{

		delete[] item_desc;

		item_desc = nullptr;
		ifstr >> sku;
		if (ifstr.fail()) {
			status = "Input file stream read failed!";
		}
		else {
			//std::cout << "SKU: " << m_sku << std::endl;
			char temp[2000];
			ifstr.ignore();
			ifstr.getline(temp, 2000, '\t');
			item_desc = new char[strlen(temp) + 1];
			strcpy(item_desc, temp);
			//std::cout << "Description: " << m_description << std::endl;
			ifstr >> quantity_OnHand;
			ifstr.ignore();

			ifstr >> quantity_Needed;
			ifstr.ignore();

			ifstr >> price;
			ifstr.ignore(1);
		}
		return ifstr;

	}
	std::ostream& Item::display(std::ostream& ostr)const
	{
		if (!status) {
			ostr << status;
		}
		else {
			if (linear_output) {
				ostr << std::setw(5) << sku << " | "
					<< std::left << std::setw(35) << std::setfill(' ') << (std::strlen(item_desc) > 35 ? std::string(item_desc, 35) : item_desc)
					<< " | " << std::right << std::setw(4) << quantity_OnHand << " | "
					<< std::right << std::setw(4) << quantity_Needed << " | "
					<< std::right << std::setw(7) << std::setprecision(2) << price << " |";
			}
			else {
				ostr << "AMA Item:" << std::endl
					<< std::setw(5) << sku << ": "
					<< item_desc << std::endl
					<< "Quantity Needed: " << quantity_Needed << std::endl
					<< "Quantity Available: " << quantity_OnHand << std::endl
					<< "Unit Price: $" << std::fixed << std::setprecision(2) << price << std::endl
					<< "Needed Purchase Fund: $" << std::fixed << std::setprecision(2) << (quantity_Needed * price) - (quantity_OnHand * price) << std::endl;
			}
		}
		return ostr;
	}
	int Item::readSku(std::istream& istr)
	{
		status.clear();
		bool success = false;
		std::cout << "SKU: ";
		while (!success) {

			if (!(istr >> sku)) {
				std::cout << "Invalid Integer, retry: ";
				istr.clear();
				istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (sku < 40000 || sku > 99999)
			{
				std::cout << "Value out of range [40000<=val<=99999]: ";
			}
			else
			{
				success = true;
			}
		}
		return sku;
	}
	std::istream& Item::read(std::istream& istr)
	{
		delete[] item_desc;
		item_desc = nullptr;

		std::cout << "AMA Item:" << std::endl
			<< "SKU: " << sku << std::endl
			<< "Description: ";

		istr.ignore();
		char temp[2000];
		istr.getline(temp, 2000);
		item_desc = new char[strlen(temp) + 1];
		strcpy(item_desc, temp);

		bool success = false;
		std::cout << "Quantity Needed: ";
		while (!success) {

			if (!(istr >> quantity_Needed))
			{
				std::cout << "Invalid Integer, retry: ";
				istr.clear();
				istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (quantity_Needed < 1 || quantity_Needed > 9999)
			{
				std::cout << "Value out of range [1<=val<=9999]: ";
			}
			else {
				success = true;
			}
		}

		// Quantity On Hand
		success = false;
		std::cout << "Quantity On Hand: ";
		while (!success) {

			if (!(istr >> quantity_OnHand))
			{
				std::cout << "Invalid Integer, retry: ";
				istr.clear();
				istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (quantity_OnHand < 0 || quantity_OnHand > quantity_Needed)
			{
				std::cout << "Value out of range [0<=val<=22]: ";
			}
			else
			{
				success = true;
			}
		}

		// Price
		success = false;
		std::cout << "Unit Price: $";
		while (!success) {

			if (!(istr >> price))
			{
				std::cout << "Invalid number, retry: ";
				istr.clear();
				istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (price < 0.0 || price > 9999.0)
			{
				std::cout << "Value out of range [0.00<=val<=9999.00]: ";
			}
			else {
				success = true;
			}
		}

		return istr;
	}
}

