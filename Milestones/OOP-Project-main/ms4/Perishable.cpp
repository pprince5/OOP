/***********************************************************************
// Final project Milestone 4
// Module: Perishable Test
// File: Perishable.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <limits>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Perishable.h"
using namespace std;
namespace sdds
{
	Perishable::Perishable():Item()
	{
		handling_instruction = nullptr;

	}
	//rule of three
		//copy constructor
	Perishable::Perishable(const Perishable& item):Item(item)
	{
		handling_instruction = nullptr;
		*this = item;
	}
	//copy assingment operator
	Perishable& Perishable::operator=(const Perishable& item)
	{
		if (this != &item)
		{
			Item::operator=(item);
			exp_date = item.exp_date;
			delete[] handling_instruction;
			handling_instruction = nullptr;
			if (item.handling_instruction != nullptr)
			{
				handling_instruction = new char[strlen(item.handling_instruction) + 1];
				strcpy(handling_instruction, item.handling_instruction);
			}
		}
		return*this;

	}
	//destructor
	Perishable::~Perishable()
	{
		delete[] handling_instruction;

	}
	//
	//query
	const Date& Perishable::expiry()const
	{
		return exp_date;
	}
	//	
	//
	//virtual overrides
	Perishable::operator bool() const
	{
		return sku != 0;
	}
		//
	int Perishable::readSku(std::istream& istr)
	{

		status.clear();
		bool success = false;
		std::cout << "SKU: ";
		while (!success) {

			if (!(istr >> sku)) {
				std::cout << "Invalid Integer, retry: ";
				istr.clear();
				istr.ignore(1000, '\n');
			}
			else if (sku < 10000 || sku > 39999)
			{
				std::cout << "Value out of range [10000<=val<=39999]: ";
			}
			else
			{
				success = true;
			}
		}
		return sku;
	}
	std::ofstream& Perishable::save(std::ofstream& ofstr)const
	{
		if (status)
		{
			Item::save(ofstr);
			if (handling_instruction != nullptr)
			{
				ofstr << handling_instruction << "\t";
			}
			else
			{
				ofstr << "\t";
			}
			ofstr << setw(2) << setfill('0') << (exp_date.year % 100) << setw(2) << setfill('0') << exp_date.month << setw(2)
				<< setw(2) << setfill('0') << exp_date.day << "\t";
		}
		return ofstr;
	}
	// loads an iProduct from a file
	std::ifstream& Perishable::load(std::ifstream& ifstr)
	{
		Item::load(ifstr);
		if (ifstr.fail())
		{
			status = "Input file stream read (perishable) failed!";
			return ifstr;
		}
		delete[] handling_instruction;
		handling_instruction = nullptr;
		char string[1000];
		if (ifstr.getline(string, 1000, '\t') && isalpha(string[0]))
		{
			handling_instruction = new char[strlen(string) + 1];
				strcpy(handling_instruction, string);
		}
		ifstr >> exp_date;
		ifstr.ignore();
		
		return ifstr;
	}
	// displays the iProduct on the screen
	std::ostream& Perishable::display(std::ostream& ostr)const
	{
		if (!status)
		{
			ostr << status; 
		}
		else
		{
			if (Item::linear())
			{
				Item::display(ostr);
				if (handling_instruction != nullptr && handling_instruction[0] != '\0')
				{
					ostr << "*";
				}
				else
				{
					ostr << " ";
				}
				ostr << exp_date;

			}
			else
			{
				ostr << "Perishable ";
				Item::display(ostr);
				ostr << "Expiry date: ";
				ostr << exp_date;
				std::cout << std::endl;
				if (handling_instruction != nullptr && handling_instruction[0] != '\0')
				{
					ostr << "Handling Instructions: ";
					ostr << handling_instruction << std::endl;
				}

			}
		}
		return ostr;
	}
	std::istream& Perishable::read(std::istream& istr)
	{
		Item::read(istr);
		delete[] handling_instruction;
		handling_instruction = nullptr;

		std::cout << "Expiry date (YYMMDD): ";
		istr >> exp_date;
		istr.ignore();
		std::cout << "Handling Instructions, ENTER to skip: ";
		char first = istr.peek();
		if (first != '\n')
		{
			handling_instruction = new char[2000];  // Adjust the size as needed
			istr.getline(handling_instruction, 2000);
		}
		else
		{
			istr.ignore();

		}
		if (istr.fail())
		{
			status = "Perishable console date entry failed!";
		}
		return istr;
	}

};
